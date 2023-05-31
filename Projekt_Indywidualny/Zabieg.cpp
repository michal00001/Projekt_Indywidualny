#include "Zabieg.h"

//std::string Zabieg::getData()
//{
//	std::string out;
//	out = data.getDzien();
//	out += " ";
//	out += data.getMiesiac();
//	out += " ";
//	out += data.getRok();
//	return out;
//}

std::string Zabieg::getMaszyna()
{
	return maszyna.getNazwa();
}

std::string Zabieg::getPole()
{
	std::string out;
	out = pole.getNazwa();
	out += " ";
	out += pole.getPowierzchnia();

	return out;
}

//void Zabieg::setData(int _dzien,int _miesiac, int _rok)
//{
//	data.setDzien(_dzien);
//	data.setMiesiac(_miesiac);
//	data.setRok(_rok);
//}

void Zabieg::setMaszyna(std::string _nazwa)
{
	maszyna.setNazwa(_nazwa);
}

void Zabieg::setPole(float _powierzchnia, std::string _nazwa, int _klasa)
{
	pole.setPowierzchnia(_powierzchnia);
	pole.setNazwa(_nazwa);
	pole.setKlasa(_klasa);
}
