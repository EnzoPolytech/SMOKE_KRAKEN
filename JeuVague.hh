#pragma once
#include "Jeu.hh"

#define NB_FUMEE_LISSAGE 12

class JeuVague : public Jeu
{
public:

  JeuVague(std::string nom);
  JeuVague(std::string nom, std::string titre);

  virtual void run() = 0;

  float alea_Proba(){return (float)rand() / (float)RAND_MAX;}

protected:
  std::map<Fumee *, int> mapFumee;

};
