#include <stdio.h>

int factorial(int liczba)
{
    if (liczba == 0)
    {
        return 1;
    }
    if (liczba == 1)
    {
        return 1;
    }
    if (liczba > 1)
    {
        return factorial(liczba - 1) * liczba;
    }
}

int main()
{
    int liczba;
    printf("Podaj liczbe do obliczenia silni: ");
    scanf("%d", &liczba);
    printf("\nSilnia z %d wynosi %d\n\n", liczba, factorial(liczba));

    return 0;
}
