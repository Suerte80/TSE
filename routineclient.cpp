#include "routineclient.h"

#include "stock.h"
#include "chariot.h"
#include "client.h"
#include "caisse.h"

int RoutineClient::m_nbClient = 0;

sem_t *RoutineClient::m_sem_portique = NULL;
mutex RoutineClient::m_mutex_achat;
mutex RoutineClient::m_mutex_caisse;
mutex RoutineClient::m_mutex_ticket;

RoutineClient::RoutineClient(vector<Stock> &stock, vector<Caisse> &caisse, Client &client)
    : m_stock(stock),
      m_caisse(caisse),
      m_chariot(Chariot(N)),
      m_client(client)
{
    if( m_sem_portique == NULL ){
        m_sem_portique = (sem_t *)malloc(sizeof(sem_t));

        sem_init(m_sem_portique, 0, M_PORTIQUE);
    }
}

void RoutineClient::routineExec()
{
    prendreChariot();
    passagePortique();
    achats();
    choixCaisse();
    recuperationTicket();
}

void RoutineClient::prendreChariot()
{
    cout << "Le client " << m_client.getId() << " prend son chariot de taille N = " << N << endl ;
    m_client.setChariot(m_chariot);
}

void RoutineClient::passagePortique()
{
    // Le client i rentre s'il peut, sinon il attend

    sem_wait(m_sem_portique);

    cout << "Le client " << m_client.getId() << " rentre dans le magasin" << endl ;
    ++m_nbClient;

    if( m_nbClient > M )
        cout << "Je suis Bonneval !" << endl;

    sem_post(m_sem_portique);

}

void RoutineClient::achats()
{
    // On verrouille le mutex.
    m_mutex_achat.lock();

    // Le client i remplit son chariot
    cout << "Le client " << m_client.getId() << " remplit son chariot de :" ;

    unsigned int articleDifferent = 0, numeroStock = 0, max = 0, nombreProduit = 0 ;

    articleDifferent = 1 + (int)( rand() % m_stock.size() ) ; // On prend au hasard le nombre d'article différent que va prendre le client
    for( unsigned int j = 0 ; j < articleDifferent ; j++ ) {
        numeroStock = (int)( rand() % m_stock.size() ) ;

        if( m_stock[numeroStock].getStock() < m_client.getChariot().getPlaceRestante() ) { max = m_stock[numeroStock].getStock() ; } // On regarde la quantité maximum qu'on peut encore prendre dans notre chariot
        else { max = m_client.getChariot().getPlaceRestante() ; }

        // On prend une quantité au hasard
        nombreProduit = 1 + rand() % max ;

        m_stock[numeroStock].retirerStock(nombreProduit) ;
        m_client.getChariot().ajouter( m_stock[numeroStock].getProduit(), nombreProduit ) ;
        cout << " " << nombreProduit << " " << m_stock[numeroStock].getProduit().getNom() ;

        if( m_client.getChariot().getPlaceRestante() <= 0 )
            break;

        // TODO Modifier les max qui peut être a 0.
        if( m_stock[numeroStock].getStock() <= 0 )
            m_stock.erase(m_stock.begin()+numeroStock);
    }
    cout << endl ;

    // On deverrouille le mutex.
    m_mutex_achat.unlock();
}

void RoutineClient::choixCaisse()
{
    // On verrouille le mutex.
    m_mutex_caisse.lock();

    // Le client i choisit la caisse avec le moins de queue et attend
    m_minCaisse = std::min_element(m_caisse.begin(), m_caisse.end());
    (*m_minCaisse).addClient( m_client );
    cout << "Le client " << m_client.getId() << " choisit la caisse " << (*m_minCaisse).getId() << " qui a le moins de queue parmis les caisses 1 à " << m_caisse.size() << endl ;

    // On deverrouille le mutex.
    m_mutex_caisse.unlock();
}

void RoutineClient::recuperationTicket()
{
    // Je pense qu'ici c'est a la caisse de deverrouiller le thread car c'est la caisse qui fait le calcul.

    // On verrouille le mutex.
    m_mutex_ticket.lock();

    #ifdef THREAD
        m_client.setTicket( (*m_minCaisse).calculThread( m_client.getChariot().getStock() ) ) ;
    #else
        m_client.setTicket( (*m_minCaisse).calcul( m_client.getChariot().getStock() ) ) ;
    #endif

    // Le client i obtient son ticket
    cout << "Le client " << m_client.getId() << " obtient son ticket de valeur " << m_client.getTicket().getValeur() << endl ;

    cout << endl;

    // On deverrouille le mutex.
    m_mutex_ticket.unlock();

    // On fait sortir le client du magasin nbClient <= nbClient - 1;
    sem_post(m_sem_portique);
    --m_nbClient;
}
