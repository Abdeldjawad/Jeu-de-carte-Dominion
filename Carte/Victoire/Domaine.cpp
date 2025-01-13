#include "Domaine.h"


Domaine::Domaine():Victoire(2,1)
{
    setCout(2);
    setValeur(1);
}

std::string Domaine::obtenirNom() const {
    return "Domaine";
}

Domaine::~Domaine()
{
}




