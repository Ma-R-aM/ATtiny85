# Zobrazovanie vzoru použitím LED
Programované použitím Arduino Nano.



#### Funkcia na rozsvecovanie jednotlivých diód podľa pinov. 
- je zadefinovaná premenná 's' pre trvanie efektu a pozerá sa aktuálny čas a čas v bode zapnutia efektu.
- rozdiel týchto časov sa porovnáva s premennou a po dosiahnutí času sa presúva na vypnutie aktuálnych a zapnutie ďalších LED v poradí efektu. 
- okrem toho sa pozerá celkový čas, ktorý po dosiahnutí nastavenej hodnoty (aktuálne 30 sekúnd) uvedie mikročip do standby režimu, v ktorom má malý odber a je pripravený na opätovnú aktiváciu tlačidlom.
