#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 200

int main()
{
    char linia[MAX_LINE_LENGTH];

    FILE *fp;
    fp = fopen("input_2.txt", "r");
    if (fp == NULL)
    {
        printf("Blad otwarcia pliku.\n");
        return 1; // NIEPOWODZENIE
    }

    int licznik = 1;
    int suma_part1 = 0;
    int suma_mocy = 0;

    while (fgets(linia, MAX_LINE_LENGTH, fp) != NULL)
    {
        int max_red = 0, max_green = 0, max_blue = 0;
        int num;

        // Oblicz rzeczywistą długość linii
        int linelength = strlen(linia);

        for (int i = 8; i < linelength;)
        {
            if (isdigit(linia[i]))
            {
                if (isdigit(linia[i + 1]))
                {
                    num = ((linia[i] - '0') * 10) + (linia[i + 1] - '0');
                    i += 2; // Przesuń o 2, bo to liczba dwucyfrowa
                }
                else
                {
                    num = linia[i] - '0';
                    i++; // Przesuń o 1, bo to liczba jednocyfrowa
                }
            }
            else if (strncmp(&linia[i], "red", 3) == 0)
            {
                if (num > max_red)
                {
                    max_red = num;
                }
                i += 3; // Przesuń o 3, bo to słowo kluczowe "red"
            }
            else if (strncmp(&linia[i], "green", 5) == 0)
            {
                if (num > max_green)
                {
                    max_green = num;
                }
                i += 5; // Przesuń o 5, bo to słowo kluczowe "green"
            }
            else if (strncmp(&linia[i], "blue", 4) == 0)
            {
                if (num > max_blue)
                {
                    max_blue = num;
                }
                i += 4; // Przesuń o 4, bo to słowo kluczowe "blue"
            }
            else
            {
                i++; // Przesuń o 1, jeśli nie znaleziono żadnego klucza
            }
        }

        // CZĘŚĆ 1
        if (!(max_red > 12 || max_green > 13 || max_blue > 14))
        {
            suma_part1 += licznik;
        }
        // CZĘŚĆ 2
        suma_mocy += (max_red * max_green * max_blue);
        licznik++;

        printf("Game %d: red: %d, green: %d, blue: %d\n", licznik, max_red, max_green, max_blue);
    }
    fclose(fp);
    printf("\n---------------\nSuma identyfikatorow (czesc 1): %d\n", suma_part1);
    printf("---------------\nSuma mocy (czesc 2): %d\n", suma_mocy);

    return 0;
}
