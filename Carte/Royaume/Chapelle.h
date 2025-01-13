#ifndef CHAPELLE_H
#define CHAPELLE_H

#include "Royaume.h"
#include "Partie.h"
#include "Joueur.h"
#include "Carte.h"

#include <string>

class Partie;

class Chapelle : public Royaume
{
public:
  std::string obtenirNom() const override;
  Chapelle();
  virtual ~Chapelle();
  void action(Joueur& joueur,Partie& p) override;

};

#endif 
