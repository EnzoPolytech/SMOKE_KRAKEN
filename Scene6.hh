 #include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#define LONGUEUR_INTRO 1024
#define LARGEUR_INTRO 639

class Scene6
{
public:
  Scene6();
  void run();

private:

  sf::RenderWindow fenetre;

  sf::Font fontAdler;

  sf::Text ligne1;
  sf::Text ligne2;
  sf::Text ligne3;

  sf::Sprite feuille_s;
  sf::Texture feuille_t;

  sf::Sprite feuille2_s;
  sf::Texture feuille2_t;

  sf::Music vent;
  sf::Music neige;


};
