
#ifndef ROYAUME_H
#define ROYAUME_H

#include "Carte.h"
#include <string>


class Joueur;
class Partie;

class Royaume : virtual public Carte
{
public:
  Royaume();
  Royaume(int c,int v,int b_achat,int b_pioche,int b_action,int b_argent);  // Constructeur qui va utiliser le constructeur de Carte et qui va ajouter 3 attributs, bonus pioche, bonus action et bonus argent
  virtual ~Royaume();
  virtual void action(Joueur& joueur,Partie& p) =0 ; // Méthode virtuelle pure qui doit être implémentée dans chaque classe fille de Royaume
  int getBonusAchat(); 
  int getBonusPioche();
  int getBonusAction();
  int getBonusArgent();
  void setBonusAchat(int b);
  void setBonusPioche(int b);
  void setBonusAction(int b);
  void setBonusArgent(int b);
  
protected:
  int bonus_achat;
  int bonus_pioche;
  int bonus_action;
  int bonus_argent;
private:
  void initAttributes();

};

#endif 
