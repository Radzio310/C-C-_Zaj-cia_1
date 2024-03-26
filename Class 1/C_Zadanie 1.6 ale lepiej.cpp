#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// kamień, papier, nożyce
enum ruch
{
    kamien,
    papier,
    nozyce
};

int gra(ruch r)
{
    srand(time(NULL));
    int liczba = rand() % 3;
    ruch komp = kamien;
    switch (liczba) // losujemy jaki ruch wykona komputer
    {
        case 0:
        {
            komp = kamien;
            break;
        }
        case 1:
        {
            komp = papier;
            break;
        }
        case 2:
        {
            komp = nozyce;
            break;
        }
        default:
        {
            komp = kamien;
            break;
        }
    }
    switch (r) // sprawdzamy kto wygrał
    {
        case kamien:
        {
            if (komp == nozyce)
            {
                return 0; // zwycięstwo gracza
            }
            else if (komp == kamien)
            {
                return 1; // remis
            }
            else
            {
                return 2; // porażka gracza
            }
        }
        case papier:
        {
            if (komp == kamien)
            {
                return 0; // zwycięstwo gracza
            }
            else if (komp == papier)
            {
                return 1; // remis
            }
            else
            {
                return 2; // porażka gracza
            }
        }
        case nozyce:
        {
            if (komp == papier)
            {
                return 0; // zwycięstwo gracza
            }
            else if (komp == nozyce)
            {
                return 1; // remis
            }
            else
            {
                return 2; // porażka gracza
            }
        }
        default:
        {
            return 1;
        }
    }
}

ruch ruch_gracza()
{
    int wybor = -1;
    printf("Wybierz jaki chcesz wykonac ruch:\n1. Kamien\n2. Papier\n3. Nozyce\n");
    scanf_s("%d", &wybor);
    ruch gracz;
    switch (wybor) // sprawdzamy wybór użytkownika i przypisujemy do zmiennej typu ruch
    {
    case 0:
    {
        gracz = kamien;
        break;
    }
    case 1:
    {
        gracz = papier;
        break;
    }
    case 2:
    {
        gracz = nozyce;
        break;
    }
    default:
    {
        gracz = kamien;
        break;
    }
    }

    return gracz;
}
void wyniki(int tabela[])
{
    system("cls");
    printf("\t\tOstatnie 10 gier\n\n");
    const char* wynik = "";
    for (int i = 0; i < 10; i++)
    {
        switch (tabela[i])
        {
            case 0:
            {
                wynik = "Wygrana gracza";
                break;
            }
            case 1:
            {
                wynik = "Remis";
                break;
            }
            case 2:
            {
                wynik = "Przegrana gracza";
                break;
            }
            case -1:
            {
                wynik = "";
                break;
            }
        }
        printf("%d gra ==> %s\n", i+1, wynik);
    }
}

int main()
{
    int tabela[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int czy_dalej = 1;
    int licznik = 0; // licznik, która to gra
    while (czy_dalej == 1)
    {
        system("cls");
        ruch gracz = ruch_gracza();
        if (licznik > 9)
        {
            for (int i = 0; i < 9; i++)
            {
                tabela[i] = tabela[i + 1];
            }
            tabela[licznik - 1] = gra(gracz);
        }
        else
        {
            tabela[licznik] = gra(gracz);
            licznik++;
        }        
        if (gra(gracz) == 0)
        {
            printf("\nGratulacje! Wygrales!\n\n");
        }
        else if (gra(gracz) == 2)
        {
            printf("\nNiestety przegrales tym razem...\n\n");
        }
        else
        {
            printf("\nMamy remis!\n\n");
        }
        printf("Jesli chcesz zobaczyc tabele wynikow wcisnij '2'\nGramy dalej? (wcisnij '1' jesli tak)\nTwoja decyzja: ");
        scanf_s("%d", &czy_dalej);
        if (czy_dalej == 2)
        {
            wyniki(tabela);
            printf("\n\nGramy dalej? (wcisnij 1 jesli tak)\nTwoja decyzja: ");
            scanf_s("%d", &czy_dalej);
        }
    }
    system("cls");
    printf("Dzieki za gre!\n");

    return 0;
}
