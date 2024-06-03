#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <thread>
#include <chrono>
#include <random>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace std::chrono;

// Funkcja wypisująca tekst litera po literze
void printLetterByLetter(const std::string& text) {
    for (char ch : text) {
        std::cout << ch << std::flush;
        std::this_thread::sleep_for(chrono::milliseconds(20));
    }
    std::cout << std::endl;
}

// Funkcja przekształcająca napis na wielkie litery i go wyświetlająca
void printUpperCase(const std::string& text) {
    std::string upperText = text;
    std::transform(upperText.begin(), upperText.end(), upperText.begin(), ::toupper);
    std::cout << upperText << std::endl;
}

string toUpper(const std::string& input) {
    std::string result = input;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

// Funkcja przekształcająca napis na wielkie litery i wyświetlająca go na fioletowo
void printUpperCasePurple(const std::string& text) {
    const std::string purple = "\033[35m"; // Kod koloru fioletowego
    const std::string reset = "\033[0m";   // Kod resetujący kolor
    std::string upperText = text;
    std::transform(upperText.begin(), upperText.end(), upperText.begin(), ::toupper);
    std::cout << purple << upperText << reset << std::endl;
}

// Funkcja zatrzymująca grę na określony czas
void sleep(int time_ms) {
    this_thread::sleep_for(chrono::milliseconds(time_ms));
}

// Funkcja do zmiany koloru tekstu na zielony
void printGreen(const string& text) {
    cout << "\033[32m" << text << "\033[0m";
}

// Funkcja do zmiany koloru tekstu na czerwony
void printRed(const string& text) {
    cout << "\033[31m" << text << "\033[0m";
}

// Funkcja do zmiany koloru tekstu na złoty
void printGold(const string& text) {
    cout << "\033[33m" << text << "\033[0m";
}

// Funkcja do zmiany koloru tekstu na fioletowy
void printPurple(const string& text) {
    cout << "\033[35m" << text << "\033[0m";
}

// Funkcja do zmiany koloru tekstu na niebieski
void printBlue(const string& text) {
    cout << "\033[34m" << text << "\033[0m";
}

// Funkcja do zmiany koloru tekstu na jasnoniebieski
void printLightBlue(const string& text) {
    cout << "\033[94m" << text << "\033[0m";
}

// Funkcja czyszcząca konsolę
void clearConsole() {
    // Systemowy sposób na czyszczenie konsoli
    // Na Windows:
    system("cls");
    // Na Unix/Linux/MacOS:
    //system("clear");
}

// Funkcja generująca liczbę całkowitą z zakresu [min, max]
int generateRandomInt(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

int cezar = generateRandomInt(1, 25);

void endEscapes() {
    sleep(3000);
    printRed("\n\nTY TCHORZU!\n");
    printLetterByLetter("Takimi okrzykami obrzucili Cie mieszkancy miasta Pyroklas, gdy po raz kolejny zobaczyli jak uciekasz z miasta z podkulonym ogonem na widok smokow.");
    printLetterByLetter("Ty, ktory miales byc ich ocaleniam...tak haniebnie zawiodles...to juz koniec nadziei o byciu nieustraszonym pogromca smokow. Pyroklas juz wiecej nie da Ci wrocic... A ich los jest raczej przesadzony...");
    printRed("\n\n========================= KONIEC GRY - PORAZKA =========================\n\n");
    printGold("\t\t*********************************************************\n\n");
    sleep(1000);
    printGold("\t\t*\t\tRADZIEK ENTERPRISES PRESENTS\t\t*\n\n");
    sleep(1000);
    printGold("\t\t*\t\t  DRAGON CITY - AWAKENESS  \t\t*\n\n");
    exit(0);
}

void endPuzzleMistakes() {
    sleep(3000);
    printRed("\n\nKOLEJNA POMYLKA!\n");
    printLetterByLetter("Takimi okrzykami obrzucili Cie koledzy, gdy po raz kolejny stracili kolege przez Twoje bledne proby rozwiazania zagadek. Ludzkie zycie to nie zabawa...");
    printLetterByLetter("Ty, ktory miales byc swieza krwia w naszym zespole...to juz koniec nadziei o byciu nieustraszonym pogromca smokow. Pyroklas juz wiecej nie da Ci wrocic... A ich los jest raczej przesadzony...");
    printRed("\n\n========================= KONIEC GRY - PORAZKA =========================\n\n");
    printGold("****************************************************************************\n\n");
    printGold("\t\t*********************************************************\n\n");
    sleep(1000);
    printGold("\t\t*\t\tRADZIEK ENTERPRISES PRESENTS\t\t*\n\n");
    sleep(1000);
    printGold("\t\t*\t\t  DRAGON CITY - AWAKENESS  \t\t*\n\n");
    exit(0);
}

void endRescueMistakes() {
    sleep(3000);
    printRed("\n\nAAAAAACH!\n");
    printRed("[TRACH!] [ŁUBUDUB!]");
    sleep(2000);
    printLetterByLetter("Raz, drugi, trzeci...udalo sie ujsc z zyciem. Ale szczescie kiedys sie konczy. Spadla na Ciebie olbrzymia belka, ktora oderwala sie spod sufitu. Nie miales szans...");
    sleep(1000);
    printLetterByLetter("Ty, ktory miales byc najdzielniejszym z nas...to juz koniec nadziei o byciu nieustraszonym pogromca smokow. Mlody bohater konczy tu swoj zywot... A los Pyroklas jest raczej przesadzony...");
    printRed("\n\n========================= KONIEC GRY - PORAZKA =========================\n\n");
    printGold("\t\t*********************************************************\n\n");
    sleep(1000);
    printGold("\t\t*\t\tRADZIEK ENTERPRISES PRESENTS\t\t*\n\n");
    sleep(1000);
    printGold("\t\t*\t\t  DRAGON CITY - AWAKENESS  \t\t*\n\n");
    exit(0);
}

void endDead() {
    sleep(3000);
    printRed("\n\nAAAAAACH!\n");
    printRed("[GRAAAAU!] [RYYYYYMS!]");
    sleep(2000);
    printLetterByLetter("On...mnie...pokonal... [padasz na kolana, a nastepnie jak dlugi padasz na ziemie i juz wiecej sie nie poruszasz]\n");
    sleep(1000);
    printLetterByLetter("Ty, ktory miales byc najpotezniejszym z nas...to juz koniec nadziei o byciu nieustraszonym pogromca smokow. Mlody bohater konczy tu swoj zywot... A los Pyroklas jest raczej przesadzony...");
    printRed("\n\n========================= KONIEC GRY - PORAZKA =========================\n\n");
    printGold("\t\t*********************************************************\n\n");
    sleep(1000);
    printGold("\t\t*\t\tRADZIEK ENTERPRISES PRESENTS\t\t*\n\n");
    sleep(1000);
    printGold("\t\t*\t\t  DRAGON CITY - AWAKENESS  \t\t*\n\n");
    exit(0);
}

void endWin() {
    sleep(3000);
    printRed("\n\n[GR...GRR]\n");
    printRed("[Aaach...]");
    sleep(2000);
    printLightBlue("NOCNA FURIA: ");
    printLetterByLetter("Skad...miales... tyle sily? To niemozliwe... Ja nie moge umiera..[zadajesz ostateczny cios i dobijasz potwora]\n");
    sleep(1000);
    printLightBlue("MIESZKANCY PYROKLAS: ");
    printLetterByLetter("Czy...to koniec? Wygralismy?\n\n");
    sleep(2000);
    printLetterByLetter("HURRRRRRA! NIECH ZYJE NASZ BOHATER! BRAWO, BRAWO! W KONCU JESTESMY WOLNI!!!\n");
    printLetterByLetter("Ty, ktory miales byc najpotezniejszym z nas...nadzieje o byciu nieustraszonym pogromca smokow okazaly sie ziscic... Trudne czasy rodza zawsze najwiekszych bohaterow. Pyroklas uratowane dzieki Tobie!");
    sleep(3000);
    printLetterByLetter("Czy teraz zapanuje spokoj? \n\n");
    sleep(1000);
    printLetterByLetter("Czas pokaze...");
    printGreen("\n\n========================= KONIEC GRY - ZWYCIESTWO =========================\n\n");
    printGold("\t\t*********************************************************\n\n");
    sleep(1000);
    printGold("\t\t*\t\tRADZIEK ENTERPRISES PRESENTS\t\t*\n\n");
    sleep(1000);
    printGold("\t\t*\t\t  DRAGON CITY - AWAKENESS  \t\t*\n\n");
    exit(0);
}

// Funkcja do kodowania tekstu
string caesarEncrypt(const string& text, int shift) {
    string result = "";
    for (char c : text) {
        if (isupper(c)) {
            result += char(int(c + shift - 65) % 26 + 65);
        }
        else if (islower(c)) {
            result += char(int(c + shift - 97) % 26 + 97);
        }
        else {
            result += c;
        }
    }
    return result;
}

// Funkcja do dekodowania tekstu
string caesarDecrypt(const string& text, int shift) {
    return caesarEncrypt(text, 26 - shift);
}

void generateMathProblem(int lower_bound, int upper_bound, char& operation, int& num1, int& num2, double& correct_answer) {
    num1 = rand() % (upper_bound - lower_bound + 1) + lower_bound;
    num2 = rand() % (upper_bound - lower_bound + 1) + lower_bound;
    int op = rand() % 4;

    switch (op) {
    case 0:
        operation = '+';
        correct_answer = num1 + num2;
        break;
    case 1:
        operation = '-';
        correct_answer = num1 - num2;
        break;
    case 2:
        operation = '*';
        correct_answer = num1 * num2;
        break;
    case 3:
        operation = '/';
        int num3 = num1 * num2;
        correct_answer = num3 / num2;
        break;
    }
}

bool getAnswerWithinTimeLimit(double& player_answer, int time_limit) {
    auto start = steady_clock::now();
    auto end = start + seconds(time_limit);

    while (steady_clock::now() < end) {
        if (cin >> player_answer) {
            return true;
        }
        this_thread::sleep_for(milliseconds(100));
    }
    return false;
}

// Klasa gracza
class Player {
public:
    std::string name;
    int health;
    int max_health;
    int actual_weapon_damage;
    std::vector<std::string> inventory;
    int level;
    int completed_missions;
    int escapes;
    int puzzleMistakes;
    int rescueMistakes;
    void displayStatus();
    void levelUp();
};

// Klasa smoka
class Dragon {
public:
    int id;
    std::string name;
    std::string type;
    int health;
    int firePower;
    double critical_hit_chance;
    void attack(Player& player);
};

void Dragon::attack(Player& player) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> crit_dis(0, 1);
    uniform_real_distribution<> dis(0.7, 1.3);
    double damageMultiplier = dis(gen);

    bool critical_hit = crit_dis(gen) < critical_hit_chance;
    int damage = firePower * damageMultiplier * (critical_hit ? 2 : 1);
    string dragonAttack = name + (critical_hit ? " zadaje cios krytyczny!" : " atakuje cie!");
    dragonAttack += " Sila ognia: " + to_string(damage) + "\n";

    if (critical_hit) {
        printPurple(dragonAttack);
    }
    else {
        printRed(dragonAttack);
    }

    player.health -= damage;
    if (player.health > 0) {
        printLightBlue("Twoje zdrowie: " + to_string(player.health) + "\n\n");
    }
    else {
        printRed("[Achhh...] Twoje zdrowie: " + to_string(player.health) + "\n\n");
    }
}

// Klasa wyposazenia
class Equipment {
public:
    string name;
    string type;
    int level;

    // Funkcja wirtualna do użycia przedmiotu
    virtual void use(Player& player, Dragon& dragon) = 0;
};

// Klasa gaśnicy
class FireExtinguisher : public Equipment {
public:
    void use(Player& player, Dragon& dragon) override {
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<> dis(0.5, 1.5);

        int damage = level * dis(gen);
        cout << "Uzywasz " << name << " i zadajesz " << damage << " obrazen smokowi!\n";
        dragon.health -= damage;
        cout << "Zdrowie smoka: " << dragon.health << "\n\n";
    }
};

// Klasa apteczki
class FirstAidKit : public Equipment {
public:
    void use(Player& player, Dragon& dragon) override {
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<> heal_dis(0.5, 1);
        double healing = player.max_health * heal_dis(rd); // Przykładowa wartość leczenia
        cout << "Uzywasz " << name << " i leczysz " << fixed << setprecision(0) << healing << " punktow zdrowia.\n";
        if (player.health + healing < player.max_health) {
            player.health += healing;
        }
        else {
            player.health = player.max_health;
        }
        printLightBlue("Twoje zdrowie: " + to_string(player.health) + "\n");
    }
};

// Klasa bomby wodnej
class WaterBomb : public Equipment {
public:
    void use(Player& player, Dragon& dragon) override {
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<> dis(0.4, 0.6);

        int damage = dragon.health * dis(gen);
        printGreen("Uzywasz bomby wodnej i zadajesz " + to_string(damage) + " obrazen smokowi!\n");
        dragon.health -= damage;
        printBlue("Zdrowie smoka: " + to_string(dragon.health) + "\n\n");
    }
};

// Klasa łusek pokonanych smoków
class DragonScales : public Equipment {
public:
    void use(Player& player, Dragon& dragon) override {
        cout << "Próbujesz wykorzystać " << name << ", ale nie masz zastosowania w tej sytuacji.\n";
    }
};

// Klasa misji
class Mission {
public:
    int id;
    string type;
    string description;
    string answer;
    bool completed;
    string reward; // Dodane pole przechowujące nagrodę za ukończenie misji
    void startMission(Player& player, const std::string& narrator);
    void execute(Player& player);
};

// Lamiglowki
std::vector<Mission> puzzles = {
    {1, "puzzles", "Mlody, chodz no tu! Otrzymalismy zaszyfrowana wiadomosc ale ni w zab nie jestem w stanie zrozumiec o co w niej chodzi. Podobno ten kod otwiera wszystkie drzwi w Dzielnicy Plomieni, a wlasnie tam sa uwiezieni Borys Rzucweza z Jurkiem Podajwiadrem. Dasz rade to odczytac?\n\n WIADOMOSC: XII, IX, XVIII, XXI", "4375", false, "Apteczka"},
    {2, "puzzles", "Ej swiezak, jestes? Otrzymalismy zaszyfrowana wiadomosc ale ni w zab nie jestem w stanie zrozumiec o co w niej chodzi.Podobno ten kod otwiera wszystkie drzwi na Ulicy Aptecznej. Podobno jest tam troche sprzetu medycznego, wiec warto by bylo tam wejsc. Dasz rade to odczytac? \n\n WIADOMOSC : X, IV, VIII, XXXVI", "2359", false, "Apteczka"},
    {3, "puzzles", "Kurde, widzial ktos mlodego? O, tu jestes! Sluchaj, znowu ktos zamknal moja szafke z drugim sniadaniem... Zostawil tylko jakas karteczke z rzymskimi liczbami ale zupelnie nie rozumiem po co bo te liczby nie pasuja jako kod... Jesli dasz rade mi to otworzyc, to mysle ze bede w stanie Ci sie nalezycie odwdzieczyc. Umieram z glodu... \n\n WIADOMOSC: VIII, II, XI, IX, XVII, I, XXXV, VIII", "52336188", false, "Gasnica doswiadczonego pogromcy"},
    {4, "puzzles", "Sluchaj mlody, slyszalem, ze jestes dobry w lamiglowkach. Chlopaki nadawali Morse'em sygnal jaki sprzet im sie skonczyl ale cos pomieszalem kolejnosc liter. Wiesz moze o jaki przedmiot chodzi? \n\n WIADOMOSC : CAINGSA", "GASNICA", false, "Apteczka"},
    {5, "puzzles", "Chlopakiiiii! O, hej swiezak. Chodz, przydasz sie. Musimy szybko rozszyfrowac czego zabraklo Generalowi Leonardowi w terenie i dostarczyc mu to do Wielkiej Fojerki. Rozumiesz cos z tego? \n\n WIADOMOSC : MYOBB NODEW", "BOMBY WODNE", false, "Apteczka"},
    {6, "puzzles", "M...m...mlody, chodz no zobacz. Zakrwawiona kartka z wiadomoscia...Bartek Chlapochlust oddal zycie zeby ja dostarczyc [SZLOCH]... Niech to nie pojdzie na marne. Musimy to odszyfrowac...cala nadzieja w Tobie, bo ja sie dzis juz nie nadaje do tego\n\n WIADOMOSC : " + caesarEncrypt("W ciemnym lesie, za gorami, drzemie FURIA ze smokami", cezar), to_string(cezar), false, "Apteczka"}
};

// Misje ratunkowe
std::vector<Mission> rescueMissions = {
    {3, "rescue", "ALAAAAARM! Cywil w budynku przy Kajakowej!! Musimy pedzic mu na ratunek! Mlody, wskakuj na pake!",  "", false, "Gasnior 2000"},
    {2, "rescue", "POBUDKAAA! Kazda sekunda jest na wage zlota! Musimy pomoc poszkodowanym, zanim pozar sie rozprzestrzeni! Czy potrafisz utrzymac zimna krew w obliczu niebezpieczenstwa?", "", false, "Bomba wodna"},
    {1, "rescue", "[TRAAAACH] Budynki sie wala!! Musimy ewakuowac mieszkancow zanim zostana pochlonieci przez ziemie i plomienie! Czas na akcje!", "", false, "Apteczka"}
};

// Misje polowan
std::vector<Mission> huntMissions = {
    {1, "hunting", "CO TO ZA HALAS? To chyba jakis smok! Mysle ze to musi byc PAROPLUJELK! Szybko, szybko chlopaki, lapac sie za gasnice! Te, mlody, Ciebie tez sie to tyczy! Nie ma czasu do stracenia", "", false, "Gasnica mlodego pogromcy"},
    {2, "hunting", "Trzeba dzialac szybko! Smoki zblizaja sie do miasta, a my musimy je powstrzymac! BRZYTWOUSTY odlaczyl sie od grupy i leci na polnoc. Mamy tam wielu cywili, ale nie wystarczajaco ludzi zeby byc tu i tam... Mlody, musisz sam z nim zawalczyc! Wierzymy w Ciebie!", "", false, "Apteczka"},
    {3, "hunting", "Czas na polowanie! ZIMNOLUB, smok znany ze swych niebezpiecznych podmuchow lodu, grasuje w okolicy! Musimy go pokonac zanim zniszczy kolejna wioske! Czujesz to? To adrenalina! Ruszajmy!", "", false, "Bomba wodna"},
    {4, "hunting", "Ale sie ciemni... To nie wrozy nic dobrego... Kiedy ostatnio widzialem takie chmury, chwile pozniej pojawil sie... AAAAA TO GROMOTRACH! Chowajcie sie chlopaki! Mlody, lap sie za gasnice i do atakuuuuuuu!", "", false, "Bomba wodna"},
    {5, "hunting", "Wooow... Tez to poczules? Cala siedziba glowna sie trzesie. To na pewno sprawka BULDOZERANA! To najpotezniejszy smok jakiego widziano! Oczywiscie jest tez NOCNA FURIA...ale jej nikt nigdy nie widzial...wowowow, dobra nie ma czasu na gadanie! Trzeba namierzyc BULDOZERANA!", "", false, "Spryskiwacz 3000"},
    {6, "hunting", "Mlody...cala nadzieja w Tobie... [ekhu, ekh] SZCZERBATEK jest legendarnym krolem smokow, nikt nigdy go nie widzial, nikt nie wie jakie ma moce i ile ma sil. Jedyne co wiemy to ze nikt nie przezyl nigdy spotkania z nim...\nAle teraz cala nadzieja w Tobie! Pyroklas na Tobie polega! Nie zawiedz nas!", "", false, "KORONA SMOKOW"}
};

void Mission::startMission(Player& player, const std::string& narrator) {
    cezar = generateRandomInt(1, 25);
    printLightBlue(narrator + ": ");
    printLetterByLetter(description + "\n");
    execute(player);
}

void Mission::execute(Player& player) {
    if (type == "puzzles") {
        bool blad = false;
        int licznik_bledow = 0;
        int maly_licznik = 0; // dla szyfru Cezara
        if (id == 6) {
            printLightBlue("Maro, Twoj buddy: ");
            printLetterByLetter("To mi wyglada na szyfr Cezara. Zmieniasz litery o odpowiednia liczbe np. A -> D (zmiana o 3)\nJak myslisz o ile musimy przesunac?\n");
        }
        do {
            string userAnswer;
            printLetterByLetter("Twoja odpowiedz: ");
            cin >> userAnswer;
            if (id == 6) {
                string wiadomosc = caesarEncrypt("W ciemnym lesie, za gorami, drzemie FURIA ze smokami", stoi(answer));
                printLetterByLetter("Zmieniona wiadomosc : ");
                if (userAnswer == answer) {
                    printGreen(caesarDecrypt(wiadomosc, stoi(userAnswer)) + "\n");
                }
                else {
                    printBlue(caesarDecrypt(wiadomosc, stoi(userAnswer)) + "\n");
                }
            }
            if (userAnswer == answer) {
                if (id < 4) {
                    printGreen("[Trach] Otwarte!\n");
                }
                else
                {
                    printGreen("UDALO SIE!\n");
                }
                printLightBlue("Emerytowany Strazak Bonifacy: ");
                printLetterByLetter("Brawo mlody! Udalo Ci sie! Jestem pod wrazeniem :)\n");
                if (id != 3) {
                    int ile = generateRandomInt(1, 3);
                    for (int i = 1; i <= ile; i++) {
                        player.inventory.push_back(reward); // Dodaj nagrodę do ekwipunku gracza
                    }
                    printGold("[dodano " + toUpper(reward) + " w liczbie " + to_string(ile) + " do ekwipunku]\n");
                }
                else if (id == 3){
                    for (auto it = player.inventory.begin(); it != player.inventory.end(); ++it) {
                        if (*it == "Stara gasnica" || *it == "Gasnica mlodego pogromcy" || *it == "Gasnior 2000" || * it == "Gasnica doswiadczonego pogromcy") {
                            player.inventory.erase(it); // Usuń stara gasnice z ekwipunku
                            break; // Zatrzymaj pętlę po usunieciu przedmiotu
                        }
                    }
                    printLightBlue("Emerytowany Strazak Bonifacy: ");
                    printLetterByLetter("Och...moje sniadanie... za to nalezy Ci sie szczegolna nagroda. Wez moja gasnice. Ja i tak jestem juz za stary do walki ze smokami\n");
                    player.inventory.push_back(reward); // Dodaj nagrodę do ekwipunku gracza
                    printGold("[dodano GASNICE DOSWIADCZONEGO POGROMCY do ekwipunku]\n");
                    player.actual_weapon_damage = 50;
                }
                
                player.completed_missions += 1;
                player.levelUp();
                completed = true;
                blad = false;
            }
            else {
                printLightBlue("Emerytowany Strazak Bonifacy: ");
                if (id < 4) {
                    printLetterByLetter("Cos nie dziala mlody, na pewno dobrze to zrobiles?\n\n");
                }
                else {
                    printLetterByLetter("Nie wyglada to najlepiej mlody, na pewno dobrze to zrobiles?\n\n");
                }
                blad = true;
                if (id != 6) {
                    licznik_bledow++;
                }
                else {
                    maly_licznik++;
                    if (maly_licznik >= 2) {
                        licznik_bledow++;
                        maly_licznik = 0;
                    }
                }
            }
        } while (blad == true && licznik_bledow < 3);
        if (licznik_bledow >= 3) {
            printLightBlue("Emerytowany Strazak Bonifacy: ");
            printLetterByLetter("Kurcze, cos dzisiaj nie idzie Ci najlepiej... Juz za pozno i tak na rozszyfrowanie. Wez sie moze zdrzemnij bo tracimy ludzi przez takie bledy...\n");
            if (++player.puzzleMistakes > 5) {
                endPuzzleMistakes();
            }
        }
    }
    else if (type == "rescue") {
        printLightBlue("General Leonard: ");
        printLetterByLetter("Ratowanie ludzi to akcja, ktora wymaga trzezwego i szybkiego umyslu. Decyzje czesto sa czysto logiczne i racjonalne - nie ma czasu na emocje. Wszystko da sie przedstawic w liczbach, wiec Twoim zadaniem bedzie obliczanie poprawnych wynikow - lacznej masy cywilow, stezenia dymu, czasu do dojazdu na miejsce -> wszystko co ma wplyw na sukces akcji. Liczymy na Ciebie i Twoje szybkie obliczenia!\n");
        srand(static_cast<unsigned int>(time(nullptr)));
        const int total_questions = 4 * id;
        const int time_limit = 15 - 3 * id; // seconds
        const int lower_bound = 1;
        const int upper_bound = 15;
        const double required_accuracy = 0.74;
        int correct_answers = 0;

        for (int i = 0; i < total_questions; ++i) {
            char operation;
            int num1, num2;
            double correct_answer;
            auto start = steady_clock::now();

            generateMathProblem(lower_bound, upper_bound, operation, num1, num2, correct_answer);
            if (operation != '/') {
                cout << "# :" << num1 << " " << operation << " " << num2 << " = ? (Masz " << time_limit << " sekund)" << endl;
                start = steady_clock::now();
            }
            else {
                int num3 = num2 * num1;
                cout << "# :" << num3 << " " << operation << " " << num2 << " = ? (Masz " << time_limit << " sekund)" << endl;
                start = steady_clock::now();
            }

            double player_answer;
            cin >> player_answer;
            auto end = steady_clock::now();
            if (end - start < seconds(time_limit) && abs(player_answer - correct_answer) < 0.0001) {
                printGreen("Cywil uratowany!\n");
                ++correct_answers;
            }
            else {
                printRed("Stracilismy czlowieka! ");
                if (end - start > seconds(time_limit)) {
                    printRed("Zajelo Ci to za duzo czasu!\n");
                }
                else {
                    printRed("Poprawny wynik to ");
                    cout << fixed << setprecision(0) << correct_answer << endl;
                }
            }
        }

        double accuracy = static_cast<double>(correct_answers) / total_questions;
        cout << "Uratowalismy " << correct_answers << " sposrod " << total_questions << " cywili w potrzebie" << endl;
        if (accuracy >= required_accuracy) {
            printLightBlue("General Leonard: ");
            printLetterByLetter("Ekstra mlody! Udalo Ci sie uratowac " + to_string(accuracy * 100) + "% cywili! Swietny wynik! Zasluzyles na nagrode!\n");
            if (id == 3) {
                for (auto it = player.inventory.begin(); it != player.inventory.end(); ++it) {
                    if (*it == "Stara gasnica" || *it == "Gasnica mlodego pogromcy" || *it == "Gasnior 2000") {
                        player.inventory.erase(it); // Usuń stara gasnice z ekwipunku
                        break; // Zatrzymaj pętlę po usunieciu przedmiotu
                    }
                }
                player.inventory.push_back(reward); // Dodaj nagrodę do ekwipunku gracza
                printGold("[dodano GASNIORA 2000 do ekwipunku]\n");
                player.actual_weapon_damage = 40;
            }
            else {
                int ile = generateRandomInt(1, 3);
                for (int i = 1; i <= ile; i++) {
                    player.inventory.push_back(reward); // Dodaj nagrodę do ekwipunku gracza
                }
                printGold("[dodano " + toUpper(reward) + " w liczbie " + to_string(ile) + " do ekwipunku]\n");
            }
            completed = true;
            player.completed_missions++;
            player.levelUp();
        }
        else {
            printLightBlue("General Leonard: ");
            printLetterByLetter("Ehhhhh, ze skutecznoscia ratowania na poziomie " + to_string(accuracy * 100) + "% mozemy sie nie pokazywac w miescie...Jak tak dalej pojdzie, nie bedzie kogo ratowac...\n");
            player.rescueMistakes++;
            if (player.rescueMistakes > 3) {
                endRescueMistakes();
            }
        }
        
    }
}

void battle(Player& player, Dragon& dragon) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.7, 1.3);
    uniform_real_distribution<> crit_dis(0, 1);

    printLetterByLetter("========================== WALKA ==========================");
    printUpperCasePurple("[ " + dragon.name + " ]");
    printBlue("Zdrowie smoka: " + to_string(dragon.health) + "\n");
    printLightBlue("\nTwoje zdrowie: " + to_string(player.health) + "\n\n");
    sleep(1500);

    string action;
    while (player.health > 0 && dragon.health > 0) {
        bool zly_ruch = false;
        printLetterByLetter("Wybierz akcje:\n");
        cout << "(1) Atak gasnica" << endl;
        if (!player.inventory.empty()) {
            cout << "(2) Uzyj bomby wodnej" << endl;
            cout << "(3) Uzyj apteczki" << endl;
        }
        cout << "(0) Ucieczka\n" << endl;
        cin >> action;
        if (action == "1") {
            // Obliczanie obrażeń
            double damageMultiplier = dis(gen);
            int damage = player.actual_weapon_damage * damageMultiplier;

            // Sprawdzenie ciosu krytycznego
            bool critical_hit = crit_dis(gen) < 0.05;
            if (critical_hit) {
                damage *= 2;
                printGold("Zadajesz cios krytyczny!\n");
            }

            printGreen("Atakujesz smoka i zadajesz " + to_string(damage) + " obrazen!\n");
            dragon.health -= damage;
            printBlue("Zdrowie smoka: " + to_string(dragon.health) + "\n\n");
        }
        else if (action == "2") {
            // bomby wodne
            if (!player.inventory.empty()) {
                bool usedWaterBomb = false;
                for (auto it = player.inventory.begin(); it != player.inventory.end(); ++it) {
                    if (*it == "Bomba wodna") {
                        WaterBomb waterBomb;
                        waterBomb.use(player, dragon);
                        player.inventory.erase(it); // Usuń użyty przedmiot z ekwipunku
                        usedWaterBomb = true;
                        break; // Zatrzymaj pętlę po użyciu apteczki
                    }
                }
                if (!usedWaterBomb) {
                    cout << "Brak bomb wodnych w ekwipunku.\n";
                    zly_ruch = true;
                }
            }
            else {
                cout << "Brak bomb wodnych w ekwipunku.\n";
                zly_ruch = true;
            }
        }
        else if (action == "3") {
            // apteczki
            if (player.health < player.max_health) {
                bool usedFirstAidKit = false;
                for (auto it = player.inventory.begin(); it != player.inventory.end(); ++it) {
                    if (*it == "Apteczka") {
                        FirstAidKit firstAidKit;
                        firstAidKit.name = "Apteczka";
                        firstAidKit.type = "healing";
                        firstAidKit.level = 1;
                        firstAidKit.use(player, dragon);
                        player.inventory.erase(it); // Usuń użyty przedmiot z ekwipunku
                        usedFirstAidKit = true;
                        break; // Zatrzymaj pętlę po użyciu apteczki
                    }
                }
                if (!usedFirstAidKit) {
                    cout << "Brak apteczek w ekwipunku.\n";
                    zly_ruch = true;
                }
            } 
            else {
                printLetterByLetter("Masz pelne zdrowie :) Nie ma sensu marnowac apteczek\n");
                zly_ruch = true;
            }
        }
        else if (action == "0") {
            printRed("Uciekasz z walki!\n");
            if (++player.escapes > 2) {
                endEscapes();
            }
            break;
        }
        else {
            cout << "Nieprawidlowa akcja!\n";
            zly_ruch = true;
        }

        // Atak smoka
        if (dragon.health > 0 && zly_ruch == false) {
            dragon.attack(player);
        }
    }

    if (player.health <= 0) {
        endDead();
    }
    else if (dragon.health <= 0) {
        sleep(1000);
        for (auto& mission : huntMissions) {
            if (!mission.completed && mission.reward != "") {
                int ile = 1;
                switch (dragon.id) {
                    case 1: {
                        printLightBlue("Marian - przypadkowy przechodzien: ");
                        printLetterByLetter("Wow...to bylo cos niesamowitego! Widze w tobie wielki potencjal! Moj dziadek kiedys tez byl pogromca smokow...mi sie to juz i tak nie przyda...");
                        printLetterByLetter("Wez, moze Tobie pomoze! Powodzenia " + player.name + "!\n");
                        if (player.actual_weapon_damage < 35) {
                            printGold("[dodano GASNICE MLODEGO POGROMCY do ekwipunku]\n");
                            player.actual_weapon_damage = 35;
                            for (auto it = player.inventory.begin(); it != player.inventory.end(); ++it) {
                                if (*it == "Stara gasnica") {
                                    player.inventory.erase(it); // Usuń stara gasnice z ekwipunku
                                    break; // Zatrzymaj pętlę po użyciu apteczki
                                }
                            }
                        }
                        else {
                            printLightBlue(player.name + ": ");
                            printLetterByLetter("Dziekuje bardzo, mam juz swoja ulubiona gasnice, ale bardzo doceniam ten hojny dar. Moze ktos potrzebuje jej bardziej niz ja ;)");
                            printLightBlue("Marian - przypadkowy przechodzien: ");
                            printLetterByLetter("Och...okej! Powodzenia " + player.name + "!\n");
                        }

                        player.completed_missions += 1;
                        player.levelUp();
                        sleep(2000);

                        break;
                    }
                    case 2: {
                        ile = generateRandomInt(1, 3);
                        printLightBlue("Bozena - stara aptekara: ");
                        printLetterByLetter("Podejdz no tu chlopcze! ");
                        sleep(1000);
                        printLetterByLetter("No, no, calkiem niezle machasz ta gasnica. Ale to nie wszystko. Czasem warto wiedziec kiedy sie wycofac i wyleczyc rany. Szczegolnie skoro przed Toba spotkanie ze Szczerbatkiem...\n");
                        printLightBlue(player.name + ": ");
                        printLetterByLetter("Zaraz, zaraz, z kim?\n");
                        printLightBlue("Bozena - stara aptekara: ");
                        printLetterByLetter("Wez, to Ci pomoze! Powodzenia " + player.name + "!\n");
                        printLetterByLetter("[Bozena znika nagle w klebach dymu, a Ty pograzasz sie we snie i budzisz nastepnego ranka w swoim domu]\n\n");
                        printGold("[dodano APTECZKE w liczbie " + to_string(ile) + " do ekwipunku]\n");

                        player.completed_missions += 1;
                        player.levelUp();
                        sleep(2000);
                        break;
                    }
                    case 3: {
                        ile = generateRandomInt(1, 2);
                        printLightBlue("Michas - maly alchemik: ");
                        printLetterByLetter("Hehehehehe, KABOOOOM! To bylo dobre! Niezla walka, przyznaje, ale zabraklo jej tego...wybuchowego finalu...moge Ci w tym pomoc ;)");
                        printLightBlue(player.name + ": ");
                        printLetterByLetter("Wybuchowego efektu?\n");
                        printLetterByLetter("Nie dopytuj tylko bierz! Aaaaa, zapomnialbym! Nie uzywaj tego w domu huehuehuehueheuhue... Powodzenia " + player.name + "!\n");
                        printGold("[dodano BOMBE WODNA w liczbie " + to_string(ile) + " do ekwipunku]\n");

                        player.completed_missions += 1;
                        player.levelUp();
                        sleep(2000);
                        break;
                    }
                    case 4: {
                        ile = generateRandomInt(2, 4);
                        printLightBlue("Bogdan - strazak zza lasu: ");
                        printLetterByLetter("Hej! Mlody! Calkiem niezle Ci poszlo, przyznaje! Ja tez cos niecos potrafie, ale musze przyznac, ze Tobie mialbym ciezko dorownac. Moze Tobie pierwszemu uda sie odnalezc legowisko Szczerbatka...\n");
                        printLightBlue(player.name + ": ");
                        printLetterByLetter("Kim do cholery jest ten Szczerbatek?!?\n");
                        printLightBlue("Bogdan - strazak zza lasu: ");
                        printLetterByLetter("To Ty nie wiesz? Toz to sam krol smokow! Jedyna NOCNA FURIA jaka przyzyla WIELKI POMOR sprzed 200 lat. Wybijaj dalej jego rodzenstwo, a jestem pewny, ze niedlugo naprzykrzysz mu sie wystarczajaco by go spotkac...obys przezyl by o tym opowiadac. No nic, wez to, moze Ci pomoze! Powodzenia " + player.name + "!\n");
                        printGold("[dodano BOMBE WODNA w liczbie " + to_string(ile) + " do ekwipunku]\n");

                        player.completed_missions += 1;
                        player.levelUp();
                        sleep(2000);
                        break;
                    }
                    case 5: {
                        printLightBlue("Klaudia - niespotykana pieknosc: ");
                        printLetterByLetter("Jeju...to bylo niesamowite...ale to ciagle za malo zebys sobie poradzil ze Szczerbatkiem. Nie moge patrzec jak idziesz na smierc, nie wiedzac co Cie czeka. Musisz isc?");
                        printLightBlue(player.name + ": ");
                        printLetterByLetter("Wiesz, ze tak...\n");
                        printLightBlue("Klaudia - niespotykana pieknosc: ");
                        printLetterByLetter("Wez przynajmniej to... Moze przedluzy Twoje zycie o pare chwil... [SZLOCH] Powodzenia " + player.name + "!\n");
                        printGold("[dodano SPRYSKIWACZ 3000 do ekwipunku]\n");
                        for (auto it = player.inventory.begin(); it != player.inventory.end(); ++it) {
                            if (*it == "Gasnica mlodego pogromcy" || *it == "Gasnior 2000" || * it == "Gasnica doswiadczonego pogromcy") {
                                player.inventory.erase(it); // Usuń stara gasnice z ekwipunku
                                break; // Zatrzymaj pętlę po użyciu apteczki
                            }
                        }
                        player.actual_weapon_damage = 70;

                        player.completed_missions += 1;
                        player.levelUp();
                        sleep(2000);
                        break;
                    }
                    case 6: {
                        printLetterByLetter("[BRZDĘK, BRZdęk, brzdęk, brzd...]\n");
                        sleep(1000);
                        printGold("[dodano KORONE SMOKOW do ekwipunku]\n");
                        player.completed_missions += 1;
                        player.levelUp();
                        sleep(2000);
                        //saveGame();
                        endWin();
                        break;
                    }
                    default: {
                        break;
                    }
                }
                for (int i = 1; i <= ile; i++) {
                    player.inventory.push_back(mission.reward); // Dodaj nagrodę do ekwipunku gracza
                }
                mission.completed = true; // Oznacz misję jako ukończoną
                break; // Przerwij pętlę po dodaniu nagrody do ekwipunku
            }
        }
    }
}

