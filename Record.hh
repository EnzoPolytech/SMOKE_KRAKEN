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
  Record(std::multimap<int, std::string, std::greater<int>> rec);

  void run();

private:

  sf::RenderWindow fenetre;

  sf::Font police;

  sf::Text textePremier;
  sf::Text texteDeuxieme;
  sf::Text texteTroisieme;

  std::string nomTemps;

  std::multimap<int, std::string, std::greater<int>> listeRecords;

};
