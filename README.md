# Tema 1 - Implementare clasa "Polinom"

##Cerinte:

Polinomul este reprezentat ca tablou unidimensional (prin gradul polinomului si vectorul coeficientilor (coeficientii vor apartine la monoame de grade consecutive), de dimensiune egala cu gradul suma 1, de la cel al termenului liber la cel de grad maxim.

- fiecare coeficient va fi de tip double;
- membri privati pentru vectorul propriuzis si numarul de elemente;
- constructori pentru initializare si copiere;
- destructor (în cazul alocarii statice, se seteaza dimensiunea vectorului la zero;
- metoda publica pentru calculul valorii unui polinom intr-un punct;
- suma a doua polinoame, implementata prin supraincarcarea operatorului +;
- diferenta a doua polinoame, implementata prin supraincarcarea operatorului -;
- produsul a doua polinoame, implementat prin supraincarcarea operatorului *;

#### Modificare aplicatie: alocare dinamica vector coeficienti

Pentru modificarea aplicatiei de la coeficienti alocati static la alocare dinamica:

- am modificat in clasa Polinom declaratia `double coef[100]` in `double * coef`
- constructorul vid (fara parametri) seteaza doar gradul zero si aloca spatiu pentru termenul liber, pe care il initializeaza cu zero
- am adaugat un constructor in care se specifica doar gradul. In acesta se aloca dimensiunea necesara (n+1), se seteaza gradul si se initializeaza coeficientii cu zero.
- in toti constructorii se aloca dinamic coeficientii (inclusiv in constructorul de copiere), avand grad cunoscut: `coef = new double(g + 1);`
- in destructor nu e necesara eliberarea memoriei cu "delete coef", intrucat alocarea coeficientilor se face pe stiva fiecarui obiect (e variablia locala in clasa), nu avem alocare in global heap 
- la operatorii de adunare si scadere am calculat gradul rezultatului (grad_rez) ca maxim intre gradul obiectului curent si al celui transmis ca parametru p.grad
- pentru operatorul de inmultire "*", gradul rezultatului este produsul celor doua grade (biect curent si obiect transmis ca parametru). Alocarea se face prin constructor, cu gradul rezultat: `int grad_rez = grad * p.grad;` 
`Polinom prod(grad_rez);`
- in nici una din functiile care supraincarca operatori nu mai e necesara functie get_grad, gradul fiind calculat si setat dinainte la fiecare operatie +, -, *. Prin urmare, functiile  `get_grad()` si `set_grad()` au fost sterse din codul sursa.

# Tema 2 - Arbori

## Cerinte

Cerinte comune tuturor temelor / in principal temelor 1-17:

1. toate clase vor conține obligatoriu constructori de inițializare, parametrizati și de
copiere, destructor, iar operatorii >>,<<,= să fie supraincarcati;
2. clasele derivate trebuie sa contina constructori prin care sa se evidentieze transmiterea
parametrilor către constructorul din clasa de baza;
3. ilustrarea conceptelor de moștenire și functii virtuale (pure – unde se considera mai natural);
4. tratarea exceptiilor;
5. citirea informațiilor complete a n obiecte, memorarea și afisarea acestora.

### Cerinta specifica - tema 11

Arbori oarecare, in reprezentare inlantuita, prin legaturile fiu (catre fiul cel mai din stanga) si frate (catre urmatorul fiu al tatalui, in ordinea fiilor tatalui de la stanga la dreapta).

Se dau urmatoarele clase:

- Nod {int info, int nr_copii, Nod * leg[10]};
- Arbore(int nr_noduri) – clasa abstracta
- Arbore_oarecare(Nod *rad) : Arbore
- Arbore binar: Arbore oarecare

Afisarea elementelor unui arbore binar oarecare sa fie data de parcurgerea în adancime si parcurgerea in latime, cu mentiunea listei fiilor pentru fiecare nod, iar afisarea unui Arbore_binar sa conțină cele 3 parcurgeri simultan.