// Klasa lokacji
class Location {
public:
    std::string name;
    std::string description;
};

// Klasa gry
class Game {
public:
    void start();
private:
    Player player;
    std::vector<Dragon> dragons;
    std::vector<Mission> missions;
    std::map<std::string, Location> locations;

    void initializeGame();
    void displayIntro();
    void mainMenu();
    void handleMainMenuInput(const std::string& input);
    void handleGameMenuInput(const std::string& input);
    void gameMenu();
    void saveGame();
    void loadGame();
};

// Implementacja metod klasy gracza
void Player::displayStatus() {
    printLightBlue("Gracz: " + name + "\n");
    printLightBlue("Poziom: " + to_string(level) + "\n");
    printLightBlue("Doswiadczenie: ");
    for (int i = 0; i < completed_missions; i++) {
        printGreen("+++");
    }
    for (int i = completed_missions; i < level; i++) {
        printRed("---");
    }
    cout << endl;
    printLightBlue("Zdrowie: " + to_string(health) + " / " + to_string(max_health) + "\n");
    printLightBlue("Ekwipunek:\n");
    for (const auto& item : inventory) {
        printLetterByLetter("- " + item);
    }
    cout << "\n\n" << endl;
}


void Player::levelUp() {
    int liczba_misji = level;
    if (completed_missions >= liczba_misji) {
        level += 1;
        completed_missions = 0;
        max_health += (15 * level);
        health = max_health;
        printGold("[AWANSOWANO NA POZIOM " + to_string(level) + "]\n");
        printGold("[ZWIEKSZONO MAKSYMALNE ZDROWIE DO " + to_string(max_health) + "]\n");
    }
}

