#ifndef GESTIONARECONTURI_H
#define GESTIONARECONTURI_H
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <list>
#include "Tranzactie.h"
#include "Cont_Economii.h"
#include "Cont_Curent.h"
#include "Data.h"

template <class T>
class GestionareConturi {

    static int index;
    std::unordered_map<int, std::list<Tranzactie>> conturi; // unordered_map<id_cont, list<operatiuni pe contul id_cont>>

public:
    GestionareConturi();
    ~GestionareConturi();

    GestionareConturi<T> &operator = (const GestionareConturi<T> &a);
    GestionareConturi<T> &operator += (T &elem);

    friend std::ostream & operator<<(std::ostream &os, const GestionareConturi<T> &a);
};

// Specializare pentru tipul Cont_Economii care sa afiseze
// toate conturile de economii care au rata dobanzii la 1 an
template <>
class GestionareConturi<Cont_Economii> {

    static int index;
    std::unordered_map<int, std::list<Tranzactie>> conturi;
    std::unordered_map<int, Cont_Economii> conturiEcon;

public:
    GestionareConturi<Cont_Economii> & operator = (const GestionareConturi<Cont_Economii> & a);
    GestionareConturi<Cont_Economii> & operator += (Cont_Economii & elem) {
        int idx = elem.getIndex();
        std::unordered_map<int, std::list<Tranzactie>>::iterator it;
        it = conturi.find(idx);
        if (it != conturi.end()) {
            // indexul contului exista deja in map
            Cont_Economii* tmp = new Cont_Economii(elem);
            tmp->setIndex(idx);
            std::list<Tranzactie> &tranz = it->second;
            tranz.splice(tranz.end(), elem.getTranzactii());
        } else {
            // cont nou
            idx = GestionareConturi<Cont_Economii>::index++;
            elem.setIndex(idx);
            conturi.insert(std::pair<int, std::list<Tranzactie>>(idx, elem.getTranzactii()));
            Cont_Economii *tmp = new Cont_Economii(elem);
            conturiEcon.insert(std::pair<int, Cont_Economii>(idx, *tmp));
        }
        return (*this);
    }

    friend std::ostream & operator<<(std::ostream & os, const GestionareConturi<Cont_Economii> &a) {
        os << "*** Index cont economii: " << a.index << "\n";

        for (auto it = a.conturi.begin(); it != a.conturi.end(); it++) {
            os << "Contul " << it->first << ", Tranzactii:" << "\n";
            for (auto tranz : it->second) {
                os << "Tranzactia din data " << tranz.getData()
                    << ", Suma: " << tranz.getSuma()
                    << ", Tip tranzactie: " << tranz.getTipTranzactie()
                    << ", " << "\n";
            }
        }
        return os;
    }

    void afisareConturiAnuale() {
        std::cout << "\n*** Conturi Economii care au rata dobanzii la 1 an:\n";
        int contor = 0;
        for (auto it = conturiEcon.begin(); it != conturiEcon.end(); it++) {
            if (it->second.getTermen() == 12) {
                std::cout << "Index " << it->first
                        << ", Client: " << it->second.getNumeClient()
                        << ", Dobanda: " << it->second.getRataDobanda()
                        << "\n";
                contor++;
            }
        }
        if (contor == 0)
            std::cout << "Nu exista";
    }
};
#endif //GESTIONARECONTURI_H
