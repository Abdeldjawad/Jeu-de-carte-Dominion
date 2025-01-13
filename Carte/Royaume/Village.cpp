#include "Village.h"
#include <iostream>


Village::Village():Royaume(3,3,0,1,2,0){
    setCout(3);
    setValeur(3);
}

Village::~Village()
{
}

std::string Village::obtenirNom() const {
    return "Village";
}


void Village::action(Joueur& joueur,Partie& p){
    joueur.tirerMain(1);
    std::cout << "\033[42mVous avez pioché 1 cartes\033[0m" << std::endl;
    joueur.setnbraction(joueur.getnbraction()+2);
    std::cout << "\033[42mVous avez 2 action en plus pour ce tour\033[0m" << std::endl;
    p.afficherEtatPartie();
}





