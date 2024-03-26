#include <stdio.h>

typedef struct {
    int x;
    int y;
}Point;

typedef struct {
    Point *x1;
    Point *x2;
    Point *x3;
    Point *x4;
}Rectangle;

Point zmien(Point* w) // funkcja do zmiany wartości współrzędnych punktu
{
    (*w).x += 1;
    (*w).y -= 1;

    return *w;
}

int pole(Rectangle r)
{
    int a = (*r.x2).x - (*r.x4).x; // długości boków
    int b = (*r.x3).y - (*r.x2).y;

    return a*b;
}

int obwod(Rectangle r)
{
    int a = (*r.x2).x - (*r.x4).x; // długości boków
    int b = (*r.x3).y - (*r.x2).y;

    return 2*a + 2*b;
}

int main()
{
    Point p = { 3,7 };
    printf("Wspolrzedne p przed zmiana: {%d ; %d}\n", p.x, p.y);
    zmien(&p);     //zmiana wartości współrzędnych punktu p
    printf("Wspolrzedne p przed zmiana: {%d ; %d}\n", p.x, p.y);
    printf("\n");
    Point x1 = { 2,3 }, x2 = { 4,3 }, x3 = { 4,7 }, x4 = { 2,7 }; // definiowanie punktów do stworzenia prostokąta
    Rectangle r = { &x1, &x2, &x3, &x4 };
    printf("Pole prostokata = %d cm^2\n", pole(r));
    printf("Obwod prostokata = %d cm\n", obwod(r));

    return 0;
}
