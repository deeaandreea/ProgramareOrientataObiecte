#ifndef CONT_H
#define CONT_H

#include <string>
#include <list>
#include "Tranzactie.h"

const std::string CONT_CURENT = "Cont Curent";
const std::string CONT_ECONOMII = "Cont Economii";

class Cont {

protected:
	int index;
	std::string numeClient;
	std::string dataDeschidere; // format yyyy-mm-dd
	double sold;

	std::list<Tranzactie> tranzactii; // istoric tranzactii cont

	Cont(int index = 0,
      std::string numeClient = "Test",
      std::string dataDeschidere="2020-01-01",
      double sold = 0.0);
	Cont& operator=(Cont& c);

	friend std::istream& operator>>(std::istream& in, Cont& ob);
	friend std::ostream& operator<<(std::ostream& out, const Cont& ob);
public:
	virtual ~Cont() { }

	virtual std::ostream& afiseaza(std::ostream&) const;

	virtual const std::string tipCont() const = 0;
	virtual double procesareTranzactie(Tranzactie tranz);

	void setIndex(int p_index) { this->index = p_index; }
	int getIndex() { return index; }
	void setNumeClient(std::string p_numeClient) { this->numeClient = p_numeClient; }
	std::string getNumeClient() { return numeClient; }
	void setDataDeschidere(std::string p_dataDeschidere) { this->dataDeschidere = p_dataDeschidere; }
	void setSold(double p_sold) { this->sold = p_sold; }
	std::list<Tranzactie> getTranzactii() { return tranzactii; }
};

#endif // CONT_H
