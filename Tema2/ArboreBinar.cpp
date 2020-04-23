/*
 * File:   ArboreBinar.cpp
 * Author: andreea
 */
#include "ArboreBinar.h"
#include<iostream>

using namespace std;

ArboreBinar::ArboreBinar() {
    max_copii_per_nod = 2; // arborele binare e limitat la 2 copii per nod (L=stanga, R=dreapta)
}

ArboreBinar::ArboreBinar(const ArboreBinar& orig) {
}

ArboreBinar::~ArboreBinar() {
}

void ArboreBinar::adauga(int info) {
    cout << " input:" << info;

    if (radacina == NULL) {
        radacina = new Nod(info); // creez radacina arborelui (primul nod)
    } else {
        Nod* curent = radacina;
        while (curent != NULL) {
            if (info < curent->info) {
                if (curent->leg[0] != NULL) {
                    curent = curent->leg[0]; // merg spre fiul din stanga
                    cout << " L";
                }
                else {
                    // adaug nod nou ca fiu stanga
                    curent->leg[0] = new Nod(info);
                    curent->nr_copii++;
                    nr_noduri++;
                    cout << " L ";
                    break;
                }
            } else if (info > curent->info) {
                if (curent->leg[1] != NULL) {
                    curent = curent->leg[1];
                    cout << " R";
                } else {
                    // adaug nod nou ca fiu dreapta
                    curent->leg[1] = new Nod(info);
                    curent->nr_copii++;
                    nr_noduri++;
                    cout << " R ";
                    break;
                }
            } else {
                // nu e nevoie sa adauga noul info, el exista deja in nodul curent
                break;
            }
        }
    }
}
