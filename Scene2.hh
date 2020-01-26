 #include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#define LONGUEUR_INTRO 1024
#define LARGEUR_INTRO 639

class Scene2
{
public:
  Scene2();
  void run();

private:

  sf::RenderWindow fenetre;

  sf::Font fontAdler;

  sf::Text ligne1;
  sf::Text ligne2;
  sf::Text ligne3;
  sf::Text ligne4;
  sf::Text ligne5;

  sf::Sprite encre_s;
  sf::Texture encre_t;

  sf::Music ambiance;
  sf::Music sanglot;


};
