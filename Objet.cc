#include "Objet.hh"

using namespace std;
using namespace sf;

Objet::Objet(std::string chemin, sf::Vector2f taille):position(POSITION_PLATEAU),taille(taille)
{
  if(!objet_t.loadFromFile(chemin))
  {
    cerr << "Erreur de chargement de l'image de la fumée " << chemin << endl;
  }
  else
  {
    objet_s.setTexture(objet_t);
    objet_s.setPosition(position);
  }
}

Objet::Objet(std::string chemin, sf::Vector2f taille, Vector2f position):position(position),taille(taille)
{
  if(!objet_t.loadFromFile(chemin))
  {
    cerr << "Erreur de chargement de l'image de la fumée " << chemin << endl;
  }
  else
  {
    objet_s.setTexture(objet_t);
    objet_s.setPosition(position);
  }
}
