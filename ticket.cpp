#include "ticket.h"

#include "stock.h"

using namespace std ;

Ticket::Ticket()
    : moyenneArithmetique(0),
      moyenneQuadratique(0),
      somme(0)
{}

Ticket::Ticket(float ma, float mq, int s)
{
    moyenneArithmetique = ma ;
    moyenneQuadratique = mq ;
    somme = s ;
}

string float2string(float f)
{
  ostringstream os ;
  os << f ;
  return os.str() ;
}

string int2string(int i) {
     ostringstream os ;
     os << i ;
     return os.str() ;
}

string Ticket::getValeur() {
    string valeur = string("MACL = ") + float2string(moyenneArithmetique) + ", Mquad = " + float2string(moyenneQuadratique) + " et Mcube = " + int2string(somme) ;
    return valeur ;
}
