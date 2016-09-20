#ifndef STOCK_H
#define STOCK_H

#include "produit.h"

class Stock
{
public:
    Stock() ;
    Stock(Produit p, int s) ;
    Produit getProduit() ;
    int getStock() const ;
    void retirerStock(int s) ;

private:
    Produit produit ;
    int stock ;
};

#endif // STOCK_H
