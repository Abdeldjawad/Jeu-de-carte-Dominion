#include "Or.h"
#include <iostream>


Or::Or():Tresor(6,3)
{
    setCout(6);
    setValeur(3);
}

std::string Or::obtenirNom() const {
    return "Or";
}

Or::~Or()
{
}


