//#include <QApplication>
//#include <QPushButton>

#include "caisse.h"
#include "client.h"
#include "produit.h"
#include "stock.h"
#include "ticket.h"
#include "chariot.h"
#include "routineclient.h"
#include "foncteurs.h"

#include <iostream>
#include <fstream>
#include <string.h>
#include <chrono>
#include <limits>
#include <mutex>
#include <thread>

void init_chrono();
int chrono_get();

//#define THREAD

#define NB_CAISSE 4

using namespace std ;

int main(int argc, char *argv[])
{
    unsigned int nombreClient = M;
    vector<Client> client ;
    vector<RoutineClient> routine ;
    Chariot chariot(N) ;
    vector<Caisse> caisse ;
    vector<thread *> threads;

    // On créer les caisses en fonction d'un nombre de caisse définie.
    for(int i = 0; i < NB_CAISSE; ++i)
        caisse.push_back(Caisse(i));

    // Création de la graine d'aléatoire.
    srand(time(0));

    // On crée les clients
    for( unsigned int i = 0 ; i < nombreClient ; ++i ) {
        client.push_back( Client(i) ) ;
    }

    // On crée le stock du magasin
    vector<Stock> stock ;
        stock.push_back( Stock( Produit( "Poulet", 10 ), 5 * M ) ) ;
        stock.push_back( Stock( Produit( "Riz", 3 ), 5 * M) ) ;
        stock.push_back( Stock( Produit( "Crème fraiche", 5 ), 2*M) ) ;

    for( unsigned int i = 0; i < nombreClient ; ++i ){
        RoutineClient r(stock, caisse, client[i]);

        routine.push_back(r);
    }

    chrono::time_point<std::chrono::system_clock> start, end;

    start = chrono::system_clock::now();

    for( unsigned int i = 0; i < nombreClient; ++i ){
        //thread t(&RoutineClient::routineExec, routine[i]);

        threads.push_back(new thread(&RoutineClient::routineExec, routine[i]));

        //t.join();
    }

    cout << threads.size() << endl;

    for( unsigned int i = 0; i < threads.size(); ++i )
        threads[i]->join();

    end = chrono::system_clock::now();

    for( unsigned int i = 0; i < threads.size(); ++i )
        delete threads[i];

    std::chrono::duration<double> temps = end - start;

    cout << "S'est terminer en: " << temps.count() << " s." << endl;

    return 0;
}
