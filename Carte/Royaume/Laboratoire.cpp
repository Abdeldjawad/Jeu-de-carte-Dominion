#include "Laboratoire.h"
#include <iostream>



Laboratoire::Laboratoire():Royaume(5,5,0,2,1,0){
    setCout(5);
    setValeur(5);
}

Laboratoire::~Laboratoire()
{
}

std::string Laboratoire::obtenirNom() const {
    return "Laboratoire";
}

void Laboratoire::action(Joueur& joueur,Partie& p){
    joueur.tirerMain(2);
    std::cout << "\033[42mVous avez pioché 2 cartes\033[0m" << std::endl;
    joueur.setnbraction(joueur.getnbraction()+1);
    std::cout << "\033[42mVous avez 1 action en plus pour ce tour\033[0m" << std::endl;
    p.afficherEtatPartie();
}





