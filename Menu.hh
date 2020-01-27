#include <iostream>
#include <SFML/Graphics.hpp>

#define LONGUEUR_MENU 1024
#define LARGEUR_MENU 639
#define TAILLE_POLICE_MENU 25

class Menu
{
public:
  Menu();

  void run();

private:

  sf::RenderWindow fenetre;

  sf::Texture titre_t;
  sf::Texture imageFond_t;
  sf::Texture boutonJouer_t;
  sf::Texture boutonRecord_t;

  sf::Sprite titre_s;
  sf::Sprite imageFond_s;
  sf::Sprite boutonJouer_s;
  sf::Sprite boutonRecord_s;
  sf::Texture perso_t;
  sf::Sprite perso_s;

  //Pour remplir la fenetre Record
  std::map<std::string,int> recordGlobal;

};
