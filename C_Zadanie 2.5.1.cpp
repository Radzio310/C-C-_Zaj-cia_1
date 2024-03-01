#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct {
     const char* imie;
     const char* nazwisko;
     const char* numer;
}Contact;

void setConsoleColor(int color) // zmiana koloru tekstu
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void clear_input_buffer() // czyszczenie bufora wejściowego, aby działał poprawnie getchar()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void wyswietl(Contact* lista, int ile)
{
    system("cls");
    for (int i = 0; i < ile; i++)
    {
        int numer = i + 1;
            printf("%2.d: %s %s ; tel: %s\n", numer, lista[i].imie, lista[i].nazwisko, lista[i].numer);
    }

    printf("\nWcisnij ENTER, aby kontynuowac...");
    clear_input_buffer();
    getchar();
}

void dodaj(Contact lista[10], Contact* nowy, int licznik)
{
    if (licznik < 10) {
        lista[licznik] = *nowy;
    }
    else {
        for (int i = 0; i < 9; i++) {
            lista[i] = lista[i + 1];
        }
        lista[9] = *nowy;
    }

    printf("\nKontakt zostal dodany pomyslnie!\n");

    printf("\nWcisnij ENTER, aby kontynuowac...");
    clear_input_buffer();
    getchar();
}

Contact wyszukaj(Contact* lista, char nazwisko[], int licznik)
{
    int znaleziono = 0;
    int znal[10];
    for (int i = 0; i < licznik; i++)
    {
        if (strncmp(lista[i].nazwisko, nazwisko, sizeof(nazwisko)) == 0)
        {
            // printf("\nZnaleziono kontakt!\n");
            // printf("%d: %s %s %s\n", i+1, lista[i].imie, lista[i].nazwisko, lista[i].numer);
            znaleziono = 1;
            znal[i] = 1; // numer w tablicy, gdzie znaleziono kontakt
        }
        else
        {
            znal[i] = 0; // numer w tablicy, gdzie nie znaleziono kontaktu
        }
    }
    if (znaleziono == 0)
    {
        printf("\nNie znaleziono takiego kontaktu\n");
    }
    else
    {
        printf("\n-----ZNALEZIONO KONTAKT-----\n");
        for (int i = 0; i < licznik; i++)
        {
            if (znal[i] == 1)
            {
                setConsoleColor(FOREGROUND_RED);
            }
            else
            {
                setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // kolor biały
            }
            printf("%d: %s %s %s\n", i + 1, lista[i].imie, lista[i].nazwisko, lista[i].numer);
        }
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // kolor biały
    }


    printf("\nWcisnij ENTER, aby kontynuowac...");
    clear_input_buffer();
    getchar();

    return *lista;
}

Contact usun(Contact* lista, char nazwisko[], int licznik)
{
    int znal[10];
    int ile_znaleziono = 0;
    for (int i = 0; i < licznik; i++)
    {
        if (strncmp(lista[i].nazwisko, nazwisko, sizeof(nazwisko)) == 0)
        {
            // printf("\nZnaleziono kontakt!\n");
            // printf("%d: %s %s %s\n", i+1, lista[i].imie, lista[i].nazwisko, lista[i].numer);
            znal[i] = 1; // numer w tablicy, gdzie znaleziono kontakt
        }
        else
        {
            znal[i] = 0; // numer w tablicy, gdzie nie znaleziono kontaktu
        }
        ile_znaleziono += znal[i];
    }
    if (ile_znaleziono == 0)
    {
        printf("\nNie znaleziono takiego kontaktu ==> nie mozna usunac\n");
    }
    else
    {
        printf("\n-----ZNALEZIONO KONTAKT-----\n");
        for (int i = 0; i < licznik; i++)
        {
            if (znal[i] == 1)
            {
                setConsoleColor(FOREGROUND_RED);
            }
            else
            {
                setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // kolor biały
            }
            printf("%d: %s %s %s\n", i + 1, lista[i].imie, lista[i].nazwisko, lista[i].numer);
        }
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // kolor biały
    }
    if (ile_znaleziono == 1)
    {
        int czy;
        printf("\nCzy na pewno chcesz usunac zaznaczony kontakt? (wcisnij 1, jesli tak)\n");
        printf("Twoja decyzja: ");
        scanf_s("%d", &czy);
        if (czy == 1)
        {
            int gdzie = 0;
            for (int i = 0; i < licznik; i++)
            {
                if (znal[i] == 1)
                {
                    gdzie = 1;
                }
                if (gdzie == 1 && i+1 < licznik)
                {
                    lista[i] = lista[i+1];
                }
                else if (gdzie == 1)
                {
                    lista[i] = { "", "", "" };
                }
            }
            printf("\nUsuwanie kontaktu zakonczone\n");
        }
    }
    else if (ile_znaleziono > 1)
    {
        int ktory;
        printf("\nKtory z wybranych numerow chcesz usunac? (wcisnij numer, ktory chcesz usunac)\n");
        printf("Twoja decyzja: ");
        scanf_s("%d", &ktory);
        if (znal[ktory - 1] == 1)
        {
            for (int i = ktory - 1; i < licznik; i++)
            {
                if (i + 1 < licznik)
                {
                    lista[i] = lista[i + 1];
                }
                else
                {
                    lista[i] = { "", "", "" };
                }
            }
            printf("\nUsuwanie kontaktu zakonczone\n");
        }
    }
    else
    {
        printf("\nNIEPOWODZENIE! - nie mozemy usunac takiego kontaktu");
    }

    printf("\nWcisnij ENTER, aby kontynuowac...");
    clear_input_buffer();
    getchar();

    return *lista;
}

