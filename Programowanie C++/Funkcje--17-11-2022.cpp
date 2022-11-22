﻿#include <iostream>
#include <cmath>

using namespace std;

int nieujemna() {
	int n;
	cout << "Wprowadz liczbe n: ";
	cin >> n;
	while (n <= 0) {
		cout << "Liczba musi byc dodatnia" << endl;
		cout << "Wprowadz liczbe n: ";
		cin >> n;
	}
	return n;
}

// ZAD 1
/*  Napisz program, który wczytuje ze standardowego wejścia liczbę całkowitą n i wypisuje na standardowe
	wyjście wartość bezwzględną z n. Do rozwiązania zadania nie używaj funkcji bibliotecznych za wyjątkiem
	operacji wejścia/wyjścia. W programie użyj samodzielnie zaimplementowanej funkcji liczącej wartość
	bezwzględną. 
*/

int bezwzgledna(int n) {
	if (n < 0) {
		n *= -1;
	}
	return n;
}

void zad1() {
	int n;

	cout << "Wpisz liczbe n: ";
	cin >> n;

	cout << "Wartosc bezwzgledna: " << bezwzgledna(n);
}

// ZAD 2
/*  Napisz program, który wczytuje ze standardowego wejścia nieujemną liczbę całkowitą n i wypisuje na
	standardowym wyjściu liczbę n!. W programie użyj samodzielnie zaimplementowanej funkcji liczącej
	wartość silni.
*/

int silnia(int n) {
	int poprzednia = 1;
	int i = 2;
	int wynik = 1;

	if (n == 0 || n == 1) {
		return 1;
	}

	while (i <= n) {
		wynik *= i;
		i++;
	}

	return wynik;
}

void zad2() {
	int n = nieujemna();
	
	printf("%d", silnia(n));
}

// ZAD 3
/*  Napisz program, który wczytuje ze standardowego wejścia nieujemną liczbę całkowitą n (n > 2) i wypisuje
	na standardowym wyjściu największą liczbę k taką, że k dzieli n i k < n. Algorytm wyszukiwania liczby k
	spełniającej powyższe warunki umieść w oddzielnej funkcji.
*/

int najwiekszy_dzielnik(int n) {
	int i = 3;
	int dzielnik = 0;
	while (i < n) {
		if (n % i == 0) {
			dzielnik = i;
		}
		i++;
	}
	return dzielnik;
}

void zad3() {
	int n;
	cout << "Wprowadz liczbe n: ";
	cin >> n;
	while (n <= 2) {
		cout << "Liczba musi byc wieksza od 2" << endl;
		cout << "Wprowadz liczbe n: ";
		cin >> n;
	}

	printf("%d", najwiekszy_dzielnik(n));
}

// ZAD 4
/*  Napisz funkcję, która dostaje jako argument nieujemną liczbę całkowitą n i zwraca jako wartość liczbę 2n	
*/

int potegowanie2(int n) {
	int wynik = 1;
	for (int i = 1; i <= n; i++) {
		wynik *= 2;
	}
	return wynik;
}

void zad4() {
	int n = nieujemna();

	cout << potegowanie2(n);
}

// ZAD 5
/*  Napisz funkcję, która dostaje jako argument liczbę całkowitą n i zwraca jako wartość liczbę 2n.
*/

float ujemne_potegowanie2(int n) {
	n *= -1;
	return 1.0/potegowanie2(n);
}

void zad5() {
	int n = 0;
	printf("Wprowadz n: ");
	scanf_s("%d", &n);

	if (n > 0) {
		printf("Wynik jest rowny: %d", potegowanie2(n));
	}
	else if (n == 0) {
		printf("Wynik jest rowny: 1");
	}
	else {
		printf("Wynik jest rowny: %f", ujemne_potegowanie2(n));
	}
}

// ZAD 6
/*  Napisz funkcję, która dostaje jako argumenty nieujemne liczby całkowite n i m, z których co najmniej jedna
	jest rożna od zera i zwraca jako wartość nm. 
*/

