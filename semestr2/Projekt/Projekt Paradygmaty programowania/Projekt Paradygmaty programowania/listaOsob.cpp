#include "listaOsob.h"
#include "Fabryka.h"

int zliczanie = 0;

int listaOsob::dodajOsobe() {
	Fabryka fabryka;
	string imie, nazwisko, id;
	int narodowosc;

	cout << "Podaj narodowoœæ (PL- 1, PT-2): ";
	cin >> narodowosc;

	for (int i = 0; i < zliczanie; i++) {
		if (tab[i]->getid().substr(4, tab[i]->getid().length() - 4) == id) return 1;
	}

	//if (wielkosc pointera >= zliczanie) nei ma miejsca

	tab[zliczanie] = fabryka.stworzOsobe(narodowosc);

	tab[zliczanie]->setimie();
	tab[zliczanie]->setnazwisko();
	tab[zliczanie]->setid();

	zliczanie++;

	return 0;
}

void listaOsob::wyswietlListe() {
	for (int i = 0; i < zliczanie; i++) {
		cout << "| " << tab[i]->getid()				 << " | " 
					 << tab[i]->getdata_urodzenia()  << " | " 
					 << tab[i]->getimie()			 << " | " 
					 << tab[i]->getnazwisko()		 << " | " 
					 << tab[i]->getdata_obecnosci()  << " | " 
					 << tab[i]->getobecnosc()		 << " | \n";
	}
}

int listaOsob::listaObecnosci(string pesel, string kiedy, bool czyObecny) {

	int d = 0, m = 0, r = 0;

	if (kiedy.length() == 10) {
		if (kiedy[2] == '.' and kiedy[5] == '.') {
			string dzien = kiedy.substr(0, 2);
			string miesiac = kiedy.substr(3, 2);
			string rok = kiedy.substr(6, 4);

			d = stoi(dzien);
			m = stoi(miesiac);
			r = stoi(rok);

			if (m <= 12 and m > 0) {

				if (m == 2) {
					if (d > 29 or d < 1) return 2;
				}
				else if (m <= 7) {
					if (m % 2 == 0) {
						if (d > 30 or d < 1) return 2;
					}
					else {
						if (d > 31 or d < 1) return 2;
					}
				}
				else {
					if (m % 2 != 0) {
						if (d > 30 or d < 1) return 2;
					}
					else {
						if (d > 31 or d < 1) return 2;
					}
				}

			}
		}

		auto tp = system_clock::now();
		auto dp = floor<days>(tp);
		year_month_day ymd{ dp };

		auto y_now = static_cast<int>(ymd.year());
		auto m_now = static_cast<unsigned>(ymd.month());
		auto d_now = static_cast<unsigned>(ymd.day());

		//SPRAWDZAÆ CZY DATA NIE JEST DAT¥ PRZYSZ£¥!

		//SPRAWDZAÆ CZY obecnosc nie jest ustawiona. Jak? bool zawsze ma jak¹œ wartoœæ. Obecnoœæ z góry jest ustawiona na 0. 

		for (int i = 0; i < zliczanie; i++) {
			if (tab[i]->getid().substr(4, tab[i]->getid().length() - 4) == pesel) {
				tab[i]->setdata_obecnosci(kiedy);
				tab[i]->setobecnosc(czyObecny);
			}
			else return 3;
		}
	}
	return 0;
}

void listaOsob::wyswietlObecnosc(string pesel, string kiedy) {
	for (int i = 0; i < zliczanie; i++) {
		if (tab[i]->getid().substr(4, tab[i]->getid().length() - 4) == pesel and tab[i]->getdata_obecnosci() == kiedy)
			cout << tab[i]->getobecnosc();
	}
}