/*
 * File:   ArboreOarecare.h
 * Author: andreea
 */

#ifndef ARBOREOARECARE_H
#define ARBOREOARECARE_H
#include "Arbore.h"
#include "Nod.h"

class ArboreOarecare: public virtual Arbore {
public:
    ArboreOarecare();
    ArboreOarecare(const ArboreOarecare& orig);
    ArboreOarecare(int p_max_copii_per_nod);
    virtual ~ArboreOarecare();
protected:
    Nod* radacina;
    int max_copii_per_nod;

public:
    void seteaza_radacina(Nod* p_radacina);
    void traverseaza(ModTraversare mod);
    void viziteaza (Nod* nod);
    void traverseaza(Nod* nod, ModTraversare mod);
};

#endif /* ARBOREOARECARE_H */

