#include "Royaume.h"

// Constructors/Destructors



Royaume::Royaume()
{
}

Royaume::Royaume(int c,int v,int b_achat,int b_pioche,int b_action,int b_argent):Carte(c,v),bonus_achat(b_achat),bonus_pioche(b_pioche),bonus_action(b_action),bonus_argent(b_argent){}

Royaume::~Royaume()
{}

int Royaume::getBonusAchat(){
  return bonus_achat;
}

int Royaume::getBonusPioche(){
  return bonus_pioche;
}

int Royaume::getBonusAction(){
  return bonus_action;
}

int Royaume::getBonusArgent(){
  return bonus_argent;
}

void Royaume::setBonusAchat(int b){
  bonus_achat = b;
}

void Royaume::setBonusPioche(int b){
  bonus_pioche = b;
}

void Royaume::setBonusAction(int b){
  bonus_action = b;
}

void Royaume::setBonusArgent(int b){
  bonus_argent = b;
}





