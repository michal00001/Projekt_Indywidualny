#include "Kalendarz.h"

int main(void) {
	Kalendarz masno;
	masno.dodajZabieg();
	/*masno.dodajZabieg();
	masno.dodajZabieg();
	masno.dodajZabieg();*/
	char sciezka[] = { "Pliczek.txt" };
	masno.wydrukujKalendarz();
	return 0;
}