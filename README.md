# Objektinis-Programavimas-2-oji-uzduotis

Programa, nuskaitanti vartotojo įvedamus duomenis ir pateikianti apskaičiuotus rezultatus
 
## Programos naudojimas ir apibendrintas veikimas 
Vartotojo veiksmų seka: 
1. Vartotojas pasirenka ar duomenys bus įvedami ar skaitomi iš failo
2. Vartotojas pasirenka, kokių būdu bus pateikiami namų darbų ir egzaminų rezultatai (atsitiktinai generuojant ar įvedant pačiam vartotojui) 
    * pasirinkus atsitiktinį generavimą, vartotojas nurodo, kiek balų bus sugeneruota
    * pasirinkus galimybę vartotojui pačiam įvesti namų darbų balus, įvedimo metu vartotojas nusprendžia kuomet jis jau įvedė visų namų           darbų rezultatus (įvedus nulį (0) yra sustabdomas balų įvedinėjimas)
3. Vartotojas pasirenka, kokių būdu bus apskaiciuojamas galutinis rezultatas (apskaičiuojant namų darbų balų vidurkį ar medianą)
4. Vartotojas pasirenka, kelių mokinių duomenys bus naudojami programoje
5. Vartotojas įveda studentų vardus ir pavardes

Po šios veiksmų sekos atspausdinama lentelė nurodanti studento vardą, pavardę ir galutinį rezultatą.

  Galutinio rezultato formulės:
  * Galutinis rezultatas = (namų darbų vidurkis) * 0.4 + (egzamino balas) * 0.6;
  * Galutinis rezultatas = (namų darbų mediana) * 0.4 + (egzamino balas) * 0.6;
