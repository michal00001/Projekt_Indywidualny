#include "Data.h"

std::ostream& operator<<(std::ostream& out,const Data& obiekt) {
    out <<std::setw(2)<< obiekt.dzien << ".";
    out.width(2);
    out.fill('0');
    out << obiekt.miesiac << "." << obiekt.rok;
    return out;
}

Data::Data(int _dzien, int _miesiac, int _rok) {
    if (_rok > 1900 && _rok < 2200)
        rok = _rok;
    else
        throw std::out_of_range("Rok jest z poza zakresu <1901,2199>");
    if (_miesiac > 0 && _miesiac < 13)
        miesiac = _miesiac;
    else
        throw std::out_of_range("Miesiac jest z poza zakresu <1,12>");

   int dlugosc = monthLength(miesiac, isLeap(_rok));
   if (_dzien <= dlugosc && _dzien > 0)
       dzien = _dzien;
   else
       throw std::out_of_range("Ten miesiac nie ma tylu dni");
}

bool Data::isLeap(int _rok) {
    static const bool YearIsLeap[] = {
        // 1900 is leap in agreement with Excel's bug
        // 1900 is out of valid date range anyway
        // 1900-1909
        true,false,false,false, true,false,false,false, true,false,
        // 1910-1919
        false,false, true,false,false,false, true,false,false,false,
        // 1920-1929
        true,false,false,false, true,false,false,false, true,false,
        // 1930-1939
        false,false, true,false,false,false, true,false,false,false,
        // 1940-1949
        true,false,false,false, true,false,false,false, true,false,
        // 1950-1959
        false,false, true,false,false,false, true,false,false,false,
        // 1960-1969
        true,false,false,false, true,false,false,false, true,false,
        // 1970-1979
        false,false, true,false,false,false, true,false,false,false,
        // 1980-1989
          true,false,false,false, true,false,false,false, true,false,
        // 1990-1999
        false,false, true,false,false,false, true,false,false,false,
        // 2000-2009
        true,false,false,false, true,false,false,false, true,false,
        // 2010-2019
        false,false, true,false,false,false, true,false,false,false,
        // 2020-2029
        true,false,false,false, true,false,false,false, true,false,
        // 2030-2039
        false,false, true,false,false,false, true,false,false,false,
        // 2040-2049
        true,false,false,false, true,false,false,false, true,false,
        // 2050-2059
        false,false, true,false,false,false, true,false,false,false,
        // 2060-2069
        true,false,false,false, true,false,false,false, true,false,
        // 2070-2079
        false,false, true,false,false,false, true,false,false,false,
        // 2080-2089
        true,false,false,false, true,false,false,false, true,false,
        // 2090-2099
        false,false, true,false,false,false, true,false,false,false,
        // 2100-2109
        false,false,false,false, true,false,false,false, true,false,
        // 2110-2119
        false,false, true,false,false,false, true,false,false,false,
        // 2120-2129
        true,false,false,false, true,false,false,false, true,false,
        // 2130-2139
        false,false, true,false,false,false, true,false,false,false,
        // 2140-2149
        true,false,false,false, true,false,false,false, true,false,
      // 2150-2159
        false,false, true,false,false,false, true,false,false,false,
        // 2160-2169
        true,false,false,false, true,false,false,false, true,false,
        // 2170-2179
        false,false, true,false,false,false, true,false,false,false,
        // 2180-2189
        true,false,false,false, true,false,false,false, true,false,
        // 2190-2199
        false,false, true,false,false,false, true,false,false,false,
        // 2200
        false
    };
    //QL_REQUIRE(y >= 1900 && y <= 2200, "year outside valid range");
    return YearIsLeap[_rok - 1900];
}

int Data::monthLength(int _miesiac, bool leapYear) {
    static const int MonthLength[] = {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };
    static const int MonthLeapLength[] = {
        31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };
    return (leapYear ? MonthLeapLength[_miesiac - 1] : MonthLength[_miesiac - 1]);
}

std::string Data::ktoryMiesiac(int _miesiac)
{
    if (_miesiac > 12 || _miesiac < 1) _miesiac = 1;

    const std::string miesiace[] = { "Styczen","Luty","Marzec","Kwiecien","Maj","Czerwiec","Lipiec","Sierpien","Wrzesien","Pazdziernik","Listopad","Grudzien" };
    return miesiace[_miesiac-1];
}

void Data::setDzien(int _dzien)
{
    int dlugosc = monthLength(miesiac, isLeap(rok));
    if (_dzien <= dlugosc && _dzien > 0)
        dzien = _dzien;
    else
        throw std::out_of_range("Ten miesiac nie ma tylu dni");
}

void Data::setMiesiac(int _miesiac) {
    if (_miesiac > 0 && _miesiac < 13)
        miesiac = _miesiac;
    else
        throw std::out_of_range("Miesiac jest z poza zakresu <1,12>");
}

void Data::setRok(int _rok)
{
    if (_rok > 1900 && _rok < 2200)
        rok = _rok;
    else
       throw std::out_of_range("Rok jest z poza zakresu <1901,2199>");
}


bool Data::operator>(const Data& _obiekt) const {
    if (rok < _obiekt.rok)
        return false;
    if (miesiac < _obiekt.miesiac)
        return false;
    if (dzien < _obiekt.dzien)
        return false;
    return true;
}

bool Data::operator<(const Data& _obiekt) const
{
    if (rok > _obiekt.rok)
        return false;
    if (miesiac > _obiekt.miesiac)
        return false;
    if (dzien > _obiekt.dzien)
        return false;
    return true;
}

bool Data::operator>=(const Data& _obiekt) const
{
    if (*this < _obiekt)
        return false;
    if (*this != _obiekt)
        return false;

    return true;
}

bool Data::operator<=(const Data& _obiekt) const
{
    if (*this >= _obiekt)
        return false;

    return true;
}

bool Data::operator==(const Data& _obiekt) const
{
    if (this->rok != _obiekt.rok)
        return false;
    if (this->miesiac != _obiekt.miesiac)
        return false;
    if (this->dzien != _obiekt.dzien)
        return false;

    return true;
}

bool Data::operator!=(const Data& _obiekt) const
{
    if (*this == _obiekt)
        return false;

    return true;
}