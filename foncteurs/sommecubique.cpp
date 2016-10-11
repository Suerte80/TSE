#include "sommecubique.h"

#include "stock.h"

#include <cmath>

SommeCubique::SommeCubique()
    : sommeCubique(0)
{
}

int SommeCubique::resultat()
{
    return sommeCubique;
}


void SommeCubique::operator ()(Stock &stock)
{
    sommeCubique += (int)pow(stock.getStock() * stock.getProduit().getPrix(), 3);
}
