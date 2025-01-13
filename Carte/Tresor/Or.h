
#ifndef OR_H
#define OR_H

#include "Tresor.h"
#include <string>


class Or : virtual public Tresor
{
public:
  std::string obtenirNom() const override;
  Or();
  virtual ~Or();


};

#endif // OR_H
