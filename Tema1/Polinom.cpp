//-----------------------------------------------------------------------------
//
// Clasa Polinom
//
// Autor: Andreea Surdu-Bob
// Programare orientata obiecte, 2019-2020, an I, sem II - Tema 1
// 
// Polinomul este reprezentat ca tablou unidimensional (prin gradul polinomului
// si vectorul coeficientilor (coeficientii vor apartine la monoame de grade consecutive),
// de dimensiune egala cu gradul suma 1, de la cel al termenului liber la cel de grad maxim.
//   - fiecare coeficient va fi de tip double;
//   - membri privati pentru vectorul propriuzis si numarul de elemente;
//   - constructori pentru initializare si copiere;
//   - destructor (în cazul alocarii statice, se seteaza dimensiunea vectorului la zero;
//   - metoda publica pentru calculul valorii unui polinom intr-un punct;
//   - suma a doua polinoame, implementata prin supraincarcarea operatorului +;
//   - diferenta a doua polinoame, implementata prin supraincarcarea operatorului -;
//   - produsul a doua polinoame, implementat prin supraincarcarea operatorului *;
//------------------------------------------------------------------------------

#include <iostream>
using namespace std;

class Polinom
{
// Definire membri privati pentru vectorul propriuzis si numarul de elemente
   int grad;			// gradul polinomului
   double * coef;	// vectorul coeficientilor (de tip double), alocat dinamic
   // coef[0] - termenul liber (x^0)
   // coef[1] - x^1
   // ...
   // coef[n] - x^n

// Definire functii membru publice
public:
   // Constructor fara parametri
   Polinom();
   // Constructor de initializare
   Polinom(int g);
   // Constructor de initializare
   Polinom(int g, double* c);
   // Constructor de copiere
   Polinom(const Polinom& p);
   // Destructor
   ~Polinom();
   
   // Metoda publica pentru calculul valorii unui polinom intr-un punct x
   double calcul_valoare(int x);
   
   // Suma a doua polinoame, implementata prin supraincarcarea operatorului +
   Polinom operator+(const Polinom& p);
   // Diferenta a doua polinoame, implementata prin supraincarcarea operatorului -
   Polinom operator-(const Polinom& p);
   // Produsul a doua polinoame, implementat prin supraincarcarea operatorului *
   Polinom operator*(const Polinom& p);
   
   int get_grad();
   void set_grad(int g);
   void afisare(const char* nume);
};

// Constructor de initializare
Polinom::Polinom()
{
    grad = 0;
    coef = new double(1); // doar termen liber
    coef[0] = 0;
}


// Constructor de initializare - se populeaza toti coeficientii cu 0
Polinom::Polinom(int g)
{
    coef = new double(g + 1); // alocam pentru coeficienti g+1 elemente, incluzand si termenul liber
    for (int i = 0; i <= g; i++)
    {
        coef[i] = 0;
    }
    grad = g;
}

// Constructor de initializare
Polinom::Polinom(int g, double* c)
{
    coef = new double(g + 1); // alocam pentru coeficienti g+1 elemente, incluzand si termenul liber 
    for (int i = 0; i <= g; i++)
    {
        coef[i] = c[i];
    }
    grad = g;
}

// Constructor de copiere
Polinom::Polinom(const Polinom& p)
{
    coef = new double(p.grad + 1); // alocam pentru coeficienti g+1 elemente, incluzand si termenul liber 
    for (int i = 0; i <= p.grad; i++)
    {
        coef[i] = p.coef[i];
    }
    grad = p.grad;
}

// Destructor
Polinom::~Polinom()
{
    grad = 0;
}
   
// Metoda publica pentru calculul valorii unui polinom intr-un punct x
double Polinom::calcul_valoare(int x)
{
    double val = 0;
    for (int i = grad; i >= 0; i--)
        val = coef[i] + (x * val);
    return val;
}

// Suma a doua polinoame, implementata prin supraincarcarea operatorului +
Polinom Polinom::operator+(const Polinom& p)
{
    int grad_rez = max(grad, p.grad);
    Polinom sum(grad_rez);
    for (int i = 0; i <= grad; i++)
        sum.coef[i] = coef[i];
    for (int i = 0; i <= p.grad; i++ )
        sum.coef[i] += p.coef[i];
    //sum.grad = sum.get_grad(); // nu mai e necesara: gradul e asignat din constructor
    return sum;
}

// Diferenta a doua polinoame, implementata prin supraincarcarea operatorului -
Polinom Polinom::operator-(const Polinom& p)
{
    int grad_rez = max(grad, p.grad);
    Polinom dif(grad_rez);
    for (int i = 0; i <= grad; i++)
        dif.coef[i] = coef[i];
    for (int i = 0; i <= p.grad; i++ )
        dif.coef[i] -= p.coef[i];
    return dif;
}

// Produsul a doua polinoame, implementat prin supraincarcarea operatorului *
Polinom Polinom::operator*(const Polinom& p)
{
    int grad_rez = grad * p.grad;    
    Polinom prod(grad_rez);
    for (int i = 0; i <= grad; i++)
        for (int j = 0; j <= p.grad; j++)
            prod.coef[i+j] += (coef[i] * p.coef[j]);            
    return prod;
}


void Polinom::afisare(const char* nume)
{
    cout << nume << "(x) = ";
    for (int i = grad; i >= 0; i--) {
        if (coef[i] != 0) {
            if (i > 0)
                cout << coef[i] << "x^" << i << " + ";
            else
                cout << coef[i];
        }
    }
    cout << endl;
}

int main()
{
    double c1[4] = {1, 1, 1, 1};
    Polinom p1(3, c1); // apeleaza constructorul de initializare
    p1.afisare("p1");
    
    double c2[3] = {2.2, 2.2, 2.2};
    Polinom p2(2, c2); // apeleaza constructorul de initializare
    p2.afisare("p2");
    
    Polinom p3 = p1; // apeleaza constructorul de copiere
    p3.afisare("p3");
    
    Polinom sum = p1 + p2;
    sum.afisare("sum");
    
    Polinom dif = p2 - p1;
    dif.afisare("dif");
    
    Polinom prod = p2 * p3;
    prod.afisare("prod");
    
    cout << endl;
    cout << "sum(2) = " << sum.calcul_valoare(2) << endl; // inlocuieste x cu 2
    cout << "dif(2) = " << dif.calcul_valoare(2) << endl; // inlocuieste x cu 2
    cout << "prod(2) = " << prod.calcul_valoare(2); // inlocuieste x cu 2
    cout << endl; 
    
    return 0;
}