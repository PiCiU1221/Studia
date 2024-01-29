#pragma once

#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <cmath>

template <typename T>
class DynamicArray {
private:
	int allocatedSize;
	float expansionFactor;

	T* array;

public:
	int currentSize;

	DynamicArray(int initialSize) : array(nullptr), currentSize(0), allocatedSize(initialSize), expansionFactor(2.0) {
		array = new T[allocatedSize];
	}

	// Copy constructor
	DynamicArray(const DynamicArray& other) : currentSize(other.currentSize), allocatedSize(other.allocatedSize), expansionFactor(other.expansionFactor) {
		array = new T[allocatedSize];
		for (int i = 0; i < currentSize; ++i) {
			array[i] = other.array[i];
		}
	}

	// Destructor
	~DynamicArray() {
		delete[] array;
	}

	// (a) dodanie nowego elementu na ko�cu tablicy (argument: dane),

	void add(T value) {
		// There is space available for the new element
		if (allocatedSize > currentSize) {
			array[currentSize] = value;

			currentSize++;
		}
		// No space remaining
		else {
			// Use of ceil here to round up the float value
			//int newSize = allocatedSize * std::ceil(expansionFactor);

			int newSize = static_cast<int>(allocatedSize * expansionFactor);

			T* newArray = new T[newSize];

			for (int i = 0; i < currentSize; i++) {
				newArray[i] = array[i];
			}

			newArray[currentSize] = value;

			delete[] array;
			array = newArray;

			allocatedSize = newSize;

			currentSize++;
		}
	}

	// (b) zwr�cenie danych i-tego elementu tablicy (argument: indeks i ��danego elementu (numeruj�c
	// od zera); wynik: dane i - tego elementu lub niepowodzenie w razie indeksu poza zakresem),

	T get(int index) {
		if (index < 0 || index >= allocatedSize) {
			throw std::out_of_range("Invalid index");
		}

		return array[index];
	}

	// (c) ustawienie (podmiana) danych i-tego elementu tablicy (argument: indeks i ��danego elementu
	// (numeruj�c od zera) oraz nowe dane; wynik: pusty lub niepowodzenie w razie indeksu poza
	// zakresem),

	void set(int index, T value) {
		if (index < 0 || index >= allocatedSize) {
			throw std::out_of_range("Invalid index");
		}

		array[index] = value;
	}

	// (b), (c) Overloaded [] operator

	T& operator[](int index) {
		if (index < 0 || index >= allocatedSize) {
			throw std::out_of_range("Invalid index");
		}

		return array[index];
	}

	// (d) czyszczenie tablicy tj. usuni�cie wszystkich element�w

	void deleteAll() {
		delete[] array;
		array = new T[allocatedSize];
		currentSize = 0;
	}

	// (e) zwr�cenie napisowej reprezentacji tablicy � np. funkcja / metoda to string(...) (format
	// wyniku wg uznania programisty, mo�e zawiera� np.aktualny rozmiar tablicy, aktualny maksymalny rozmiar
	// tablicy, wypis pewnej liczby element�w pocz�tkowych / ko�cowych, opcjonalnie
	// adres tablicy w pami�ci; argumenty: r�wnie� wg uznania programisty � np.liczba element�w
	// do wypisania, wska�nik na funkcj� wypisuj�c� pojedynczy rekord danych).

	std::string to_string(bool displayAll) {
		std::ostringstream os;

		if (currentSize == 0) {
			os << "Array is empty" << std::endl;
		}
		else {
			if (displayAll) {
				for (int i = 0; i < currentSize; i++) {
					os << array[i] << " ";
				}
			}
			else {
				// Display the first 3 elements
				for (int i = 0; i < std::min(3, currentSize); i++) {
					os << array[i] << " ";
				}

				// Display ellipsis if there are more than 6 elements
				if (currentSize > 6) {
					os << "... ";
				}

				// Display the last 3 elements
				for (int i = std::max(currentSize - 3, 3); i < currentSize; i++) {
					os << array[i] << " ";
				}
			}

			os << "\n";
		}

		return os.str();
	}

	// (f) b�belkowe posortowanie tablicy(argument: wska�nik na komparator lub brak argumentu
	// przy za�o�eniu istnienia przeci��onego operatora < lub >); uwaga: sortowanie ma odbywa� si�
	// w miejscu.

	void sort(int (*data_cmp)(T, T)) {
		// If the array size is less than 2
		if (currentSize < 2) {
			return;
		}
		else {
			for (int i = 0; i < currentSize - 1; i++) {
				for (int j = 0; j < currentSize - 1 - i; j++) {
					if (data_cmp(array[j], array[j + 1]) >= 0) {
						T temp = array[j];
						array[j] = array[j + 1];
						array[j + 1] = temp;
					}
				}
			}
			return;
		}
	}
};
