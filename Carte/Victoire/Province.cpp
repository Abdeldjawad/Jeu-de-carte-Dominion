#include "Province.h"


Province::Province():Victoire(8,6)
{
    setCout(8);
    setValeur(6);
}

std::string Province::obtenirNom() const {
    return "Province";
}

Province::~Province()
{
}


