#ifndef DATA_H
#define DATA_H
#include <string>
#include "Exceptie.h"

class Data
{
    int an;
    int luna;
    int zi;
    std::string dataStr;

    std::string setDataStr();
    std::string setDataCurenta();

public:
    Data();
    Data(int p_an, int p_luna, int p_zi);
    Data(std::string p_dataStr);
    virtual ~Data();

    std::string getDataStr() { return dataStr; }
    bool validareFormat() throw(Exceptie);
};

#endif // DATA_H
