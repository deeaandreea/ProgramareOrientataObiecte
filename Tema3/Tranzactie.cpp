#include "Tranzactie.h"

Tranzactie::Tranzactie(std::string p_data, double p_suma, std::string p_tipTranzactie) {
    data = p_data;
    suma = p_suma;
    tipTranzactie = p_tipTranzactie;
}

Tranzactie& Tranzactie::operator=(Tranzactie& other)
{
	this->data = other.data;
	this->suma = other.suma;
	this->tipTranzactie = other.tipTranzactie;

	return (*this);
}
