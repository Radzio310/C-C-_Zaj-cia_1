#include <stdio.h>
#include <stdlib.h>

int rows = 0; // ile wierszy ma trojkat Pascala
int cols = 0; // ile kolumn ma trojkat Pascala

void fullfilPascal(int** pascal)
{
    // Wypełnianie trójkąta Pascala
    for (int line = 0; line < rows; line++)
    {
        for (int i = 0; i <= line; i++)
        {
            // Pierwszy i ostatni element w wierszu są zawsze równe 1
            if (i == 0 || i == line)
            {
                pascal[line][i] = 1;
            }
            else
            {
                // Obliczanie kolejnych elementów na podstawie poprzedniego wiersza
                pascal[line][i] = pascal[line - 1][i - 1] + pascal[line - 1][i];
            }
        }
    }
}

void displayPascal(int** pascal)
{
     system("cls");
    printf("Twoj trojkat Pascala:\n\n");
    // Wypełnianie trójkąta Pascala
    for (int line = 0; line < rows; line++)
    {
        for (int i = 0; i <= line; i++)
        {
            printf("%d ", pascal[line][i]);
        }
        printf("\n");
    }
}

int main()
{
    printf("Ile wierszy chcesz wyswietlic? ");
    printf("\nTwoja odpowiedz: ");
    scanf("%d", &rows);

    int** pascal = (int**)malloc(rows * sizeof(int*)); // alokacja pamięci dla wierszy
    for (int i = 0; i < rows; i++)
    {
        pascal[i] = (int*)malloc((i+1) * sizeof(int)); // alokacja pamięci dla kolumn
    }

    fullfilPascal(pascal);
    displayPascal(pascal);

    free(pascal); // zwolnienie pamięci

    return 0;
}

