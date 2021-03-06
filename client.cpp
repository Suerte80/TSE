#include "client.h"

#include "stock.h"
#include "produit.h"

Client::Client(int i)
    : id(i),
      chariot(),
      ticket()
{
}

void Client::ajouterArticle(Produit &produit, int quantite) { chariot.ajouter( produit, quantite ) ; }

// Getters
Chariot &Client::getChariot() { return chariot ; }
Ticket &Client::getTicket() { return ticket ; }
int Client::getId() { return id; }

// Setters
void Client::setTicket(Ticket t) { ticket = t ; }
void Client::setChariot(Chariot c) { chariot = c ; }
