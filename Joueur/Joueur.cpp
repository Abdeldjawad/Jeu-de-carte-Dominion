#include "Joueur.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


std::vector<Joueur> Joueur::liste_inscrit;

Joueur::Joueur(std::string u) : username(u), deck(MainJoueur::createDefaultHand()), nbr_action(1), nbr_pioche(0), nbr_achat(1) {
  deck.melangerDeck();
  envoyerPioche();
  tirerMain(5);
  }

Joueur::Joueur(const Joueur& other) 
    : username(other.username), deck(MainJoueur::createDefaultHand()), nbr_action(1),nbr_pioche(0),nbr_achat(1) {
      deck.melangerDeck();
      envoyerPioche();
      tirerMain(5);
      
}

Joueur::~Joueur() {
}


std::string Joueur::getUsername(){
  return username;
}

void Joueur::afficherDeck() {
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Le deck de " << username << " est : " << std::endl;
    deck.Deck::afficherDeck();
}

void Joueur::inscrire() { 
    std::string input;
    std::cout << "Entrez l'username du premier joueur" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    std::cin >> input;
    Joueur j(input); 
    liste_inscrit.push_back(j);  
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Premier utilisateur inscrit" << std::endl;
    std::cout << "---------------------------------" << std::endl;

    std::string input2;
    bool usernameCorrect = false;
    std::cout << "Entrez l'username du deuxième joueur" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    while(usernameCorrect == false){
      std::cin >> input2;
      if(input2 == input){
        std::cout << "Entrez un username correct" << std::endl;
      }
      else{
        usernameCorrect = true;
      }
    }
    Joueur j2(input2); 
    liste_inscrit.push_back(j2);  
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Deuxième utilisateur inscrit" << std::endl;
    std::cout << "---------------------------------" << std::endl;
}

std::vector<Joueur>& Joueur::getListe() {
    return liste_inscrit;
}

int Joueur::getnbraction(){
  return nbr_action;
}

int Joueur::getnbrpioche(){
  return nbr_pioche;
}

int Joueur::getnbrachat(){
  return nbr_achat;
}

void Joueur::setnbraction(int a){
  nbr_action = a;
}

void Joueur::setnbrpioche(int p){
  nbr_pioche = p;
}

void Joueur::setnbrachat(int a){
  nbr_achat = a;
}

int Joueur::getArgent(){
  int n = 0;
  for(Carte* c: deck.getDeck()){
    if(c->obtenirNom() == "Cuivre"){
      n = n + 1;
    }
    else{
      if(c->obtenirNom() == "Argent"){
        n = n + 2;
      }
      else{
        if(c->obtenirNom() == "Or"){
          n = n + 3;
        }
      }
    }
  }
  return n;
}

std::vector<Royaume*> Joueur::verifierCarteAction() {
    std::vector<Royaume*> carteAction;
    for (Carte* c : deck.getDeck()) {
      if(c->obtenirNom()!= "Jardin"){
        if (Royaume* royaume = dynamic_cast<Royaume*>(c)) {
            std::cout << c->obtenirNom() << " est une carte Royaume " << std::endl;
            carteAction.push_back(royaume);
        }
      }
    }
    return carteAction;
}


MainJoueur& Joueur::getDeck(){
  return deck;
}


Pioche& Joueur::getPioche(){
  return pioche;
}

Defausse& Joueur::getDefausse(){
  return defausse;
}

void Joueur::envoyerDefausse(){
    while (!deck.getDeck().empty()) {
        defausse.getDeck().push_back(deck.getDeck().back());
        deck.getDeck().pop_back();
    }
}

void Joueur::envoyerPioche(){
    while (!deck.getDeck().empty()) {
        pioche.getDeck().push_back(deck.getDeck().back());
        deck.getDeck().pop_back();
    }
}


void Joueur::ecarterDefausse(Carte* c){
  defausse.getDeck().push_back(c);
  std::vector<Carte*>& deck = getDeck().getDeck();
  auto it = std::find(deck.begin(), deck.end(), c); 
  if (it != deck.end()) {
    deck.erase(it); 
  }
}



void Joueur::tirerMain(int n){
  int i=0;
  while(i < n ){
      if(!pioche.getDeck().empty()){
        deck.getDeck().push_back(pioche.getDeck().back());
        pioche.getDeck().pop_back();
        i++;
      }
      else{
        inverserPiocheDefausse();
      } 
  }
}


void Joueur::inverserPiocheDefausse(){
  defausse.melangerDeck();
  while (!defausse.getDeck().empty()) {
        pioche.getDeck().push_back(defausse.getDeck().back());
        defausse.getDeck().pop_back();
    }
}


void Joueur::setArgentDeck(int n){
  argentDeck = n;
}
    
int Joueur::getArgentDeck(){
  return argentDeck;
}

int Joueur::compterPointVictoire(){
  int n = 0;
  int z = 0;
  int total = 0;
  for(Carte* c:getDeck().getDeck()){
      if(dynamic_cast<Victoire*>(c)){
        n = n + c->getValeur();
      }
      if(dynamic_cast<Jardin*>(c)){
        z++;
      }
      if(dynamic_cast<Malediction*>(c)){
        n = n-1;
      }
  }
  for(Carte* c:getPioche().getDeck()){
    if(dynamic_cast<Victoire*>(c)){
        n = n + c->getValeur();
      }
    if(dynamic_cast<Jardin*>(c)){
        z++;
      }
    if(dynamic_cast<Malediction*>(c)){
        n = n-1;
      }
  }
  for(Carte* c:getDefausse().getDeck()){
    if(dynamic_cast<Victoire*>(c)){
        n = n + c->getValeur();
      }
    if(dynamic_cast<Jardin*>(c)){
        z++;
      }
    if(dynamic_cast<Malediction*>(c)){
        n = n-1;
      }
  }
  total = getPioche().getDeck().size() + getDeck().getDeck().size() + getDefausse().getDeck().size();
  n = n + (total/10) * z;
  return n;
}