int main()
{
    Contact lista[10] = { {"Marek", "Kowalski", "765432198"},
                        {"Zofia", "Malecka", "557786888"},
                        {"Tomek", "Borowiecki", "532988127"},
                        {"Basia", "Nowak", "359872365"},
                        {"Magda", "Domacka", "459973921"} };
    int licznik = 5;
    int wybor = 1;
    while (wybor == 4 || wybor == 3 || wybor == 2 || wybor == 1)
    {
        system("cls");
        printf("---------------------------------------------------------\n");
        printf("| 1. Wyswietl liste kontaktow                           |\n");
        printf("| 2. Dodaj nowy kontakt                                 |\n");
        printf("| 3. Wyszukaj kontakt (po nazwisku)                     |\n");
        printf("| 4. Usun kontakt (po nazwisku)                         |\n");
        printf("|    Aby zakonczyc wcisnij inna liczbe...               |\n");
        printf("|    Wpisuj tylko liczby bo program wybuchnie, prosze   |\n");
        printf("\n  Twoja decyzja: ");
        scanf_s("%d", &wybor);
            switch (wybor)
            {
                case 1: // wyświetlanie
                {
                    wyswietl(&lista[0], licznik);
                    break;
                }
                case 2: // dodawanie kontaktu
                {
                    system("cls");
                    char imie[30] = "";
                    char nazwisko[30] = "";
                    char numer[30] = "";
                    printf("-----Podaj dane nowego kontaktu-----\n"); // tworzenie nowego kontaktu
                    printf("Imie: ");
                    scanf_s("%s", imie, unsigned(sizeof(imie)));
                    printf("Nazwisko: ");
                    scanf_s("%s", nazwisko, unsigned(sizeof(nazwisko)));
                    printf("Numer telefonu: ");
                    scanf_s("%s", numer, unsigned(sizeof(numer)));
                    Contact nowy;
                    nowy.imie = imie;
                    nowy.nazwisko = nazwisko;
                    nowy.numer = numer;
                         
                    printf("%p", & nowy);
                    dodaj(lista, &nowy, licznik);
                    licznik++;

                    break;
                }
                case 3: // wyszukiwanie kontaktu
                {
                    system("cls");
                    char nazwisko[30] = "";
                    printf("-----Wyszukiwanie kontaktu po nazwisku-----\n"); // tworzenie nowego kontaktu
                    printf("\nPodaj szukane nazwisko: ");
                    scanf_s("%s", nazwisko, unsigned(sizeof(nazwisko)));
                    wyszukaj(&lista[0], nazwisko, licznik);
                    break;
                }
                case 4: // usuwanie kontaktu
                {
                    system("cls");
                    char nazwisko[30] = "";
                    printf("-----Usuwanie kontaktu po nazwisku-----\n"); // tworzenie nowego kontaktu
                    printf("\nPodaj nazwisko do usuniecia: ");
                    scanf_s("%s", nazwisko, unsigned(sizeof(nazwisko)));
                    usun(&lista[0], nazwisko, licznik);
                    licznik--;
                    break;
                }
                default: // inna liczba -> zakończenie programu
                {
                    printf("\nDo zobaczenia!\n");
                    break;
                }
            }
    }



    return 0;
}
