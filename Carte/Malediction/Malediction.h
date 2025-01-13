
#ifndef MALEDICTION_H
#define MALEDICTION_H

#include "Carte.h"

#include <string>




class Malediction : virtual public Carte
{
public:
  Malediction();
  Malediction(int c,int v);
  virtual ~Malediction();
  std::string obtenirNom() const override;


};

#endif 