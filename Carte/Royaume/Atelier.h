
#ifndef ATELIER_H
#define ATELIER_H

#include "Royaume.h"
#include "Partie.h"
#include "Joueur.h"
#include "Carte.h"
#include <string>



class Atelier : public Royaume
{
public:
  std::string obtenirNom() const override;
  Atelier();
  virtual ~Atelier();
  void action(Joueur& joueur,Partie& p) override;
  
};

#endif 
