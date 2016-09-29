#ifndef FONCTEURS_H
#define FONCTEURS_H

#include <vector>
#include <iostream>
#include <cmath>

#include "stock.h"
#include "caisse.h"
#include "routineclient.h"

using namespace std;

class MoyenneArithmetique{
public:
    MoyenneArithmetique()
        : somme(0),
          iteration(0)
    {}

    float resultat(){ return somme / iteration ; }

    void operator()(Stock &stock){
        somme += stock.getStock() * stock.getProduit().getPrix() ;
        ++ iteration;
    }

private:
    unsigned int somme;
    unsigned int iteration;
};

class MoyenneQuadratique{
public:
    MoyenneQuadratique()
        : sommeQuadratique(0),
          iteration(0)
    {}

    float resultat(){ return sqrtf( sommeQuadratique / iteration ) ; }

    void operator()(Stock &stock){
        sommeQuadratique += powf( stock.getStock() * stock.getProduit().getPrix(), 2 ) ;
        ++ iteration;
    }

private:
    int sommeQuadratique;
    int iteration;
};

class SommeCubique{
public:
    int resultat() { return sommeCubique; }

    void operator()(Stock &stock){
        sommeCubique += (int)pow(stock.getStock() * stock.getProduit().getPrix(), 3);
    }

private:
    int sommeCubique;
};

class RoutineExec{
public:
    void operator()(RoutineClient &rc){
        rc.routineExec();
    }
};

class RoutineThreadsJoin{
public:
    void operator()(thread t){
        cout << "LOL MDR" << endl;
        t.join();
    }
};

#endif // FONCTEURS_H
