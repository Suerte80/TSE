#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>

using namespace std;

class Produit
{
public:
    Produit() ;
    Produit(string n, int p) ;
    string getNom() ;
    int getPrix() ;

private:
    string nom ;
    int prix ;
};

#endif // PRODUIT_H
