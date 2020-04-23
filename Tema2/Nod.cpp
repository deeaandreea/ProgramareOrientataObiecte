/*
 * File:   Nod.cpp
 * Author: andreea
 */
#include <iostream>
#include "Nod.h"

Nod::Nod() {
}

Nod::Nod(const Nod& orig) {
}

Nod::Nod(int p_info) {
    info = p_info;
    nr_copii = 0;
    for (int i=0; i<10; i++)
        leg[i] = NULL;
}

Nod::~Nod() {
}

void Nod::print() const {
    cout << info << " ";
}
/*
// listeaza continutul uni nod: informatie si copii (NULL daca nu sunt copii)
void Nod::print(ostream& out) const {
    out << " [" << info << "] (";
    for (int i=0; i<nr_copii; i++)
        if (leg[i] != NULL)
            out << " " << leg[i] -> info;
        else
            out << " N";
    out << ") ";
}

ostream& operator<<(ostream& os, const Nod& nod) {
    print(os);
    return os;
}
*/
