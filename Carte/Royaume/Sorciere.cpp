#include "Sorciere.h"
#include <iostream>



Sorciere::Sorciere():Royaume(5,5,0,2,0,0){
    setCout(5);
    setValeur(5);
};

std::string Sorciere::obtenirNom() const {
    return "Sorciere";
}


Sorciere::~Sorciere()
{
}

void Sorciere::action(Joueur& joueur,Partie& p){
    joueur.tirerMain(2);
    std::cout << "\033[42mVous avez pioché 2 cartes\033[0m" << std::endl;
    std::vector<Joueur>& joueurs = Joueur::getListe(); 
    for(Joueur& j:joueurs){
        if(j.getUsername()!=joueur.getUsername()){
            if(j.getDeck().trouverCarte("Douve")){
                std::cout << "\033[41mVotre adversaire est protégé car il a une douve\033[0m" << std::endl;
            }
            else{
            p.getReserve().ajouterCarte("Malediction",j.getDefausse().getDeck());
            std::cout << j.getUsername() << "\033[42m a reçu une malédiction\033[0m" << std::endl;
            }
        }
    }
}






