#include "antraste_vector.h"
#include "antraste.h"
#include "Timer.h"

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

/// rikiuojame i faila
void I_FAILA_pazymiu_generavimas (Studentas1* Studentas, std::string pavadinimas, int kiek)
{
    int galas=0; int kiek1; int ST;  int galas_st=0; int nezinau_kas_vyksta=0;
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

void vektorius()
{
    std::vector<Studentas1> Studentas; std::string kas_vyksta; Studentas1 laikinas;
    char vidurkis_mediana, generuojam, vektorius_masyvas, skaitom_ivedam, i_faila_ar_ne, rusiuojame;
    int kelintas = 0, nd, jei_nulis_baigiam=1, studentu_kiek, pabaiga=0; std::string failas, pavadinimas; int daug_nuliu, kiek;
    std::vector<int> vektoriukas;  Studentas.reserve(10000000);

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
    ar_tinkamas_skaiciukas (kiek, 1, daugiausia);

         I_FAILA_pazymiu_generavimas (&laikinas, "1000.txt", kiek);  failas="1000.txt";
          I_FAILA_pazymiu_generavimas (&laikinas, "10000.txt", kiek);  failas="10000.txt";
           I_FAILA_pazymiu_generavimas (&laikinas, "100000.txt", kiek);  failas="100000.txt";
            I_FAILA_pazymiu_generavimas (&laikinas, "1000000.txt", kiek);  failas="1000000.txt";
             I_FAILA_pazymiu_generavimas (&laikinas, "10000000.txt", kiek);  failas="10000000.txt";
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
            ar_tinkamas_skaiciukas(studentu_kiek, 1, daugiausia);
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
                int i = 0; Studentas1 tmp, tmp2;

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
                    tmp.galutinis=galutinis_skaitant(vidurkis_mediana, &tmp, vektoriukas);
                    vektoriukas.clear(); Studentas.push_back(tmp);
                }
            std::cout << "Skaitymas is failo uztruko ->  " ;
            std::cout << t.elapsed() <<std::endl;
        }

    if (skaitom_ivedam == 'i')
    {
        do
        {   Studentas1 temp; std::cout<<std::endl;
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
                    else if (generuojam == 'g') pazymiu_generavimas(vektorius_masyvas, &temp);
            Studentas.push_back(temp); kelintas++; studentu_kiek--;
        } while (pabaiga!=studentu_kiek);
     
        for (int i = 0; i < Studentas.size(); i ++)
            Studentas[i].galutinis=galutinis(vidurkis_mediana, &Studentas[i]);    
 }
 
 int dydis=Studentas.size();
{
                std::vector <Studentas1> nevykeliai2;
                std::vector <Studentas1> vykeliai2;
                std::ofstream vykeliai ("vykeliai.txt");
                std::ofstream nevykeliai ("nevykeliai.txt");
                int opa=dydis;
                if(i_faila_ar_ne=='t') opa=dydis-1;
                nevykeliai2.reserve(opa); vykeliai2.reserve(opa);
                int kiek1 = 0;  int kiek2 = 0; Timer t, p; 

            {
                for (int i = 0; i < opa; i++)
                {
                    if ( Studentas[i].galutinis<5.0)
                    {
                           nevykeliai2.push_back(Studentas[i]);  kiek1++;     
                    }

                      else if ( Studentas[i].galutinis>=5.0)
                        {
                            vykeliai2.push_back(Studentas[i]);  kiek2++;
                        }
                }       std::cout << "Studentu rusiavimas i dvi grupes uztruko ->  " ;
                        std::cout << t.elapsed() <<std::endl;

            }

                  if(rusiuojame == 'b')
                  {
                       std::sort(vykeliai2.begin(), vykeliai2.end(), rikiuojam_pagal_bala);
                       std::sort(nevykeliai2.begin(), nevykeliai2.end(), rikiuojam_pagal_bala);
                  }

                   else
                   {
                       std::sort(vykeliai2.begin(), vykeliai2.end(), rikiuojam);
                       std::sort(nevykeliai2.begin(), nevykeliai2.end(), rikiuojam);
                   }

                   
                    if (kiek2!=0)
                    {
                        vykeliai << "Vardas \t\tPavarde \t";
                        if(vidurkis_mediana == 'm') vykeliai << "Galutinis (Med.)" << std::endl;
                        else  vykeliai << "Galutinis (Vid.)" << std::endl;
                        vykeliai << "-------------------------------------------------------------------" << std::endl;
                    }
                        
                    if (kiek1!=0)
                    {
                        nevykeliai << "Vardas \t\tPavarde \t";
                        if(vidurkis_mediana == 'm') nevykeliai << "Galutinis (Med.)" << std::endl;
                        else  nevykeliai << "Galutinis (Vid.)" << std::endl;
                        nevykeliai << "-------------------------------------------------------------------" << std::endl;
                    }

                if(i_faila_ar_ne=='n' && skaitom_ivedam=='i')
                {
                    for(int j=0; j<kiek2; j++)
                        vykeliai << vykeliai2[j].vardas << " \t\t" << vykeliai2[j].pavarde << " \t\t" << std::fixed << std::setprecision(2) <<
                        vykeliai2[j].galutinis << std::endl;

                    for (int k = 0; k<kiek1; k++)
                         nevykeliai << nevykeliai2[k].vardas << " \t\t" << nevykeliai2[k].pavarde << " \t\t" << std::fixed << std::setprecision(2) <<
                         nevykeliai2[k].galutinis << std::endl;

                }

                else if(i_faila_ar_ne=='n' && skaitom_ivedam=='s')
                {
                    for(int j=0; j<kiek2; j++)
                        vykeliai << vykeliai2[j].vardas << " \t" << vykeliai2[j].pavarde << " \t" << std::fixed << std::setprecision(2) <<
                        vykeliai2[j].galutinis << std::endl;

                    for (int k = 0; k<kiek1; k++)
                         nevykeliai << nevykeliai2[k].vardas << " \t" << nevykeliai2[k].pavarde << " \t" << std::fixed << std::setprecision(2) <<
                         nevykeliai2[k].galutinis << std::endl;
                }

                else if (i_faila_ar_ne=='t')
                {
                    for(int j=0; j<kiek2; j++)
                        vykeliai << vykeliai2[j].vardas << " \t" << vykeliai2[j].pavarde << "\t" << std::fixed << std::setprecision(2) <<
                        vykeliai2[j].galutinis << std::endl;

                    for (int k = 0; k<kiek1; k++)
                         nevykeliai << nevykeliai2[k].vardas << " \t" << nevykeliai2[k].pavarde << "\t" << std::fixed << std::setprecision(2) <<
                         nevykeliai2[k].galutinis << std::endl;
                }
}
std::cout <<std::endl;
std::cout << "Programos pabaiga" <<std::endl;
std::cout <<std::endl;
}