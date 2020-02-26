#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <vector>
#include <numeric>
#include <bits/stdc++.h>
#include <limits>
#include <fstream>
#include <random>
#include <chrono>

#define daugiausia 50
/// struktura sauganti duomenis apie studenta ir jo pazymius
struct Studentas1
{
    std::string vardas, pavarde;
    int egz; int n = 0;
    double galutinis;
    std::vector<int> vektoriukas;
};
/// funkcija patikrinanti ar vartotojo ivesti duomenys (siuo atveju simbolis) yra tinkamo formato
void ar_tas_simboliukas (char& simbolis, char pirmas, char antras)
{
    while (!(simbolis == pirmas || simbolis == antras))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"Ivestas netinkamas dydis" <<std::endl;
        std::cout << "Pasirinkite viena is variantu arba " << pirmas << " arba " << antras << ": ";
        std::cin >> simbolis;
    }
}
/// funkcija patikrinanti ar vartotojo ivesti duomenys (siuo atveju skaiciai) yra tinkamo formato
void ar_tinkamas_skaiciukas (int& skaicius, int pradzia, int pabaiga)
{
    while (std::cin.fail() || skaicius < pradzia || skaicius > pabaiga)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"Ivestas netinkamas dydis" <<std::endl;
        std::cout << "Pasirinkite skaiciu is intervalo nuo" << pradzia << " iki " << pabaiga << ": ";
        std::cin >> skaicius;
    }
}
/// funkcija apskaiciuojanti mediana
double rastimediana (std::vector<int> vekt)
{
    typedef std::vector<int>::size_type vec_sz;
    vec_sz size = vekt.size(); std::sort(vekt.begin(), vekt.end());
    vec_sz mid = size / 2;
    return (double)(size % 2 == 0 ? ((double)(vekt[mid]) + (double)(vekt[mid-1])) / 2 : (double)(vekt[mid]));
}
/// funkcija apskaiciuojanti masyvo elementu vidurki
double vidurkis (int* nd, int n)
{
    double sum = 0;
    for (int i = 0; i < n; i ++) sum += nd[i];
    return (sum / n);
}
/// funkcija apsakiciuojanti galutini rezultata pagal vartotojo pasirinktus skaiciavimo metodus
double galutinis (char kas_cia1, Studentas1* Studentas)
{
    double nd;
      if(kas_cia1 == 'm') nd = rastimediana (Studentas->vektoriukas);
           else nd = vidurkis(&Studentas->vektoriukas[0], Studentas->vektoriukas.size());
    return (0.4 * nd + 0.6 * Studentas->egz);
}
/// funkcija generuojanti namu darbu ir egzamino balus
void pazymiu_generavimas (char kas_cia, Studentas1* Studentas)
{
    int galas=0; int kiek=1;
    std::cout << "Generuojamu pazymiu kiekis: "; std::cin >> kiek; std::cout<<std::endl;
    ar_tinkamas_skaiciukas (kiek, 1, daugiausia);
    std::cout << "Namu darbu balai: " ; std::cout<<std::endl;

    using hrClock = std::chrono::high_resolution_clock;
    std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> dist(1, 10);
            do
            {       Studentas->vektoriukas.push_back(dist(mt));
                    std::cout  << Studentas->vektoriukas[Studentas->n]<<" " ;
                    Studentas->n ++; kiek--;
            } while (galas != kiek);

    std::cout<<std::endl; Studentas->egz = dist(mt);
    std::cout << "Egzamino balas: " << Studentas->egz <<std::endl; std::cout<<std::endl;
}

bool rikiuojam(Studentas1 a, Studentas1  b)
{
    return a.vardas < b.vardas;
}

