#include "Jardin.h"
#include <iostream>

Jardin::Jardin():Royaume(4,4,0,0,0,0){
    setCout(4);
    setValeur(4);
}

Jardin::~Jardin()
{
}

std::string Jardin::obtenirNom() const {
    return "Jardin";
}


void Jardin::action(Joueur& joueur,Partie& p){
    p.afficherEtatPartie();
    joueur.getArgentDeck();
}






