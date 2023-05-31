#pragma once
#include <string>

class Pole
{
private:
	float powierzchnia;
	int klasa;
	std::string nazwa;
public:
	Pole() :powierzchnia(0.0), klasa(1) {};
	std::string getNazwa() { return nazwa; };
	int getKlasa() { return klasa; };
	float getPowierzchnia() { return powierzchnia; };

	void setNazwa(std::string _nazwa);
	void setKlasa(int _klasa);
	void setPowierzchnia(float _powierzchnia);
};

