#include "Fumee.hh"

using namespace sf;
using namespace std;

Fumee::Fumee():position(POS_INIT_FUMEE), taille(TAILLE_IMAGE_FUMEE), vitesse(VITESSE_FUMEE)
{
    if(!fumee_t.loadFromFile(CHEMIN_IMAGE_FUMEE))
    {
        cerr << "Erreur de chargement de l'image de la fumée " << CHEMIN_IMAGE_FUMEE << endl;
    }
    else
    {
        fumee_s.setTexture(fumee_t);
        fumee_s.setPosition(position);
    }
}

Fumee::Fumee(sf::Vector2f pos):position(pos),taille(TAILLE_IMAGE_FUMEE), vitesse(VITESSE_FUMEE)
{
  if(!fumee_t.loadFromFile(CHEMIN_IMAGE_FUMEE))
  {
      cerr << "Erreur de chargement de l'image de la fumée " << CHEMIN_IMAGE_FUMEE << endl;
  }
  else
  {
    fumee_s.setTexture(fumee_t);
    fumee_s.setPosition(position);
  }
}

Fumee::Fumee(sf::Vector2f pos, int vit):position(pos),taille(TAILLE_IMAGE_FUMEE), vitesse(vit)
{
  if(!fumee_t.loadFromFile(CHEMIN_IMAGE_FUMEE))
  {
      cerr << "Erreur de chargement de l'image de la fumée " << CHEMIN_IMAGE_FUMEE << endl;
  }
  else
  {
    fumee_s.setTexture(fumee_t);
    fumee_s.setPosition(position);
  }
}

void Fumee::modifierPosition(sf::Vector2f position)
{
  fumee_s.setPosition(position);
}

Sprite Fumee::recupererSprite()
{
    return fumee_s;
}

void Fumee::toString()
{
  cout << "Position x = " << position.x << endl;
  cout << "Position y = " << position.y << endl;
}

void Fumee::deplacerDroite()
{
  fumee_s.move(vitesse, 0);
}

void Fumee::deplacerGauche()
{
  fumee_s.move(-vitesse, 0);
}

void Fumee::deplacerHaut()
{
  fumee_s.move(0,-vitesse);
}

void Fumee::deplacerBas()
{
  fumee_s.move(0,vitesse);
}
