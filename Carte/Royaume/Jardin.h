
#ifndef JARDIN_H
#define JARDIN_H

#include "Royaume.h"

#include "Partie.h"
#include "Joueur.h"
#include "Carte.h"
#include <string>
#include <string>


class Jardin : public Royaume
{
public:
  std::string obtenirNom() const override;
  Jardin();
  virtual ~Jardin();
  void a_jardin();
  void action(Joueur& joueur,Partie& p) override;
  

};

#endif
