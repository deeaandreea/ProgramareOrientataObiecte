/*
 * File:   Nod.cpp
 * Author: andreea
 */
#include <iostream>
#include "Nod.h"

using namespace std;

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

// listeaza continutul uni nod: informatie si copii (NULL daca nu sunt copii)
void Nod::print(int limita_copii) {
    std::cout << " [" << info << "](";
    for (int i=0; i<limita_copii; i++)
        if (leg[i] != NULL)
            cout << " " << leg[i] -> info;
        else
            cout << " N";
    cout << ")";
}
