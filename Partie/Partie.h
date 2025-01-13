#ifndef PARTIE_H
#define PARTIE_H

#include <string>
#include <vector>
#include "Joueur.h"
#include "Deck.h"
#include "Reserve.h"
#include "Rebut.h"
#include <algorithm>
#include "Royaume.h"
#include <limits>


class Partie
{
public:
    Partie(); // Instancie une partie avec nbTours = 0, Partieterminée = false et une réserve
    virtual ~Partie();
    void lancerPartie(std::vector<Joueur>& j); // Méthode qui lance la partie
    void tourJoueur(Joueur& joueur); // Méthode qui va gérer le tour de chaque joueur
    void jouerCarte(Joueur& joueur); // Méthode qui va gérer l'utilisation des cartes d'action
    void afficherEtatPartie();
    bool verifierFinPartie(std::vector<Joueur>& j); // Méthode qui va vérifier les conditions de fin de partie
    void acheter(Joueur& joueur,int argent); // Méthode qui va gérer l'achat de cartes dans la réserve
    void ecarterRebut(Joueur& j, Carte* c); // Méthode qui va écarter des cartes vers le rébut (comme la carte Festin et la carte Voleur)
    Rebut& getRebut(); // Getter qui renvoie le rebut de la partie
    Reserve& getReserve(); // Getter qui renvoie la réserve de la partie

private:
    int nbTours;                  
    bool partieTerminee;    
    Reserve reserve;    
    Rebut rebut;

    void initialiserJoueurs();  
};

#endif
