#include <stdio.h>

int main()
{
    int tablica[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int *wskaznik = &tablica[0];
    printf("TWOJA TABLICA: \n");
    for(int i = 0; i < 10; i++)
    {
        printf("%d: %d\n", i+1, *wskaznik);
        wskaznik++;
    }
    return 0;
}