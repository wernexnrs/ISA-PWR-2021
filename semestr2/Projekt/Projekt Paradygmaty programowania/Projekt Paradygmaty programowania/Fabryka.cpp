#include "Fabryka.h"
#include "Polak.h"
#include "Portugalczyk.h"

IOsoba* Fabryka::stworzOsobe(int narodowosc) {
	switch (narodowosc){
		case 1:
			return new Polak;
			break;
		case 2:
			return new Portugalczyk;
			break;
	}
}
