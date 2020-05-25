/*
 * File:   main.cpp
 * Author: Andreea Surdu Bob
 * Programare orientata obiecte, 2019-2020, an I, sem II - Tema 3
 * Problema 8 - Implementarea unei aplicatii care sa permita gestionarea
 * conturilor deschise la banca X
 */
#include <iostream>
#include <list>
#include <unordered_map>
#include <utility>
#include "GestionareConturi.h"
#include "Tranzactie.h"
#include "Cont_Curent.h"
#include "Cont_Economii.h"
#include "Cont_Curent.h"
#include "Exceptie.h"

int main() {

    GestionareConturi<Cont_Economii> gce;
//    GestionareConturi<Cont_Curent> gcc;

    try {
        Cont_Economii ce;
        std::cout << "*** Completati date Cont Economii:\n";
        std::cin >> ce;
        gce += ce;
        std::cout << "\n*** Verificati Cont Economii:\n";
        std::cout << ce;
        std::cout << "\n";

        Cont_Economii ce2;
        std::cout << "*** Completati date Cont Economii:\n";
        std::cin >> ce2;
        gce += ce2;
        std::cout << "\n*** Verificati Cont Economii:\n";
        std::cout << ce2;
        std::cout << "\n";

        Cont_Curent cc;
        std::cout << "*** Completati date Cont Curent:\n";
        std::cin >> cc;
//        gcc += cc;
        std::cout << "\n*** Verificati Cont Curent:\n";
        std::cout << cc;
        std::cout << "\n";

        std::cout << gce << "\n";
        gce.afisareConturiAnuale();

    } catch (std::invalid_argument& ei) {
        std::cout << "Format invalid" << "\n";
    } catch (Exceptie& e) {
       std::cout << e.getMessage() << "\n";
    }

    return 0;
}
