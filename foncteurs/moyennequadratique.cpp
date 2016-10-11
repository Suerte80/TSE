#include "moyennequadratique.h"

#include <cmath>

#include "stock.h"

MoyenneQuadratique::MoyenneQuadratique()
    : sommeQuadratique(0),
      iteration(0)
{}

float MoyenneQuadratique::resultat()
{
    return sqrtf( sommeQuadratique / iteration );
}

void MoyenneQuadratique::operator ()(Stock &stock)
{
    sommeQuadratique += powf( stock.getStock() * stock.getProduit().getPrix(), 2 ) ;
    ++ iteration;
}
