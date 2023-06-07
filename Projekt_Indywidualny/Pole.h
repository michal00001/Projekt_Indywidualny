#pragma once
#include <iostream>
#include <iomanip>

class Pole
{
private:
	float powierzchnia;
	int stadiumWzrostu;//liczba od 0 do 6
	std::string nazwa;
	bool uprawiono;
	bool nawieziono;
	bool zasiano;
	bool zebrano;

public:
	Pole() :powierzchnia(0.0), stadiumWzrostu(0), nazwa("Basic"), uprawiono(false), nawieziono(false), zasiano(false), zebrano(false) {};

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

	bool operator<(const Pole& _obiekt) const;

	friend std::ostream& operator<<(std::ostream& out,const Pole& obiekt);
};
