#pragma once
#include "IOsoba.h"

using namespace std;

class Polak : public IOsoba{
public:
	void setid() {
		string id;
		
		cout << "Podaj id: ";
		cin >> id;

		int wagi[10] = { 1,3,7,9,1,3,7,9,1,3 }, suma = 0;

		for (int i = 0; i < 10; i++) suma += (id[i] - '0') * wagi[i];

		if (10 - (to_string(suma).back() - '0') == (id[10] - '0')) {
			this->id = "PL: " + id;

			string dzien = id.substr(4, 2), miesiac = id.substr(2, 2), rok = id.substr(0, 2), prefix;

			if (miesiac[0] == '8' or miesiac[0] == '9') {
				prefix = "18";
				miesiac = to_string(stoi(miesiac) - 80);
			}

			else if (miesiac[0] == '0' or miesiac[0] == '1') 
				prefix = "19";

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

			this->data_urodzenia = dzien + "." + miesiac + "." + prefix + rok;
		}
		else this->id = "B£ÊDNY PESEL";
	}
};