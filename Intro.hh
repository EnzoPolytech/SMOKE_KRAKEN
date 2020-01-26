 #include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#define LONGUEUR_INTRO 1024
#define LARGEUR_INTRO 639
#define TAILLE_POLICE_INTRO 25

class Intro
{
public:
  Intro();
  void run();

private:

  sf::RenderWindow fenetre;

  sf::Font fontAdler;

  sf::Text date;
  sf::Text ligne1;
  sf::Text ligne2;
  sf::Text ligne3;
  sf::Text ligne4;
  sf::Text ligne5;
  sf::Text ligne6;
  sf::Text ligne7;
  sf::Text ligne8;

  sf::Music music;
  sf::Music machine;


};
