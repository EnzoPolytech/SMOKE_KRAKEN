#include <iostream>
#include <SFML/Graphics.hpp>
#include <map>

#define LONGUEUR_RECORD 800
#define LARGEUR_RECORD 600
#define TAILLE_POLICE_RECORD 25

class Record
{
public:
  Record();

  void run();

private:

  sf::RenderWindow fenetre;

  sf::Font police;

  sf::Text textePremier;
  sf::Text texteDeuxieme;
  sf::Text texteTroisieme;

  std::string nomTemps;

  std::multimap<std::string,int> listeRecords;

};
