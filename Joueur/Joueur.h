#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
#include <string>
#include <vector>
#include "MainJoueur.h"
#include "Carte.h"
#include "Royaume.h"
#include "Pioche.h"
#include "Defausse.h"
#include "Victoire.h"
#include "Jardin.h"
#include "Malediction.h"

class Joueur
{
public:
    Joueur(std::string u);  // Constructeur qui prend qu'un username en paramètre
    Joueur(const Joueur& other); // Constructeur de copie (qui nous a permis d'éviter des segmentation fault lorsque des objets sont détruits)
    virtual ~Joueur();  // Destructeur virtuel (dans ce cas là, il n'y a pas réellement d'intérêt mais dans les classes parents comme Carte, ça permet d'être sûr qu'on utilise le bon destructeur)
    void afficherDeck(); // Méthode qui affiche la main d'un joueur (utilisée à chaque tour)
    static void inscrire();  // Fonction qui va inscrire les deux utilisateurs en prenant leur username et ensuite créer deux instances de cette classe
    std::string getUsername(); // Getter qui renvoie l'username d'une instance joueur

    static std::vector<Joueur>& getListe(); //Getter qui va renvoyer la liste des inscrits (qui est un champ de classe) pour qu'on puisse y accéder d'autres classes
    int getnbraction(); // Getter du nombre d'actions restantes du joueur 
    int getnbrpioche(); // Getter du nombre de cartes qu'on doit piocher
    int getnbrachat(); // Getter du nombre d'achats restants du joueur
    void setnbraction(int a); // Setter du nbr d'action
    void setnbrpioche(int p); // Setter du nbr de cartes à piocher
    void setnbrachat(int a); // Setter du nbr d'achats
    int getArgent(); // Méthode qui calcule l'argent contenue dans la main du joueur
    std::vector<Royaume*> verifierCarteAction(); // Méthode qui vérifie si la main du joueur contient des cartes actions
    MainJoueur& getDeck(); // Getter de la main du joueur
    Pioche& getPioche(); // Getter de la pioche du joueur
    Defausse& getDefausse(); // Getter de la défausse du joueur
    void envoyerDefausse(); // Méthode qui envoie les cartes de la main du joueur vers la défausse (à chaque fin de tour) 
    void tirerMain(int n); // Méthode qui tire la main du joueur (de la pioche) et qui inverse la défausse et la pioche si la pioche est vide
    void envoyerPioche(); // Méthode qui envoie les cartes de la main du joueur vers la pioche (utilisé à l'initalisation)
    void inverserPiocheDefausse(); // Inverse pioche et défausse lorsque la pioche est vide (en mélangeant la défausse au préalable)
    void ecarterDefausse(Carte* c); // Méthode qui envoie les cartes vers la défausse (les cartes achetées par exemple)
    void setArgentDeck(int n); // Permet d'ajouter de l'argent à l'utilisateur (utile pour la carte bûcheron par exemple)
    int getArgentDeck(); 
    int compterPointVictoire(); // Compte les points de victoire à la fin de la partie
private:
    static std::vector<Joueur> liste_inscrit;
    std::string username;  
    MainJoueur deck;
    Pioche pioche;
    Defausse defausse;  
    int nbr_action;
    int nbr_pioche;
    int nbr_achat;
    int argentDeck;
};

#endif 
