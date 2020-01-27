#pragma once
#include "Jeu.hh"
#include "Objet.hh"

#define NB_FUMEE 45
#define NB_CHRONO 4
#define NB_EXTINCTEUR 4

const std::string CHEMIN_IMAGE_EXTINCTEUR = "images/extincteur.png";
const sf::Vector2f TAILLE_IMAGE_EXTINCTEUR(51,51);

const std::string CHEMIN_IMAGE_CHRONO = "images/chrono.png";
const sf::Vector2f TAILLE_IMAGE_CHRONO(51,51);

const std::string CHEMIN_IMAGE_SORTIE("images/sortie.png");
const sf::Vector2f TAILLE_IMAGE_SORTIE(51,51);


class JeuLabyrinthe : public Jeu
{
public:

  JeuLabyrinthe(std::string nom, int nbFumee, int nbChrono);

  void run();

  int alea_a_b_Int(int a, int b){return rand()%(b-a) + a;}

protected:

  std::vector<Objet *> tabChrono;

  std::vector<Objet *> tabExtincteur;

  Objet sortie;

  int score;

};
