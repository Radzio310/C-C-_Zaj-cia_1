#include <stdio.h>

float podwoj(float* liczba)
{
    *liczba = *liczba * 2;
    return *liczba;
}

int main()
{
    float liczba = 3;
    printf("Wartosc przed zmiana: %.2f\n", liczba);
    podwoj(&liczba);
    printf("Wartosc po podwojeniu: %.1f\n", liczba);

}
