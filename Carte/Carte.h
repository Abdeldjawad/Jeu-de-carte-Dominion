
#ifndef CARTE_H
#define CARTE_H



#include <string>
#include <vector>


class Partie;
class Joueur;


class Carte 
{
public:
  Carte(); 
  Carte(int c,int v); // Constructeur qui initalise une carte avec un cout et une valeur
  virtual ~Carte(); 
  int getCout(); // Getter du cout d'une carte
  virtual int getValeur(); // Getter du valeur d'une carte
  void setCout(int c); // Setter du cout
  void setValeur(int v); // Setter de la valeur d'une carte
  virtual std::string obtenirNom() const = 0; // Fonction virtuelle pure qui n'est pas implémentée dans Carte.cpp mais elle est implémentée dans chaque carte (Royaume, Trésor, Victoire)

protected:
  int cout;
  int valeur;
};

#endif 
