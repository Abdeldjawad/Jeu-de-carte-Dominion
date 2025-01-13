
#ifndef LABORATOIRE_H
#define LABORATOIRE_H

#include "Royaume.h"
#include "Partie.h"
#include "Joueur.h"
#include "Carte.h"
#include <string>



class Laboratoire : public Royaume
{
public:
  std::string obtenirNom() const override;
  Laboratoire();
  virtual ~Laboratoire();
  void action(Joueur& joueur,Partie& p) override;
  
};

#endif 
