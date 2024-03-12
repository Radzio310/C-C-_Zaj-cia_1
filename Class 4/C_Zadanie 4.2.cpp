#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void setConsoleColor(int color) // zmiana koloru tekstu
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void clear_input_buffer() // czyszczenie bufora wejściowego, aby działał poprawnie getchar()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void sortuj(int* tablica, int ile)
{
    for (int i = 0; i < ile; i++)
    {
        for (int j = 1; j < ile - i; j++) //pętla wewnętrzna
        {
            if ((tablica)[j - 1] > (tablica)[j])
            {
                //zamiana miejscami
                int temp = tablica[j - 1];
                tablica[j - 1] = tablica[j];
                tablica[j] = temp;
            }
        }
    }
}
void wyswietl(int* tablica, int ile)
{
    system("cls");
    printf("Tak wyglada Twoja tablica:\n\n");
    for (int i = 0; i < ile; i++)
    {
        if (i % 10 == 0)
        {
            printf("\n");
        }
        printf("%3.d\t", tablica[i]);
    }
}

int szukaj(int* tablica, int lewy, int prawy, int szukana)
{
    int srodek = (lewy + prawy) / 2;
    if (tablica[srodek] == szukana)
    {
        return srodek;
    }
    else
    {
        if (szukana > tablica[srodek])
        {
            if (lewy != srodek)
            {
                lewy = srodek;
            }
            else
            {
                return -1;
            }
        }
        else
        {
            if (prawy != srodek)
            {
                prawy = srodek;
            }
            else
            {
                return -1;
            }
        }
        return szukaj(tablica, lewy, prawy, szukana);
    }
}

int main()
{
    srand(time(NULL));
    int tablica[50];
    clock_t start, end;
    double cpu_time_used;

    for (int i = 0; i < 50; i++)
    {
        tablica[i] = (rand() % 100) - 50;
    }
    int ile = sizeof(tablica) / sizeof(int);

    wyswietl(&tablica[0], ile);

    printf("\n\nWcisnij ENTER, aby posortowac...");
    getchar();

    sortuj(&tablica[0], ile);
    wyswietl(&tablica[0], ile);
    start = clock(); // początek mierzenia czasu
    end = clock();
    while (((double)(end - start)) / CLOCKS_PER_SEC < 3) //odczekanie 3 sekund
    {
        end = clock();
    }
    system("cls");
    printf("Jaki element chcesz znalezc? ");
    int szukana;
    scanf_s("%d", &szukana);
    int indeks = szukaj(&tablica[0], 0, ile, szukana);
    if (indeks != -1)
    {
        printf("\nTwoja liczba znajduje sie na miejscu %d\n\n", indeks+1);
        for (int i = 0; i < ile; i++)
        {
            if (i % 10 == 0)
            {
                printf("\n");
            }
            if (i == indeks)
            {
                setConsoleColor(FOREGROUND_RED);
            }
            else
            {
                setConsoleColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
            }
            printf("%3.d\t", tablica[i]);
        }
    }
    else
    {
        printf("\nTwojej liczby nie ma w tabeli!");
    }
    setConsoleColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);

    printf("\n\nWcisnij ENTER, aby zakonczyc...");
    clear_input_buffer();
    getchar();

    return 0;
}
