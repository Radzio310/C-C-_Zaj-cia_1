#include <stdio.h>
#include <stdlib.h>

union Unia {
    int calkowita;
    float zmiennoprzecinkowa;
    char znakowa;
};

int main()
{
    int c;
    float f;
    char z;
    union Unia unia;
    // Wskaźnik do unii
    union Unia *w = &unia;

    printf("Podaj liczbe calkowita:  ");
    scanf("%d", &c);
    unia.calkowita = c;
    printf("Dane w unii: %d\n", w->calkowita);


    printf("Podaj liczbe zmiennoprzecinkowa: ");
    scanf("%f", &f);
    unia.zmiennoprzecinkowa = f;
    printf("Dane w unii: %f\n", w->zmiennoprzecinkowa);

    unia.znakowa = 'X';
    printf("Dane w unii: %c\n", w->znakowa);

    return 0;
}