/*
 * File:   main.cpp
 * Author: Andreea Surdu Bob
 * Programare orientata obiecte, 2019-2020, an I, sem II - Tema 2
 */
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "ArboreBinar.h"

using namespace std;

int main() {
    cout << "Arbore oarecare - Andreea Surdu Bob" << endl;

    ifstream fin("input.txt");

    int valoare;
    ArboreBinar arbore;

    while (fin >> valoare)
    {
        arbore.adauga(valoare);
        cout << endl;
    }
    arbore.afiseaza();
    //cout << arbore;
    return 0;
}

