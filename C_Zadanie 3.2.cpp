#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int max = 99; // górna granica losowania liczb
int rows;
int cols;

void fullfilMatrix(int** matrix)
{
    srand(time(NULL));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = rand() % max + 1;
        }
    }
}

void displayMatrix(int** matrix)
{
    system("cls");
    srand(time(NULL));

    printf("Twoja macierz:\n\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%2.d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    printf("Ile wierszy ma miec Twoja macierz? "); // podanie danych przez użytkownika
    printf("\nTwoja odpowiedz: ");
    scanf_s("%d", &rows);
    printf("Ile kolumn ma miec Twoja macierz? ");
    printf("\nTwoja odpowiedz: ");
    scanf_s("%d", &cols);

    int** matrix = (int**)malloc(rows * sizeof(int*)); // alokacja pamięci dla wierszy
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int*)malloc(cols * sizeof(int)); // alokacja pamięci dla kolumn
    }

    fullfilMatrix(matrix);
    displayMatrix(matrix);


    free(matrix);

    return 0;
}
