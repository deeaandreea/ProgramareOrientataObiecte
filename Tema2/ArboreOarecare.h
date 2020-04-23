/*
 * File:   ArboreOarecare.h
 * Author: andreea
 */

#ifndef ARBOREOARECARE_H
#define ARBOREOARECARE_H
#include "Arbore.h"
#include "Nod.h"
#include <iomanip>

using namespace std;

class ArboreOarecare: public virtual Arbore {
public:
    ArboreOarecare();
    ArboreOarecare(const ArboreOarecare& orig);
    ArboreOarecare(int p_max_copii_per_nod);
    virtual ~ArboreOarecare();

    friend ostream& operator<<(ostream& os, const ArboreOarecare& arb);

protected:
    Nod* radacina;
    int max_copii_per_nod;

public:
    void seteaza_radacina(Nod* p_radacina);
    void viziteaza (Nod* nod);
    void viziteaza (Nod* nod, ostream& out) const;
    void traverseaza(Nod* nod, ModTraversare mod);
    void traverseaza(Nod* nod, ModTraversare mod, ostream& out) const;
    void afiseaza();
};

#endif /* ARBOREOARECARE_H */

