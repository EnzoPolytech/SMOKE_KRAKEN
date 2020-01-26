#pragma once
#include "JeuLabyrinthe.hh"

#define NB_FUMEE 45
#define NB_CHRONO 4
const std::string CHEMIN_IMAGE_SORTIE("images/sortie.png");

class LabyrintheNiv1 : public JeuLabyrinthe
{
public:
  LabyrintheNiv1(std::string nom);

  void run();

};
