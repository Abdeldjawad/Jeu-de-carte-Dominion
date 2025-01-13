#include "Douve.h"
#include <iostream>



Douve::Douve():Royaume(2,2,0,2,0,0){
    setCout(2);
    setValeur(2);
}

Douve::~Douve()
{
}

std::string Douve::obtenirNom() const {
    return "Douve";
}

void Douve::action(Joueur& joueur,Partie& p){
    joueur.tirerMain(2);
    std::cout << "\033[42mVous avez pioché 2 cartes\033[0m" << std::endl;
    p.afficherEtatPartie();
}






