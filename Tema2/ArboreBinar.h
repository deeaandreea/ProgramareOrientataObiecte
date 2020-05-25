/*
 * File:   ArboreBinar.h
 * Author: andreea
 */

#ifndef ARBOREBINAR_H
#define ARBOREBINAR_H

#include "ArboreOarecare.h"

class ArboreBinar: public ArboreOarecare {
    // la arborele binar vom avea prin conventie:
    // in leg[0] subarborele stanga, cu valori mai mici decat cea a nodului curent
    // in leg[1] subarborele dreapta, cu valori mai mari decat cea a nodului curent
    // in caz de egalitate cu elementul curent, nu mai creem nod suplimentar (am putea incrementa un contor de aparitii)
public:
    ArboreBinar();
    ArboreBinar(const ArboreBinar& orig);
    virtual ~ArboreBinar();

public:
    void adauga(int info);

};

#endif /* ARBOREBINAR_H */

