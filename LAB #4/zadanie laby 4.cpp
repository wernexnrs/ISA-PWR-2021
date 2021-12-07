#include <iostream>
#include <string>

using namespace std;

void wyswietlanie(char *tab, int rozmiar) {
	for (int i = 0; i < rozmiar; i++) cout << tab[i];
}

int liczba_znakow(char* tab, int rozmiar) {
	int count = 0;
	for (int i = 0; i < rozmiar; i++) if (tab[i] != ' ') count += 1;
	return count;
}

void zamiana_wielkosci(char *tab, int rozmiar) {
	for (int i = 0; i < rozmiar; i++) {
		if ((int)tab[i] >= 65 && (int)tab[i] <= 90) tab[i] = (char)((int)tab[i] + 32);
		else if ((int)tab[i] >= 97 && (int)tab[i] <= 122) tab[i] = (char)((int)tab[i] - 32);
	}
	cout << tab;
}

void histogram(char* tab, int rozmiar) {
	int  k{ 0 }, count = 0, i = 0, j = 0;


	while (tab[i]){
		if ((int)tab[i] >= 65 && (int)tab[i] <= 90) tab[i] = (char)((int)tab[i] + 32);
		if (((int)tab[i] >= 65 && (int)tab[i] <= 90) || ((int)tab[i] >= 97 && (int)tab[i] <= 122)) tab[j++] = tab[i];
		i++;
	}

	tab[j] = '\0';

	rozmiar = j;

	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar - i - 1; j++) {
			if (tab[j] > tab[j + 1]) {
				k = tab[j + 1];
				tab[j + 1] = tab[j];
				tab[j] = k;
			}
		}

	}

	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			if (tab[i] == tab[j]) count += 1;
		}
		cout << tab[i] << " ";
		for (int g = 0; g < count; g++) cout << "#";
		cout << endl;
		count = 0;
	}
	cout << tab;
}

void add(char *& tab, char znak, int *rozmiar, int *pojemnosc) {
	if (*rozmiar == *pojemnosc-1) {
		*pojemnosc *= 2;
		char* newArr = new char[*pojemnosc]();

		memcpy(newArr, tab, *rozmiar * sizeof(char));

		delete[] tab;
		tab = newArr;
	}
	tab[*rozmiar] = znak;
	*rozmiar += 1;
}

void remove(char *& tab, int index, int* rozmiar) {
	for (int i = index-1; i < *rozmiar; i++) tab[i] = tab[i+1];
	*rozmiar -= 1;
	tab[*rozmiar] = 0;
}

void trzecie() {
	int rozmiar = 0, index = 0;
	int* rozmiar_wsk = &rozmiar;

	int pojemnosc = 4;
	int* pojemnosc_wsk = &pojemnosc;

	char* tab= new char[pojemnosc]();

	char znak;
	int wybor = 0;

	while (wybor != 3) {
		
		cout << "\n||| MENU |||\n" <<
			"1. Dodaj na koniec\n" <<
			"2. Usun pozycje\n" <<
			"3. Wyjdz\n" <<
			"\nWybor: ";

		cin >> wybor;

		switch (wybor) {
			case 1:
				cout << "Podaj znak: ";
				cin >> znak;
				add(tab, znak, rozmiar_wsk, pojemnosc_wsk);
				cout << "\nIlosc elementow: " << rozmiar << endl;
				cout << "Pojemnosc: " << pojemnosc << endl;
				cout << "Tablica: " << tab << endl;
				break;

			case 2:
				cout << "Tablica przed usunieciem: " << tab << endl;
				cout << "Podaj pozycje znaku: ";
				cin >> index;
				remove(tab, index, rozmiar_wsk);
				cout << "\nTablica po usunieciu: " << tab << endl;
				cout << "\nIlosc elementow: " << rozmiar << endl;
				break;
		}
	}
}

int main() {
	int wyb = 0;

	while (wyb != 6) {
		cout << "\n\n||| MENU |||\n" <<
			"1. Wyswietlanie tekstu\n" <<
			"2. Liczba znakow\n" <<
			"3. Zmiana wielkosci liter\n" <<
			"4. Histogram\n" <<
			"5. Tablice dynamiczne\n" <<
			"6. Wyjdz\n" <<
			"\nWybor: ";
		cin >> wyb;
		cin.ignore();

		if (wyb != 5) {
			string tekst;
			cout << "Podaj tekst ze znakami: ";
			getline(cin, tekst);

			int rozmiar = tekst.length();
			char* tab = new char[rozmiar + 1];

			for (int i = 0; i < rozmiar; i++) tab[i] = tekst[i];

			tab[rozmiar] = 0;

			switch (wyb) {
			case 1:
				wyswietlanie(tab, rozmiar);
				break;

			case 2:
				cout << liczba_znakow(tab, rozmiar);
				break;

			case 3:
				zamiana_wielkosci(tab, rozmiar);
				break;

			case 4:
				histogram(tab, rozmiar);
				break;

			}
			delete[] tab;
		}
		else trzecie();
	}
	return 0;
}