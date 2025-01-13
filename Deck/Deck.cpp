#include "Deck.h"
#include <iostream>
#include <algorithm>
#include <random> 
#include <cstdlib>  
#include <ctime>
#include "Domaine.h"
#include "Cuivre.h"
#include "Carte.h"
#include "MainJoueur.h"


Deck::Deck() {
  taille = 0;  
}

Deck::Deck(std::vector<Carte*> d){
  liste_cartes = d;
  taille = d.size();
}

Deck::~Deck() {
  for (Carte* carte : liste_cartes) {
    delete carte; 
  }
}

void Deck::afficherDeck() {
  for (size_t i = 0; i < liste_cartes.size(); i++) {
    std::cout << "Carte n°" << i << " : " << liste_cartes[i]->obtenirNom() << std::endl;  // Use -> for pointer dereferencing
  }
}



std::vector<Carte*>& Deck::getDeck(){
  return liste_cartes;
}

void Deck::ajouterCarte(std::string name, std::vector<Carte*>& deck) {
    for (Carte*& c : liste_cartes) {
        if (c->obtenirNom() == name) {
            deck.push_back(c); 
            auto it = std::find(liste_cartes.begin(), liste_cartes.end(), c);
            if (it != liste_cartes.end()) {
                liste_cartes.erase(it);
            }
            break; 
        }
    }
}

bool Deck::trouverCarte(std::string name){
  for(Carte* c:getDeck()){
    if(c->obtenirNom()== name){
      return true;
    }
  }
  return false;
}



void Deck::melangerDeck() {
  std::srand(static_cast<unsigned int>(std::time(nullptr)));
  std::random_device rd;
  std::mt19937 rng(rd());  
  std::shuffle(liste_cartes.begin(), liste_cartes.end(), rng);
}


