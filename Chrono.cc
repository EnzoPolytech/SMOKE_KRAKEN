#include "Chrono.hh"

using namespace std;
using namespace sf;

Chrono::Chrono():position(POSITION_PLATEAU),taille(TAILLE_IMAGE_CHRONO)
{
  if(!chrono_t.loadFromFile(CHEMIN_IMAGE_CHRONO))
  {
    cerr << "Erreur de chargement de l'image de la fumée " << CHEMIN_IMAGE_CHRONO << endl;
  }
  else
  {
    chrono_s.setTexture(chrono_t);
    chrono_s.setPosition(position);
  }
}

Chrono::Chrono(Vector2f position):position(position),taille(TAILLE_IMAGE_CHRONO)
{
  if(!chrono_t.loadFromFile(CHEMIN_IMAGE_CHRONO))
  {
    cerr << "Erreur de chargement de l'image de la fumée " << CHEMIN_IMAGE_CHRONO << endl;
  }
  else
  {
    chrono_s.setTexture(chrono_t);
    chrono_s.setPosition(position);
  }
}
