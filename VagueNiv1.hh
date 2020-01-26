#pragma once
#include "JeuVague.hh"
#include "VagueNiv2.hh"

#define VITESSE_FUMEE_NIV_1 1
#define PROBA_APPARITION_NIV_1 0.50

class VagueNiv1 : public JeuVague
{
public:

  VagueNiv1(std::string nom);

  void run();

};
