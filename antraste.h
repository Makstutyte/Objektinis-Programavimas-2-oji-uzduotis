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
double rastimediana (std::vector<int> vekt);
double vidurkis (int* nd, int n);
double galutinis (char kas_cia1, Studentas1* Studentas);
void pazymiu_generavimas (char kas_cia, Studentas1* Studentas);
bool rikiuojam(Studentas1 a, Studentas1  b);


#endif // ANTRASTE_H_INCLUDED
