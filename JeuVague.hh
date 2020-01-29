#pragma once
#include "Jeu.hh"
#include "Objet.hh"

#define NB_FUMEE_LISSAGE 12

const int VITESSE_FUMEE_VAGUE = 1;
const float PROBA_APPARITION = 0.50;

class JeuVague : public Jeu
{
public:

  JeuVague(std::string nom, int niveau, int scoreActuel);

  int run();

  float alea_Proba(){return (float)rand() / (float)RAND_MAX;}
  int alea_a_b_Int(int a, int b){return rand()%(b-a) + a;}

protected:
  std::map<Fumee *, int> mapFumee;

  Objet * extincteur;

};
