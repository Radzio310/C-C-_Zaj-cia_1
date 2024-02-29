#include <stdio.h>

int main()
{
    int x = 2;
    int* w_x = &x;
    printf("Wartosc przed zmiana: %d\n", x);
    (*w_x)++; // modyfikacja wartości x przez wskaźnik w_x
    printf("Wartosc po zmianie: %d\n", *w_x);

    return 0;
}
