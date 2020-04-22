/*
 * File:   Arbore.h
 * Author: andreea
*/

#ifndef ARBORE_H
#define ARBORE_H

class Arbore {
public:
    Arbore();
    Arbore(const Arbore& orig);
    virtual ~Arbore();

protected:
    int nr_noduri;

public:
    int getNr_noduri();

};

#endif /* ARBORE_H */

