#ifndef TRANZACTIE_H
#define TRANZACTIE_H

#include <string>

const std::string DESCHIDERE = "Deschidere cont";
const std::string DEPUNERE = "Depunere";
const std::string RETRAGERE = "Retragere";
const std::string RETRAGERE2 = "Retragere bancomat alta banca";
const std::string ONLINE = "Plata online";
const double COMISION_TRANZ_ONLINE = 1.5;

class Tranzactie {
    std::string data; // format yyyy-mm-dd
    double suma;
    std::string tipTranzactie;
public:
    Tranzactie(std::string data, double suma, std::string tipTranzactie);
	Tranzactie& operator=(Tranzactie& tranz);

    bool esteDepunere() {return (tipTranzactie == DEPUNERE);}
    double getSuma() {return suma;}
    std::string getData() {return data;}
    std::string getTipTranzactie() { return tipTranzactie; }
};

#endif // TRANZACTIE_H
