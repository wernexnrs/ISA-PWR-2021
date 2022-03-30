#include <iostream>
#include <string>

using namespace std;

class cOsoba {
	public:
		string getImie();
		string getnazwisko();
		string getpesel();
		string getdata_urodzenia();

		void setImie(string x) {
			imie = x;
		}

		void setnazwisko(string x) {
			nazwisko = x;
		}

		void setpesel(string x) {
			bool walidacja = false;

			int wagi[10] = {1,3,7,9,1,3,7,9,1,3}, suma = 0;
			
			for (int i = 0; i < 10; i++) suma += (x[i] - '0') * wagi[i];

			if ((10 - (to_string(suma).back() - '0')) == (x[10] - '0')) walidacja = true;

			if (walidacja == true) {
				pesel = x;
				
				string dzien = x.substr(4, 2);
				string miesiac = x.substr(2, 2);
				string rok = x.substr(0, 2);

				string prefix;

				if (miesiac[0] == '8' or miesiac[0] == '9'){
					prefix = "18";
					miesiac = to_string(stoi(miesiac) - 80);
				}
				else if (miesiac[0] == '0' or miesiac[0] == '1') prefix = "19";
				else if (miesiac[0] == '2' or miesiac[0] == '3') {
					prefix = "20";
					miesiac = to_string(stoi(miesiac) - 20);
				}
				else if (miesiac[0] == '4' or miesiac[0] == '5') {
					prefix = "21";
					miesiac = to_string(stoi(miesiac) - 40);
				}
				else if (miesiac[0] == '6' or miesiac[0] == '7') {
					prefix = "22";
					miesiac = to_string(stoi(miesiac) - 60);
				}

				data_urodzenia = dzien + "." + miesiac + "." + prefix + rok;
			}
			else pesel = "Błędny pesel!";	
		}

	private:
		string imie;
		string nazwisko;
		string pesel;
		string data_urodzenia;
};


string cOsoba::getImie() {
	return this->imie;
}

string cOsoba::getnazwisko() {
	return this->nazwisko;
}

string cOsoba::getpesel() {
	return this->pesel;
}

string cOsoba::getdata_urodzenia() {
	return this->data_urodzenia;
}


int main() {
	cOsoba obiekt_klasa;

	obiekt_klasa.setImie("Dawid");
	obiekt_klasa.setnazwisko("Poplawski");
	obiekt_klasa.setpesel("68042113258");

	cout << obiekt_klasa.getImie() << "\n";
	cout << obiekt_klasa.getnazwisko() << "\n";
	cout << obiekt_klasa.getpesel() << "\n";
	cout << obiekt_klasa.getdata_urodzenia() << "\n";

	return 0;
}
