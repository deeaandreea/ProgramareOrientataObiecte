/*
 * File:   ArboreOarecare.cpp
 * Author: andreea
 */
#include "ArboreOarecare.h"
#include <iostream>

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

void ArboreOarecare::viziteaza (Nod* nod) {
    nod->print();
}

void ArboreOarecare::viziteaza (Nod* nod, ostream& out) const {
    out << nod;
}

void ArboreOarecare::traverseaza(Nod* nod, ModTraversare mod) {
    if (nod != NULL){
        switch (mod){
            case INORDINE:
                traverseaza(nod->leg[0], mod);
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
    } else {
        cout << "nod null";
    }
}

void ArboreOarecare::traverseaza(Nod* nod, ModTraversare mod, ostream& out) const {
    if (nod != NULL){
        switch (mod){
            case INORDINE:
                traverseaza(nod->leg[0], mod, out);
                viziteaza(nod, out);
                traverseaza(nod->leg[1], mod, out);
                break;
            case PREORDINE:
                viziteaza(nod, out);
                for (int i=0; i < max_copii_per_nod; i++)
                    traverseaza(nod->leg[i], mod, out);
                break;
            case POSTORDINE:
                for (int i=0; i < max_copii_per_nod; i++)
                    traverseaza(nod->leg[i], mod, out);
                viziteaza(nod, out);
                break;
        }
    }
}

void ArboreOarecare::afiseaza() {
    cout << "Traversare Inordine: ";
    traverseaza(radacina, INORDINE);
    cout << endl;
    cout << "Traversare Preordine: ";
    traverseaza(radacina, PREORDINE);
    cout << endl;
    cout << "Traversare Postordine: ";
    traverseaza(radacina, POSTORDINE);
    cout << endl;
}

ostream& operator<<(ostream& out, const ArboreOarecare& arb) {
    out << "Traversare Inordine: ";
    arb.traverseaza(arb.radacina, INORDINE, out);
    out << "\n";
    out << "Traversare Preordine: ";
    arb.traverseaza(arb.radacina, PREORDINE, out);
    out << "\n";
    out << "Traversare Postordine: ";
    arb.traverseaza(arb.radacina, POSTORDINE, out);
    out << "\n";
    return out;
}
