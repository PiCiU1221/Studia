#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	printf("INST. WARUNKOW I WYBORU\n\n");
	// ZAD 1
	/* Napisz program, kt�ry wczytuje ze standardowego wej�cia liczb� ca�kowit� n i wypisuje na standardowe wyj�cie
	   warto�� bezwzgl�dn� z n.Do rozwi�zania zadania nie u�ywaj funkcji bibliotecznych za wyj�tkiem operacji
	   wej�cia / wyj�cia. */

	/*
	int a;
	scanf_s("%d", &a);
	if (a < 0) {
		a *= -1;
	}
	printf("%d", a);
	*/

	// ZAD 2
	/* Napisz program, kt�ry wczytuje ze standardowego wej�cia dwie liczby ca�kowite i wypisuje na standardowym
	   wyj�ciu wi�ksz� z nich (w przypadku gdy podane liczby s� r�wne, program powinien wypisa� kt�r�kolwiek z
       nich). 
	*/

	/*
	int a, b;
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	if (a >= b) {
		printf("%d", a);
	}
	else {
		printf("%d", b);
	}
	*/

	// ZAD 3
	/* Napisz program, kt�ry wczytuje ze standardowego wej�cia trzy liczby ca�kowite i wypisuje na standardowym
	   wyj�ciu najwi�ksz� z ich warto�ci (pami�taj o przypadku gdy wszystkie podane liczby lub dwie z nich s� r�wne).
	*/

	/*
	int a, b, c;
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	scanf_s("%d", &c);
	if (a >= b) {
		if (a >= c) {
			printf("%d", a);
		}
		else {
			printf("%d", c);
		}
	}
	else {
		if (b >= c) {
			printf("%d", b);
		}
		else {
			printf("%d", c);
		}
	}
	*/

	// ZAD 4
	/* Napisz program, kt�ry wczytuje ze standardowego wej�cia dwie liczby ca�kowite i wypisuje t� o wi�kszej
	   warto�ci bezwzgl�dnej.
	*/

	/*
	int a, b, a1, b1;
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	a1 = a;
	b1 = b;
	if (a < 0) {
		a *= -1;
	}
	if (b < 0) {
		b *= -1;
	}
	if (a >= b) {
		printf("%d", a1);
	}
	else {
		printf("%d", b1);
	}
	*/

	// ZAD 5
	/* Napisz program obliczaj�cy pole tr�jk�ta na podstawie wymiar�w podanych przez u�ytkownika. U�ytkownik
	   powinien mie� mo�liwo�� podania d�ugo�ci podstawy i wysoko�ci lub wszystkich bok�w tr�jk�ta. 
	*/

	/*
	int wybor, a, b, c, h, p;
	float wynik;
	printf("Pole trojkata na podstawie:\n\n1) Dlugosci podstawy i wysokosci.\n2) Dlugosci wszystkich bokow trojkata\n");
	scanf_s("%d", &wybor);
	switch (wybor) {
	case 1:
		printf("\nPodaj dlugosc podstawy: ");
		scanf_s("%d", &a);
		printf("Podaj dlugosci wysokosci: ");
		scanf_s("%d", &h);
		wynik = a * h / 2;
		break;
	case 2:
		printf("\nPodaj dlugosc boku a: ");
		scanf_s("%d", &a);
		printf("Podaj dlugosc boku b: ");
		scanf_s("%d", &b);
		printf("Podaj dlugosc boku c: ");
		scanf_s("%d", &c);
		p = (a + b + c) / 2;
		wynik = sqrt(p * (p - a) * (p - b) * (p - c));
		break;
	}
	printf("\nPole trojkata wynosi: %.2f", wynik);
	*/

	// ZAD 6
	/* Napisz program, kt�ry wczytuje ze standardowego wej�cia wsp�czynniki uk�adu dw�ch r�wna� liniowych z
	   dwoma niewiadomymi i wypisuje na standardowym wyj�ciu rozwi�zanie uk�adu r�wna�. W przypadku
	   niesko�czonej liczby lub braku rozwi�za� program powinien wypisa� na standardowym wyj�ciu odpowiedni�
	   informacj�.
	*/

	/*
	float a1, b1, a2, b2, c1, c2, wg, wx, wy, x, y;
	printf("(a1) * x + (b1) * y = (c1)\n");
	printf("(a2) * x + (b2) * y = (c2)\n\n");
	printf("a1: ");
	scanf_s("%f", &a1);
	printf("b1: ");
	scanf_s("%f", &b1);
	printf("c1: ");
	scanf_s("%f", &c1);
	printf("a2: ");
	scanf_s("%f", &a2);
	printf("b2: ");
	scanf_s("%f", &b2);
	printf("c2: ");
	scanf_s("%f", &c2);

	wg = (a1 * b2) - (b1 * a2);
	wx = (c1 * b2) - (b1 * c2);
	wy = (a1 * c2) - (c1 * a2);

	x = wx / wg;
	y = wy / wg;

	if (isinf(x) || isinf(y)) {
		printf("Uklad sprzeczny, brak rozwiazan");
	}
	else if (isnan(x) || isnan(y)){
		printf("Uklad nieoznaczony, ma nieskonczenie wiele rozwiazan");
	}
	else {
		printf("\nX jest rowne: %2.f\nY jest rowne: %2.f", x, y);
	}
	*/

	// ZAD 7
	/* Napisz program, kt�ry wczytuje ze standardowego wej�cia wsp�czynniki r�wnania kwadratowego z jedn�
	   niewiadom� i wypisuje na standardowym wyj�ciu wszystkie rozwi�zania rzeczywiste tego r�wnania lub
	   odpowiedni� informacj� w przypadku braku rozwi�za�.
	*/

	/*
	float a, b, c, delta, x1, x2;
	printf("(a)x^2 + (b)x + (c) = 0\n\n");
	printf("a: ");
	scanf_s("%f", &a);
	printf("b: ");
	scanf_s("%f", &b);
	printf("c: ");
	scanf_s("%f", &c);

	delta = b * b - (4 * a * c);

	if (delta > 0) {
		x1 = (-b - sqrt(delta)) / (2 * a);
		x2 = (-b + sqrt(delta)) / (2 * a);
		printf("Rownanie ma 2 rozwiazania:\nx1: %2.f  x2: %2.f", x1, x2);
	}
	else if (delta == 0) {
		x1 = -b / (2 * a);
		printf("Rownanie ma 1 rozwiazanie:\nx1: %2.f", x1);
	}
	else {
		printf("Rownanie nie ma rozwiazan");
	}
	*/

	// ZAD 8 
	/* Napisz program, kt�ry w zale�no�ci od wyboru u�ytkownika wczytuje ze standardowego wej�cia wymiary:
	   kwadratu, prostok�ta lub tr�jk�ta i wypisuje na standardowym wyj�ciu pole figury o wczytanych wymiarach.
	*/

	/*
	int wybor;
	float wynik, a, b, c, p;
	printf("Oblicz pole:\n1) Kwadratu\n2) Prostokata\n3) Trojkata\n");
	scanf_s("%d", &wybor);
	switch (wybor) {
	case 1:
		printf("Podaj dlugosc boku a kwadratu: ");
		scanf_s("%f", &a);
		wynik = a * a;
		printf("Pole kwadratu wynosi: %2.f", wynik);
		break;
	case 2:
		printf("Podaj dlugosc boku a prostokata: ");
		scanf_s("%f", &a);
		printf("Podaj dlugosc boku b prostokata: ");
		scanf_s("%f", &b);
		wynik = a * b;
		printf("Pole prostokatu wynosi: %2.f", wynik);
		break;
	case 3:
		printf("Podaj dlugosc boku a trojkata: ");
		scanf_s("%f", &a);
		printf("Podaj dlugosc boku b trojkata: ");
		scanf_s("%f", &b);
		printf("Podaj dlugosc boku c trojkata: ");
		scanf_s("%f", &c);
		p = (a + b + c) / 2;
		wynik = sqrt(p * (p - a) * (p - b) * (p - c));
		printf("Pole trojkata wynosi: %2.f", wynik);
		break;
	}
	*/

	// ZAD 9
	/* Napisz program kalkulator, kt�ry wykonuje wybran� przez u�ytkownika operacj� arytmetyczn� na dw�ch
	   wczytanych liczbach. Program powinien wczytywa� dane ze standardowego wej�cia i wypisywa� wynik na
	   standardowym wyj�ciu.
	*/

	/*
	float a, b, wynik;
	int wybor;
	printf("Kalkulator\n\nPodaj pierwsza liczbe: ");
	scanf_s("%f", &a);
	printf("\n1) Dodawanie\n2) Odejmowanie\n3) Mnozenie\n4) Dzielenie\n");
	scanf_s("%d", &wybor);
	printf("Podaj druga liczbe: ");
	scanf_s("%f", &b);
	switch (wybor) {
	case 1:
		wynik = a + b;
		break;
	case 2:
		wynik = a - b;
		break;
	case 3:
		wynik = a * b;
		break;
	case 4:
		wynik = a / b;
		break;
	}
	printf("\nWynik dzialania: %2.f", wynik);
	*/
}