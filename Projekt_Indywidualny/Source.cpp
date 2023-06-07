#include "Kalendarz.h"
#include "Drukarka.h"
int main(void) {
	Kalendarz masno;
	char sciezka[] = { "Pliczek.txt" };
	//Data zabieg(12, 5, 2020);
	Pole koloDomu;
	Maszyna traktor;
	traktor.setDoSiewu();
	traktor.zasiej(koloDomu);
	if (koloDomu.czyZasiano())
		std::cout << "Zasiano\n";
	else
		std::cout << "Nie zasiano\n";

	masno.dodajZabieg(sciezka);
	std::unique_ptr<Drukarka> ted = DrukarkaFactory<TerminalDrukarka>::stworzDrukarke();
	(*ted).drukuj(masno.getlistaZabiegow());

	//Zabieg wMaju(zabieg, traktor, koloDomu);
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

	
	//masno.wydrukujlistaZabiegow();
	return 0;
}