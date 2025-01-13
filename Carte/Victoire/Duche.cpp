#include "Duche.h"

Duche::Duche():Victoire(5,3)
{
    setCout(5);
    setValeur(3);
}

std::string Duche::obtenirNom() const {
    return "Duche";
}

Duche::~Duche()
{
}




