#include "listaOsob.h"

int main() {
	listaOsob lista;

	int wybor = 0;

	while (wybor != 5) {

		cout << "\n\n||||| MENU |||||\n" <<
			"1. Wy�wietl list� obecno�ci\n" <<
			"2. Dodaj osob� do listy obecno�ci\n" <<
			"3. Wy�wietl obecno�� danego ucznia\n" <<
			"4. Dodaj obecnosc\n" <<
			"5. Wyjd�\n\n";

		cin >> wybor;

		switch (wybor) {
		case 1:
			lista.wyswietlListe();
			break;
		case 2:
			lista.dodajOsobe();
			break;
		case 3:

			break;
		case 4:
			string a,b;
			int c;
			cout << "Podaj id: \n";
			cin >> a;
			cout << "Podaj date [dd.mm.rrrr]: \n";
			cin >> b;
			cout << "Obecny - 1, nieobecny - 2: \n";
			cin >> c;
			lista.listaObecnosci(a,b,c);
			break;
		}
	}

}