// Implementacja metod klasy gry
void Game::start() {
    initializeGame();
    displayIntro();
    mainMenu();
}

void Game::initializeGame() {
    // Inicjalizacja danych gry (lokacje, smoki, misje)
    Dragon paroplujek = { 1, "Paroplujek", "Fire Dragon", 100, 10, 0.02 };
    dragons.push_back(paroplujek);
    Dragon brzytwousty = { 2, "Brzytwousty", "Steel Dragon", 200, 30, 0.1 };
    dragons.push_back(brzytwousty);
    Dragon zimnolub = { 3, "Zimnolub", "Ice Dragon", 300, 50, 0.05 };
    dragons.push_back(zimnolub);
    Dragon gromotrach = { 4, "Gromotrach", "Electric Dragon", 500, 40, 0.15 };
    dragons.push_back(gromotrach);
    Dragon buldozeran = { 5, "Buldozeran", "Ground Dragon", 650, 75, 0.1 };
    dragons.push_back(buldozeran);
    Dragon szczerbatek = { 6, "Szczerbatek", "Plazma Dragon", 1000, 100, 0.5 }; // zamiast Władcy Żaru
    dragons.push_back(szczerbatek);
}

void Game::displayIntro() {
    string intro = "\t\t*********************************************************\n\n\t\t*\t\tRADZIEK ENTERPRISES PRESENTS\t\t*\n\n\t\t*\t\t  DRAGON CITY - AWAKENESS  \t\t*\n\n";
    printLetterByLetter(intro);
}

