#ifndef CAISSE_H
#define CAISSE_H

#include "ticket.h"
#include "stock.h"

#include <vector>

class Caisse
{
public:
    Caisse(int i) ;
    Ticket calcul(std::vector<Stock> chariot);

private:
    int id ;
    float moyenneArithmetique(std::vector<Stock> chariot) ;
    float moyenneQuadratique(std::vector<Stock> chariot) ;
    int somme(std::vector<Stock> chariot) ;
};

#endif // CAISSE_H
