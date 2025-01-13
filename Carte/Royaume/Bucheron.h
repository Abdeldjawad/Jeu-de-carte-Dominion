
#ifndef BUCHERON_H
#define BUCHERON_H

#include "Royaume.h"

#include <string>
#include "Partie.h"
#include "Joueur.h"
#include "Carte.h"


class Bucheron : public Royaume
{
public:
  std::string obtenirNom() const override;
  Bucheron();
  virtual ~Bucheron();
  void action(Joueur& joueur,Partie& p) override;
  
};

#endif 
