#pragma once
#include "JeuVague.hh"

#define VITESSE_FUMEE_NIV_2 30
#define PROBA_APPARITION_NIV_2 0.60

class VagueNiv2 : public JeuVague
{
public:

  VagueNiv2(std::string nom);

  void run();

};
