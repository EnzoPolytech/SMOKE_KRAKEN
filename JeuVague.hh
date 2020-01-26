#pragma once
#include "Jeu.hh"

#define NB_FUMEE_LISSAGE 12

const int VITESSE_FUMEE_VAGUE = 1;
const float PROBA_APPARITION = 0.50;

class JeuVague : public Jeu
{
public:

  JeuVague(std::string nom, int niveau);

  void run();

  float alea_Proba(){return (float)rand() / (float)RAND_MAX;}

protected:
  std::map<Fumee *, int> mapFumee;

};
