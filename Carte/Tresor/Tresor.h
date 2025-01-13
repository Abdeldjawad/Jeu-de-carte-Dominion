
#ifndef TRESOR_H
#define TRESOR_H
#include "Carte.h"
#include <string>




class Tresor : virtual public Carte
{
public:
  Tresor(int c,int v); // Reprend le constructeur de Carte
  virtual ~Tresor();
  
};

#endif 
