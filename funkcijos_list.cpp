#include "antraste_list.h"
#include "antraste.h"
#include "Timer.h"

double rastimedianaL (std::list<int> vektoriukas)
{    
    double m;
    vektoriukas.sort();                     
    int n=vektoriukas.size();
    auto it1 = vektoriukas.begin();         
    auto it2 = it1;
    std::advance(it1, n / 2 - 1);  
    std::advance(it2, n / 2);       

    n % 2 == 0 ? (m = 1.00 * (*it1 + *it2) / 2) : m = *it2; // Calculate median
    return m;
}

/// funkcija apskaiciuojanti masyvo elementu vidurki
double vidurkisL (std::list<int> vektoriukas, int n) 
{
    double sum = 0;
    auto it = vektoriukas.begin();
    for (auto it = vektoriukas.begin(); it != vektoriukas.end(); it ++)
        sum += *(it);
    return (sum / n);
}

double galutinisL (char kas_cia1, Studentas2* Studentas)
{
    double nd;
      if(kas_cia1 == 'm') nd = rastimedianaL (Studentas->vektoriukas);
           else nd = vidurkisL (Studentas->vektoriukas, Studentas->vektoriukas.size());
    return (0.4 * nd + 0.6 * Studentas->egz);
}

double galutinis_skaitantL (char kas_cia1, Studentas2* Studentas, std::list<int> vektoriukas )
{
    double nd; int n=vektoriukas.size();
      if(kas_cia1 == 'm') nd = rastimedianaL (vektoriukas);
           else nd = vidurkisL(vektoriukas, vektoriukas.size());
    return (0.4 * nd + 0.6 * Studentas->egz);
}

/// funkcija generuojanti namu darbu ir egzamino balus
void pazymiu_generavimasL (char vidurkis_mediana, Studentas2* Studentas)
{
    int galas=0; int kiek=1;
    std::cout << "Generuojamu pazymiu kiekis: "; std::cin >> kiek; std::cout<<std::endl;
    ar_tinkamas_skaiciukas(kiek, 1, daugiausia1);
    std::cout << "Namu darbu balai: " ; std::cout<<std::endl;

    using hrClock = std::chrono::high_resolution_clock;
    std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> dist(1, 10);

    std::list<int> nd;
           do
            {        nd.push_back(dist(mt));                      
                     std::cout << nd.back() << " " ;
                     Studentas->vektoriukas.push_back(nd.back());
                      kiek--;
            } while (galas != kiek);

    std::cout<<std::endl; Studentas->egz = dist(mt);
    std::cout << "Egzamino balas: " << Studentas->egz <<std::endl; std::cout<<std::endl;

}

bool rikiuojamL (Studentas2 a, Studentas2  b)
{
    return a.vardas < b.vardas;
}

/// rikiuojame i faila
void I_FAILA_pazymiu_generavimasL (Studentas2* Studentas, std::string pavadinimas, int kiek)
{
    int galas=0; int kiek1; int ST;  int galas_st=0; int nezinau_kas_vyksta=0;
    Timer t;

            if(pavadinimas=="1000.txt") ST=1000;
            if(pavadinimas=="10000.txt") ST=10000;
            if(pavadinimas=="100000.txt") ST=100000;
            if(pavadinimas=="1000000.txt") ST=1000000;
            if(pavadinimas=="10000000.txt") ST=10000000;

    std::ofstream i_faila(pavadinimas);
    using hrClock = std::chrono::high_resolution_clock;
    std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> dist(1, 10);
    int a=0; std::list<int> vektoriukas;

    std::ostringstream eilutis ("");    
    eilutis << std::setw(20) << std::left << "VARDAS" << std::setw(21) << "PAVARDE";
    for (int i = 1; i <= kiek; i ++)
        eilutis << "ND" << std::setw(8) << std::left << i;
    eilutis << "Egz.\n";
    i_faila << eilutis.str();
    for (int i = 0; i < ST; i ++) 
    {
        eilutis.str("");   
        eilutis << "Vardas" << std::setw(14) << std::left << i+1 << "Pavarde" << std::setw(14) << std::left << i+1;
        for (int j = 0; j < kiek; j ++)
        {
             vektoriukas.push_back(dist(mt));
             eilutis << std::setw(10) << std::left << vektoriukas.back();
        }
             Studentas->egz = dist(mt);
             eilutis << Studentas->egz;
        eilutis << "\n";
        i_faila << eilutis.str();
    }

            std::cout<<std::endl; std::cout << pavadinimas << "  failo kurimas uztruko ->  " ;
            std::cout << t.elapsed() <<std::endl;
}

