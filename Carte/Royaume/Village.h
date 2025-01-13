
#ifndef VILLAGE_H
#define VILLAGE_H

#include "Royaume.h"
#include "Royaume.h"

#include <string>
#include "Partie.h"
#include "Joueur.h"
#include "Carte.h"

class Village : public Royaume
{
public:
  std::string obtenirNom() const override;
  Village();
  virtual ~Village();
  void action(Joueur& joueur,Partie& p) override;

};

#endif 
