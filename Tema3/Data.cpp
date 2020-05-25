#include "Data.h"
#include <iostream>
#include <chrono>
#include <sstream>
#include <iomanip>

using namespace std::chrono;

Data::Data()
{
    dataStr = setDataCurenta();
}

Data::Data(int p_an, int p_luna, int p_zi)
{
    an = p_an;
    luna = p_luna;
    zi = p_zi;
    dataStr = setDataStr();
}

Data::Data(std::string p_dataStr) {
    dataStr = p_dataStr;
    an = std::stoi(p_dataStr.substr(0,4));
    luna = std::stoi(p_dataStr.substr(5,2));
    zi = std::stoi(p_dataStr.substr(8,2));
}

Data::~Data()
{
    //dtor
}

std::string Data::setDataStr() {
    std::stringstream ss_luna, ss_zi;
    ss_luna << std::setw(2) << std::setfill('0') << std::to_string(luna);
    ss_zi << std::setw(2) << std::setfill('0') << std::to_string(zi);
    std::string dataD = std::to_string(an) + "-" + ss_luna.str() + "-" + ss_zi.str();
    dataStr = dataD;
    return dataD;
}

std::string Data::setDataCurenta() {
    // get data curenta in format yyyy-mm-dd
    auto dataCurenta = system_clock::now();
    time_t tt = system_clock::to_time_t(dataCurenta);
    tm local_tm = *localtime(&tt);

    an = local_tm.tm_year + 1900;
    luna = local_tm.tm_mon + 1;
    zi = local_tm.tm_mday;
    dataStr = setDataStr();

    return dataStr;
}

bool Data::validareFormat() throw(Exceptie) {
	if (an < 1970 || an > 2020)
        throw Exceptie("Anul trebuie sa fie intre 1970 si 2020.");
	if (luna < 1 || luna > 12)
        throw Exceptie("Luna trebuie sa fie intre 1 si 12.");
	if (zi < 1 || zi > 31)
        throw Exceptie("Ziua trebuie sa fie intre 1 si 31.");
    if (dataStr[4] != '-' || dataStr[7] != '-')
        throw Exceptie("Format data invalid");
    return true;
}
