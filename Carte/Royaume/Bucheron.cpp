#include "Bucheron.h"
#include <iostream>



Bucheron::Bucheron():Royaume(3,3,1,0,0,2){
    setCout(3);
    setValeur(3);
}
Bucheron::~Bucheron()
{
}

std::string Bucheron::obtenirNom() const {
    return "Bucheron";
}

void Bucheron::action(Joueur& joueur,Partie& p){
    joueur.setnbrachat(joueur.getnbrachat()+1);
    std::cout << "\033[42mVous avez 2 achats en plus pour ce tour\033[0m" << std::endl;
    std::cout << "L'argent du deck est :" << joueur.getArgentDeck() << std::endl;
    joueur.setArgentDeck(joueur.getArgentDeck()+2);
    std::cout << "L'argent du deck est :" << joueur.getArgentDeck() << std::endl;
    std::cout << "\033[42mVous avez 2 points d'argent en plus pour ce tour\033[0m" << std::endl;
    p.afficherEtatPartie();
}







