#include "Kalendarz.h"
#include "Drukarka.h"
#include "Interfejs.h"

int main(void) {
	//Kalendarz masno;
	//std::unique_ptr<Drukarka> ted = DrukarkaFactory<TerminalDrukarka>::stworzDrukarke();
	///*try {
	//(*ted).drukuj(masno.getlistaZabiegow());
	//}
	//catch (std::domain_error e) {
	//	std::cerr << e.what()<<std::endl;
	//	return -1;
	//}*/
	//try{
	//Data piateczek(31, 12, 2001);
	//}
	//catch (std::out_of_range e) {
	//	std::cerr << e.what() << std::endl;
	//	return - 1;
	//}
	
	Maszyna traktor;
	traktor.setDoNawozenia();
	Pole laka;
	laka.setNazwa("Pole nr 1");
	laka.setPowierzchnia((float)5.76);
	Zabieg nawozenie;
	nawozenie.setData(12,05,2023);
	nawozenie.setMaszyna(&traktor);
	nawozenie.setPole(&laka);
	nawozenie.wykonajZabieg(1);
	nawozenie.wyswietl();
	/*Interfejs program;
	program.MenuGlowne();*/
	return 0;
}