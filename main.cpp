#include <iostream>
#include "Joueur.h"
#include "Partie.h"

void displayMenu() {
    std::cout << "===== DOMINION =====" << std::endl;
    std::cout << "1. Démarrer la partie" << std::endl;
    std::cout << "2. Exit" << std::endl;
    std::cout << "Choisissez: ";
    std::cout << "------------------------------------------ "<< std::endl;
}
void handleChoice() {
    std::vector<Joueur>& joueurs = Joueur::getListe();  
    Partie p;  
    bool choixCorrect = false;
    int choix;
    while(choixCorrect == false){
        std::cin >> choix;
        switch (choix) {
            case 1:
                std::cout << "------------------------------------------" << std::endl;
                Joueur::inscrire();  
                if (joueurs.empty()) {
                    std::cout << "Erreur" << std::endl;
                } else {
                    p.lancerPartie(joueurs);  
                }
                choixCorrect = true;
                break;
            case 2:
                break;
            default:
                std::cout << "Choisissez une valeur existante" << std::endl;
                break;
        }
    }
}

int main() {
        displayMenu();
        handleChoice();
    return 0;
}
