#ifndef CLIENT_H
#define CLIENT_H

#include "chariot.h"
#include "ticket.h"

class Stock;
class Produit;

class Client
{
public:
    Client(int i) ;
    void ajouterArticle(Produit &produit, int quantite) ;
    Chariot &getChariot() ;
    void setTicket(Ticket t) ;
    void setChariot(Chariot c) ;
    Ticket &getTicket() ;
    int getId() ;

private:
    int id ;
    Chariot chariot ;
    Ticket ticket ;
};

#endif // CLIENT_H