void Game::mainMenu() {
    std::string input;
    while (true) {
        std::cout << "\n\nCZAS NA TWOJA PRZYGODE!\n";
        std::cout << "1. Rozpocznij gre\n";
        std::cout << "2. Wczytaj gre\n";
        std::cout << "3. Zakoncz gre\n\n";
        std::cin >> input;
        handleMainMenuInput(input);
    }
}

void Game::handleMainMenuInput(const std::string& input) {
    if (input == "1") {
        printLetterByLetter("Wprowadz swoje imie: ");
        cin >> player.name;

        // startowe właściwości gracza
        player.level = 1;
        player.completed_missions = 0;
        player.health = 100;
        player.max_health = 100;
        player.actual_weapon_damage = 25;
        player.escapes = 0;
        player.puzzleMistakes = 0;
        player.rescueMistakes = 0;
        player.inventory = { "Apteczka", "Stara gasnica" };

        clearConsole(); // Czyszczenie konsoli po wprowadzeniu imienia

        // Opisowe intro gry
        printLetterByLetter("Cisza...\n");
        sleep(1000);
        printLetterByLetter("Spokoj...\n");
        sleep(3000);
        cout << "[TRAAAAACH!]" << endl;
        printLetterByLetter("Miasto smokow, Pyroklas, budzi sie ze snu w naglym rozblysku plomieni i huku zawalonych budynkow!\n");
        printLetterByLetter("Mieszkancow przeszywa strach gdy widza cienie skrzydel i ogonow przesuwajace sie po scianach zabudowan ich domow. Praktycznie stracili juz nadzieje. Codziennie znika kolejna osoba. Codziennie plona kolejne budynki. Nie zaznali spokojnej nocy od...\n");
        sleep(1000);
        printLetterByLetter("No wlasnie. Od kiedy?\n");
        printLetterByLetter("Ale moze pojawila sie wlasnie ostatnia deska ratunku... Do Pyroklas przybyl mlody, ambitny pogromca smokow, " + player.name + ", swiezo po Akademii Ogniochronow. Nikt nie poklada w nim zbyt wielkiej nadziei bo to jednak mlodziak...ale co innego im pozostalo ? \n");
        printLetterByLetter("Czas pokaze jaka bedzie przyszlosc Pyroklas...\n\n\n");
        sleep(3000);

        gameMenu(); // Przejscie do glownego menu gry
    }
    else if (input == "2") {
        loadGame();
    }
    else if (input == "3") {
        printGold("\t\t*********************************************************\n\n");
        sleep(1000);
        printGold("\t\t*\t\tRADZIEK ENTERPRISES PRESENTS\t\t*\n\n");
        sleep(1000);
        printGold("\t\t*\t\t  DRAGON CITY - AWAKENESS  \t\t*\n\n");
        exit(0);
    }
    else {
        printLetterByLetter("Nieprawidlowe polecenie.\n");
    }
}

