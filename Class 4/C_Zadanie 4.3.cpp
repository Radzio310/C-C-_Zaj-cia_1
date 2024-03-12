#include <stdio.h>

void swap(int* x, int* y) 
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void generate_permutations(int array[], int start, int end) {
    if (start == end) 
    {
        // Jeśli doszliśmy do końca ciągu, wyświetlamy permutację
        for (int i = 0; i <= end; i++) 
        {
            printf("%d ", array[i]);
        }
        printf("\n");
    }
    else {
        for (int i = start; i <= end; i++) 
        {
            // Zamieniamy obecny element z elementem na pozycji 'start'
            swap(&array[start], &array[i]);
            generate_permutations(array, start + 1, end);
            // Przywracamy pierwotne ustawienie tablicy
            swap(&array[start], &array[i]);
        }
    }
}

int main() 
{
    // Przykładowy ciąg liczb
    int array[] = { 1, 2, 3, 4, 5 };
    int length = sizeof(array) / sizeof(array[0]);

    printf("Wszystkie permutacje ciagu:\n");
    generate_permutations(array, 0, length - 1);

    return 0;
}

