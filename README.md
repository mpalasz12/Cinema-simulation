# Dokumentacja Wstępna Projektu

### Michał Pałasz, Bartosz Nowak - Symulacja Działania Kina.

> Wstępnym planem realizacji projektu jest zaimplementowanie symulacji kina w czasie rzeczywistym. Działanie programu planowane jest w terminalu, bez ewentualnej wersji graficznej. Sama symulacja kina będzie umożliwiona dzięki klasom reprezentującym informacje o każdej składowej kina.

### Klasa ``Cinema``

> Planowo klasa ``Cinema`` jest główną klasą reprezentującą kino i zawierającą wszystkie jego składowe, takie jak:

* ``name`` - nazwa kina,
* ``openingHour, closingHour`` - godziny otwarcia i zamknięcia
* wektory zawierające miejsca pracy pracowników
* wektor z klientami z danego dnia

> Sama klasa ``Cinema`` jest najbardziej złożoną klasą w całej symulacji i zawiera większość jej logiki, to tutaj tworzone są plany dnia dla pracowników, generowani losowi klienci itd.


### Klasa ``Workplace``

> Klasa ``Workplace`` reprezentuje miejsce pracy, jest ono obsługiwane przez pracownika w godzinach pracy kina, do kasy będą mogli ustawić się w kolejce klienci i kupić bilet na jeden z filmów granych w kinie

> Przy czym samo kupowanie biletów jest losowe, kasa może w ciągu danej godziny obsłużyć różną ilość osób, reszta pozostanie w kolejce.

### Klasa ``Schedule``

> Klasa schedule reprezentuje rozkład i plan na dany tydzień dla pracowników. Zawiera informacje o ich dostępności danego dnia oraz o tygodniowych godzinach pracy

### Klasa ``Movie``

> Klasa film reprezentować będzie.. film. Do generowania losowych filmów używamy biblioteki <random>, ponieważ posiada ona lepszą generację liczb losowych od funkcji rand() z biblioteki <cstdlib>.

### Klasy reprezentujące osoby.

> Główna klasa ``Worker``, od której będą wychodzić klasy dotyczące poszczególnych pracowników

> Dziedziczą po niej konkretni pracownicy tacy jak sprzedawcy biletów, jedzenia oraz woźni.

### Klasa ``Screening room``

> Klasa reprezentująca salę kinową. to w niej będzie wyświetlany film i w niej zasiądą klienci. Sala filmowa posiadać będzie ograniczoną liczbę miejsc.

### Klasa ``Showing ``

> W tej klasie przechowywane są informacje o seansie, czyli w której sali, o której godzinie, jaki film i ilość wolnych miejsc.

### Klasa ``Time ``

> Zawiera dzień tygodnia oraz godzinę.

## Sposób uruchamiania programu.

> Program uruchamiany jest poprzez wywołanie go z terminala podając jako argumenty kolejno:

1) Ścieżkę do pliku z salami kinowymi
2) Ścieżkę do pliku z filmami
3) Ścieżkę do pliku z pracownikami
4) Ścieżkę do pliku z miejscami pracy

> Podział obowiązków do ustalenia
