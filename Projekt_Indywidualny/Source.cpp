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
	
	Interfejs program;
	program.MenuGlowne();
	return 0;
}