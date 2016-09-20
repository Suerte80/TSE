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

#define N 10

using namespace std ;

int main(int argc, char *argv[])
{
    unsigned int nombreClient = 100 ;
    vector<Client> client ;
    Chariot chariot(N) ;
    vector<Caisse> caisse ;
        caisse.push_back( Caisse(0) ) ;

    srand(time(0));

    // On crée les clients
    for( unsigned int i = 0 ; i < nombreClient ; i++ ) {
        client.push_back( Client(i) ) ;
    }

    unsigned int articleDifferent = 0, numeroStock = 0, max = 0, nombreProduit = 0 ;

    // On crée le stock du magasin
    vector<Stock> stock ;
        stock.push_back( Stock( Produit( "Poulet", 10 ), 50 ) ) ;
        stock.push_back( Stock( Produit( "Riz", 3 ), 50) ) ;
        stock.push_back( Stock( Produit( "Poulet", 5 ), 20) ) ;

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
            numeroStock = 1 + (int)( rand() % articleDifferent ) ; // numeroStock = 1 + (int)( (float)rand() / 32767 * (articleDifferent) ) ;
            cout << numeroStock << endl ;
            if( stock[numeroStock].getStock() < client[i].getChariot().getPlaceRestante() ) { max = stock[numeroStock].getStock() ; } // On regarde la quantité maximum qu'on peut encore prendre dans notre chariot
            else { max = client[i].getChariot().getPlaceRestante() ; }

            // On prend une quantité au hasard
            nombreProduit = 1 + (int)( (float)rand() / 32767 * (max) ) ;

            stock[numeroStock].retirerStock(nombreProduit) ;
            client[i].getChariot().ajouter( stock[numeroStock].getProduit(), nombreProduit ) ;
            cout << " " << nombreProduit << " " << stock[numeroStock].getProduit().getNom() ;
        }
        cout << endl ;


        // Le client i choisit la caisse avec le moins de queue et attend
        cout << "Le client " << i << " choisit la caisse avec le moins de queue parmis les caisses 1 à " << caisse.size() << endl ;


        // Le client i obtient son ticket
        cout << "Le client " << i << " obtient son ticket de valeur " << client[i].getTicket().getValeur() << endl ;
        client[i].setTicket( caisse[0].calcul( client[i].getChariot().getStock() ) ) ;


        // Le client i sort du hall et range son chariot
        cout << "Le client " << i << " sort du hall" << endl ;
        chariot.vider() ;


        cout << endl ;


        if(stock.size() < 1) {
            printf("Stock vide, fermeture du supermaché") ;
            break ;
        }
    }


    QApplication app(argc, argv);

    QPushButton bouton("Fin d'éxécution");

    bouton.show();

    return app.exec();
}
