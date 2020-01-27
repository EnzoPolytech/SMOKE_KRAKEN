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
  Record(std::map<std::string, int> rec);

  void run();

private:

  sf::RenderWindow fenetre;

  sf::Font police;

  sf::Text textePremier;
  sf::Text texteDeuxieme;
  sf::Text texteTroisieme;

  std::string nomTemps;

  std::map<std::string,int> listeRecords;

};
