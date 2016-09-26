#include "caisse.h"

#include "ticket.h"

using namespace std ;

Caisse::Caisse(int i)
{
    id = i ;
}

Ticket Caisse::calcul(vector<Stock> &chariot)
{
    float ma = moyenneArithmetique(chariot) ;
    float mq = moyenneQuadratique(chariot) ;
    int s = somme(chariot) ;
    return Ticket(ma, mq, s) ;
}

Ticket Caisse::calculThread(std::vector<Stock> &chariot)
{
    this->chariot = new vector<Stock>(chariot);

    thread threadS(&Caisse::ssomme, this);
    thread threadA(&Caisse::sarithmetique, this);
    thread threadQ(&Caisse::squadratique, this);

    threadS.join();
    threadA.join();
    threadQ.join();

    return Ticket(CMoyenneArithmetique, CMoyenneQuadratique, CSomme) ;
}

float Caisse::moyenneArithmetique(vector<Stock> &chariot)
{
    float ma = 0 ;
    int diviseur = 0 ;
    for( unsigned int i = 0 ; i < chariot.size() ; i++) {
        ++ diviseur ;
        ma += ( diviseur * chariot[i].getProduit().getPrix() );
    }
    return ma/diviseur ;
}

float Caisse::moyenneQuadratique(vector<Stock> &chariot)
{
    float mq = 0 ;
    int diviseur = 0 ;
    for( unsigned int i = 0 ; i < chariot.size() ; i++) {
        diviseur = chariot[i].getStock() ;
        mq += ( diviseur * (chariot[i].getProduit().getPrix() * chariot[i].getProduit().getPrix()));
    }
    return sqrt(mq/diviseur) ;
}

int Caisse::somme(vector<Stock> &chariot)
{
    int s = 0 ;

    for(unsigned int i = 0 ; i < chariot.size() ; ++i) {
        s += ( chariot[i].getStock() * chariot[i].getProduit().getPrix() );
    }

    return s ;
}

void Caisse::sarithmetique()
{
    float ma = 0 ;
    int diviseur = 0 ;
    for(unsigned int i = 0 ; i < chariot->size() ; i++) {
        ++ diviseur ;
        ma += ( diviseur * chariot->at(i).getProduit().getPrix() );
    }

    CMoyenneArithmetique = ma/diviseur ;
}

void Caisse::squadratique()
{
    float mq = 0 ;
    int diviseur = 0 ;
    for(unsigned int i = 0 ; i < chariot->size() ; i++) {
        diviseur = chariot->at(i).getStock() ;
        mq += ( diviseur * (chariot->at(i).getProduit().getPrix() * chariot->at(i).getProduit().getPrix()));
    }

    CMoyenneQuadratique = sqrt(mq/diviseur) ;
}

void Caisse::ssomme()
{
    int s = 0 ;
    for(unsigned int i = 0 ; i < chariot->size() ; i++) {
        s += ( chariot->at(i).getStock() * chariot->at(i).getProduit().getPrix() );
    }

    CSomme = s;
}
