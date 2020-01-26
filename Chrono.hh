#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Jeu.hh"

// Chrono

const std::string CHEMIN_IMAGE_CHRONO = "images/chrono.png";
const sf::Vector2f TAILLE_IMAGE_CHRONO(51,51);

class Chrono
{
public:

  Chrono();

  Chrono(sf::Vector2f position);

  void modifierPosition(sf::Vector2f position){chrono_s.setPosition(position);}

  sf::Sprite recupererSprite(){return chrono_s;}

private :

  sf::Texture chrono_t;
  sf::Sprite chrono_s;

  sf::Vector2f position;
  sf::Vector2f taille;

};
