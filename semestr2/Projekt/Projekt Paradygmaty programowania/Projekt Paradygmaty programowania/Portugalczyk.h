#pragma once
#include "IOsoba.h"

using namespace std;

class Portugalczyk : public IOsoba{
	void setid() { 
		string id;

		cout << "Podaj id: ";
		cin >> id;

		this->id = "PT: " + id;
	}
};