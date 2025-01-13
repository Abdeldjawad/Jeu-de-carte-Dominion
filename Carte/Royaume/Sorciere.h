
#ifndef SORCIERE_H
#define SORCIERE_H

#include "Royaume.h"
#include "Partie.h"
#include "Joueur.h"
#include "Carte.h"
#include <string>



class Sorciere : public Royaume
{
public:
  std::string obtenirNom() const override;
  Sorciere();
  virtual ~Sorciere();
  void action(Joueur& joueur,Partie& p) override;
  
};

#endif 
