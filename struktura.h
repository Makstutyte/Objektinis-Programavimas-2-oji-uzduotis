#ifndef STRUKTURA_H_INCLUDED
#define STRUKTURA_H_INCLUDED

/// struktura sauganti duomenis apie studenta ir jo pazymius
struct Studentas1
{
    std::string vardas, pavarde;
    int egz; int n = 0;
    double galutinis;
    std::vector<int> vektoriukas;
};

#endif // STRUKTURA_H_INCLUDED
