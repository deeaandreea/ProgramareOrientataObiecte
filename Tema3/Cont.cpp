#include "Cont.h"
#include <list>
#include <iostream>
#include "Exceptie.h"
#include "Tranzactie.h"
#include "Data.h"

Cont::Cont(int p_index,
           std::string p_numeClient,
           std::string p_dataDeschidere,
           double p_sold) :
               index(p_index), numeClient(p_numeClient), dataDeschidere(p_dataDeschidere), sold(p_sold) {

    std::list<Tranzactie> lstTranz;
    Data dataCurenta;
    Tranzactie t(dataCurenta.getDataStr(), 0.0, DESCHIDERE);
    procesareTranzactie(t);
}

Cont& Cont::operator=(Cont& c)
{
	this->numeClient = c.numeClient;
	this->dataDeschidere = c.dataDeschidere;
	this->sold = c.sold;
	this->index = c.index;

	return (*this);
}

std::ostream& Cont::afiseaza(std::ostream& out) const {
	out << "Tip: " << this->tipCont() << '\n';
	out << "Index: " << this->index << '\n';
	out << "Client: " << this->numeClient << '\n';
	out << "Data deschidere: " << this->dataDeschidere << '\n';
	out << "Sold: " << this->sold << '\n';
	return out;
}

std::istream& operator>>(std::istream& in, Cont& ob) {
	std::cout << "Nume client: ";
	std::cin.get();
	getline(in, ob.numeClient);
	std::cout << "Data deschidere (format yyyy-mm-dd): ";
	getline(in, ob.dataDeschidere);
	Data dataDeschidere(ob.dataDeschidere);
	dataDeschidere.validareFormat();
	std::cout << "Sold (lei): ";
	in >> ob.sold;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Cont& ob) {
	return ob.afiseaza(out);
}

double Cont::procesareTranzactie(Tranzactie tranz) {
    std::list<Tranzactie>::iterator it = tranzactii.end();
    tranzactii.insert(it, tranz);

    if (tranz.esteDepunere())
        sold += tranz.getSuma();
    else
        sold -= tranz.getSuma();

    return sold;
}
