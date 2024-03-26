#include <stdio.h>

typedef struct {
    const char *imie;
    float ocena;
}Student;

Student sortuj(Student* lista, int ile)
{
    Student temp;
    for (int i = 0; i < ile; i++)
    {
        for (int j = 1; j < ile - i; j++) //pętla wewnętrzna
        {
            if (lista[j - 1].ocena < lista[j].ocena)
            {
                //zamiana miejscami
                temp = lista[j - 1];
                lista[j - 1] = lista[j];
                lista[j] = temp;
            }
        }
    }

    return *lista;
}

int main()
{
    Student lista[] = {{"Marek", 4},{"Zofia", 3},{"Tomek", 5},{"Basia", 3.5},{"Magda", 4.5}};
    Student* w = &lista[0];
    int rozmiar = sizeof(lista) / sizeof(lista[0]);
    for (int i = 0; i < rozmiar; i++) // wyświetlenie tablicy studentów
    {
        int numer = i + 1;
        printf("%d: %s --> %.1f\n", numer, lista[i].imie, lista[i].ocena);
    }
    sortuj(w, rozmiar);
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < 5; i++) // wyświetlenie tablicy studentów
    {
        int numer = i + 1;
        printf("%d: %s --> %.1f\n", numer, lista[i].imie, lista[i].ocena);
    }

    return 0;
}
