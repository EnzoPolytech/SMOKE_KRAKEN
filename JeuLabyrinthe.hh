#pragma once
#include "Jeu.hh"
#include "Chrono.hh"


class JeuLabyrinthe : public Jeu
{
public:

  JeuLabyrinthe(std::string nom, int nbFumee, int nbChrono);
  JeuLabyrinthe(std::string nom, std::string titre, int nbFumee, int nbChrono);

  virtual void run() = 0;

  int alea_a_b_Int(int a, int b){return rand()%(b-a) + a;}

protected:

  std::vector<Chrono *> tabChrono;

  sf::Texture sortie_t;
  sf::Sprite sortie_s;

};


