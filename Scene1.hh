 #include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#define LONGUEUR_INTRO 1024
#define LARGEUR_INTRO 639

class Scene1
{
public:
  Scene1();
  void run();

private:

  sf::RenderWindow fenetre;

  sf::Font fontAdler;

  sf::Text ligne1;
  sf::Text ligne2;
  sf::Text ligne1bis;
  sf::Text ligne1ter;

  sf::Sprite dessin_ville_s;
  sf::Texture dessin_ville_t;

  sf::Music marcher;
  sf::Music dessiner;

};