int nieujemna_n() {
	int n;
	cout << "Wprowadz liczbe n: ";
	cin >> n;
	while (n < 0) {
		cout << "Liczba musi byc dodatnia" << endl;
		cout << "Wprowadz liczbe n: ";
		cin >> n;
	}
	return n;
}

int nieujemna_m() {
	int m;
	cout << "Wprowadz liczbe m: ";
	cin >> m;
	while (m < 0) {
		cout << "Liczba musi byc dodatnia" << endl;
		cout << "Wprowadz liczbe m: ";
		cin >> m;
	}
	return m;
}

int potegowanie_nm(int n, int m) {
	int wynik = 0;
	if (n == 0) {
		wynik = 0;
		return wynik;
	} 
	if (m == 0) {
		wynik = 1;
		return wynik;
	}
	wynik = n;
	for (int i = 2; i <= m; i++) {
		wynik *= n;
	}
	return wynik;
}

void zad6() {
	int n = nieujemna_n();
	int m = nieujemna_m();
	while (n == 0 && m == 0) {
		cout << "Jedna liczba musi byc rozna od zera" << endl;
		n = nieujemna_n();
		m = nieujemna_m();
	}

	cout << "Wynik dzialania: " << potegowanie_nm(n, m) << endl;
}

// ZAD 7
/*  Napisz funkcję, która dostaje jako argumenty liczby całkowite n i m, z których co najmniej jedna jest rożna
	od zera i zwraca jako wartość nm.
*/

int potegowanie_nm_zad7(int n, int m) {
	int wynik = 0;
	if (n == 0) {
		wynik = 0;
		return wynik;
	} 
	if (m == 0) {
		wynik = 1;
		return wynik;
	}
	if (n > 0) {
		wynik = n;
		for (int i = 2; i <= m; i++) {
			wynik *= n;
		}
		return wynik;
	}
	if (n < 0) {
		n *= -1;
		wynik = n;
		for (int i = 2; i <= m; i++) {
			wynik *= n;
		}
		return wynik * -1;
	}
}

float potegowanie_nm_zad7_ujemne(int n, int m) {
	float wynik = 0;
	m *= -1;
	if (n == 0) {
		wynik = 0;
		return wynik;
	}
	if (n > 0) {
		wynik = n;
		for (int i = 2; i <= m; i++) {
			wynik *= n;
		}
		return 1.0 / wynik;
	}
	if (n < 0) {
		n *= -1;
		wynik = n;
		for (int i = 2; i <= m; i++) {
			wynik *= n;
		}
		return 1.0 / wynik * -1;
	}
}

void zad7() {
	int n, m;
	cout << "Wprowadz liczbe n: " << endl;
	cin >> n;
	cout << "Wprowadz liczbe m: " << endl;
	cin >> m;
	while (n == 0 && m == 0) {
		cout << "Conajmniej jedna liczba rozna od zera" << endl;
		cout << "Wprowadz liczbe n: " << endl;
		cin >> n;
		cout << "Wprowadz liczbe m: " << endl;
		cin >> m;
	}

	if (m < 0) {
		cout << "Wynik dzialania: " << potegowanie_nm_zad7_ujemne(n, m);
	}
	else {
		cout << "Wynik dzialania: " << potegowanie_nm_zad7(n, m);
	}
}

// ZAD 8
/*  Napisz funkcję, która dostaje jako argumenty liczbę dodatnią n i zwraca jako wartość ⌊√n⌋. Rozwiąż zadanie
	nie wykorzystując funkcji bibliotecznych.
*/

float pierwiastek_bez_biblioteki() {
	float n, est, prev_est = 0;
	float delta = 0.01;

	cout << "Wprowadz liczbe n: ";
	cin >> n;
	while (n <= 0) {
		cout << "Liczba musi byc dodatnia" << endl;
		cout << "Wprowadz liczbe n: ";
		cin >> n;
	}

	est = n / 2.0;
	prev_est = est + 2 * delta;

	while (abs(prev_est - est) > delta) {
		prev_est = est;
		est = (est + n / est) / 2.0;
	}
	return est;
}

void zad8() {
	cout << "Wynik: " << pierwiastek_bez_biblioteki() << endl;
}

