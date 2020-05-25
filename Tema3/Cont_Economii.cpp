#include "Cont_Economii.h"
#include <iostream>
#include "Exceptie.h"

Cont_Economii::Cont_Economii() : termen(3), rataDobanda(0) {
    index = -1;
}

Cont_Economii::Cont_Economii(int p_index,
                             std::string p_numeClient,
                             std::string p_dataDeschidere,
                             double p_sold,
                             int p_termen,
                             double p_rataDobanda):
                                 Cont(p_index, p_numeClient, p_dataDeschidere, p_sold), termen(p_termen),
                                 rataDobanda(p_rataDobanda) {
}

Cont_Economii& Cont_Economii::operator=(Cont_Economii& other)
{
	this->Cont::operator=(other);
	this->termen = other.termen;

	return (*this);
}

std::ostream& Cont_Economii::afiseaza(std::ostream& out) const
{
	this->Cont::afiseaza(out);
	out << "Termen (luni): " << this->termen << '\n';
	out << "Rata dobanzii: " << this->rataDobanda << '\n';
	out << "Istoric sold: " << '\n';
	for (const auto it = istoricSold.begin(); it != istoricSold.end(); it)
        out << "Sold: " << *it << '\n';
	return out;
}

std::istream& operator>>(std::istream& in, Cont_Economii& ob) {
	in >> (Cont&)ob;
	std::cout << "Termen (luni): "; in >> ob.termen;
	if (ob.termen != 3 && ob.termen != 6 && ob.termen != 12)
        throw(Exceptie("Termenul contului de economii poate fi 3, 6 sau 12 luni."));
	std::cout << "Rata dobanzii (%): "; in >> ob.rataDobanda;
	if (ob.rataDobanda < 0 || ob.rataDobanda > 100)
        throw(Exceptie("Rata dobanzii trebuie sa fie inte 0-100%."));
	return in;
}

double Cont_Economii::procesareTranzactie(Tranzactie tranz) {
    double soldCurent = Cont::procesareTranzactie(tranz);

    std::list<double>::iterator it = istoricSold.end();
    istoricSold.insert(it, soldCurent);

    return soldCurent;
}
