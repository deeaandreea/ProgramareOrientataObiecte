/*
 * File:   Nod.h
 * Author: andreea
 */

#ifndef NOD_H
#define NOD_H

using namespace std;

typedef enum {
    PREORDINE,
    INORDINE,
    POSTORDINE
} ModTraversare;

class Nod {
public:
    int info;
    int nr_copii;
    Nod* leg[10]; // vector de 10 pointeri catre nodurile-fiu

    void print() const;
//    void print(ostream& out) const; // error: 'ostream' has not been declared
//    friend ostream& operator<<(ostream& os, const Nod& nod);

public:
    // constructor vid
    Nod();
    // constructor de copiere
    Nod(const Nod& orig);
    // constructor cu parametrul info (informatia din nod, creeaza un nod fara copii)
    Nod(int p_info);
    // destructor
    virtual ~Nod();
};

#endif /* NOD_H */