bool rikiuojam_pagal_balaL(Studentas2 a, Studentas2  b)
{
    return a.galutinis < b.galutinis;
}

void listas()
{
    std::list<Studentas2> Studentas; std::string kas_vyksta; Studentas2 laikinas;
    char vidurkis_mediana, generuojam, vektorius_masyvas, skaitom_ivedam, i_faila_ar_ne, rusiuojame;
    int kelintas = 0, nd, jei_nulis_baigiam=1, studentu_kiek, pabaiga=0; std::string failas, pavadinimas; int daug_nuliu, kiek;
    std::list<int> vektoriukas; 

    /// vatrotojas pasirenka  kokiais budais apskaiciuoti galutini rezultata
    std::cout << "generuojamas failas (t) / ne (n)? --> "; std::cin >> i_faila_ar_ne;
    ar_tas_simboliukas(i_faila_ar_ne, 't', 'n');

    if (i_faila_ar_ne=='t')
    {
         std::cout << "vidurkis (v) / mediana (m)? --> "; std::cin >> vidurkis_mediana;
         ar_tas_simboliukas(vidurkis_mediana, 'm', 'v');
        std::cout << "rikiavimas pagal varda (v) / bala (b)? --> "; std::cin >> rusiuojame;
        ar_tas_simboliukas(rusiuojame, 'v', 'b');
         
    std::cout << "Generuojamu pazymiu kiekis: "; std::cin >> kiek; std::cout<<std::endl;
    ar_tinkamas_skaiciukas (kiek, 1, daugiausia1);

         I_FAILA_pazymiu_generavimasL (&laikinas, "1000.txt", kiek);  failas="1000.txt";
          I_FAILA_pazymiu_generavimasL (&laikinas, "10000.txt", kiek);  failas="10000.txt";
           I_FAILA_pazymiu_generavimasL (&laikinas, "100000.txt", kiek);  failas="100000.txt";
            I_FAILA_pazymiu_generavimasL (&laikinas, "1000000.txt", kiek);  failas="1000000.txt";
             I_FAILA_pazymiu_generavimasL (&laikinas, "10000000.txt", kiek);  failas="10000000.txt";
             std::cout <<std::endl;

          std::cout << "tolimesni veiksmai atleikami su: "<<std::endl;
          std::cout << "1000.txt (1), 10000.txt (2), 100000.txt (3), 1000000.txt (4), 10000000.txt (5) arba kursiokai.txt (6) --> "; std::cin >> daug_nuliu;
          std::cout<<std::endl; ar_tinkamas_skaiciukas(daug_nuliu, 1, 6);
          if(daug_nuliu==1) failas="1000.txt";
          if(daug_nuliu==2) failas="10000.txt";
          if(daug_nuliu==3) failas="100000.txt";
          if(daug_nuliu==4) failas="1000000.txt";
          if(daug_nuliu==5) failas="10000000.txt";
          if(daug_nuliu==6) failas="kursiokai.txt";    
    }

    if (i_faila_ar_ne=='n')
    {
        std::cout << "skaitome (s) / ivedame ranka (i)?  --> "; std::cin >> skaitom_ivedam;
        ar_tas_simboliukas(skaitom_ivedam, 's', 'i');

        if(skaitom_ivedam=='s' )
        {
          std::cout<<std::endl;
          std::cout << "Pasirinkite faila, is kurio bus skaitomi duomenys "<<std::endl;
          std::cout << "1000.txt (1), 10000.txt (2), 100000.txt (3), 1000000.txt (4), 10000000.txt (5) arba kursiokai.txt (6) --> "; std::cin >> daug_nuliu;
          std::cout<<std::endl; ar_tinkamas_skaiciukas(daug_nuliu, 1, 6);
          if(daug_nuliu==1) failas="1000.txt";
          if(daug_nuliu==2) failas="10000.txt";
          if(daug_nuliu==3) failas="100000.txt";
          if(daug_nuliu==4) failas="1000000.txt";
          if(daug_nuliu==5) failas="10000000.txt";
          if(daug_nuliu==6) failas="kursiokai.txt";
        }
        std::cout << "vidurkis (v) / mediana (m)?  --> "; std::cin >> vidurkis_mediana;
        ar_tas_simboliukas(vidurkis_mediana, 'm', 'v');
        std::cout << "rikiavimas pagal varda (v) / bala (b)? --> "; std::cin >> rusiuojame;
        ar_tas_simboliukas(rusiuojame, 'v', 'b');
    }

    if (skaitom_ivedam == 'i')
    {
            std::cout << "balai generuojami (g) / negeneruojami (n)? --> "; std::cin >> generuojam;
            ar_tas_simboliukas(generuojam, 'g', 'n');
            std::cout << "Studentu skaicius: "; std::cin >> studentu_kiek;
            ar_tinkamas_skaiciukas(studentu_kiek, 1, daugiausia1);
    }
        else if (skaitom_ivedam == 's' || i_faila_ar_ne=='t')
        {
            int nd_kiekis_faile = 0; Timer t; 
            std::ifstream duom(failas.c_str());

                  try
                  {
                   std::string Exception = "SKAITYMO FAILAS NEEGZISTUOJA";
                     if (duom) { std::cout << "skaitymo failas egzistuoja " << std::endl;}
                            else if(!duom) { throw (Exception);}
                  }

                    catch (std::string isimtis)
                    {
                        std::cout << isimtis << std::endl;
                        return;
                    }

                     if (duom.good())
                    {
                        std::string str;  std::getline(duom, str);
                        std::istringstream s (str);  std::string str1;
                        while (s >> str1) {  nd_kiekis_faile++; }
                    }

                nd_kiekis_faile -= 3;
                int i = 0; Studentas2 tmp, tmp2;

              while(duom >> tmp.vardas)
                {
                    duom >> tmp.pavarde;
                    
                    for (int j = 0; j < nd_kiekis_faile; j++)
                    {
                            if (duom.fail())
                            {
                                duom.clear(); duom.ignore();
                            }
                        duom >> nd; vektoriukas.push_back(nd);
                    }
                    duom >> tmp.egz;
                    tmp.galutinis=galutinis_skaitantL(vidurkis_mediana, &tmp, vektoriukas);
                    vektoriukas.clear(); Studentas.push_back(tmp);
                }
            std::cout << "Skaitymas is failo uztruko ->  " ;
            std::cout << t.elapsed() <<std::endl;
        }

    if (skaitom_ivedam == 'i')
    {
        do
        {   Studentas2 temp; std::cout<<std::endl;
            /// ivedamas vartotojaus vardas
            std::cout << kelintas + 1 << "-studentas-----------------------------------------------" << std::endl;
            std::cout << "Vardas, pavarde: "; std::cin >> temp.vardas >> temp.pavarde; std::cout<<std::endl;

              if(generuojam == 'n')
                {
                    /// vartotojas iveda namu darbu balus, kurie saugomi vektoriuje
                        std::cout << "Po kiekvieno ivesto balo pasapuskite Enter, norint uzbaigti balu ivedinejima - iveskite 0:"<<std::endl;
                        std::cout << "Namu darbai:"<<std::endl;

                     for(int g=0; g<jei_nulis_baigiam; g++)
                        {
                            std::cin >> nd; ar_tinkamas_skaiciukas(nd, 0, 10);
                            if (nd == 0) jei_nulis_baigiam = 0;
                            else temp.vektoriukas.push_back(nd); ///temp.n++;
                             jei_nulis_baigiam++;
                        }
                       /// vartotojas iveda egzamino bala
                       std::cout<<std::endl;
                       std::cout << "Egzamino balas: "; std::cin >> temp.egz;
                       ar_tinkamas_skaiciukas(temp.egz, 1, 10); std::cout<<std::endl;
                }
                    /// vartotojas pasirinkimas generuoti namu darbu ir egzamino balus
                    else if (generuojam == 'g') pazymiu_generavimasL(vektorius_masyvas, &temp);
            Studentas.push_back(temp); kelintas++; studentu_kiek--;
        } while (pabaiga!=studentu_kiek);

         for (auto itr = Studentas.begin(); itr != Studentas.end(); itr++) 
            itr->galutinis=galutinisL(vidurkis_mediana, &*itr);    
      
 }
 
 int dydis=Studentas.size();
{
                std::list <Studentas2> nevykeliai2;
                std::list <Studentas2> vykeliai2;
                std::ofstream vykeliai ("vykeliai.txt");
                std::ofstream nevykeliai ("nevykeliai.txt");
                int opa=dydis;
                if(i_faila_ar_ne=='t') opa=dydis-1;
                int kiek1 = 0;  int kiek2 = 0;
                int strategija;

            std::cout << "1 strategija / 2 strategija ? --> "; std::cin >> strategija;
            ar_tinkamas_skaiciukas(strategija, 1, 2);


            if(strategija==1)
            { Timer t;
                    for (auto itr = Studentas.begin(); itr != Studentas.end(); itr++)
                {
                    if ( itr->galutinis<5.0)
                    {
                           nevykeliai2.push_back(*itr);  kiek1++;     
                    }

                      else if ( itr->galutinis>=5.0)
                        {
                            vykeliai2.push_back(*itr);  kiek2++;
                        }
                }     
                        std::cout << "Studentu rusiavimas i dvi grupes uztruko ->  " ;
                        std::cout << t.elapsed() <<std::endl;
            }

 else if(strategija==2)
{ Timer o;
     int ne = 0;
    /// Studentas.sort(rikiuojam_pagal_balaL);
     Studentas.sort([](Studentas2 &a, Studentas2 &b) 
     {
         return a.galutinis < b.galutinis;
     });

    auto i = Studentas.begin();
    while (i->galutinis < 5.0 && i != Studentas.end()) 
    {
            ne ++;
            i ++;
    }
    vykeliai2.assign(i, Studentas.end());  Studentas.clear();
    Studentas.resize(ne);  
    kiek2=ne;
    std::cout << "Studentu rusiavimas i dvi grupes uztruko ->  " ;
    std::cout << o.elapsed() <<std::endl;
}
                  if(rusiuojame == 'b')
                  {
                      if (strategija==1)
                      {
                        vykeliai2.sort(rikiuojam_pagal_balaL);
                        nevykeliai2.sort(rikiuojam_pagal_balaL);
                      }
                       
                       else if (strategija==2)
                       {
                           vykeliai2.sort(rikiuojam_pagal_balaL);
                           Studentas.sort(rikiuojam_pagal_balaL);
                       }
                  }

                   else
                   {
                        if (strategija==1)
                        {
                             vykeliai2.sort(rikiuojamL);
                             nevykeliai2.sort(rikiuojamL);
                        }
                       
                        else if (strategija==2)
                        {
                             vykeliai2.sort(rikiuojamL);
                             Studentas.sort(rikiuojamL);
                        }
                   }

                        vykeliai << "Vardas \t\tPavarde \t";
                        if(vidurkis_mediana == 'm') vykeliai << "Galutinis (Med.)" << std::endl;
                        else  vykeliai << "Galutinis (Vid.)" << std::endl;
                        vykeliai << "-------------------------------------------------------------------" << std::endl;
                        
                        nevykeliai << "Vardas \t\tPavarde \t";
                        if(vidurkis_mediana == 'm') nevykeliai << "Galutinis (Med.)" << std::endl;
                        else  nevykeliai << "Galutinis (Vid.)" << std::endl;
                        nevykeliai << "-------------------------------------------------------------------" << std::endl;

                if(i_faila_ar_ne=='n' && skaitom_ivedam=='i')
                {
                     if (strategija==1)
                     {
                        auto it = vykeliai2.begin();
                        for (auto it = vykeliai2.begin(); it != vykeliai2.end(); ++it) 
                            vykeliai << it->vardas << " \t\t" << it->pavarde << " \t\t" << std::fixed << std::setprecision(2) <<
                            it->galutinis << std::endl;
    
                        auto iti = nevykeliai2.begin();
                        for (auto iti = nevykeliai2.begin(); iti != nevykeliai2.end(); ++iti) 
                            nevykeliai << iti->vardas << " \t\t" << iti->pavarde << " \t\t" << std::fixed << std::setprecision(2) <<
                            iti->galutinis << std::endl;
                     }

                    else if (strategija==2)
                    {
    
                        auto it = vykeliai2.begin();
                        for (auto it = vykeliai2.begin(); it != vykeliai2.end(); ++it) 
                            vykeliai << it->vardas << " \t\t" << it->pavarde << " \t\t" << std::fixed << std::setprecision(2) <<
                            it->galutinis << std::endl;


                        auto iti = Studentas.begin();
                        for (auto iti = Studentas.begin(); iti != Studentas.end(); ++iti) 
                            nevykeliai << iti->vardas << " \t\t" << iti->pavarde << " \t\t" << std::fixed << std::setprecision(2) <<
                            iti->galutinis << std::endl;
                         
                    }
                }

                else if(i_faila_ar_ne=='n' && skaitom_ivedam=='s')
                {
                     if (strategija==1)
                     {
                        auto it = vykeliai2.begin();
                        for (auto it = vykeliai2.begin(); it != vykeliai2.end(); ++it) 
                            vykeliai << it->vardas << " \t" << it->pavarde << " \t" << std::fixed << std::setprecision(2) <<
                            it->galutinis << std::endl;
    
                        auto iti = nevykeliai2.begin();
                        for (auto iti = nevykeliai2.begin(); iti != nevykeliai2.end(); ++iti) 
                            nevykeliai << iti->vardas << " \t" << iti->pavarde << " \t" << std::fixed << std::setprecision(2) <<
                            iti->galutinis << std::endl;
                     }

                    else if (strategija==2)
                    {
    
                        auto it = vykeliai2.begin();
                        for (auto it = vykeliai2.begin(); it != vykeliai2.end(); ++it) 
                            vykeliai << it->vardas << " \t" << it->pavarde << " \t" << std::fixed << std::setprecision(2) <<
                            it->galutinis << std::endl;


                        auto iti = Studentas.begin();
                        for (auto iti = Studentas.begin(); iti != Studentas.end(); ++iti) 
                            nevykeliai << iti->vardas << " \t" << iti->pavarde << " \t" << std::fixed << std::setprecision(2) <<
                            iti->galutinis << std::endl;
                    }
                }

                else if (i_faila_ar_ne=='t')
                {
                    if (strategija==1)
                     {
                        auto it = vykeliai2.begin();
                        for (auto it = vykeliai2.begin(); it != vykeliai2.end(); ++it) 
                            vykeliai << it->vardas << " \t" << it->pavarde << " \t" << std::fixed << std::setprecision(2) <<
                            it->galutinis << std::endl;
    
                        auto iti = nevykeliai2.begin();
                        for (auto iti = nevykeliai2.begin(); iti != nevykeliai2.end(); ++iti) 
                            nevykeliai << iti->vardas << " \t" << iti->pavarde << " \t" << std::fixed << std::setprecision(2) <<
                            iti->galutinis << std::endl;
                     }

                    else if (strategija==2)
                    {
    
                        auto it = vykeliai2.begin();
                        for (auto it = vykeliai2.begin(); it != vykeliai2.end(); ++it) 
                            vykeliai << it->vardas << " \t" << it->pavarde << " \t" << std::fixed << std::setprecision(2) <<
                            it->galutinis << std::endl;


                        auto iti = Studentas.begin();
                        for (auto iti = Studentas.begin(); iti != Studentas.end(); ++iti) 
                            nevykeliai << iti->vardas << " \t" << iti->pavarde << " \t" << std::fixed << std::setprecision(2) <<
                            iti->galutinis << std::endl;    
                    }    
                }
}
std::cout <<std::endl;
std::cout << "Programos pabaiga" <<std::endl;
std::cout <<std::endl;

}
