#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Jeu.hh"

// Objet

class Objet
{
public:

  Objet(std::string chemin, sf::Vector2f taille);

  Objet(std::string chemin, sf::Vector2f taille, sf::Vector2f position);

  void modifierPosition(sf::Vector2f position){objet_s.setPosition(position);}

  sf::Sprite recupererSprite(){return objet_s;}

private :

  sf::Texture objet_t;
  sf::Sprite objet_s;

  sf::Vector2f position;
  sf::Vector2f taille;

};
