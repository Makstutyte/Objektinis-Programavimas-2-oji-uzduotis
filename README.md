# Objektinis-Programavimas-2-oji-uzduotis

Programa, nuskaitanti vartotojo įvedamus, generuojamus (atskirus duomenis arba failus) arba iš failo perskaitomus duomenis ir pateikianti apskaičiuotus rezultatus
 
 ## Įdiegimo instrukcija 
Norint paleisti programos kodą reikia:
1. Atsisiųsti bet kurį iš pateiktų programos kodų 
   <br />[releases](https://github.com/Makstutyte/Objektinis-Programavimas-2-oji-uzduotis/releases) 
2. Įsidiegti C++ compiler 
   <br />[GCC](https://gcc.gnu.org/)
3. Naudojant komandinę eilutę paleisti programos kodą naudojant Makefile 
   * make
   * test
 
 
## Programos naudojimas ir apibendrintas veikimas 
Vartotojo veiksmų seka: 
1. Vartotojas pasirenka,  kokiame STL konteineryje (vector, list ar deque) bus saugomi duomenys
2. Vartotojas pasirenka ar bus generuojami nauji duomenų failai 
   *  sugeneravus failus vartotojas pasirenka, su kokiu failu bus toliau dirbama
   *  pasirinkus generavima vartotojas pasirenka kaip bus apskaičiuotas galutinis rezultatas (apskaičiuojant namų darbų balų vidurkį ar medianą)
   *  rezultatai bus rikiuojami pagal vardą ar galutinį balą
   *  išvedami duomenų failai bus suskirtomi naudojant 1-ąją ar 2-ąją strategiją
       *  pasirinkus STL konteinerį std::vector yra galimybė pasirinkti, jog išvedamų duomenų failai būtų sukuriami naudojant papildomus algoritmus
  
 #### Tuo atveju, jei pasirinkta, jog nebus genetuojami nauji duomenų failai
 
1. Vartotojas pasirenka ar duomenys bus įvedami ar skaitomi iš failo 
Pasirinkus duomenų įvedimą:

2. Vartotojas pasirenka, kokių būdu bus pateikiami namų darbų ir egzaminų rezultatai (atsitiktinai generuojant ar įvedant pačiam vartotojui) 
    * pasirinkus atsitiktinį generavimą, vartotojas nurodo, kiek balų bus sugeneruota
    * pasirinkus galimybę vartotojui pačiam įvesti namų darbų balus, įvedimo metu vartotojas nusprendžia kuomet jis jau įvedė visų namų           darbų rezultatus (įvedus nulį (0) yra sustabdomas balų įvedinėjimas)
3. Vartotojas pasirenka, kokių būdu bus apskaiciuojamas galutinis rezultatas (apskaičiuojant namų darbų balų vidurkį ar medianą)
4. Vartotojas pasirenka, kaip bus rikiuojami išvedami duomenys - pagal vardą ar galutinį balą
5. Vartotojas pasirenka, kelių mokinių duomenys bus naudojami programoje
6. Vartotojas įveda studentų vardus ir pavardes
7. Vartotojas pasirenka išvedami duomenų failai bus suskirtomi naudojant 1-ąją ar 2-ąją strategiją
   *  pasirinkus STL konteinerį std::vector yra galimybė pasirinkti, jog išvedamų duomenų failai būtų sukuriami naudojant papildomus algoritmus

Pasirinkus duomenų skaitymą:

2. Vartotojas pasirenka, iš kokio failo bus skaitomi duomenys (vienas iš pateiktų variantų)
3. Vartotojas pasirenka, kokių būdu bus apskaiciuojamas galutinis rezultatas (apskaičiuojant namų darbų balų vidurkį ar medianą)
4. Vartotojas pasirenka, kaip bus rikiuojami išvedami duomenys - pagal vardą ar galutinį balą
5. Vartotojas pasirenka išvedami duomenų failai bus suskirtomi naudojant 1-ąją ar 2-ąją strategiją
   *  pasirinkus STL konteinerį std::vector yra galimybė pasirinkti, jog išvedamų duomenų failai būtų sukuriami naudojant papildomus algoritmus


Po šios veiksmų sekos atspausdinami du .txt failai pagal galutinio balo rezultatą (jei galutinis balas >=5.0 duomenys išspausdinami į failą "vykeliai.txt", jei galutinis balas < 5.0  duomenys išspausdinami į failą "nevykeliai.txt"), nurodantys studentų vardus, pavardes ir galutinius rezultatus.


  Galutinio rezultato formulės:
  * Galutinis rezultatas = (namų darbų vidurkis) * 0.4 + (egzamino balas) * 0.6;
  * Galutinis rezultatas = (namų darbų mediana) * 0.4 + (egzamino balas) * 0.6;
  
  ## Programos versijos v0.4 veikimo spartos analizė

Išmatuotas laikas pateikiamas sekundėmis. Namų darbų kiekis sugeneruotuose failuose - 5.

| Duomenų kiekis  | Duomenų failo generavimas | Duomenų failo skaitymas  | Rezultatų rūšiavimas | Surūšiuotų duomenų išspausdinimas |
| ------------- | ------------- | ------------- | ------------- | ------------- |
| 1000  | 1.59454  | 0.018584  | 0.001812 | 0.060258  |
| 10000 | 2.2234 | 0.048893  | 0.008486 | 0.572778  |
| 100000 | 4.95502  | 1.08912  | 0.163851 | 14.5011 |
| 1000000  | 8.23857 | 5.56081 | 1.17097  |  148.988  |
| 10000000  | 74.0793 | 59.8561 | 141.068 | 321.963  |


## Programos versijos v0.5 veikimo spartos analizė

Įrangos parametrai:
| CPU | RAM | SSD |
| ------------- | ------------- | ------------- |
| Intel CORE i5 7th Gen 2.70 GHz | 8 GB  | 256 GB |

Išmatuotas laikas pateikiamas sekundėmis. Namų darbų kiekis sugeneruotuose failuose - 5.

Duomenų skaitymas: 
| Studentų duomenų kiekis |std::vector| std::list | std::deque |
| ------------- | ------------- | ------------- | ------------- |
| 1000  | 0.05164  | 0.013033 | 0.00715 |
| 10000  | 0.0825  | 0.088022 | 0.080193 |
| 100000 | 0.97028 | 0.79475 | 0.612528 |
| 1000000  | 8.14501 | 14.1512 | 9.16061 |
| 10000000 | 69.2747  | 124.473 | 93.1991 |

Duomenų rūšiavimas: 
| Studentų duomenų kiekis |std::vector| std::list | std::deque |
| ------------- | ------------- | ------------- | ------------- |
| 1000  | 0.001287  |  0.00107  | 0.002456 |
| 10000  | 0.004886 | 0.006977  | 0.018425 |
| 100000 | 0.063788| 0.056337 | 0.113519 |
| 1000000  | 0.733202 |  0.945085  | 1.67702 |
| 10000000 |  42.893  |25.94792 | 41.2374|


Laikai naudojant STL konteinerį vector:
| std::vector | Duomenų skaitymas | Duomenų rūšiavimas |
| ------------- | ------------- | ------------- |
| 1000  | 0.05164  | 0.001287 |
| 10000  | 0.0825  | 0.004886 |
| 100000 | 0.97028  | 0.063788 |
| 1000000  | 8.14501 | 0.733202 |
| 10000000 | 69.2747  | 42.893 |


Laikai naudojant STL konteinerį list:
| std::list | Duomenų skaitymas | Duomenų rūšiavimas |
| ------------- | ------------- | ------------- |
| 1000  | 0.013033 | 0.00107 |
| 10000  | 0.088022  | 0.006977 |
| 100000 | 0.79475  | 0.056337 |
| 1000000  | 14.1512 | 0.945085 |
| 10000000 | 124.473  | 25.94792 |


Laikai naudojant STL konteinerį deque:
| std::deque| Duomenų skaitymas | Duomenų rūšiavimas |
| ------------- | ------------- | ------------- |
| 1000  | 0.00715 | 0.002456 |
| 10000  | 0.080193  | 0.018425 |
| 100000 | 0.612528 | 0.113519 |
| 1000000  | 9.16061 | 1.67702 |
| 10000000 | 93.1991 | 41.2374|

## Programos versijos v1.0 veikimo spartos analizė

### 1 - oji strategija 
Konteinerio skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "vykeliai" ir "nevykeliai".

### 2 - oji strategija  
Konteinerio skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "vykeliai". Tokiu būdu, jei studento galutinis balas yra >=5.0, jo duomenys bus įkelti į naująjį "vykelių" konteinerį ir ištrinti iš bendro studentai konteinerio.

## Programos veikimo spartos analizė

Išmatuotas laikas pateikiamas sekundėmis. Namų darbų kiekis sugeneruotuose failuose - 5.

Duomenų rūšiavimo laikų ir naudojamų STL konteinerių palyginimas:

| Studentų įrašų kiekis | std::vector 1-oji strategija | std::vector 2-oji strategija | std::list 1-oji strategija | std::list 2-oji strategija | std::deque 1-oji strategija | std::deque 2-oji strategija |
| ------------- | ------------- | ------------- | ------------- | ------------- | ------------- | ------------- |
| 1000  | 0.003932 | 0.001158 | 0.005124 | 0.001559 | 0.0029813 | 0.0010732 |
| 10000  | 0.024134 | 0.017482 | 0.015617 | 0.0098251 | 0.084553  |  0.006508 |
| 100000 | 0.143842  | 0.092961 | 0.193978 | 0.068597 | 0.372512 | 0.097351 |
| 1000000  | 0.740968 | 0.44283 | 1.2678 | 0.697743 | 3.115801 | 1.46423 |
| 10000000 | 5.14563  | 1.99313 | 6.2745 | 2.48977 | 13.59419 | 8.3652 |

### Išvados
Su visais STL konteineriais (std::vector, std::list, std::deque) naudojant 2-ąją strategiją duomenų išrūšiavimas vyksta efektyviau (greičiau). Std::vector konteineris iš naudojamų konteinerių laiko prasme išsiskiria kaip efektyviausias. 

Duomenų rūšiavimo laikų ir naudojant std::vector konteinerį palyginimas:

| Studentų įrašų kiekis | std::vector 1-oji strategija be papildomų algoritmų | std::vector 1-oji strategija su papildomais algoritmais | std::vector 2-oji strategija be papildomų algoritmų | std::vector 2-oji strategija su papildomais algoritmais |
| ------------- | ------------- | ------------- | ------------- | ------------- | 
| 1000  | 0.003932 | 0.002612 | 0.001158 | 0.00155713 |
| 10000  | 0.024134 | 0.0131385 | 0.017482 | 0.010418 | 
| 100000 | 0.143842  | 0.067599 | 0.092961 | 0.08172 |
| 1000000  | 0.740968 | 0.202667 |  0.44283  | 0.32956 |
| 10000000 | 5.14563  | 3.37423 | 1.99313  | 1.02471 |

### Išvados
Naudojami algoritmai:
* std::copy
* std::partition
Algoritmų naudojimas paspartina duomenų išrūšiavimą į dvi atskiras grupes pagal galutinį balą.

## Releases 
<br />[v0.1](https://github.com/Makstutyte/Objektinis-Programavimas-2-oji-uzduotis/releases/tag/v0.1) 
Pirmoji programos versija
* Programa apskaiciuojanti galutinius rezultatus pagal vartotojo suvestus arba atsitiktinai sugeneruotus duomenis.

<br />[v0.2](https://github.com/Makstutyte/Objektinis-Programavimas-2-oji-uzduotis/releases/tag/v0.2) 
Antroji programos versija
* Programa apskaiciuojanti galutinius rezultatus pagal vartotojo suvestus, perskaitytus iš failo arba atsitiktinai sugeneruotus duomenis.

<br />[v0.3](https://github.com/Makstutyte/Objektinis-Programavimas-2-oji-uzduotis/releases/tag/v0.3) 
Trečioji programos versija
* Programa apskaiciuojanti galutinius rezultatus pagal vartotojo suvestus, perskaitytus iš failo arba atsitiktinai sugeneruotus duomenis, kurioje funkcijos ir struktūra yra laikomi atskiruose antraštiniuose failuose.

<br />[v0.4](https://github.com/Makstutyte/Objektinis-Programavimas-2-oji-uzduotis/releases/tag/v0.4) 
Ketvirtoji programos versija
* Programa, kuri 
  *  nuskaito vartotojo įvedamus duomenis
  *  nuskaito faile esančius duomenis
  *  sugeneruoja naujus duomenų failus

Programa taip pat skirsto duomenis pagal galutinį balą ir atspausdina juos dviejuose skirtinguose failuose (jei galutinis balas >=5.0 duomenys išspausdinami į failą "vykeliai.txt", jei galutinis balas < 5.0  duomenys išspausdinami į failą "nevykeliai.txt").

<br />[v0.5](https://github.com/Makstutyte/Objektinis-Programavimas-2-oji-uzduotis/releases/tag/v0.5) 
Penktoji programos versija
* Programa, kuri leidžia vartotojui pasirinkti, kokiame STL konteineryje (vector, list ar deque) bus saugomi duomenys, bei apskaiciuojanti galutinius rezultatus pagal vartotojo suvestus, perskaitytus iš failo arba atsitiktinai sugeneruotus duomenis.

<br />[v1.0](https://github.com/Makstutyte/Objektinis-Programavimas-2-oji-uzduotis/releases/tag/v1.0) 
Šeštoji programos versija
* Programa, kuri leidžia vartotojui pasirinkti, kokiame STL konteineryje (vector, list ar deque) bus saugomi duomenys, pasirinkti pagal, kokią strategiją bus suskirstyti failai.
