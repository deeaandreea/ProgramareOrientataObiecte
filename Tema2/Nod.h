/*
 * File:   Nod.h
 * Author: andreea
 */

#ifndef NOD_H
#define NOD_H

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

public:
    Nod();
    Nod(const Nod& orig);
    // constructor cu parametrul info (informatia din nod, creeaza un nod fara copii)
    Nod(int p_info);
    virtual ~Nod();

    void print(int limita_copii);
};

#endif /* NOD_H */

