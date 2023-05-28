#pragma once
#include "Data.h"
#include "Maszyna.h"
#include "Pole.h"

std::ofstream& operator<<(std::ofstream& out, Zabieg& obiekt) {
		out << obiekt.getData() << obiekt.getMaszyna()<< obiekt.getPole() << std::endl;
		return out;
	}

class Zabieg
{
private:
	Data data;
	Maszyna maszyna;
	Pole pole;
public:
	std::string getData();
	std::string getMaszyna();
	std::string getPole();
};

