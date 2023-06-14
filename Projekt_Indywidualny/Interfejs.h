#pragma once
#include "Kalendarz.h"
#include "Gospodarstwo.h"
#include "Drukarka.h"

class Interfejs
{
	Kalendarz KalendarzZabiegow;
	Gospodarstwo Gospodarstwo;
public:
	void MenuGlowne();
	void OpcjaKalendarzZabiegow();
	void OpcjaZapisanePola();
	void OpcjaZapisaneMaszyny();
	void OpcjaDodaj();
	void OpcjaUsun();
	void OpcjaEdytuj();
	void OpcjaWczytajKalendarz();
};

