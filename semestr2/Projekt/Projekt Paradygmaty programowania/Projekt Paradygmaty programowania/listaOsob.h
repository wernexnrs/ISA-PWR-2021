#pragma once
#include "IOsoba.h"
#include "Portugalczyk.h"
#include "Polak.h"
#include <chrono>

using namespace std::chrono;

class listaOsob
{
public:
	int dodajOsobe();                                                       //Zwraca 0 - wszystko jest okej. DZIA£A
																			//Zwraca 1 - osoba ju¿ istnieje. DZIA£A
																			//Zwraca 2 - nie ma miejsca na liœcie.

	void wyswietlListe();													//Zwraca nic. DZIA£A XD

	int listaObecnosci(string pesel, string kiedy, bool czyObecny);         //Zwraca 0 - wszystko posz³o pomyœlnie. DZIA£A XD
																			//Zwraca 1 - Obecnoœæ jest ju¿ ustawiona. DO przemyslenia
																			//Zwraca 2 - B³êdna data. DZIA£A, oprócz dat przysz³ych
																			//Zwraca 3 - Osoby nie ma na liœcie. DZIA£A

	void wyswietlObecnosc(string pesel, string kiedy);						//Zwraca nic. DZIA£A

private:
	IOsoba* tab[10];
};

