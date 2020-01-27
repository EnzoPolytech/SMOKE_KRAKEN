#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Jeu.hh"

#define LONGUEUR_NOMJOUEUR 600
#define LARGEUR_NOMJOUEUR 200
#define TAILLE_POLICE_NOMJOUEUR 18

class NomJoueur
{
public:
  NomJoueur();
  NomJoueur(std::string nom);

  std::string run();

  std::string getNomJoueur(){return nomJoueur;}

private:

  sf::RenderWindow fenetre;

  sf::Font police;

  sf::Text texte_Question;
  sf::Text texte_NomJoueur;

  std::string nomJoueur;

  sf::Texture boutonValider_t;
  sf::Sprite boutonValider_s;

};
