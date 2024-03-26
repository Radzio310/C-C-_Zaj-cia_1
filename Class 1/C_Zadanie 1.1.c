#include <stdio.h>

int main()
{
	/*string imie;
	cout << "Podaj imie: ";
	cin >> imie;
	cout << "Twoje imie to " << imie << endl;*/
	char imie[50];
	printf("Podaj imie: ");
	scanf("%s", imie, sizeof(imie));
	printf("Twoje imie to %s", imie);
}
