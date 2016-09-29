#ifndef CAISSE_H
#define CAISSE_H

#include <algorithm>
#include <vector>
#include <thread>
#include <cmath>
#include <iostream>
#include <queue>

using namespace std;

class Ticket;
class Stock;
class Client;
class Stock;

class Caisse
{
public:
    Caisse(int i) ;
    Ticket calcul(std::vector<Stock> &chariot);
    Ticket calculThread(std::vector<Stock> &chariot);

    // Méthode qui permet d'ajouter un client.
    void addClient( const Client &client );

    // Méthode qui fait sort un client de la caisse.
    void sortClient( );

    // Méthode qui permet de récupérer le nombre de client présent dans la file de la caisse.
    int getNombreClient() const;

    int getId() const;

    friend bool operator<(const Caisse &a, const Caisse &b)
    {
        return a.getNombreClient() < b.getNombreClient();
    }

private:
    int id ;

    // Attribut pour le ticket de caisse façon thread.
    int CSommeCubique;
    float CMoyenneArithmetique;
    float CMoyenneQuadratique;
    vector<Stock> *chariot;

    float moyenneArithmetique(std::vector<Stock> &chariot) ;
    float moyenneQuadratique(std::vector<Stock> &chariot) ;
    int sommeCubique(std::vector<Stock> &chariot) ;

    void sarithmetique();

    void squadratique();

    void ssomme();

    // Attribut qui permet de gerer les queues.
    queue<Client> m_queue;
};

#endif // CAISSE_H
