#include "caisse.h"

#include "ticket.h"
#include "stock.h"
#include "client.h"
#include "foncteurs.h"
#include "stock.h"

using namespace std ;

Caisse::Caisse(int i)
    : id(i),
      m_queue()
{
}

Ticket Caisse::calcul(vector<Stock> &chariot)
{
    float ma = moyenneArithmetique(chariot) ;
    float mq = moyenneQuadratique(chariot) ;
    int s = sommeCubique(chariot) ;
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

    return Ticket(CMoyenneArithmetique, CMoyenneQuadratique, CSommeCubique) ;
}

void Caisse::addClient(const Client &client)
{
    cout << m_queue.size() << " LOL" << endl;

    m_queue.push(client);
}

void Caisse::sortClient()
{
    m_queue.pop();
}

int Caisse::getNombreClient() const
{
    return m_queue.size();
}

int Caisse::getId() const
{
    return id;
}

float Caisse::moyenneArithmetique(vector<Stock> &chariot)
{
    MoyenneArithmetique ma;

    ma = for_each(chariot.begin(), chariot.end(), ma);

    return ma.resultat() ;
}

float Caisse::moyenneQuadratique(vector<Stock> &chariot)
{
    MoyenneQuadratique mq;

    mq = for_each(chariot.begin(), chariot.end(), mq);

    return mq.resultat();
}

int Caisse::sommeCubique(vector<Stock> &chariot)
{
    SommeCubique sc;

    sc = for_each(chariot.begin(), chariot.end(), sc);

    return sc.resultat();
}

void Caisse::sarithmetique()
{
    MoyenneArithmetique ma;

    ma = for_each(chariot->begin(), chariot->end(), ma);

    CMoyenneArithmetique = ma.resultat() ;
}

void Caisse::squadratique()
{
    MoyenneQuadratique mq;

    mq = for_each(chariot->begin(), chariot->end(), mq);

    CMoyenneQuadratique = mq.resultat();
}

void Caisse::ssomme()
{
    SommeCubique sc;

    sc = for_each(chariot->begin(), chariot->end(), sc);

    CSommeCubique = sc.resultat();
}