void Game::gameMenu() {
    std::string input;
    while (true) {
        std::cout << "\nJaki nastepny krok " + player.name + "?\n";
        std::cout << "1. Wyrusz na gaszenie pozarow\n";
        std::cout << "2. Ratowanie cywili\n";
        std::cout << "3. Zapoluj na smoki\n";
        std::cout << "4. Twoj ekwipunek\n";
        std::cout << "5. Uzyj apteczki\n";
        std::cout << "6. Zapisz gre\n";
        std::cout << "7. Zakoncz gre\n";
        std::cin >> input;
        handleGameMenuInput(input);
    }
}

void Game::handleGameMenuInput(const std::string& input) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> puz_dis(0, 5);
    uniform_int_distribution<> res_dis(0, 2);
    uniform_int_distribution<> dis(0, 9);

    int puzzlesType = puz_dis(gen); // Losuje liczby od 0 do 5
    if (puzzlesType == 3) {
        int check = dis(gen);
        if (!(check % 2 == 0)) {
            puzzlesType = puz_dis(gen); // ponowne losowanie żeby zmniejszyć szansę wylosowania opcji nr 3 - z GASNICA DOSWIADCZONEGO POGROMCY
        }
    }
    int rescueType = res_dis(gen);

    if (input == "1") {
        puzzles[puzzlesType].startMission(player, "Emerytowany Strazak Bonifacy");
    }
    else if (input == "2") {
        rescueMissions[rescueType].startMission(player, "General Leonard");
    }
    else if (input == "3") {
        for (int i = 0; i < 6; i++) {
            if (dragons[i].health >= 0) {
                int czy_na_pewno = 1;
                switch (i) {
                    case 0: {
                        if (player.health < 100) {
                            printLightBlue("Maro, Twoj buddy: ");
                            printLetterByLetter("Nie wydaje mi sie, zeby to byl najlepszy pomysl...lepiej jeszcze sie podszkolic i poszukac ekwipunku. Jesli jestes pewny, to Cie nie zatrzymuje, ale pamietaj ze ostrzegalem. \nAby wyruszyc mimo wszystko wcisnij (1)\n");
                            cin >> czy_na_pewno;
                        }
                        break;
                    }
                    case 1: {
                        if (player.health < 175) {
                            printLightBlue("Maro, Twoj buddy: ");
                            printLetterByLetter("Nie wydaje mi sie, zeby to byl najlepszy pomysl...lepiej jeszcze sie podszkolic i poszukac ekwipunku. Jesli jestes pewny, to Cie nie zatrzymuje, ale pamietaj ze ostrzegalem. \nAby wyruszyc mimo wszystko wcisnij (1)\n");
                            cin >> czy_na_pewno;
                        }
                        break;
                    }
                    case 2: {
                        if (player.health < 200) {
                            printLightBlue("Maro, Twoj buddy: ");
                            printLetterByLetter("Nie wydaje mi sie, zeby to byl najlepszy pomysl...lepiej jeszcze sie podszkolic i poszukac ekwipunku. Jesli jestes pewny, to Cie nie zatrzymuje, ale pamietaj ze ostrzegalem. \nAby wyruszyc mimo wszystko wcisnij (1)\n");
                            cin >> czy_na_pewno;
                        }
                        break;
                    }
                    case 3: {
                        if (player.health < 250 || player.actual_weapon_damage < 50) {
                            printLightBlue("Maro, Twoj buddy: ");
                            printLetterByLetter("Nie wydaje mi sie, zeby to byl najlepszy pomysl...lepiej jeszcze sie podszkolic i poszukac ekwipunku. Jesli jestes pewny, to Cie nie zatrzymuje, ale pamietaj ze ostrzegalem. \nAby wyruszyc mimo wszystko wcisnij (1)\n");
                            cin >> czy_na_pewno;
                        }
                        break;
                    }
                    case 4: {
                        if (player.health < 325) {
                            printLightBlue("Maro, Twoj buddy: ");
                            printLetterByLetter("Nie wydaje mi sie, zeby to byl najlepszy pomysl...lepiej jeszcze sie podszkolic i poszukac ekwipunku. Jesli jestes pewny, to Cie nie zatrzymuje, ale pamietaj ze ostrzegalem. \nAby wyruszyc mimo wszystko wcisnij (1)\n");
                            cin >> czy_na_pewno;
                        }
                        break;
                    }
                    case 5: {
                        if (player.health < 400 || player.actual_weapon_damage < 70) {
                            printLightBlue("Maro, Twoj buddy: ");
                            printLetterByLetter("Nie wydaje mi sie, zeby to byl najlepszy pomysl...lepiej jeszcze sie podszkolic i poszukac ekwipunku. Jesli jestes pewny, to Cie nie zatrzymuje, ale pamietaj ze ostrzegalem. \nAby wyruszyc mimo wszystko wcisnij (1)\n");
                            cin >> czy_na_pewno;
                        }
                        break;
                    }
                }
                if (czy_na_pewno == 1) {
                    printPurple(".\n");
                    sleep(500);
                    printPurple(".\n");
                    sleep(500);
                    printPurple(".\n");
                    sleep(500);
                    huntMissions[i].startMission(player, "Leon Zamachowiec");
                    battle(player, dragons[i]);
                }
                else {
                    printLightBlue("Maro, Twoj buddy: ");
                    printLetterByLetter("Dobra decyzja, to nie czas na popisywanie sie :) Jeszcze przyjdzie czas, zeby sie wykazac");
                    sleep(1500);
                }
                break;
            }
        }
    }
    else if (input == "4") {
        player.displayStatus();
    }
    else if (input == "5") {
        if (player.health < player.max_health) {
            bool usedFirstAidKit = false;
            for (auto it = player.inventory.begin(); it != player.inventory.end(); ++it) {
                if (*it == "Apteczka") {
                    FirstAidKit firstAidKit;
                    Dragon dragon;
                    firstAidKit.use(player, dragon);
                    player.inventory.erase(it); // Usuń użyty przedmiot z ekwipunku
                    usedFirstAidKit = true;
                    break; // Zatrzymaj pętlę po użyciu apteczki
                }
            }
            if (!usedFirstAidKit) {
                printLetterByLetter("Brak apteczek w ekwipunku.\n");
            }
        }
        else {
            printLetterByLetter("Masz pelne zdrowie :) Nie ma sensu marnowac apteczek");
        }
    }
    else if (input == "6") {
        saveGame();
    }
    else if (input == "7") {
        clearConsole();
        start();
    }
    else {
        printLetterByLetter("Nieprawidlowe polecenie.\n");
    }
}


