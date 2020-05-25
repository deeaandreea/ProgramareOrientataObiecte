#ifndef CONT_CURENT_H
#define CONT_CURENT_H

#include "Cont.h"
#include <vector>

class Cont_Curent: public virtual Cont {

	int nrTranzactiiGratuite;
	static int nrTranzactiiEfectuate;

public:
    Cont_Curent();
	Cont_Curent(int p_index,
             std::string p_numeClient,
             std::string p_dataDeschidere,
             double p_sold,
             int p_nrTranzactiiGratuite);
	~Cont_Curent() { }

	Cont_Curent& operator=(Cont_Curent&);

	const std::string tipCont() const { return CONT_CURENT; }

	std::ostream& afiseaza(std::ostream&) const;
	friend std::istream& operator>>(std::istream& in, Cont_Curent& ob);

	double procesareTranzactie(Tranzactie tranz);
};

#endif // CONT_CURENT_H
