#include "Chapelle.h"
#include <iostream>



Chapelle::Chapelle():Royaume(2,2,0,0,0,0){
    setCout(2);
    setValeur(2);
}

Chapelle::~Chapelle()
{
}


std::string Chapelle::obtenirNom() const {
    return "Chapelle";
}



void Chapelle::action(Joueur& joueur,Partie& p) {
    int input;
    bool inputCorrect =false;
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Combien de cartes voulez vous écarter ?" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    while(inputCorrect == false){
        std::cin >> input;
        if(input <= 4 && input >= 0){
            inputCorrect = true;
        }
        else{
            std::cout << "\033[41mVeuillez introduire une valeur valide\033[0m" << std::endl;
        }
    }
    inputCorrect=false;
    int input2;
    for(int i = 0;i<input ; i++){
        inputCorrect=false;
        joueur.afficherDeck();
        std::cout << "Quelle carte voulez-vous écarter ? " << std::endl;
        while(inputCorrect == false){
            std::cin >>input2;
            if(input2 > static_cast<int>(joueur.getDeck().getDeck().size() - 1 ) || input2<0 ){
                std::cout << "\033[41mVeuillez introduire une valeur valide\033[0m" << std::endl;    
            }
            else{if(joueur.getDeck().getDeck()[input2]->obtenirNom() == "Chapelle"){
                std::cout << "\033[41mVous ne pouvez pas écarter la carte chapelle\033[0m" << std::endl;  
                }
                else{
                    inputCorrect = true;
                }
            }
        }
        p.ecarterRebut(joueur, joueur.getDeck().getDeck()[input2]);
        std::cout << "\033[42mCette carte a été écarté du jeu\033[0m" << std::endl;
    }
    
}





