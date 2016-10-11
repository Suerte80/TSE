#ifndef ROUTINECLIENT_H
#define ROUTINECLIENT_H

#include <vector>
#include <algorithm>

#include <stdlib.h>
#include <semaphore.h>

#include "chariot.h"
#include "client.h"

using namespace std;

#define N 10
#define M 1000
#define M_PORTIQUE 100
#define NB_CAISSE 4

#include <mutex>

class Stock;
class Caisse;

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

    static sem_t *m_sem_portique;
    static std::mutex m_mutex_achat;
    static std::mutex m_mutex_caisse;
    static std::mutex m_mutex_ticket;

    void prendreChariot();
    void passagePortique();
    void achats();
    void choixCaisse();
    void recuperationTicket();
};

#endif // ROUTINECLIENT_H
