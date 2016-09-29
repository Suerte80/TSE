#ifndef TICKET_H
#define TICKET_H

#include <sstream>
#include <string.h>

class Stock;

class Ticket
{
public:
    Ticket() ;
    Ticket(float ma, float mq, int s) ;
    std::string getValeur() ;

private:
    int id ;
    float moyenneArithmetique ;
    float moyenneQuadratique ;
    int somme ;
};

#endif // TICKET_H
