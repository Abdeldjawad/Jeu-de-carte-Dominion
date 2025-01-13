
#ifndef ARGENT_H
#define ARGENT_H

#include "Tresor.h"
#include <string>



class Argent : virtual public Tresor
{
public:
  std::string obtenirNom() const override;  
  Argent();
  virtual ~Argent();


};

#endif 
