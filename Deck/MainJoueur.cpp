#include "MainJoueur.h"
#include "Cuivre.h"
#include "Domaine.h"

MainJoueur::MainJoueur() : Deck(createDefaultHand()) {}

MainJoueur::MainJoueur(const std::vector<Carte*>& cards) : Deck(cards) {}

MainJoueur::~MainJoueur() {}

MainJoueur MainJoueur::createDefaultHand() {
    std::vector<Carte*> deck;
    for (int i = 0; i < 7; ++i) {
        deck.push_back(new Cuivre());
    }
    for (int i = 0; i < 3; ++i) {
        deck.push_back(new Domaine());
    }
    return MainJoueur(deck);
}
