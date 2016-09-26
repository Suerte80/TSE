#ifndef CAISSE_H
#define CAISSE_H

#include "ticket.h"
#include "stock.h"
#include "client.h"

#include <vector>
#include <thread>
#include <cmath>
#include <iostream>
#include <queue>

#include "stock.h"

using namespace std;

class Caisse
{
public:
    Caisse(int i) ;
    Ticket calcul(std::vector<Stock> &chariot);
    Ticket calculThread(std::vector<Stock> &chariot);

    // Méthode qui permet d'ajouter un client.
    void addClient( const Client &client );

    // Méthode qui permet de récupérer le nombre de client présent dans la file de la caisse.
    int getNombreClient() const;

private:
    int id ;

    // Attribut pour le ticket de caisse façon thread.
    int CSomme;
    float CMoyenneArithmetique;
    float CMoyenneQuadratique;
    vector<Stock> *chariot;

    float moyenneArithmetique(std::vector<Stock> &chariot) ;
    float moyenneQuadratique(std::vector<Stock> &chariot) ;
    int somme(std::vector<Stock> &chariot) ;

    void sarithmetique();

    void squadratique();

    void ssomme();

    // Attribut qui permet de gerer les queues.
    queue<Client> m_queue;
};

#endif // CAISSE_H
