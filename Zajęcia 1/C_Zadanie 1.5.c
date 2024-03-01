#include <stdio.h>

int main()
{
    int liczba = 0;
    int suma = 0;
    printf("Podaj liczbe ponizej ktorej bedziemy sprawdzac: ");
    scanf("%d", &liczba);
    if (liczba <= 1)
    {
        suma = 0;
    }
    else
    {
        for (int i = 1; i < liczba; i++)
        {
            if (i % 3 == 0)
            {
                suma += i;
            }
            else if (i % 5 == 0) // nie trzeba sprawdzać warunku łącznego bo gdy dzieli się przez obydwie liczby to i tak liczymy ją raz
            {
                suma += i;
            }
        }
    }
    // wyświetlenie wyniku
    printf("\nDo liczby %d suma liczb podzielnych przez 3 lub 5 wynosi %d\n", liczba, suma);

    return 0;
}
