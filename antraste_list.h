#ifndef ANTRASTE_LIST_H_INCLUDED
#define ANTRASTE_LIST_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <vector>
#include <numeric>
#include <limits>
#include <fstream>
#include <random>
#include <chrono>
#include <list>
#include <algorithm>
#include <sstream>
#include <iterator> 

const int daugiausia1 = 50;


/// struktura sauganti duomenis apie studenta ir jo pazymius
struct Studentas2
{
    std::string vardas, pavarde;
    int egz; int n = 0;
    double galutinis;
    std::list<int> vektoriukas;
};

void konteinerisL (char& simbolis, char pirmas, char antras, char trecias);
void ar_tas_simboliukas (char& simbolis, char pirmas, char antras);
void ar_tinkamas_skaiciukas (int& skaicius, int pradzia, int pabaiga);
//double rastimediana (std::vector<int> vekt);
double rastimedianaL (std::list<int> vektoriukas);
double vidurkisL (std::list<int> vektoriukas, int n) ;
///double vidurkis (int* nd, int n);
double galutinisL (char kas_cia1, Studentas2* Studentas);
double galutinis_skaitantL (char kas_cia1, Studentas2* Studentas, std::list<int> vektoriukas);
void pazymiu_generavimasL (char vidurkis_mediana, Studentas2* Studentas);
bool rikiuojamL (Studentas2 a, Studentas2  b);
void I_FAILA_pazymiu_generavimasL (Studentas2* Studentas, std::string pavadinimas, int kiek);
bool rikiuojam_pagal_balaL (Studentas2 a, Studentas2  b);
void listas();

#endif // ANTRASTE_LIST_H_INCLUDED