// ZAD 9
/*  Napisz funkcję, która dostaje jako argumenty liczbę całkowitą m (m > 1) oraz nieujemną liczbę n i zwraca
	jako wartość ⌊ Ȃ⌋.
	Rozwiąż zadanie nie wykorzystując funkcji bibliotecznych.
*/

// potegi mid w stosunku do liczby m
double m_ilosc_mid(double mid, double m) {
	double wynik = mid;
	for (int i = 1; i < m; i++) {
		wynik *= mid;
	}
	return wynik;
}

// zwrot wartosci calkowitej z roznicy z i poteg mid
double diff(double n, double mid, double m)
{
	if (n > (m_ilosc_mid(mid, m)))
		return (n - (m_ilosc_mid(mid, m)));
	else
		return (m_ilosc_mid(mid, m) - n);
}

double pierwiastek_ntego_stopnia_z_n(double n, double m) {
	// start i koniec dla poszukiwan
	double start = 0, end = n;

	// akceptowalny margines
	double e = 0.0001;

	while (true)
	{
		double mid = (start + end) / 2;
		double error = diff(n, mid, m);

		// jesli nasz wynik ma mniejszy margines od
		// zadeklarowanego wyzej to akceptujemy to jako
		// nasza odpowiedz
		if (error <= e)
			return mid;

		// jesli potegi mid wieksze od n to ustawiamy
		// nowy koniec poszukiwan
		if ((m_ilosc_mid(mid, m)) > n)
			end = mid;

		// jesli potegi mid mniejsze od n to ustawiamy
		// nowy start poszukiwan
		else
			start = mid;
	}
}

void zad9() {
	double n = nieujemna();
	double m;
	cout << "Wprowadz m: ";
	cin >> m;
	
	cout << "Wynik jest rowny: " << pierwiastek_ntego_stopnia_z_n(n, m) << endl;
}

// ZAD 10
/*  Napisz program, który wczytuje ze standardowego wejścia nieujemną liczbę całkowitą n i wypisuje na
	standardowym wyjściu sumę liczb mniejszych od n i zarazem względnie pierwszych z n. Algorytm
	wyliczania sumy podziel na dwie funkcje.
*/

int nwd(int i) {
	int nwd = 0;
	int j = 1;
	while (j < i) {
		if (i % j == 0) {
			nwd = j;
		}
		j++;
	}
	return nwd;
}

int wzglednie_pierwsze_zad10(int n) {
	int i = 2;
	int suma = 0;

	while (i < n) {
		if (nwd(i) == 1) {
			suma = suma + i;
			cout << i << endl;
		}
		i++;
	}
	return suma;
}

void zad10() {
	int n = nieujemna();

	cout << "Suma jest rowna: " << wzglednie_pierwsze_zad10(n);
}

// ZAD 11
/*  Napisz program, który wczytuje ze standardowego wejścia nieujemną liczbę całkowitą n i wypisuje na
	standardowym wyjściu następującą sumę _√0_ + _√1_ + . . . + ⌊√n⌋. Algorytm wyliczania sumy podziel na
	dwie funkcje. 
*/

float suma_pierwiastkow_do_n(int n) {
	float suma = 0;
	for (int i = 0; i <= n; i++) {
		suma += pierwiastek_ntego_stopnia_z_n(i, 2);
	}
	return suma;
}

void zad11() {
	int n = nieujemna();

	cout << "Suma jest rowna: " << suma_pierwiastkow_do_n(n);
}

// ZAD 12
/*  Napisz program, który wczytuje ze standardowego wejścia nieujemne liczby całkowitą n i m (m > 1), i
	wypisuje na standardowym wyjściu następującą sumę _ m√0_ + _ m√1_ + . . . + ⌊ m√n⌋. Algorytm wyliczania
	sumy podziel na dwie funkcje. 
*/

float suma_pierwiastkow_do_n_z_m(int n, int m) {
	float suma = 0;
	for (int i = 0; i <= n; i++) {
		suma += pierwiastek_ntego_stopnia_z_n(i, m);
	}
	return suma;
}

