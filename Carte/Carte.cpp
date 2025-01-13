#include "Carte.h"
#include <iostream>




Carte::Carte(){}

Carte::Carte(int c,int v): cout(c),valeur(v)
{
}

Carte::~Carte()
{
}


int Carte::getCout()
{
  return cout;
}

int Carte::getValeur()
{
  return valeur;
  
}


void Carte::setCout(int c)
{
  cout = c;
}


void Carte::setValeur(int v)
{
  valeur = v;
}






