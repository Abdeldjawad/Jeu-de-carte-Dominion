
#ifndef VICTOIRE_H
#define VICTOIRE_H

#include "Carte.h"
#include "Carte.h"

#include <string>
#include <iostream>



class Victoire : virtual public Carte
{
public:
  Victoire();
  Victoire(int c,int v); // Reprend le constructeur de carte
  virtual ~Victoire();

};

#endif 