void zad12() {
	int n = nieujemna();
	int m = 0;

	printf("Wprowadz liczbe m: ");
	scanf_s("%d", &m);
	
	while (!(m > 1)) {
		printf("Wprowadzona liczba nie jest wieksza od 1\n");
		printf("Wprowadz liczbe m: ");
		scanf_s("%d", &m);
	}

	printf("Suma pierwiastkow jest rowna: %f", suma_pierwiastkow_do_n_z_m(n, m));
}

// ZAD 13
/*  Napisz funkcję, która dostaje jako argument dodatnią liczbę całkowitą n i wypisuje na standardowym wyjściu
	wszystkie możliwe rozkłady liczby n na sumy dwóch kwadratów dodatnich liczb całkowitych. Rozważ dwa
	przypadki (jeżeli zajdzie taka potrzeba, możesz w rozwiązaniu używać funkcji pomocniczych):
	a. gdy „a2 + b2
	” i „b2 + a2
	” dla a 6= b traktujemy jako dwa równe rozkłady,
	b. gdy „a2 + b2
	” i „b2 + a2
	” traktujemy jako ten sam rozkład i wypisujemy tylko jedne z nich. 
*/

void rozklad_liczby_calkowitej_na_sume_kwadratow(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (((i * i) + (j * j)) == n) {
				printf("%d^2 + %d^2 = %d\n", i, j, n);
			}
		}
	}
	printf("\n");
}

void rozklad_liczby_calkowitej_na_sume_kwadratow_2(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if ((((i * i) + (j * j)) == n) && (i <= j)){
				printf("%d^2 + %d^2 = %d\n", i, j, n);
			}
		}
	}
}

void zad13() {
	int n = nieujemna();

	printf("Przypadek 1: \n");
	rozklad_liczby_calkowitej_na_sume_kwadratow(n);

	printf("Przypadek 2: \n");
	rozklad_liczby_calkowitej_na_sume_kwadratow_2(n);
}

// ZAD 14
/*  Napisz funkcję, która dostaje jako argument dodatnią liczbę całkowitą n i wypisuje na standardowym wyjściu
	wszystkie możliwe rozkłady liczby n na sumy kwadratów dodatnich liczb całkowitych. Rozważ dwa
	przypadki analogiczne do tych z zadania 2.2.13. Jeżeli zajdzie taka potrzeba możesz w rozwiązaniu używać
	funkcji pomocniczych. 
*/

void zad14() {
	int n = nieujemna();


}

// ZAD 15
/*  Napisz funkcję, która dostaje jako argumenty dodatnie liczby całkowite n i m, i wypisuje na standardowym
	wyjściu wszystkie możliwe rozkłady liczby n na sumę dwóch dodatnich liczb całkowitych podniesionych do
	potęgi m. Rozważ dwa przypadki analogiczne do tych z zadania 2.2.13. Jeżeli zajdzie taka potrzeba możesz
	w rozwiązaniu używać funkcji pomocniczych. 
*/

void rozklad_liczby_calkowitej_na_sume_kwadratow_zad15(int n, int m) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (((m_ilosc_mid(i, m)) + (m_ilosc_mid(j, m))) == n) {
				printf("%d^%d + %d^%d = %d\n", i, m, j, m, n);
			}
		}
	}
	printf("\n");
}

void rozklad_liczby_calkowitej_na_sume_kwadratow_2_zad15(int n, int m) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if ((((m_ilosc_mid(i, m)) + (m_ilosc_mid(j, m))) == n) && (i <= j)) {
				printf("%d^%d + %d^%d = %d\n", i, m, j, m, n);
			}
		}
	}
}

void zad15() {
	int n = nieujemna_n();
	int m = nieujemna_m();

	printf("Przypadek 1: \n");
	rozklad_liczby_calkowitej_na_sume_kwadratow_zad15(n, m);

	printf("Przypadek 2: \n");
	rozklad_liczby_calkowitej_na_sume_kwadratow_2_zad15(n, m);
}

int main()
{
	//zad1();
	//zad2();
	//zad3();
	//zad4();
	//zad5();
	//zad6();
	//zad7();
	//zad8();
	//zad9();
	//zad10();
	//zad11();
	//zad12();
	//zad13();
	//zad14(); // nie zrobione :/
	//zad15();
}

