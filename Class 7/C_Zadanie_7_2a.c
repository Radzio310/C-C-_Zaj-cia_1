#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 200

int znajdzSlowo(char *napis, char *slowo) {
    char *wynik = strstr(napis, slowo);
    return (wynik != NULL); // Zwraca 1, jeśli słowo zostało znalezione, 0 w przeciwnym razie
}

int main()
{
    char linia[MAX_LINE_LENGTH];

    FILE *fp;
    fp = fopen("input_2.txt", "r");
    if (fp == NULL) // czy plik został otwarty poprawnie
    {
        printf("Blad otwarcia pliku.\n");
        return 1; // NIEPOWODZENIE
    }

    int licznik = 1;
    int suma_part1 = 0;
    int suma_mocy = 0;

    while (fgets(linia, 200, fp) != NULL)
    {
        int max_red = 0, max_green = 0, max_blue = 0;
        int num = 0;
        int linelength = 1;

        // rzeczywista długość linii
        for(int i = 0; i < MAX_LINE_LENGTH; i++) {
            if(linia[i] != NULL) {
                linelength++;
            }
        }

        for (int i = 8; i < linelength; i++) // Iterujemy przez znaki w linii do napotkania znaku końca linii
        {
            char znak = linia[i];
            if (isdigit(znak))
            {
                if (i > 0 && isdigit(linia[i + 1]))
                {
                    num = ( (linia[i] - '0') * 10) + (linia[i+1] -'0'); // liczba dwucyfrowa
                    i++;
                }
                else
                {
                    num = znak - '0';
                }
            } else if (isalpha(znak))
            {
                for (int j = 0; j < 5; j++)
                {
                    char slowo[6]; // Maksymalna długość słowa to 5 liter
                    for (int k = 0; k < 5 && (i + k) < 100; k++)
                    {
                        slowo[k] = linia[i + k]; // Tworzymy słowo z następnych 5 liter w napisie
                        //slowo[k + 1] = '\0'; // Kończymy słowo znakiem null
                        if (znajdzSlowo(slowo, "red"))
                        {
                            if (num > max_red)
                            {
                                max_red = num;
                                i += k + 1;
                            }
                        } else if (znajdzSlowo(slowo, "green"))
                        {
                            if (num > max_green)
                            {
                                max_green = num;
                                i += k + 1;
                            }
                        } else if (znajdzSlowo(slowo, "blue"))
                        {
                            if (num > max_blue)
                            {
                                max_blue = num;
                                i += k + 1;
                            }
                        }
                    }
                }
            }
        }
        printf("Game %d: red: %d, green: %d, blue: %d\n", licznik, max_red, max_green, max_blue);
        // CZĘŚĆ 1
        if(max_red <= 12 && max_green <= 13 && max_blue <= 14)
        {
            suma_part1 += licznik;
            //printf("Game %d: red: %d, green: %d, blue: %d\n", licznik, max_red, max_green, max_blue);
        }
        // CZĘŚĆ 2
        suma_mocy += (max_red * max_green * max_blue);
        licznik++;
    }
    fclose(fp);
    printf("\n---------------\nSuma identyfikatorow (czesc 1): %d\n", suma_part1);
    printf("---------------\nSuma mocy (czesc 2): %d\n", suma_mocy);

    return 0;
}
