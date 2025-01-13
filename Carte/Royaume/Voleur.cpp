#include "Voleur.h"
#include <iostream>



Voleur::Voleur():Royaume(4,4,0,0,0,0){
    setCout(4);
    setValeur(4);
}

Voleur::~Voleur()
{
}

std::string Voleur::obtenirNom() const {
    return "Voleur";
}

void Voleur::action(Joueur& joueur,Partie& p){
    std::vector<Joueur>& joueurs = joueur.getListe(); 
    std::string choix;
    
    for(Joueur& j:joueurs){
        if(j.getUsername()!=joueur.getUsername()){
            if(j.getDeck().trouverCarte("Douve")){
                std::cout << "\033[41mVotre adversaire est protégé car il a une douve\033[0m" << std::endl;
            }
            else{
                for(int i=0;i<2;i++){
                    bool choixCorrect = false;
                    std::cout << "Carte n°" << i << " : " << j.getPioche().getDeck()[i]->obtenirNom() << std::endl;
                    if(dynamic_cast<Tresor*>(j.getPioche().getDeck()[i])){ 
                        std::cout << "Voulez vous prendre cette carte ?  oui/non" << std::endl;    
                        while(!choixCorrect){
                            std::string choix;
                            std::cin >> choix;  
                            if(choix == "oui"){
                                joueur.getDefausse().getDeck().push_back(j.getPioche().getDeck()[i]);
                                j.getPioche().getDeck().erase(j.getPioche().getDeck().begin() + i);
                                std::cout << "\033[42mVous avez ajouté cette carte à votre jeu\033[0m" << std::endl;
                                choixCorrect = true;
                            }
                            else{
                                if(choix == "non"){
                                    p.ecarterRebut(j,j.getPioche().getDeck()[i]);
                                    choixCorrect = true;
                                }
                                else{
                                    std::cout << "\033[41mVeuillez entrer une valeur valide\033[0m" << std::endl;
                                }
                            }
                        }
                    } 
                }
            }
            p.afficherEtatPartie();
        }
    } 
}





