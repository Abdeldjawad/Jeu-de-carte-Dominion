
#ifndef VOLEUR_H
#define VOLEUR_H

#include "Royaume.h"
#include "Partie.h"
#include "Joueur.h"
#include "Carte.h"
#include "Tresor.h"
#include <string>


class Voleur : public Royaume
{
public:
  std::string obtenirNom() const override;
  Voleur();
  virtual ~Voleur();
  void action(Joueur& joueur,Partie& p) override;
  
};

#endif
