#ifndef RESERVE_H
#define RESERVE_H

#include "Deck.h"
#include <vector>
#include <string>

class Or;
class Cuivre;
class Argent;
class Domaine;
class Province;
class Duche;
class Malediction;
class Sorciere;
class Festin;
class Douve;
class Chapelle;
class Voleur;
class Atelier;
class Bucheron;
class Laboratoire;
class Jardin;
class Village;


class Reserve : public Deck
{
public:
    Reserve(const std::vector<Carte*>& cards); // Constructeur qui va construire la réserve en créeant un vector contenant toutes les différentes cartes (en faisant appel à creerReserveHand())
    Reserve();
    virtual ~Reserve();
    void afficherReserve(); // Affiche la réserve en utilisant un dictionnaire afin de garder le même nombre pour un carte donnée et ainsi ne pas poser de problème avec le switch case
    static Reserve createReserveHand(); // Cette méthode crée la réserve en utilsant des boucles for et en créeant des instances de chaque type de carte et comptabilise le nombre de cartes restantes
    int verifierCarte(std::string name); // Méthode qui vérifie si un packet est vide (utilisée pour détecter la fin de partie pour la carte province)
    int compterPacket(); // Calcule le nombre de packets restants pour détecter la fin de partie    
private:
    std::vector<Carte*> cards;
};

#endif
