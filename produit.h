#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>

class Produit
{
public:
    Produit() ;
    Produit(std::string n, int p) ;
    std::string getNom() ;
    int getPrix() ;

private:
    std::string nom ;
    int prix ;
};

#endif // PRODUIT_H
