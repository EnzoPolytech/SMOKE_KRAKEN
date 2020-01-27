#pragma once
#include "Jeu.hh"
#include "Chrono.hh"

#define NB_FUMEE 45
#define NB_CHRONO 4
const std::string CHEMIN_IMAGE_SORTIE("images/sortie.png");

class JeuLabyrinthe : public Jeu
{
public:

  JeuLabyrinthe(std::string nom, int nbFumee, int nbChrono);

  void run();

  int alea_a_b_Int(int a, int b){return rand()%(b-a) + a;}

protected:

  std::vector<Chrono *> tabChrono;

  sf::Texture sortie_t;
  sf::Sprite sortie_s;

};
