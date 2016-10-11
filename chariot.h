#ifndef CHARIOT_H
#define CHARIOT_H

#include <vector>

class Produit;
class Stock;

using namespace std;

class Chariot
{
public:
    Chariot() ;
    Chariot(int t) ;
    void vider() ;
    void ajouter(Produit &p, int s) ;
    std::vector<Stock> &getStock() ;
    int getPlaceRestante() ;

private:
    std::vector<Stock> stock ;
    unsigned int place ;
    unsigned int placeRestante ;
};

#endif // CHARIOT_H
