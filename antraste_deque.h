#ifndef ANTRASTE_DEQUE_H_INCLUDED
#define ANTRASTE_DEQUE_H_INCLUDED

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
#include <deque> 
#include <algorithm>
#include <sstream>

const int daugiausia2 = 50;

struct Studentas3
{
    std::string vardas, pavarde;
    int egz; int n = 0;
    double galutinis;
    std::deque<int> vektoriukas;
};

void konteinerisD (char& simbolis, char pirmas, char antras, char trecias);
void ar_tas_simboliukas (char& simbolis, char pirmas, char antras);
void ar_tinkamas_skaiciukas (int& skaicius, int pradzia, int pabaiga);
double rastimedianaD (std::deque<int> vekt);
double vidurkisD (int* nd, int n);
double galutinisD (char kas_cia1, Studentas3* Studentas);
double galutinis_skaitantD (char kas_cia1, Studentas3* Studentas, std::deque<int> vektoriukas);
void pazymiu_generavimasD (char kas_cia, Studentas3* Studentas);
bool rikiuojamD (Studentas3 a, Studentas3  b);
void I_FAILA_pazymiu_generavimasD (Studentas3* Studentas, std::string pavadinimas, int kiek);
bool rikiuojam_pagal_balaD (Studentas3 a, Studentas3  b);
void kazkas_is_d_raides();

#endif // ANTRASTE_DEQUE_H_INCLUDED
