#include <QApplication>
#include <QPushButton>

#include "caisse.h"
#include "client.h"
#include "produit.h"
#include "stock.h"
#include "ticket.h"
#include "chariot.h"

#include <iostream>
#include <fstream>
#include <string.h>
#include <chrono>
#include <limits>

void init_chrono();
int chrono_get();

//#define THREAD

#define N 10
#define M 100
#define NB_CAISSE 4

using namespace std ;

int main(int argc, char *argv[])
{
    unsigned int nombreClient = M;
    vector<Client> client ;
    Chariot chariot(N) ;
    vector<Caisse> caisse ;

    // On créer les caisses en fonction d'un nombre de caisse définie.
    for(int i = 0; i < NB_CAISSE; ++i)
        caisse.push_back(Caisse(i));

    // Création de la graine d'aléatoire.
    srand(time(0));

    // On crée les clients
    for( unsigned int i = 0 ; i < nombreClient ; i++ ) {
        client.push_back( Client(i) ) ;
    }

    unsigned int articleDifferent = 0, numeroStock = 0, max = 0, nombreProduit = 0 ;

    // On crée le stock du magasin
    vector<Stock> stock ;
        stock.push_back( Stock( Produit( "Poulet", 10 ), 5 * M ) ) ;
        stock.push_back( Stock( Produit( "Riz", 3 ), 5 * M) ) ;
        stock.push_back( Stock( Produit( "Crème fraiche", 5 ), 2*M) ) ;

    chrono::time_point<std::chrono::system_clock> start, end;

    start = chrono::system_clock::now();

    for( unsigned int i = 0 ; i < nombreClient ; i++ ) {

        // Le client i prend son chariot
        cout << "Le client " << i << " prend son chariot de taille N = " << N << endl ;
        client[i].setChariot(chariot) ;


        // Le client i rentre s'il peut, sinon il attend
        cout << "Le client " << i << " rentre dans le magasin" << endl ;


        // Le client i remplit son chariot
        cout << "Le client " << i << " remplit son chariot de :" ;

        articleDifferent = 1 + (int)( rand() % stock.size() ) ; // On prend au hasard le nombre d'article différent que va prendre le client
        for( unsigned int j = 0 ; j < articleDifferent ; j++ ) {
            numeroStock = (int)( rand() % stock.size() ) ;

            if( stock[numeroStock].getStock() < client[i].getChariot().getPlaceRestante() ) { max = stock[numeroStock].getStock() ; } // On regarde la quantité maximum qu'on peut encore prendre dans notre chariot
            else { max = client[i].getChariot().getPlaceRestante() ; }

            // On prend une quantité au hasard
            nombreProduit = 1 + rand() % max ;

            stock[numeroStock].retirerStock(nombreProduit) ;
            client[i].getChariot().ajouter( stock[numeroStock].getProduit(), nombreProduit ) ;
            cout << " " << nombreProduit << " " << stock[numeroStock].getProduit().getNom() ;

            if( client[i].getChariot().getPlaceRestante() <= 0 )
                break;

            // TODO Modifier les max qui peut être a 0.
            if( stock[numeroStock].getStock() <= 0 )
                stock.erase(stock.begin()+numeroStock);
        }
        cout << endl ;


        // Le client i choisit la caisse avec le moins de queue et attend
        int idCaisse = std::numeric_limits::infinity() ;
        for( int i = 0; i < caisse.size(); ++i ){
            if( caisse. )
        }

        cout << "Le client " << i << " choisit la caisse avec le moins de queue parmis les caisses 1 à " << caisse.size() << endl ;

        #ifdef THREAD
            client[i].setTicket( caisse[0].calculThread( client[i].getChariot().getStock() ) ) ;
        #else
            client[i].setTicket( caisse[0].calcul( client[i].getChariot().getStock() ) ) ;
        #endif

        // Le client i obtient son ticket
        cout << "Le client " << i << " obtient son ticket de valeur " << client[i].getTicket().getValeur() << endl ;

        // Le client i sort du hall et range son chariot
        cout << "Le client " << i << " sort du hall" << endl ;
        chariot.vider() ;


        cout << endl ;


        if(stock.size() < 1) {
            printf("Stock vide, fermeture du supermaché") ;
            break ;
        }
    }

    end = chrono::system_clock::now();

    std::chrono::duration<double> temps = end - start;

    cout << "S'est terminer en: " << temps.count() << " s." << endl;


    QApplication app(argc, argv);

    QPushButton bouton("Fin d'éxécution");

    bouton.show();

    return 0;//app.exec();
}
