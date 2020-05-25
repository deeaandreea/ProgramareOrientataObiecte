#ifndef CONT_ECONOMII_H
#define CONT_ECONOMII_H

#include "Cont.h"

class Cont_Economii : public virtual Cont {

	int termen; // in numar luni (3, 6 sau 12)
	double rataDobanda; // procent 0-100%
	std::list<double> istoricSold;

public:
    Cont_Economii();
	Cont_Economii(int p_index,
               std::string p_numeClient,
               std::string p_dataDeschidere,
               double p_sold,
               int p_termen,
               double p_rataDobanda);
	~Cont_Economii() { }

	Cont_Economii& operator= (Cont_Economii&);

	const std::string tipCont() const { return CONT_ECONOMII; }

	std::ostream& afiseaza(std::ostream&) const;
	friend std::istream& operator>>(std::istream& in, Cont_Economii& ob);

	double procesareTranzactie(Tranzactie tranz);

	int getTermen() { return termen; }
	double getRataDobanda() { return rataDobanda; }
};

#endif // CONT_ECONOMII_H
