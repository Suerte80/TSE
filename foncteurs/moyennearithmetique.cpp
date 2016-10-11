#include "moyennearithmetique.h"

#include "stock.h"

MoyenneArithmetique::MoyenneArithmetique()
    : somme(0),
      iteration(0)
{}

float MoyenneArithmetique::resultat()
{
    return somme / iteration;
}

void MoyenneArithmetique::operator()(Stock &stock){
    somme += stock.getStock() * stock.getProduit().getPrix() ;
    ++ iteration;
}
