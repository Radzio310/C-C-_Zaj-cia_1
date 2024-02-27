#include <cstdio>
#include <iostream>
#include <stdio.h>

int main()
{
	float srednia_mat = 0, srednia_fiz = 0;
	int grades[5][2] = { { 4,3 }, {5, 4}, {3, 2}, {5, 5}, {4, 1} }; // pierwsza ocena - matematyka, druga ocena - fizyka
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (j == 0)
			{
				srednia_mat += grades[i][j]; // sumowanie ocen z matematyki
			}
			else
			{
				srednia_fiz += grades[i][j]; // sumowanie ocen z fizyki
			}
		}
	}
	// obliczenie średniej
	srednia_mat /= 5;
	srednia_fiz /= 5;

	// wyświetlenie wyników z zaokrągleniem do 2 miejsc po przecinku
	printf("Srednia z matematyki wynosi %.2f, a srednia z fizyki %.2f\n", srednia_mat, srednia_fiz);

	return 0;
}
