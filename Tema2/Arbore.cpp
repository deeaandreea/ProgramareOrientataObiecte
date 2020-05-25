/*
 * File:   Arbore.cpp
 * Author: andreea
 */

#include "Arbore.h"

// constructor vid
Arbore::Arbore() {
    nr_noduri = 0; // arbore vid, fara nici un nod
}

Arbore::Arbore(const Arbore& orig) {
}

Arbore::~Arbore() {
}

int Arbore::getNr_noduri() {
    return nr_noduri;
}
