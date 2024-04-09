#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dodaj(int pierwsza, int druga)
{
    int wynik = pierwsza + druga;
    return wynik;
}

int pomnoz(int pierwsza, int druga)
{
    int wynik = pierwsza * druga;
    return wynik;
}

int odejmij(int pierwsza, int druga)
{
    int wynik = pierwsza - druga;
    return wynik;
}

int main()
{
    int (*wskaznik)(int, int);
    printf("Do jakiej funkcji ma sie odnosic wskaznik?\n");
    printf("1. Dodawanie\n2. Mnozenie\n3. Odejmowanie\nTwoj wybor: ");
    int wybor;
    scanf("%d", &wybor);

    srand(time(NULL));

    // Losowanie dwóch liczb całkowitych
    int pierwsza = rand() % 1000 - 500; // liczba od -500 do 500
    int druga = rand() % 1000 - 500; // liczba od -500 do 500

    switch(wybor)
    {
        case 1:
        {
            wskaznik = &dodaj;
            printf("%d + %d = %d\n",pierwsza, druga, wskaznik(pierwsza,druga));
            break;
        }
        case 2:
        {
            wskaznik = &pomnoz;
            printf("%d * %d = %d\n",pierwsza, druga, wskaznik(pierwsza,druga));
            break;
        }
        case 3:
        {
            wskaznik = &odejmij;
            printf("%d - %d = %d\n",pierwsza, druga, wskaznik(pierwsza,druga));
            break;
        }
        default:
        {
            wskaznik = &dodaj;
            printf("%d + %d = %d\n",pierwsza, druga, wskaznik(pierwsza,druga));
            break;
        }
    }

    return 0;
}