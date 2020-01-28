#pragma once
#include "Jeu.hh"
#include "Objet.hh"

const std::string CHEMIN_IMAGE_EXTINCTEUR = "images/extincteur.png";
const sf::Vector2f TAILLE_IMAGE_EXTINCTEUR(51,51);

class JeuBrouillard : public Jeu
{
public:

  JeuBrouillard(std::string nom, int niveau);
  JeuBrouillard(std::string nom, std::string titre, int niveau);

  int run();

  int alea_a_b_Int(int a, int b){return rand()%(b-a) + a;}

protected:

  int nb_fumee;
  std::map<Fumee *, int> mapFumee;

  // Sprite nuit_s;
  // Texture nuit_t;

  Objet * extincteur;

};
