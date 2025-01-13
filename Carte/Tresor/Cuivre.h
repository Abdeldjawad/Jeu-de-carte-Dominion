
#ifndef CUIVRE_H
#define CUIVRE_H

#include "Tresor.h"

#include <string>


class Cuivre : virtual public Tresor
{
public:

  std::string obtenirNom() const override;

  Cuivre();

  virtual ~Cuivre();


};

#endif 
