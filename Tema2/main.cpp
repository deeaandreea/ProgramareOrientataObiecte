/*
 * File:   main.cpp
 * Author: Andreea Surdu Bob
 *
 */
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "ArboreBinar.h"

using namespace std;

int main() {
    cout << "Arbore oarecare - Andreea Surdu Bob";

    ifstream fin("input.txt");

    int valoare;
    fin >> valoare;
    cout << valoare << endl;

    ArboreBinar arbore;

    while (fin >> valoare)
    {
        cout << valoare << endl;
        arbore.adauga(valoare);
    }
    cout << endl;
    cout << "Arbore oarecare - end";
    return 0;
}

