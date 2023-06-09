#pragma once
#include <iostream>

class Pole
{
private:
	std::string nazwa;
	float powierzchnia;
	int stadiumWzrostu;//liczba od 0 do 7
	bool uprawiono;
	bool nawieziono;
	bool zasiano;
	bool zebrano;

public:
	Pole() :powierzchnia(0.0), stadiumWzrostu(0), nazwa("Basic"), uprawiono(false), nawieziono(false), zasiano(false), zebrano(false) {};
	Pole(std::string _nazwa, float powierzchnia);

	std::string const getNazwa() { return nazwa; };
	int const getstadiumWzrostu() { return stadiumWzrostu; };
	float const getPowierzchnia() { return powierzchnia; };

	bool const czyNawieziono() { return nawieziono; };
	bool const czyUprawiono() { return uprawiono; };
	bool const czyZasiano() { return zasiano; } ;
	bool const czyZebrano() { return zebrano; } ;

	void setNazwa(std::string _nazwa);
	void setstadiumWzrostu(int _stadiumWzrostu);
	void setPowierzchnia(float _powierzchnia);

	void setUprawiono(bool _stan);
	void setNawieziono (bool _stan);
	void setZasiano (bool _stan);
	void setZebrano (bool _stan);

	void wyzerujStanPola();

	bool operator<(const Pole& _obiekt) const;
	bool operator==(const Pole& _obiekt) const;
	
};
