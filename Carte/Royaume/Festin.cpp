#include "Festin.h"
#include <iostream>



Festin::Festin():Royaume(4,4,0,0,0,0){
    setCout(4);
    setValeur(4);
}


std::string Festin::obtenirNom() const {
    return "Festin";
}

Festin::~Festin()
{
}

void Festin::action(Joueur& joueur,Partie& p){
    p.getReserve().afficherReserve();
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Choisissez une carte qui peut coûter jusqu'à 5" << std::endl;
    std::cout << "------------------------------------------ "<< std::endl;
    bool carteChoisie = false;
    while(!carteChoisie){
        int choix;
        std::cin >> choix;
        switch (choix) {
                case 1: {
                    int cost_of_card = 0; 
                    if (cost_of_card <= 5) {
                        if(p.getReserve().verifierCarte("Cuivre") == 1){
                            std::cout << "Vous avez acheté la carte 1." << std::endl;
                            p.getReserve().ajouterCarte("Cuivre",joueur.getDefausse().getDeck()); 

                            carteChoisie = true;
                        }
                        else{
                            std::cout << "\033[41mVous ne pouvez pas selectionner cette carte car il n'y en a plus\033[0m" << std::endl;
                        }                     
                    } else {
                        std::cout << "\033[41mVous n'avez pas assez d'argent pour selectionner cette carte\033[0m" << std::endl;
                    }
                    break;
                }
                case 2: {
                    int cost_of_card = 6; 
                    if (cost_of_card <= 5) {
                        if(p.getReserve().verifierCarte("Or") == 1){
                            std::cout << "Vous avez acheté la carte 2." << std::endl;
                            p.getReserve().ajouterCarte("Or",joueur.getDefausse().getDeck()); 
                             
                    
                        }
                        else{
                            std::cout << "\033[41mVous ne pouvez pas selectionner cette carte car il n'y en a plus\033[0m" << std::endl;
                        }                     
                    } else {
                        std::cout << "\033[41mVous n'avez pas assez d'argent pour selectionner cette carte\033[0m" << std::endl;
                    }
                    break;
                }
                case 3: {
                    int cost_of_card = 3; 
                    if (cost_of_card <= 5) {
                        if(p.getReserve().verifierCarte("Argent") == 1){
                            std::cout << "Vous avez acheté la carte 3." << std::endl;
                            p.getReserve().ajouterCarte("Argent",joueur.getDefausse().getDeck()); 
                            
                            carteChoisie = true;
                        }
                        else{
                            std::cout << "\033[41mVous ne pouvez pas selectionner cette carte car il n'y en a plus\033[0m" << std::endl;
                        }                     
                    } else {
                        std::cout << "\033[41mVous n'avez pas assez d'argent pour selectionner cette carte\033[0m" << std::endl;
                    }
                    break;
                }
                case 4: {
                    int cost_of_card = 2; 
                    if (cost_of_card <= 5) {
                        if(p.getReserve().verifierCarte("Domaine") == 1){
                            std::cout << "Vous avez acheté la carte 4." << std::endl;
                            p.getReserve().ajouterCarte("Domaine",joueur.getDefausse().getDeck()); 
                             
                            carteChoisie = true;
                        }
                        else{
                            std::cout << "\033[41mVous ne pouvez pas selectionner cette carte car il n'y en a plus\033[0m" << std::endl;
                        }                     
                    } else {
                        std::cout << "\033[41mVous n'avez pas assez d'argent pour selectionner cette carte\033[0m" << std::endl;
                    }
                    break;
                }
                case 5: {
                    int cost_of_card = 8; 
                    if (cost_of_card <= 5) {
                        if(p.getReserve().verifierCarte("Province") == 1){
                            std::cout << "Vous avez acheté la carte 5." << std::endl;
                            p.getReserve().ajouterCarte("Province",joueur.getDefausse().getDeck()); 
                             
                        
                        }
                        else{
                            std::cout << "\033[41mVous ne pouvez pas selectionner cette carte car il n'y en a plus\033[0m" << std::endl;
                        }                     
                    } else {
                        std::cout << "\033[41mVous n'avez pas assez d'argent pour selectionner cette carte\033[0m" << std::endl;
                    }
                    break;
                }
                case 6: {
                    int cost_of_card = 5; 
                    if (cost_of_card <= 5) {
                        if(p.getReserve().verifierCarte("Duche") == 1){
                            std::cout << "Vous avez acheté la carte 6." << std::endl;
                            p.getReserve().ajouterCarte("Duche",joueur.getDefausse().getDeck()); 
                             
                            carteChoisie = true;
                        
                        }
                        else{
                            std::cout << "\033[41mVous ne pouvez pas selectionner cette carte car il n'y en a plus\033[0m" << std::endl;
                        }                     
                    } else {
                        std::cout << "\033[41mVous n'avez pas assez d'argent pour selectionner cette carte\033[0m" << std::endl;
                    }
                    break;
                }
                case 8: {
                    int cost_of_card = 5; 
                    if (cost_of_card <= 5) {
                        if(p.getReserve().verifierCarte("Sorciere") == 1){
                            std::cout << "Vous avez acheté la carte 8." << std::endl;
                            p.getReserve().ajouterCarte("Sorciere",joueur.getDefausse().getDeck()); 
                         
                            carteChoisie = true;
                        }
                        else{
                            std::cout << "\033[41mVous ne pouvez pas selectionner cette carte car il n'y en a plus\033[0m" << std::endl;
                        }                     
                    } else {
                        std::cout << "\033[41mVous n'avez pas assez d'argent pour selectionner cette carte\033[0m" << std::endl;
                    }
                    break;
                }
                case 9: {
                    int cost_of_card = 4; 
                    if (cost_of_card <= 5) {
                        if(p.getReserve().verifierCarte("Festin") == 1){
                            std::cout << "Vous avez acheté la carte 9." << std::endl;
                            p.getReserve().ajouterCarte("Festin",joueur.getDefausse().getDeck()); 
                             
                            carteChoisie = true;
                        }
                        else{
                            std::cout << "\033[41mVous ne pouvez pas selectionner cette carte car il n'y en a plus\033[0m" << std::endl;
                        }                     
                    } else {
                        std::cout << "\033[41mVous n'avez pas assez d'argent pour selectionner cette carte\033[0m" << std::endl;
                    }
                    break;
                }
                case 10: {
                    int cost_of_card = 2; 
                    if (cost_of_card <= 5) {
                        if(p.getReserve().verifierCarte("Douve") == 1){
                            std::cout << "Vous avez acheté la carte 10." << std::endl;
                            p.getReserve().ajouterCarte("Douve",joueur.getDefausse().getDeck()); 
                            carteChoisie = true;
                        }
                        else{
                            std::cout << "\033[41mVous ne pouvez pas selectionner cette carte car il n'y en a plus\033[0m" << std::endl;
                        }                     
                    } else {
                        std::cout << "\033[41mVous n'avez pas assez d'argent pour selectionner cette carte\033[0m" << std::endl;
                    }
                    break;
                }
                case 11: {
                    int cost_of_card = 2; 
                    if (cost_of_card <= 5) {
                        if(p.getReserve().verifierCarte("Chapelle") == 1){
                            std::cout << "Vous avez acheté la carte 11." << std::endl;
                            p.getReserve().ajouterCarte("Chapelle",joueur.getDefausse().getDeck()); 
                             
                            carteChoisie = true;
                        }
                        else{
                            std::cout << "\033[41mVous ne pouvez pas selectionner cette carte car il n'y en a plus\033[0m" << std::endl;
                        }                     
                    } else {
                        std::cout << "\033[41mVous n'avez pas assez d'argent pour selectionner cette carte\033[0m" << std::endl;
                    }
                    break;
                }
                case 12: {
                    int cost_of_card = 4; 
                    if (cost_of_card <= 5) {
                        if(p.getReserve().verifierCarte("Voleur") == 1){
                            std::cout << "Vous avez acheté la carte 12." << std::endl;
                            p.getReserve().ajouterCarte("Voleur",joueur.getDefausse().getDeck()); 
                            carteChoisie = true; 
                        }
                        else{
                            std::cout << "\033[41mVous ne pouvez pas selectionner cette carte car il n'y en a plus\033[0m" << std::endl;
                        }                     
                    } else {
                        std::cout << "\033[41mVous n'avez pas assez d'argent pour selectionner cette carte\033[0m" << std::endl;
                    }
                    break;
                }
                case 13: {
                    int cost_of_card = 3; 
                    if (cost_of_card <= 5) {
                        if(p.getReserve().verifierCarte("Atelier") == 1){
                            std::cout << "Vous avez acheté la carte 13." << std::endl;
                            p.getReserve().ajouterCarte("Atelier",joueur.getDefausse().getDeck()); 
                            carteChoisie = true; 
                        }
                        else{
                            std::cout << "\033[41mVous ne pouvez pas selectionner cette carte car il n'y en a plus\033[0m" << std::endl;
                        }                     
                    } else {
                        std::cout << "\033[41mVous n'avez pas assez d'argent pour selectionner cette carte\033[0m" << std::endl;
                    }
                    break;
                }
                case 14: {
                    int cost_of_card = 3; 
                    if (cost_of_card <= 5) {
                        if(p.getReserve().verifierCarte("Bucheron") == 1){
                            std::cout << "Vous avez acheté la carte 14." << std::endl;
                            p.getReserve().ajouterCarte("Bucheron",joueur.getDefausse().getDeck()); 
                            carteChoisie = true; 
                        }
                        else{
                            std::cout << "\033[41mVous ne pouvez pas selectionner cette carte car il n'y en a plus\033[0m" << std::endl;
                        }                     
                    } else {
                        std::cout << "\033[41mVous n'avez pas assez d'argent pour selectionner cette carte\033[0m" << std::endl;
                    }
                    break;
                }
                case 15: {
                    int cost_of_card = 5; 
                    if (cost_of_card <= 5) {
                        if(p.getReserve().verifierCarte("Laboratoire") == 1){
                            std::cout << "Vous avez acheté la carte 15." << std::endl;
                            p.getReserve().ajouterCarte("Laboratoire",joueur.getDefausse().getDeck()); 
                        
                            carteChoisie = true;
                        }
                        else{
                            std::cout << "\033[41mVous ne pouvez pas selectionner cette carte car il n'y en a plus\033[0m" << std::endl;
                        }                     
                    } else {
                        std::cout << "\033[41mVous n'avez pas assez d'argent pour selectionner cette carte\033[0m" << std::endl;
                    }
                    break;
                }
                case 16: {
                    int cost_of_card = 4; 
                    if (cost_of_card <= 5) {
                        if(p.getReserve().verifierCarte("Jardin") == 1){
                            std::cout << "Vous avez acheté la carte 16." << std::endl;
                            p.getReserve().ajouterCarte("Jardin",joueur.getDefausse().getDeck()); 
                            carteChoisie = true;
                        }
                        else{
                            std::cout << "\033[41mVous ne pouvez pas selectionner cette carte car il n'y en a plus\033[0m" << std::endl;
                        }                     
                    } else {
                        std::cout << "\033[41mVous n'avez pas assez d'argent pour selectionner cette carte\033[0m" << std::endl;
                    }
                    break;
                }
                case 17: {
                    int cost_of_card = 3; 
                    if (cost_of_card <= 5) {
                        if(p.getReserve().verifierCarte("Village") == 1){
                            std::cout << "Vous avez acheté la carte 17." << std::endl;
                            p.getReserve().ajouterCarte("Village",joueur.getDefausse().getDeck()); 
                            carteChoisie = true; 
                        }
                        else{
                            std::cout << "\033[41mVous ne pouvez pas selectionner cette carte car il n'y en a plus\033[0m" << std::endl;
                        }                     
                    } else {
                        std::cout << "\033[41mVous n'avez pas assez d'argent pour selectionner cette carte\033[0m" << std::endl;
                    }
                    break;
                }
                default:
                    std::cout << "Choix invalide. Veuillez entrer un numéro entre 1 et 16. Vous ne pouvez pas sélectionner de carte Malédiction" << std::endl;
                    continue;
        }           
        }
}
    








