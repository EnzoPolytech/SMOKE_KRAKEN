#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Jeu.hh"

#define LONGUEUR_FIN_DE_PARTIE 600
#define LARGEUR_FIN_DE_PARTIE 200
#define TAILLE_POLICE_FIN_DE_PARTIE 18

class FinDePartie
{
public:

  FinDePartie();
  FinDePartie(std::string nJ);

  void run();

private:

  std::string nomJoueur;

  sf::RenderWindow fenetre;

  sf::Font police;

  sf::Text message;

  sf::Texture boutonRejouer_t;
  sf::Sprite boutonRejouer_s;

  sf::Texture boutonQuitter_t;
  sf::Sprite boutonQuitter_s;
};
