#include "chariot.h"

#include "stock.h"

#include <vector>

using namespace std ;

Chariot::Chariot()
    : place(0),
      placeRestante(0),
      stock()
{}

Chariot::Chariot(int t)
{
    place = t ;
    placeRestante = t ;
}

void Chariot::ajouter(Produit &p, int s)
{
    stock.push_back( Stock(p, s) ) ;
}

void Chariot::vider()
{
    placeRestante = place ;
    stock.clear() ;
}

// Getters
vector<Stock> &Chariot::getStock() { return stock ; }
int Chariot::getPlaceRestante() { return placeRestante ; }
