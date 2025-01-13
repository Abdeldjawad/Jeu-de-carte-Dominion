
#ifndef FESTIN_H
#define FESTIN_H

#include "Royaume.h"


#include <string>
#include "Partie.h"
#include "Joueur.h"
#include "Carte.h"

class Festin : public Royaume
{
public:

  std::string obtenirNom() const override;
  Festin();
  virtual ~Festin();
  void action(Joueur& joueur,Partie& p) override;
  


};

#endif 
