#include "produit.h"

Produit::Produit()
    : nom(""),
      prix(0)
{}

Produit::Produit(string n, int p)
{
    nom = n ;
    prix = p ;
}

// Getters
std::string Produit::getNom() { return nom ; }
int Produit::getPrix() { return prix ; }
