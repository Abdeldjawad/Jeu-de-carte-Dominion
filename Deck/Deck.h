#ifndef DECK_H
#define DECK_H

#include <string>
#include <vector>
#include "Carte.h"

class Deck
{
public:
  Deck(); // Constructeur par défaut
  virtual ~Deck(); // Va parcourir le vector de cartes d'un deck et supprime chaque carte
  Deck(std::vector<Carte*> d); // Constructor qui prend un vector de cartes en paramètre
  void afficherDeck(); // Affiche le vector de cartes contenu dans une instance Deck (utilisée pour afficher des cartes action par exemple)
  std::vector<Carte*>& getDeck(); // Getter qui renvoie le vector de cartes contenus dans une instance Deck
  void melangerDeck(); // Fonction qui va mélanger le deck (pour la défausse par exemple)
  void ajouterCarte(std::string name, std::vector<Carte*>& deck); // Permet d'ajouter une carte d'un nom "name" à un deck (utilisé dans la méthode d'achat par exemple)
  bool trouverCarte(std::string name); // Permet de trouver une carte dans un deck et renvoie true ou false

private:
  std::vector<Carte*> liste_cartes;  
  int taille;
};

#endif 
