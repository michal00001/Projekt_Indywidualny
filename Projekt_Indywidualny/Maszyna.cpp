#include "Maszyna.h"

std::ostream& operator<<(std::ostream& out,const Maszyna& obiekt) {
	out.fill(' ');
	out<<obiekt.nazwa;
	return out;
}

void Maszyna::setNazwa(std::string _nazwa)
{
	nazwa = _nazwa;
}
