#ifndef EXCEPTIE_H
#define EXCEPTIE_H
#include <exception>
#include <string>

class Exceptie : public std::exception {
    std::string mesaj;
public:
	Exceptie(std::string p_mesaj);
	~Exceptie() noexcept {}

	std::string getMessage() {return mesaj;}
};

#endif // EXCEPTIE_H
