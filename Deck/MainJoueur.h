
#ifndef MAINJOUEUR_H
#define MAINJOUEUR_H

#include "Deck.h"
#include <string>


class MainJoueur : public Deck {
public:
    MainJoueur();  
    MainJoueur(const std::vector<Carte*>& cards); // Initialise la main d'un joueur en faisant appel à la fonction createDefaultHand()
    virtual ~MainJoueur();
    static MainJoueur createDefaultHand(); // Créer la main d'un joueur avec 7 cartes Cuivre et 3 cartes Domaine
};

#endif 
