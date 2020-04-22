/*
 * File:   ArboreOarecare.cpp
 * Author: andreea
 */
#include "ArboreOarecare.h"
#include <cstddef>

ArboreOarecare::ArboreOarecare() {
}

ArboreOarecare::ArboreOarecare(const ArboreOarecare& orig) {
}

ArboreOarecare::~ArboreOarecare() {
}


// la arborele binar fiecare nod are doi copii, stanga si dreapta
ArboreOarecare::ArboreOarecare(int p_max_copii_per_nod) {
    max_copii_per_nod = p_max_copii_per_nod;
}

void ArboreOarecare::seteaza_radacina(Nod* p_radacina) {
    nr_noduri = 1;
    radacina = p_radacina;
}

void ArboreOarecare::traverseaza(ModTraversare mod){
    traverseaza(radacina, mod);
    cout << endl;
}

void ArboreOarecare::viziteaza (Nod* nod){
    nod->print(max_copii_per_nod);
}

void ArboreOarecare::traverseaza(Nod* nod, ModTraversare mod){
    if (nod != NULL){
        switch (mod){
            case INORDINE:
                traverseaza((nod->leg)[0], mod);
                viziteaza(nod);
                traverseaza(nod->leg[1], mod);
                break;
            case PREORDINE:
                viziteaza(nod);
                for (int i=0; i < max_copii_per_nod; i++)
                    traverseaza(nod->leg[i], mod);
                break;
            case POSTORDINE:
                for (int i=0; i < max_copii_per_nod; i++)
                    traverseaza(nod->leg[i], mod);
                viziteaza(nod);
                break;
        }
    }
}
