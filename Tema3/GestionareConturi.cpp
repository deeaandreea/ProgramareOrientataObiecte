#include "GestionareConturi.h"
#include "Cont_Economii.h"
#include "Cont_Curent.h"

template <class T>
int GestionareConturi<T>::index = 0;
int GestionareConturi<Cont_Economii>::index = 0;

template<class T>
GestionareConturi<T>::~GestionareConturi() { }

template<class T>
GestionareConturi<T> &GestionareConturi<T>::operator=(const GestionareConturi<T> & a) {
    this->index = a.index;
    for (int i = 0; i < a.conturi.size(); i++)
        this->conturi[i] = a.conturi[i];
    return *this;
}

template <class T>
GestionareConturi<T> &GestionareConturi<T>::operator += (T &elem) {
    int idx = elem.getIndex();

    std::unordered_map<int, std::list<Tranzactie>>::iterator it;
    it = conturi.find(idx);
    if (it != conturi.end()) {
        // indexul contului exista deja in map
        std::list<Tranzactie> &tranz = it->second;
        tranz.splice(tranz.end(), elem.getTranzactii());
    } else {
        // nu exista, elem este cont nou
        idx = GestionareConturi<T>::index++;
        std::list<Tranzactie> tranz = elem.getTranzactii();
        conturi.insert(std::pair<int, std::list<Tranzactie>>(idx, tranz));
    }
    return (*this);
}

template <>
GestionareConturi<Cont_Curent> &GestionareConturi<Cont_Curent>::operator += (Cont_Curent &elem) {
    int idx = elem.getIndex();

    std::unordered_map<int, std::list<Tranzactie>>::iterator it;
    it = conturi.find(idx);
    if (it != conturi.end()) {
        // indexul contului exista deja in map
        std::list<Tranzactie> &tranz = it->second;
        tranz.splice(tranz.end(), elem.getTranzactii());
    } else {
        // nu exista, elem este cont nou
        idx = GestionareConturi<Cont_Curent>::index++;
        conturi.insert(std::pair<int, std::list<Tranzactie>>(idx, elem.getTranzactii()));
    }
    return (*this);
}

template <class T>
std::ostream &operator<<(std::ostream &os, const GestionareConturi<T> &a){
    os << "Test";

    os << "Index cont: " << a.index << "\n";
    if (a.conturi.size() > 0) {
        os << "Operatiuni:\n";
        for (int i = 0; i < a.conturi.size(); i++) {
//            os << a.conturi[i];
        }
    } else {
        os << "Nu exista operatiuni";
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const GestionareConturi<Cont_Curent> &a){
    os << "Index cont: " << a.index << "\n";
    if (a.conturi.size() > 0) {
        os << a.conturi.size() << " Operatiuni:\n";
    } else {
        os << "Nu exista operatiuni";
    }
    return os;
}