void Game::saveGame() {
    std::ofstream saveFile("savegame.txt");
    if (saveFile.is_open()) {
        saveFile << player.name << "\n";
        saveFile << player.level << "\n";
        saveFile << player.health << "\n";
        saveFile << player.max_health << "\n";
        saveFile << player.actual_weapon_damage << "\n";
        saveFile << player.escapes << "\n";
        saveFile << player.puzzleMistakes << "\n";
        saveFile << player.rescueMistakes << "\n";
        for (const auto& item : player.inventory) {
            saveFile << item << "\n";
        }
        saveFile.close();
        printLetterByLetter("Gra zostala zapisana.\n");
    }
    else {
        printLetterByLetter("Nie udalo sie zapisac gry.\n");
    }
}

void Game::loadGame() {
    std::ifstream loadFile("savegame.txt");
    if (loadFile.is_open()) {
        std::getline(loadFile, player.name);
        loadFile >> player.level;
        loadFile >> player.health;
        loadFile >> player.max_health;
        loadFile >> player.actual_weapon_damage;
        loadFile >> player.escapes;
        loadFile >> player.puzzleMistakes;
        loadFile >> player.rescueMistakes;
        std::string item;
        player.inventory.clear();
            //pusta linijka
            string temp;
            std::getline(loadFile, temp);
        while (std::getline(loadFile, item)) {
            player.inventory.push_back(item);
        }
        loadFile.close();
        printLetterByLetter("Gra zostala wczytana.\n");
        gameMenu(); // Przejscie do glownego menu gry po wczytaniu gry
    }
    else {
        printLetterByLetter("Nie udalo sie wczytac gry.\n");
    }
}

// Klasa NPC
class NPC {
public:
    std::string name;
    std::string role;
    std::string dialogue;
    void talk();
};

void NPC::talk() {
    std::cout << name << ": ";
    printLetterByLetter(dialogue);
}

// Glowna funkcja
int main() {
    Game game;
    game.start();
    return 0;
}
