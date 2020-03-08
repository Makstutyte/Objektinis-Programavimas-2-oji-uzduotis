# Objektinis-Programavimas-2-oji-uzduotis

Programa, nuskaitanti vartotojo įvedamus, generuojamus (atskirus duomenis arba failus) arba iš failo perskaitomus duomenis ir pateikianti apskaičiuotus rezultatus
 
## Programos naudojimas ir apibendrintas veikimas 
Vartotojo veiksmų seka: 
1. Vartotojas pasirenka ar bus generuojami nauji duomenų failai
  * sugeneravus failus vartotojas pasirenka, su kokiu failu bus toliau dirbama
  * pasirinkus generavima vartotojas pasirenka kaip bus apskaičiuotas galutinis rezultatas (apskaičiuojant namų darbų balų vidurkį ar medianą)
  * rezultatai bus rikiuojami pagal vardą ar balą
  
 #### Tuo atveju, jei pasirinkta, jog nebus genetuojami nauji duomenų failai
 
1. Vartotojas pasirenka ar duomenys bus įvedami ar skaitomi iš failo 
2. Vartotojas pasirenka, kokių būdu bus pateikiami namų darbų ir egzaminų rezultatai (atsitiktinai generuojant ar įvedant pačiam vartotojui) 
    * pasirinkus atsitiktinį generavimą, vartotojas nurodo, kiek balų bus sugeneruota
    * pasirinkus galimybę vartotojui pačiam įvesti namų darbų balus, įvedimo metu vartotojas nusprendžia kuomet jis jau įvedė visų namų           darbų rezultatus (įvedus nulį (0) yra sustabdomas balų įvedinėjimas)
3. Vartotojas pasirenka, kokių būdu bus apskaiciuojamas galutinis rezultatas (apskaičiuojant namų darbų balų vidurkį ar medianą)
4. Vartotojas pasirenka, kelių mokinių duomenys bus naudojami programoje
5. Vartotojas įveda studentų vardus ir pavardes

Po šios veiksmų sekos atspausdinami du .txt failai pagal galutinio balo rezultatą (jei galutinis balas >=5.0 duomenys išspausdinami į failą "vykeliai.txt", jei galutinis balas < 5.0  duomenys išspausdinami į failą "nevykeliai.txt"), nurodantys studentų vardus, pavardes ir galutinius rezultatus.

  Galutinio rezultato formulės:
  * Galutinis rezultatas = (namų darbų vidurkis) * 0.4 + (egzamino balas) * 0.6;
  * Galutinis rezultatas = (namų darbų mediana) * 0.4 + (egzamino balas) * 0.6;
  
  ## Programos veikimo spartos analizė

Išmatuotas laikas pateikiamas sekundėmis. Namų darbų kiekis sugeneruotuose failuose - 5.

| Duomenų kiekis  | Duomenų failo generavimas | Duomenų failo skaitymas  | Rezultatų rūšiavimas | Surūšiuotų duomenų išspausdinimas |
| ------------- | ------------- | ------------- | ------------- | ------------- |
| 1000  | 1.59454  | 0.018584  | 0.001812 | 0.060258  |
| 10000 | 2.2234 | 0.048893  | 0.008486 | 0.572778  |
| 100000 | 4.95502  | 1.08912  | 0.163851 | 14.5011 |
| 1000000  | 8.23857 | 5.56081 | 1.17097  |  148.988  |
| 10000000  | 74.0793 | 59.8561 | 141.068 | 321.963  |

### Programos paleidimas naudojant Makefile:
1. make
2. test

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
Trečioji programos versija
* Programa, kuri 
  *  nuskaito vartotojo įvedamus duomenis
  *  nuskaito faile esančius duomenis
  *  sugeneruoja naujus duomenų failus

Programa taip pat skirsto duomenis pagal galutinį balą ir atspausdina juos dviejuose skirtinguose failuose (jei galutinis balas >=5.0 duomenys išspausdinami į failą "vykeliai.txt", jei galutinis balas < 5.0  duomenys išspausdinami į failą "nevykeliai.txt").
