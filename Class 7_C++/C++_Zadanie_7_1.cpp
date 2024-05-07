#include <iostream>
#include <fstream>
#include <string>
#include <cctype> // Do isdigit i isalpha
#include <cstring> // Do strstr

using namespace std;

// Funkcja sprawdzająca, czy dany słowny zapis cyfry występuje w danym fragmencie napisu
int znajdzSlowo(const string& napis, const string& slowo) {
    size_t pozycja = napis.find(slowo);
    return (pozycja != string::npos); // Zwraca true, jeśli słowo zostało znalezione, false w przeciwnym razie
}

int main()
{
    ifstream plik("input.txt");
    if (!plik) // Sprawdź, czy plik został otwarty poprawnie
    {
        cout << "Blad otwarcia pliku.\n" << endl;
        return 1; // NIEPOWODZENIE
    }

    string linia;
    int licznik = 1;
    int wartosci_energetyczne = 0;

    while (getline(plik, linia)) {
        int pierwsza = -1, ostatnia = -1;

        for (size_t i = 0; i < linia.length(); ++i) {
            char znak = linia[i];
            if (isdigit(znak)) {
                if (pierwsza == -1) {
                    pierwsza = znak - '0'; // Konwersja znaku na cyfrę
                }
                ostatnia = znak - '0'; // Zawsze aktualizujemy ostatnią napotkaną cyfrę
            } else if (isalpha(znak)) {
                char slowo[6]; // Maksymalna długość słowa to 5 liter
                for (size_t k = 0; k < 5 && (i + k) < linia.length(); ++k) {
                    slowo[k] = linia[i + k]; // Tworzymy słowo z następnych 5 liter w napisie
                    if(isdigit(slowo[k])) {
                        if(pierwsza == -1) {
                            pierwsza = slowo[k] - '0';
                        }
                    }
                    slowo[k + 1] = '\0'; // Kończymy słowo znakiem null

                    // Przetwarzanie słów
                    if (znajdzSlowo(slowo, "null")) {
                        if(pierwsza == -1) pierwsza = 0;
                        else ostatnia = 0;
                    } else if (znajdzSlowo(slowo, "one")) {
                        if(pierwsza == -1) pierwsza = 1;
                        else ostatnia = 1;
                    } else if (znajdzSlowo(slowo, "two")) {
                        if(pierwsza == -1) pierwsza = 2;
                        else ostatnia = 2;
                    } else if (znajdzSlowo(slowo, "three")) {
                        if(pierwsza == -1) pierwsza = 3;
                        else ostatnia = 3;
                    } else if (znajdzSlowo(slowo, "four")) {
                        if(pierwsza == -1) pierwsza = 4;
                        else ostatnia = 4;
                    } else if (znajdzSlowo(slowo, "five")) {
                        if(pierwsza == -1) pierwsza = 5;
                        else ostatnia = 5;
                    } else if (znajdzSlowo(slowo, "six")) {
                        if(pierwsza == -1) pierwsza = 6;
                        else ostatnia = 6;
                    } else if (znajdzSlowo(slowo, "seven")) {
                        if(pierwsza == -1) pierwsza = 7;
                        else ostatnia = 7;
                    } else if (znajdzSlowo(slowo, "eight")) {
                        if(pierwsza == -1) pierwsza = 8;
                        else ostatnia = 8;
                    } else if (znajdzSlowo(slowo, "nine")) {
                        if(pierwsza == -1) pierwsza = 9;
                        else ostatnia = 9;
                    }
                }
            }
        }

        wartosci_energetyczne += (10*pierwsza) + ostatnia;
        cout << "Linia " << licznik << ":  " << pierwsza << " " << ostatnia << "\t== plik: " << linia << endl;
        licznik++;
    }

    plik.close(); // Zamknij plik po zakończeniu pracy

    cout << "\n\nSuma wartosci energetycznych = " << wartosci_energetyczne << endl;

    return 0;
}
