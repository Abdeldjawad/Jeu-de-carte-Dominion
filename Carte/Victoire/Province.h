
#ifndef PROVINCE_H
#define PROVINCE_H

#include "Victoire.h"

#include <string>


/// 
/// class Province

class Province : virtual public Victoire
{
public:
  std::string obtenirNom() const override;
  Province();
  virtual ~Province();


};

#endif 
