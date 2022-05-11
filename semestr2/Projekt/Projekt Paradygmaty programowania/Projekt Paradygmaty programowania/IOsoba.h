#pragma once
#include <iostream>
#include <string>

using namespace std;

class IOsoba{

	friend class Portugalczyk;
	friend class Polak;
	friend class listaOsob;

public:
	string getimie();
	string getnazwisko();
	string getid();
	string getdata_urodzenia();
	bool getobecnosc();
	string getdata_obecnosci();

	virtual void setid() = 0;

	void setnazwisko() {
		cout << "Podaj nazwisko: ";
		cin >> nazwisko;
	}

	void setimie() {
		cout << "Podaj imiê: ";
		cin >> imie;
	}

	void setobecnosc(bool czy) { obecnosc = czy; }

	void setdata_obecnosci(string kiedy) { data_obecnosci = kiedy; }

private:
	string imie = "BRAK";
	string nazwisko = "BRAK";
	string id;
	string data_urodzenia = "BRAK";
	bool obecnosc = false;
	string data_obecnosci = "BRAK";
};