#include "antraste.h"
#include "struktura.h"
#include "Timer.h"

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

void ar_tas_pavadinimas (std::string& failas, std::string pirmas, std::string antras, std::string trecias, std::string ketvirtas, std::string penktas)
{
    while (!(failas == pirmas || failas == antras || failas == trecias || failas == ketvirtas || failas == penktas))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"Ivestas netinkamas pavadinimas" <<std::endl;
        std::cout << "Pasirinkite viena is variantu arba " << pirmas << ", arba " << antras << ", arba "  << trecias <<
        ", arba " << ketvirtas << ", arba " << penktas  << ": ";
        std::cin >> failas;
    }
}

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

double galutinis_skaitant (char kas_cia1, Studentas1* Studentas, std::vector<int> vektoriukas )
{
    double nd; int n=vektoriukas.size();
      if(kas_cia1 == 'm') nd = rastimediana (vektoriukas);
           else nd = vidurkis(&vektoriukas[0], n );
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

void I_FAILA_pazymiu_generavimas (Studentas1* Studentas, std::string pavadinimas, int kiek)
{
    int galas=0; int kiek1; int ST; int did=INT_MAX; int galas_st=0; int nezinau_kas_vyksta=0;
    Timer t;

            if(pavadinimas=="1000.txt") ST=1000;
            if(pavadinimas=="10000.txt") ST=10000;
            if(pavadinimas=="100000.txt") ST=100000;
            if(pavadinimas=="1000000.txt") ST=1000000;
            if(pavadinimas=="10000000.txt") ST=10000000;

    std::ofstream i_faila(pavadinimas);

    i_faila << "VARDAS \t\t" << "PAVARDE \t";
    for (int i=0; i<kiek; i++)
         i_faila<< "ND" << i+1 << "\t";
    i_faila << "Egz." << std::endl;

    using hrClock = std::chrono::high_resolution_clock;
    std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> dist(1, 10);
int a=0; std::vector<int> vektoriukas;

          for (int h=0; h<ST; h++)
          {
                   i_faila << "Vardas" << h+1 << " \t" << "Pavarde" << h+1 << " \t";
                        for (int k=0; k<kiek; k++)
                           {
                               vektoriukas.push_back(dist(mt));
                                i_faila  << vektoriukas[a]<<"\t" ;
                                a ++;
                           }
                Studentas->egz = dist(mt);
                i_faila << Studentas->egz <<std::endl;
          }

            std::cout<<std::endl; std::cout << pavadinimas << "  failo kurimas uztruko ->  " ;
            std::cout << t.elapsed() <<std::endl;
}

bool rikiuojam_pagal_bala(Studentas1 a, Studentas1  b)
{
    return a.galutinis < b.galutinis;
}
