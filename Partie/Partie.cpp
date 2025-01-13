#include "Partie.h"


Partie::Partie(): reserve(Reserve::createReserveHand())
{
    partieTerminee =false;
    nbTours = 0;
}

Partie::~Partie()
{
}

Rebut& Partie::getRebut(){
    return rebut;
}

Reserve& Partie::getReserve(){
    return reserve;
}


void Partie::lancerPartie(std::vector<Joueur>& j) {
    while (!partieTerminee) {
        for (Joueur& joueur : j) {
            if (!partieTerminee){
                
                /* std::cout << "PRINT DECK AVANT TOUR" << std::endl;
                joueur.getDeck().afficherDeck();
                std::cout << "PRINT DEFAUSSE AVANT TOUR" << std::endl;
                joueur.getDefausse().afficherDeck();
                std::cout << "PRINT PIOCHE AVANT TOUR" << std::endl;
                joueur.getPioche().afficherDeck(); */
                tourJoueur(joueur);  
            }
        }
        partieTerminee = verifierFinPartie(j);
        nbTours++;
    }
    std::cout << "La partie est terminée après " << nbTours << " tours." << std::endl;
}

void Partie::tourJoueur(Joueur& joueur) {
    std::cout << "\033[41m                                               \033[0m" << std::endl;
    std::cout << "C'est au tour de " << joueur.getUsername() << std::endl;
    joueur.afficherDeck();
    int argent = joueur.getArgent();
    joueur.setArgentDeck(argent);
    jouerCarte(joueur);
    argent = joueur.getArgent();
    joueur.setArgentDeck(argent);
    acheter(joueur,joueur.getArgentDeck());
    /* std::cout << "PRINT DECK APRES TOUR" << std::endl;
    joueur.getDeck().afficherDeck();
    std::cout << "PRINT DEFAUSSE APRES TOUR" << std::endl;
    joueur.getDefausse().afficherDeck();
    std::cout << "PRINT PIOCHE APRES TOUR" << std::endl;
    joueur.getPioche().afficherDeck(); */
    joueur.envoyerDefausse();
    joueur.tirerMain(5);
}

void Partie::jouerCarte(Joueur& joueur){
    std::vector<Royaume*> carteAction = joueur.verifierCarteAction();
    if(carteAction.size() == 0){
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "\033[41m Vous n'avez pas de carte action à jouer \033[0m" << std::endl;
        std::cout << "------------------------------------------ "<< std::endl;
        return;
    }
    else{
        while(joueur.getnbraction() > 0 && carteAction.size()!=0){
            int input;
            bool inputCorrect = false;
            for(size_t i = 0 ; i<carteAction.size();i++){
                std::cout <<  i+1 << "-  " << carteAction[i]->obtenirNom() << std::endl;
            }
            std::cout << "---------------------------------" << std::endl;
                std::cout << "Quelle carte voulez-vous sélectionner ?" << std::endl;
                std::cout << "---------------------------------" << std::endl;
                std::cout << "Choisir 0 pour ne pas jouer de carte action" << std::endl; 
            while(inputCorrect == false){
                std::cin >> input;
                
                if(input > static_cast<int>(carteAction.size()) || input <0){
                    std::cout << "\033[41m Veuillez sélectionner une carte existante \033[0m" << std::endl;
                }
                else{
                    if(std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "\033[41mVeuillez entrer un nombre valide \033[0m" << std::endl;
                    }
                    else{
                    inputCorrect = true;
                    }
                }
            }
            if(input == 0){
                std::cout << "\033[41m Vous n'avez pas joué de carte action \033[0m" << std::endl;
                return;
            }
            else{
                carteAction[input-1]->action(joueur,*this);
                carteAction = joueur.verifierCarteAction();
                if(carteAction[input-1]->obtenirNom()!="Festin"){
                    joueur.ecarterDefausse(carteAction[input-1]);
                    joueur.afficherDeck();
                    std::cout << "------------------------------------------" << std::endl;

                }
                else{
                    ecarterRebut(joueur,carteAction[input-1]);
                    joueur.afficherDeck();
                    std::cout << "------------------------------------------" << std::endl;
                }
                joueur.setnbraction(joueur.getnbraction()-1);
                carteAction.erase(carteAction.begin() + (input - 1));  
            } 
        }
    }
}

