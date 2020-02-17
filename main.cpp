#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <vector>
#include <numeric>
#include <cstdlib>
#include <bits/stdc++.h>
#include <limits>
#define daugiausia 50
/// struktura sauganti duomenis apie studenta ir jo pazymius
struct Studentas1
{
    std::string vardas, pavarde;
    int egz; int n = 0;
    double galutinis;
    int C[daugiausia];
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
/// funkcija apskaiciuojanti mesyvo elementu mediana
double mediana_masyvui(int a[], int n)
{
    std::sort(a, a+n);
    if (n % 2 != 0)
       return (double)a[n/2];
    return (double)(a[(n-1)/2] + a[n/2])/2.0;
}
/// funkcija apskaiciuojanti masyvo elementu vidurki
double vidurkis (int n, double is_main, int nd[], char kas_cia)
{
    double suma = 0;
        if(kas_cia=='a') suma=is_main;
        else if (kas_cia=='b')
        {
             for (int i = 0; i < n; i ++)
                suma += nd[i];
        }
        return (suma / n);
}
/// funkcija apsakiciuojanti galutini rezultata pagal vartotojo pasirinktus skaiciavimo metodus
void galutinis (char kas_cia1, char kas_cia2, Studentas1* Studentas, int kelintas, double is_main, double mediana)
{
    double nd;
    if(kas_cia2=='b')
    {
       if(kas_cia1 == 'm' ) nd = mediana_masyvui(Studentas[kelintas].C, Studentas[kelintas].n);
            else nd = vidurkis(Studentas[kelintas].n, is_main, Studentas[kelintas].C, kas_cia2);
    }
     else if(kas_cia2=='a')
    {
      if(kas_cia1 == 'm') nd = (double)mediana;
           else nd = vidurkis(Studentas[kelintas].n, is_main, Studentas[kelintas].C, kas_cia2); ///S[i].C NEREIKE CIA
    }
    Studentas[kelintas].galutinis = (0.4 * nd + 0.6 * Studentas[kelintas].egz);
}
/// funkcija generuojanti namu darbu ir egzamino balus
void pazymiu_generavimas (char kas_cia, Studentas1* Studentas, int kelintas, double& suma, double& mediana)
{
    srand(time(NULL));
    int galas=0; int kiek=1; suma=0;
    std::cout << "Generuojamu pazymiu kiekis: "; std::cin >> kiek;
    ar_tinkamas_skaiciukas (kiek, 1, daugiausia);
    std::cout << "Namu darbu balai: " ;

 /// sugeneruotos reiksmes saugomos masyve
 if(kas_cia=='b')
 {
    do
    {   Studentas[kelintas].C[Studentas[kelintas].n] = 1+(double)rand ()/ RAND_MAX * 10;
        std::cout  << Studentas[kelintas].C[Studentas[kelintas].n]<<" " ;
        Studentas[kelintas].n ++; kiek--;
    } while (galas != kiek);
 }
      /// sugeneruotos reiksmes saugomos vektoriuje
      else if (kas_cia=='a')
        {
            do
            {       Studentas[kelintas].vektoriukas.push_back(1+(double)rand ()/ RAND_MAX * 10);
                    std::cout  << Studentas[kelintas].vektoriukas[Studentas[kelintas].n]<<" " ;
                    /// apskaiciuojama sugeneruoto vektoriaus elementu suma
                    suma=std::accumulate(Studentas[kelintas].vektoriukas.begin(), Studentas[kelintas].vektoriukas.end(), 0);
                    Studentas[kelintas].n ++; kiek--;
            } while (galas != kiek);
                 /// apskaiciuojama sugeneruoto vektoriaus elementu mediana
                 std::sort(Studentas[kelintas].vektoriukas.begin(), Studentas[kelintas].vektoriukas.end());
                 if (Studentas[kelintas].n % 2 != 0)
                 mediana = (double)(Studentas[kelintas].vektoriukas[Studentas[kelintas].n/2])*1.0;
                 else mediana= (double)(Studentas[kelintas].vektoriukas[(Studentas[kelintas].n-1)/2] + Studentas[kelintas].vektoriukas[Studentas[kelintas].n/2])/2.0;
        }
    std::cout<<std::endl;
    Studentas[kelintas].egz = 1+(double)rand ()/ RAND_MAX * 10;
    std::cout << "Egzamino balas: " << Studentas[kelintas].egz <<std::endl;;
}

int main ()
{
    srand(time(NULL));
    Studentas1 *Studentas = new Studentas1[daugiausia];
    char vidurkis_mediana, generuojam, vektorius_masyvas;
    int kelintas = 0, nd;
    int jei_nulis_baigiam=1; int sk=1;
    int nda; double suma=0; double mediana; int studentu_kiek, pabaiga=0;

    /// vatrotojas pasirenka kiek studentu ir kokiais budais apskaiciuoti galutini rezultata
    std::cout << "Studentu skaicius: "; std::cin >> studentu_kiek;
    ar_tinkamas_skaiciukas(studentu_kiek, 1, daugiausia);

    std::cout << "vektorius (a) ar masyvas (b)? iveskite 'a' arba 'b' --> "; std::cin >> vektorius_masyvas;
    ar_tas_simboliukas(vektorius_masyvas, 'a', 'b');

    std::cout << "generuojam (g) ar negeneruojam (n)? iveskite 'g' arba 'n' --> "; std::cin >> generuojam;
    ar_tas_simboliukas(generuojam, 'g', 'n');

    std::cout << "vidurkis (v) ar mediana (m)? iveskite 'v' arba 'm' --> "; std::cin >> vidurkis_mediana;
    ar_tas_simboliukas(vidurkis_mediana, 'm', 'v');
    std::cout<<std::endl;

    do
    {   /// ivedamas vartotojaus vardas
        std::cout << kelintas + 1 << "-studentas-----------------------------------------------" << std::endl;
        std::cout << "Vardas, pavarde: "; std::cin >> Studentas[kelintas].vardas >> Studentas[kelintas].pavarde;
        std::cout<<std::endl;

          if(generuojam == 'n')
            {
                /// vartotojas iveda namu darbu balus, kurie saugomi masyve
                if(vektorius_masyvas=='b')
                {
                    std::cout << "Po kiekvieno ivesto balo pasapuskite Enter, norint uzbaigti balu ivedinejima - iveskite 0:"<<std::endl;
                    std::cout << "Namu darbai:"<<std::endl;

                    for(int g=0; g<jei_nulis_baigiam; g++)
                    {
                        std::cin >> nd; ar_tinkamas_skaiciukas(nd, 0, 10);
                        if (nd == 0) jei_nulis_baigiam = 0;
                        else
                        {
                           Studentas[kelintas].C[Studentas[kelintas].n] = nd; Studentas[kelintas].n++;
                        }
                        jei_nulis_baigiam++;
                    }
                }

                /// vartotojas iveda namu darbu balus, kurie saugomi vektoriuje
                else if (vektorius_masyvas=='a')
                {
                    std::cout << "Po kiekvieno ivesto balo pasapuskite Enter, norint uzbaigti balu ivedinejima - iveskite 0:"<<std::endl;
                    std::cout << "Namu darbai:"<<std::endl;

                 for(int g=0; g<jei_nulis_baigiam; g++)
                    {
                        std::cin >> nd;
                        ar_tinkamas_skaiciukas(nd, 0, 10);
                        if (nd == 0)
                            jei_nulis_baigiam = 0;
                        else
                        {
                           Studentas[kelintas].vektoriukas.push_back(nd); Studentas[kelintas].n++;
                        }
                        suma=accumulate(Studentas[kelintas].vektoriukas.begin(),Studentas[kelintas].vektoriukas.end(),0);
                         jei_nulis_baigiam++;
                    }
                }
                   /// vartotojas iveda egzamino bala
                   std::cout<<std::endl;
                   std::cout << "Egzamino balas: "; std::cin >> Studentas[kelintas].egz;
                   ar_tinkamas_skaiciukas(Studentas[kelintas].egz, 1, 10);
                   std::cout<<std::endl;
            }
                /// vartotojas pasirinkimas generuoti namu darbu ir egzamino balus
                else if (generuojam == 'g')
                {
                    pazymiu_generavimas(vektorius_masyvas, Studentas, kelintas, suma, mediana);
                }

        kelintas++; studentu_kiek--;
    } while (pabaiga!=studentu_kiek);

    std::cout<<std::endl; std::cout<<std::endl;
    std::cout << "Vardas\t\tPavarde\t\t";
    if(vidurkis_mediana == 'm') std::cout << "Galutinis (Med.)" << std::endl;
      else  std::cout << "Galutinis (Vid.)" << std::endl;

    std::cout << "--------------------------------------------------------------" << std::endl;

    for (int i = 0; i < kelintas; i ++)
    {
        galutinis(vidurkis_mediana, vektorius_masyvas, Studentas, i, suma, mediana);
        std::cout << Studentas[i].vardas << "\t\t" << Studentas[i].pavarde << "\t\t" << std::fixed << std::setprecision(2) << Studentas[i].galutinis << std::endl;;
    }

    delete[] Studentas;
    return 0;
}
