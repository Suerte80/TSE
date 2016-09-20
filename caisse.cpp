#include "caisse.h"

#include "ticket.h"

#include <vector>
#include <math.h>

using namespace std ;

Caisse::Caisse(int i)
{
    id = i ;
}

Ticket Caisse::calcul(vector<Stock> chariot)
{
    float ma = moyenneArithmetique(chariot) ;
    float mq = moyenneQuadratique(chariot) ;
    int s = somme(chariot) ;
    return Ticket(ma, mq, s) ;
}

float Caisse::moyenneArithmetique(vector<Stock> chariot)
{
    float ma = 0 ;
    int diviseur = 0 ;
    for(int i = 0 ; chariot.size() ; i++) {
        diviseur = chariot[i].getStock() ;
        ma += ( diviseur * chariot[i].getProduit().getPrix() );
    }
    return ma/diviseur ;
}

float Caisse::moyenneQuadratique(vector<Stock> chariot)
{
    float mq = 0 ;
    int diviseur = 0 ;
    for(int i = 0 ; chariot.size() ; i++) {
        diviseur = chariot[i].getStock() ;
        mq += ( diviseur * (chariot[i].getProduit().getPrix() * chariot[i].getProduit().getPrix()));
    }
    return sqrt(mq/diviseur) ;
}

int Caisse::somme(vector<Stock> chariot)
{
    int s = 0 ;
    for(int i = 0 ; chariot.size() ; i++) {
        s += ( chariot[i].getStock() * chariot[i].getProduit().getPrix() );
    }
    return s ;
}
