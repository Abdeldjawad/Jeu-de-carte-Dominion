
#ifndef DOMAINE_H
#define DOMAINE_H

#include "Victoire.h"

#include <string>

class Domaine : virtual public Victoire
{
public:
  std::string obtenirNom() const override;
  Domaine();
  virtual ~Domaine();


};

#endif 
