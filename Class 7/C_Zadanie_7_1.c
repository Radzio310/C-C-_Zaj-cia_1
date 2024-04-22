#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Funkcja sprawdzająca, czy dany słowny zapis cyfry występuje w danym fragmencie napisu
int znajdzSlowo(char *napis, char *slowo) {
    char *wynik = strstr(napis, slowo);
    return (wynik != NULL); // Zwraca 1, jeśli słowo zostało znalezione, 0 w przeciwnym razie
}

int main() {
    char linia[100]; // tablica znaków z maksymalną długością linijki
    int licznik = 1;
    int wartosci_energetyczne = 0;
    FILE *fp;

    fp = fopen("./input.txt", "r");
    if (fp == NULL) // czy plik został otwarty poprawnie
    {
        printf("Blad otwarcia pliku.\n");
        return 1; // NIEPOWODZENIE
    }

    while (fgets(linia, 100, fp) != NULL) {
        char liczby[5][10]; // tablica tablic znaków do przechowywania słownych zapisów cyfr
        int pierwsza = -1, ostatnia = -1; // zmienne na cyfry

        for (int i = 0; linia[i] != '\0'; i++) // Iterujemy przez znaki w linii do napotkania znaku końca linii
        {
            char znak = linia[i];
            if (isdigit(znak)) {
                if (pierwsza == -1) {
                    pierwsza = znak - '0'; // Konwersja znaku na cyfrę liczbową
                }
                ostatnia = znak - '0'; // Konwersja znaku na cyfrę liczbową, zawsze aktualizujemy ostatnią napotkaną cyfrę
            } else if (isalpha(znak))
            {
                char slowo[6]; // Maksymalna długość słowa to 5 liter
                for (int k = 0; k < 5 && (i + k) < 100; k++) {
                    slowo[k] = linia[i + k]; // Tworzymy słowo z następnych 5 liter w napisie
                    if(isdigit(slowo[k])) {
                        if(pierwsza == -1) {
                            pierwsza = slowo[k] - '0';
                        }
                    }
                    slowo[k + 1] = '\0'; // Kończymy słowo znakiem null
                    if (znajdzSlowo(slowo, "null")) {
                        if(pierwsza == -1) pierwsza = 0;
                        else ostatnia = 0;
                    }
                    else if (znajdzSlowo(slowo, "one")) {
                        if(pierwsza == -1) pierwsza = 1;
                        else ostatnia = 1;
                    }
                    else if (znajdzSlowo(slowo, "two")) {
                        if(pierwsza == -1) pierwsza = 2;
                        else ostatnia = 2;
                    }
                    else if (znajdzSlowo(slowo, "three")) {
                        if(pierwsza == -1) pierwsza = 3;
                        else ostatnia = 3;
                    }
                    else if (znajdzSlowo(slowo, "four")) {
                        if(pierwsza == -1) pierwsza = 4;
                        else ostatnia = 4;
                    }
                    else if (znajdzSlowo(slowo, "five")) {
                        if(pierwsza == -1) pierwsza = 5;
                        else ostatnia = 5;
                    }
                    else if (znajdzSlowo(slowo, "six")) {
                        if(pierwsza == -1) pierwsza = 6;
                        else ostatnia = 6;
                    }
                    else if (znajdzSlowo(slowo, "seven")) {
                        if(pierwsza == -1) pierwsza = 7;
                        else ostatnia = 7;
                    }
                    else if (znajdzSlowo(slowo, "eight")) {
                        if(pierwsza == -1) pierwsza = 8;
                        else ostatnia = 8;
                    }
                    else if (znajdzSlowo(slowo, "nine")) {
                        if(pierwsza == -1) pierwsza = 9;
                        else ostatnia = 9;
                    }
                }
            }
        }

        wartosci_energetyczne += (10*pierwsza) + ostatnia;
        printf("Linia %d:  %d,%d\t== plik: %s", licznik, pierwsza, ostatnia, linia);
        licznik++;
    }
    fclose(fp);
    printf("\n\nSuma wartosci energetycznych = %d\n", wartosci_energetyczne);

    return 0;
}