void Partie::acheter(Joueur& joueur, int argent) {
    reserve.afficherReserve();
    std::cout << "18 - Je ne choisis pas de carte " << std::endl;
    bool choixCorrect = false;
    while (joueur.getnbrachat() > 0) {
        choixCorrect = false;
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "\033[42m Argent disponible : \033[0m" ;
        std::cout << argent << std::endl;
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "Quelle carte voulez-vous acheter ? (Entrez un numéro entre 1 et 16)" << std::endl;
        std::cout << "------------------------------------------ "<< std::endl;
        int choix;
        while(choixCorrect==false){
            std::cin >> choix;            
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Veuillez entrer un nombre valide" << std::endl;
            }
            else{
                choixCorrect=true;
            }
            std::cout << "---------------------------------" << std::endl;
        }
        switch (choix) {
            case 1: {
                int cost_of_card = 0; 
                if (argent >= cost_of_card) {
                    if(reserve.verifierCarte("Cuivre") == 1){
                        std::cout << "\033[42mVous avez acheté la carte 1\033[0m" << std::endl;
                        argent -= cost_of_card;
                        reserve.ajouterCarte("Cuivre",joueur.getDefausse().getDeck()); 
                        joueur.setnbrachat(joueur.getnbrachat()-1); 
                    }
                    else{
                        std::cout << "\033[41mVous ne pouvez pas acheter cette carte car il n'y en a plus\033[0m" << std::endl;
                    }                     
                } else {
                    std::cout << "\033[41mVous n'avez pas assez d'argent pour acheter cette carte\033[0m" << std::endl;
                }
                break;
            }
            case 2: {
                int cost_of_card = 6; 
                if (argent >= cost_of_card) {
                    if(reserve.verifierCarte("Or") == 1){
                        std::cout << "\033[42mVous avez acheté la carte 2\033[0m" << std::endl;
                        argent -= cost_of_card;
                        reserve.ajouterCarte("Or",joueur.getDefausse().getDeck()); 
                        joueur.setnbrachat(joueur.getnbrachat()-1); 
                    }
                    else{
                        std::cout << "\033[41mVous ne pouvez pas acheter cette carte car il n'y en a plus\033[0m" << std::endl;
                    }                     
                } else {
                    std::cout << "\033[41mVous n'avez pas assez d'argent pour acheter cette carte\033[0m" << std::endl;
                }
                break;
            }
            case 3: {
                int cost_of_card = 3;
                if (argent >= cost_of_card) {
                    if(reserve.verifierCarte("Argent") == 1){
                        std::cout << "\033[42mVous avez acheté la carte 3\033[0m" << std::endl;
                        argent -= cost_of_card;
                        reserve.ajouterCarte("Argent",joueur.getDefausse().getDeck()); 
                        joueur.setnbrachat(joueur.getnbrachat()-1);
                    }
                    else{
                        std::cout << "\033[41mVous ne pouvez pas acheter cette carte car il n'y en a plus\033[0m" << std::endl;
                    }                     
                } else {
                    std::cout << "\033[41mVous n'avez pas assez d'argent pour acheter cette carte\033[0m" << std::endl;
                }
                break;
            }
            case 4: {
                int cost_of_card = 2; 
                if (argent >= cost_of_card) {
                    if(reserve.verifierCarte("Domaine") == 1){
                        std::cout << "\033[42mVous avez acheté la carte 4\033[0m" << std::endl;
                        argent -= cost_of_card;
                        reserve.ajouterCarte("Domaine",joueur.getDefausse().getDeck()); 
                        joueur.setnbrachat(joueur.getnbrachat()-1);
                    }
                    else{
                        std::cout << "\033[41mVous ne pouvez pas acheter cette carte car il n'y en a plus\033[0m" << std::endl;
                    }                     
                } else {
                    std::cout << "\033[41mVous n'avez pas assez d'argent pour acheter cette carte\033[0m" << std::endl;
                }
                break;
            }
            case 5: {
                int cost_of_card = 8; 
                if (argent >= cost_of_card) {
                    if(reserve.verifierCarte("Province") == 1){
                        std::cout << "\033[42mVous avez acheté la carte 5\033[0m" << std::endl;
                        argent -= cost_of_card;
                        reserve.ajouterCarte("Province",joueur.getDefausse().getDeck()); 
                        joueur.setnbrachat(joueur.getnbrachat()-1); 
                    }
                    else{
                        std::cout << "\033[41mVous ne pouvez pas acheter cette carte car il n'y en a plus\033[0m" << std::endl;
                    }                     
                } else {
                    std::cout << "\033[41mVous n'avez pas assez d'argent pour acheter cette carte\033[0m" << std::endl;
                }
                break;
            }
            case 6: {
                int cost_of_card = 5; 
                if (argent >= cost_of_card) {
                    if(reserve.verifierCarte("Duche") == 1){
                        std::cout << "\033[42mVous avez acheté la carte 6\033[0m" << std::endl;
                        argent -= cost_of_card;
                        reserve.ajouterCarte("Duche",joueur.getDefausse().getDeck()); 
                        joueur.setnbrachat(joueur.getnbrachat()-1); 
                    }
                    else{
                        std::cout << "\033[41mVous ne pouvez pas acheter cette carte car il n'y en a plus\033[0m" << std::endl;
                    }                     
                } else {
                    std::cout << "\033[41mVous n'avez pas assez d'argent pour acheter cette carte\033[0m" << std::endl;
                }
                break;
            }
            case 8: {
                int cost_of_card = 5; 
                if (argent >= cost_of_card) {
                    if(reserve.verifierCarte("Sorciere") == 1){
                        std::cout << "\033[42mVous avez acheté la carte 8\033[0m" << std::endl;
                        argent -= cost_of_card;
                        reserve.ajouterCarte("Sorciere",joueur.getDefausse().getDeck());
                        joueur.setnbrachat(joueur.getnbrachat()-1); 
                    }
                    else{
                        std::cout << "\033[41mVous ne pouvez pas acheter cette carte car il n'y en a plus\033[0m" << std::endl;
                    }                     
                } else {
                    std::cout << "\033[41mVous n'avez pas assez d'argent pour acheter cette carte\033[0m" << std::endl;
                }
                break;
            }
            case 9: {
                int cost_of_card = 4; 
                if (argent >= cost_of_card) {
                    if(reserve.verifierCarte("Festin") == 1){
                        std::cout << "\033[42mVous avez acheté la carte 9\033[0m" << std::endl;
                        argent -= cost_of_card;
                        reserve.ajouterCarte("Festin",joueur.getDefausse().getDeck()); 
                        joueur.setnbrachat(joueur.getnbrachat()-1); 
                    }
                    else{
                        std::cout << "\033[41mVous ne pouvez pas acheter cette carte car il n'y en a plus\033[0m" << std::endl;
                    }                     
                } else {
                    std::cout << "\033[41mVous n'avez pas assez d'argent pour acheter cette carte\033[0m" << std::endl;
                }
                break;
            }
            case 10: {
                int cost_of_card = 2; 
                if (argent >= cost_of_card) {
                    if(reserve.verifierCarte("Douve") == 1){
                        std::cout << "\033[42mVous avez acheté la carte 10\033[0m" << std::endl;
                        argent -= cost_of_card;
                        reserve.ajouterCarte("Douve",joueur.getDefausse().getDeck()); 
                        joueur.setnbrachat(joueur.getnbrachat()-1); 
                    }
                    else{
                        std::cout << "\033[41mVous ne pouvez pas acheter cette carte car il n'y en a plus\033[0m" << std::endl;
                    }                     
                } else {
                    std::cout << "\033[41mVous n'avez pas assez d'argent pour acheter cette carte\033[0m" << std::endl;
                }
                break;
            }
            case 11: {
                int cost_of_card = 2; 
                if (argent >= cost_of_card) {
                    if(reserve.verifierCarte("Chapelle") == 1){
                        std::cout << "\033[42mVous avez acheté la carte 11\033[0m" << std::endl;
                        argent -= cost_of_card;
                        reserve.ajouterCarte("Chapelle",joueur.getDefausse().getDeck()); 
                        joueur.setnbrachat(joueur.getnbrachat()-1); 
                    }
                    else{
                        std::cout << "\033[41mVous ne pouvez pas acheter cette carte car il n'y en a plus\033[0m" << std::endl;
                    }                     
                } else {
                    std::cout << "\033[41mVous n'avez pas assez d'argent pour acheter cette carte\033[0m" << std::endl;
                }
                break;
            }
            case 12: {
                int cost_of_card = 4; 
                if (argent >= cost_of_card) {
                    if(reserve.verifierCarte("Voleur") == 1){
                        std::cout << "\033[42mVous avez acheté la carte 12\033[0m" << std::endl;
                        argent -= cost_of_card;
                        reserve.ajouterCarte("Voleur",joueur.getDefausse().getDeck()); 
                        joueur.setnbrachat(joueur.getnbrachat()-1); 
                    }
                    else{
                        std::cout << "\033[41mVous ne pouvez pas acheter cette carte car il n'y en a plus\033[0m" << std::endl;
                    }                     
                } else {
                    std::cout << "\033[41mVous n'avez pas assez d'argent pour acheter cette carte\033[0m" << std::endl;
                }
                break;
            }
            case 13: {
                int cost_of_card = 3; 
                if (argent >= cost_of_card) {
                    if(reserve.verifierCarte("Atelier") == 1){
                        std::cout << "\033[42mVous avez acheté la carte 13\033[0m" << std::endl;
                        argent -= cost_of_card;
                        reserve.ajouterCarte("Atelier",joueur.getDefausse().getDeck()); 
                        joueur.setnbrachat(joueur.getnbrachat()-1); 
                    }
                    else{
                        std::cout << "\033[41mVous ne pouvez pas acheter cette carte car il n'y en a plus\033[0m" << std::endl;
                    }                     
                } else {
                    std::cout << "\033[41mVous n'avez pas assez d'argent pour acheter cette carte\033[0m" << std::endl;
                }
                break;
            }
            case 14: {
                int cost_of_card = 3; 
                if (argent >= cost_of_card) {
                    if(reserve.verifierCarte("Bucheron") == 1){
                        std::cout << "\033[42mVous avez acheté la carte 14\033[0m" << std::endl;
                        argent -= cost_of_card;
                        reserve.ajouterCarte("Bucheron",joueur.getDefausse().getDeck()); 
                        joueur.setnbrachat(joueur.getnbrachat()-1); 
                    }
                    else{
                        std::cout << "\033[41mVous ne pouvez pas acheter cette carte car il n'y en a plus\033[0m" << std::endl;
                    }                     
                } else {
                    std::cout << "\033[41mVous n'avez pas assez d'argent pour acheter cette carte\033[0m" << std::endl;
                }
                break;
            }
            case 15: {
                int cost_of_card = 5;
                if (argent >= cost_of_card) {
                    if(reserve.verifierCarte("Laboratoire") == 1){
                        std::cout << "\033[42mVous avez acheté la carte 15\033[0m" << std::endl;
                        argent -= cost_of_card;
                        reserve.ajouterCarte("Laboratoire",joueur.getDefausse().getDeck()); 
                        joueur.setnbrachat(joueur.getnbrachat()-1);
                    }
                    else{
                        std::cout << "\033[41mVous ne pouvez pas acheter cette carte car il n'y en a plus\033[0m" << std::endl;
                    }                     
                } else {
                    std::cout << "\033[41mVous n'avez pas assez d'argent pour acheter cette carte\033[0m" << std::endl;
                }
                break;
            }
            case 16: {
                int cost_of_card = 4; 
                if (argent >= cost_of_card) {
                    if(reserve.verifierCarte("Jardin") == 1){
                        std::cout << "\033[42mVous avez acheté la carte 16\033[0m" << std::endl;
                        argent -= cost_of_card;
                        reserve.ajouterCarte("Jardin",joueur.getDefausse().getDeck()); 
                        joueur.setnbrachat(joueur.getnbrachat()-1); 
                    }
                    else{
                        std::cout << "\033[41mVous ne pouvez pas acheter cette carte car il n'y en a plus\033[0m" << std::endl;
                    }                     
                } else {
                    std::cout << "\033[41mVous n'avez pas assez d'argent pour acheter cette carte\033[0m" << std::endl;
                }
                break;
            }
            case 17: {
                int cost_of_card = 3;
                if (argent >= cost_of_card) {
                    if(reserve.verifierCarte("Village") == 1){
                        std::cout << "\033[42mVous avez acheté la carte 17\033[0m" << std::endl;
                        argent -= cost_of_card;
                        reserve.ajouterCarte("Village",joueur.getDefausse().getDeck()); 
                        joueur.setnbrachat(joueur.getnbrachat()-1); 
                    }
                    else{
                        std::cout << "\033[41mVous ne pouvez pas acheter cette carte car il n'y en a plus\033[0m" << std::endl;
                    }                     
                } else {
                    std::cout << "\033[41mVous n'avez pas assez d'argent pour acheter cette carte\033[0m" << std::endl;
                }
                break;
            }
            case 18: {
                std::cout << "\033[42mVous avez fait le choix de ne rien acheter\033[0m" << std::endl;
                joueur.setnbrachat(joueur.getnbrachat()-1); 
                break;
                
            }
            default:
                std::cout << "Choix invalide. Veuillez entrer un numéro entre 1 et 18. Vous ne pouvez pas acheter de carte Malédiction." << std::endl;
                continue; 
                
        }

        
    }
    joueur.setnbrachat(1);
    joueur.setnbraction(1);
}


