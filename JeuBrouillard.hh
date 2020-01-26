#pragma once
#include "Jeu.hh"

class JeuBrouillard : public Jeu
{
public:

  JeuBrouillard(std::string nom, int niveau);
  JeuBrouillard(std::string nom, std::string titre, int niveau);

  void run();

  int alea_a_b_Int(int a, int b){return rand()%(b-a) + a;}

protected:

  int nb_fumee;
  std::map<Fumee *, int> mapFumee;

  // Sprite nuit_s;
  // Texture nuit_t;

};
