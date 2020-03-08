#ifndef ANTRASTE_H_INCLUDED
#define ANTRASTE_H_INCLUDED

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

const int daugiausia = 50;

struct Studentas1;

void ar_tas_simboliukas (char& simbolis, char pirmas, char antras);
void ar_tinkamas_skaiciukas (int& skaicius, int pradzia, int pabaiga);
void ar_tas_pavadinimas (std::string& failas, std::string pirmas, std::string antras, std::string trecias, std::string ketvirtas, std::string penktas);
double rastimediana (std::vector<int> vekt);
double vidurkis (int* nd, int n);
double galutinis (char kas_cia1, Studentas1* Studentas);
double galutinis_skaitant (char kas_cia1, Studentas1* Studentas, std::vector<int> vektoriukas);
void pazymiu_generavimas (char kas_cia, Studentas1* Studentas);
bool rikiuojam(Studentas1 a, Studentas1  b);
void I_FAILA_pazymiu_generavimas (Studentas1* Studentas, std::string pavadinimas, int kiek);
bool rikiuojam_pagal_bala(Studentas1 a, Studentas1  b);

#endif // ANTRASTE_H_INCLUDED