bool Partie::verifierFinPartie(std::vector<Joueur>& j) {
    if(!reserve.verifierCarte("Province") || reserve.compterPacket() <15 || nbTours>=30){
        int n1 = j[0].compterPointVictoire();
        int n2 = j[1].compterPointVictoire();
        if(n1>n2){
            std::cout << "\033[42mPartie gagnée par \033[0m" << j[0].getUsername() << "\033[42mavec \033[0m" << n1 << "\033[42mpoints de victoire contre  \033[0m" << n2 << std::endl;
        }
        else{
            if(n2>n1){
                std::cout << "\033[42mPartie gagnée par \033[0m" << j[1].getUsername() << "\033[42mavec \033[0m" << n2 << "\033[42mpoints de victoire contre  \033[0m" << n1 << std::endl;
            }
            else{
                std::cout << "\033[41mIl y a égalité \033[0m"  << "\033[41mavec \033[0m" << n1 << "\033[42mpoints de victoire \033[0m" <<std::endl;
            }
        }
        j[0].getListe().clear();
        return true;
    }
    return false;  
}


void Partie::ecarterRebut(Joueur& j, Carte* c) {
    rebut.getDeck().push_back(c);
    std::vector<Carte*>& deck = j.getDeck().getDeck();
    auto it = std::find(deck.begin(), deck.end(), c); 
    if (it != deck.end()) {
        deck.erase(it);
    }
}

void Partie::afficherEtatPartie(){
    std::cout << "" << std::endl;
}
