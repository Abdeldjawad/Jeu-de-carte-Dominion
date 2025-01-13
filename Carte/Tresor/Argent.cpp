#include "Argent.h"

Argent::Argent():Tresor(3,2)
{
    setCout(3);
    setValeur(2);
}

std::string Argent::obtenirNom() const {
    return "Argent";
}

Argent::~Argent()
{
}




