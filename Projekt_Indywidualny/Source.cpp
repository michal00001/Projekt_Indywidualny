#include "Kalendarz.h"

int main(void) {
	Kalendarz masno;
	char sciezka[] = { "Pliczek.txt" };
	Data zabieg(12, 5, 2020);
	Pole koloDomu;
	Maszyna traktor;
	Zabieg wMaju(zabieg, traktor, koloDomu);
	/*masno.dodajZabieg(wMaju);
	masno.dodajZabieg(wMaju);
	masno.dodajZabieg(wMaju);
	masno.dodajZabieg(wMaju);
	masno.dodajZabieg(wMaju);
	masno.dodajZabieg(wMaju);
	masno.dodajZabieg(wMaju);
	masno.dodajZabieg(wMaju);
	masno.dodajZabieg(wMaju);
	masno.dodajZabieg(wMaju);
	masno.dodajZabieg(wMaju);
	masno.dodajZabieg(wMaju);
	masno.dodajZabieg(wMaju);
	masno.dodajZabieg(wMaju);
	masno.dodajZabieg(wMaju);
	masno.wydrukujKalendarz(sciezka);*/

	masno.dodajZabieg(sciezka);
	masno.wydrukujlistaZabiegow();
	return 0;
}