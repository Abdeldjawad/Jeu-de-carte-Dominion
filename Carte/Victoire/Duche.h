
#ifndef DUCHE_H
#define DUCHE_H

#include "Victoire.h"
#include <string>



class Duche : virtual public Victoire
{
public:
  std::string obtenirNom() const override;
  Duche();
  virtual ~Duche();

};

#endif 
