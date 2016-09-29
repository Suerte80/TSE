#ifndef ROUTINECLIENT_H
#define ROUTINECLIENT_H

#include "chariot.h"
#include "client.h"
#include "stock.h"
#include "caisse.h"

#include <vector>
#include <mutex>
#include <algorithm>

using namespace std;

#define N 10
#define M 1000
#define NB_CAISSE 4

class RoutineClient{
public:
    RoutineClient(vector<Stock> &stock, vector<Caisse> &caisse, Client &client);

    void routineExec();
private:
    vector<Stock> m_stock;
    vector<Caisse> m_caisse;
    Chariot m_chariot;
    Client m_client;

    vector<Caisse>::iterator m_minCaisse;

    static int m_nbClient;

    static mutex m_mutex_portique;
    static mutex m_mutex_achat;
    static mutex m_mutex_caisse;
    static mutex m_mutex_ticket;

    void prendreChariot();
    void passagePortique();
    void achats();
    void choixCaisse();
    void recuperationTicket();
};

#endif // ROUTINECLIENT_H
