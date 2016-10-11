#include "stock.h"

#include "produit.h"

Stock::Stock()
    : produit(),
      stock(0)
{
}

Stock::Stock(Produit p, int s)
    : produit(p),
      stock(s)
{
}

void Stock::retirerStock(int s)
{
    stock -= s ;
}

// Getters
Produit &Stock::getProduit() { return produit ; }
int Stock::getStock() const { return stock ; }