int main ()
{
    srand(time(NULL)); std::vector<Studentas1> Studentas; std::string kas_vyksta;
    char vidurkis_mediana, generuojam, vektorius_masyvas, skaitom_ivedam;
    int kelintas = 0, nd, jei_nulis_baigiam=1, studentu_kiek, pabaiga=0;

    /// vatrotojas pasirenka kiek studentu ir kokiais budais apskaiciuoti galutini rezultata
    /// ar vartotojas nuspres keliu mokiniu duomenis nuskaityti is failo
    std::cout << "skaitom is failo (s) ar ivedam ranka (i)? iveskite 's' arba 'i' --> "; std::cin >> skaitom_ivedam;
    ar_tas_simboliukas(skaitom_ivedam, 's', 'i'); std::cout<<std::endl;

    std::cout << "vidurkis (v) ar mediana (m)? iveskite 'v' arba 'm' --> "; std::cin >> vidurkis_mediana;
    ar_tas_simboliukas(vidurkis_mediana, 'm', 'v'); std::cout<<std::endl;

    if (skaitom_ivedam == 'i')
    {
            std::cout << "generuojam (g) ar negeneruojam (n)? iveskite 'g' arba 'n' --> "; std::cin >> generuojam;
            ar_tas_simboliukas(generuojam, 'g', 'n');

            std::cout << "Studentu skaicius: "; std::cin >> studentu_kiek;
            ar_tinkamas_skaiciukas(studentu_kiek, 1, daugiausia);
    }
        else if (skaitom_ivedam == 's')
        {
            int nd_kiekis_faile = 0; std::ifstream duom ("kursiokai.txt");
                if (duom.good())
                {
                    std::string str;  std::getline(duom, str);
                    std::istringstream s (str);  std::string str1;
                    while (s >> str1) {  nd_kiekis_faile++; }
                }
                nd_kiekis_faile -= 3;
                int i = 0; Studentas1 tmp;
                while(!duom.eof())
                {
                    duom >> tmp.vardas >> tmp.pavarde;
                    for (int j = 0; j < nd_kiekis_faile; j++)
                    {
                            if (duom.fail())
                            {
                                duom.clear();
                                duom.ignore();
                            }
                        duom >> nd; tmp.vektoriukas.push_back(nd);
                    }
                    duom >> tmp.egz;
                    tmp.galutinis=galutinis(vidurkis_mediana, &tmp);
                    tmp.vektoriukas.clear(); Studentas.push_back(tmp);
                }
                std::sort(Studentas.begin(), Studentas.end(), rikiuojam);
        }

    if (skaitom_ivedam == 'i')
    {
        do
        {   Studentas1 temp;
            /// ivedamas vartotojaus vardas
            std::cout << kelintas + 1 << "-studentas-----------------------------------------------" << std::endl;
            std::cout << "Vardas, pavarde: "; std::cin >> temp.vardas >> temp.pavarde;
            std::cout<<std::endl;

              if(generuojam == 'n')
                {
                    /// vartotojas iveda namu darbu balus, kurie saugomi vektoriuje
                        std::cout << "Po kiekvieno ivesto balo pasapuskite Enter, norint uzbaigti balu ivedinejima - iveskite 0:"<<std::endl;
                        std::cout << "Namu darbai:"<<std::endl;

                     for(int g=0; g<jei_nulis_baigiam; g++)
                        {
                            std::cin >> nd; ar_tinkamas_skaiciukas(nd, 0, 10);
                            if (nd == 0) jei_nulis_baigiam = 0;
                            else temp.vektoriukas.push_back(nd); temp.n++;
                             jei_nulis_baigiam++;
                        }
                       /// vartotojas iveda egzamino bala
                       std::cout<<std::endl;
                       std::cout << "Egzamino balas: "; std::cin >> temp.egz;
                       ar_tinkamas_skaiciukas(temp.egz, 1, 10); std::cout<<std::endl;
                }
                    /// vartotojas pasirinkimas generuoti namu darbu ir egzamino balus
                    else if (generuojam == 'g') pazymiu_generavimas(vektorius_masyvas, &temp);
            Studentas.push_back(temp); kelintas++; studentu_kiek--;
        } while (pabaiga!=studentu_kiek);

        for (int i = 0; i < Studentas.size(); i ++)
           Studentas[i].galutinis=galutinis(vidurkis_mediana, &Studentas[i]);
 }
    std::cout<<std::endl; std::cout<<std::endl;
    std::cout << "Vardas\t\tPavarde\t\t";
    if(vidurkis_mediana == 'm') std::cout << "Galutinis (Med.)" << std::endl;
      else  std::cout << "Galutinis (Vid.)" << std::endl;
    std::cout << "-------------------------------------------------------------------" << std::endl;
            for (int i = 0; i < Studentas.size(); i++)
            {
                if (skaitom_ivedam=='s')
                std::cout << Studentas[i].vardas << " \t" << Studentas[i].pavarde << " \t" << std::fixed << std::setprecision(2) <<
                Studentas[i].galutinis << " \t " << std::endl;
                else
                std::cout << Studentas[i].vardas << "\t\t" << Studentas[i].pavarde << "\t\t"
                << std::fixed << std::setprecision(2) <<  Studentas[i].galutinis << std::endl;;
            }
    return 0;
}
