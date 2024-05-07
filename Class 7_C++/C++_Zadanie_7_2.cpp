#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

int main() {
    try {
        ifstream file("input_2.txt");
        if (!file) {
            throw runtime_error("Blad otwarcia pliku."); // Rzuć wyjątek w przypadku niepowodzenia otwarcia pliku
        }

        int sum = 0;
        int min_sum = 0;
        string line;
        int max_red = 12;
        int max_green = 13;
        int max_blue = 14;

        while (getline(file, line)) {
            int flag = 0;

            int min_red = 0;
            int min_green = 0;
            int min_blue = 0;

            char c1 = line[5];
            char c2 = line[6];
            char c3 = line[7];
            int game_number;

            if (isdigit(c3)) {
                game_number = (c1 - '0') * 100 + (c2 - '0') * 10 + (c3 - '0');
            } else if (isdigit(c2)) {
                game_number = (c1 - '0') * 10 + (c2 - '0');
            } else {
                game_number = (c1 - '0');
            }

            int number;
            for (size_t i = 8; i < line.length(); i++) { // Używamy size_t do pętli for

                if (isdigit(line[i])) {
                    if (isdigit(line[i + 1])) {
                        number = (line[i] - '0') * 10 + (line[i + 1] - '0');
                        i++;
                    } else {
                        number = line[i] - '0';
                    }
                }

                if (line.substr(i, 3) == "red") {
                    if (number > max_red) {
                        flag = 1;
                    }
                    if (number > min_red) {
                        min_red = number;
                    }
                }

                if (line.substr(i, 5) == "green") {
                    if (number > max_green) {
                        flag = 1;
                    }
                    if (number > min_green) {
                        min_green = number;
                    }
                }

                if (line.substr(i, 4) == "blue") {
                    if (number > max_blue) {
                        flag = 1;
                    }
                    if (number > min_blue) {
                        min_blue = number;
                    }
                }

            }

            min_sum += (min_red * min_green * min_blue);

            if (flag == 0) {
                sum += game_number;
            }
            cout << "Game " << game_number << ": red: " << min_red << ", green: " << min_green;
            cout << ", blue: " << min_blue << endl;
        }

        file.close();

        cout << "\n\nSuma numerow gier, ktore mozna rozegrac: " << sum << endl;
        cout << "Suma mocy zestawow wymaganych do rozegrania gier: " << min_sum << endl;

    } catch (const exception& e) {
        cerr << e.what() << endl;
        return 1;
    }

        return 0;
}