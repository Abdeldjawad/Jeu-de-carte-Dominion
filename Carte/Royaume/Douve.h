
#ifndef DOUVE_H
#define DOUVE_H

#include "Royaume.h"


#include <string>
#include "Partie.h"
#include "Joueur.h"
#include "Carte.h"
#include "Tresor.h"


class Douve : public Royaume
{
public:
  std::string obtenirNom() const override;
  Douve();
  virtual ~Douve();
  void action(Joueur& joueur,Partie& p) override;

};

#endif 
