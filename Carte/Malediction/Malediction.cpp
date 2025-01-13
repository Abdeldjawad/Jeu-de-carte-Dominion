#include "Malediction.h"

// Constructors/Destructors


Malediction::Malediction():Carte(0,-1)
{
    setCout(0);
    setValeur(-1);
}

std::string Malediction::obtenirNom() const {
    return "Malediction";
}


Malediction::~Malediction()
{
}





