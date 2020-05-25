#include "Cont_Curent.h"
#include <list>
#include <iostream>

int Cont_Curent::nrTranzactiiEfectuate = 0;

Cont_Curent::Cont_Curent() : nrTranzactiiGratuite(10) { }

Cont_Curent::Cont_Curent(int p_index,
                         std::string p_numeClient,
                         std::string p_dataDeschidere,
                         double p_sold,
                         int p_nrTranzactiiGratuite):
                             Cont(p_index, p_numeClient, p_dataDeschidere, p_sold),
                             nrTranzactiiGratuite(p_nrTranzactiiGratuite) {
}

Cont_Curent& Cont_Curent::operator=(Cont_Curent& other)
{
	this->Cont::operator=(other);
	this->nrTranzactiiGratuite = other.nrTranzactiiGratuite;
	this->nrTranzactiiEfectuate = other.nrTranzactiiEfectuate;

	return (*this);
}

std::ostream& Cont_Curent::afiseaza(std::ostream& out) const
{
	this->Cont::afiseaza(out);
	out << "Numar tranzactii gratuite: " << this->nrTranzactiiGratuite << "\n";
	out << "Numar tranzactii efectuate: " << this->nrTranzactiiEfectuate << "\n";

	return out;
}

std::istream& operator>>(std::istream& in, Cont_Curent& ob) {
	in >> (Cont&)ob;
	std::cout << "Numar tranzactii gratuite: ";
	in >> ob.nrTranzactiiGratuite;
	return in;
}

double Cont_Curent::procesareTranzactie(Tranzactie tranz) {
    double soldCurent = Cont::procesareTranzactie(tranz);
    nrTranzactiiEfectuate++;
    return soldCurent;
}
