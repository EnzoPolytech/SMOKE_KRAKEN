#include "JeuVague.hh"

using namespace sf;
using namespace std;

JeuVague::JeuVague(string nomJoueur):Jeu(nomJoueur, "Mode Vague")
{
  for (int i = 1; i <= NB_FUMEE_LISSAGE; ++i)
  {
    //On remplis la map avec les Fumee au positions aléaoire
    //comme clés et un bit d'apparition en valeur
    mapFumee[new Fumee(Vector2f(POSITION_PLATEAU.x + TAILLE_IMAGE_FUMEE.x, (POSITION_PLATEAU.y)+50*(i-1)))] = 1;

  }
}

JeuVague::JeuVague(string nomJoueur, string titre):
Jeu(nomJoueur, titre)
{
  for (int i = 1; i <= NB_FUMEE_LISSAGE; ++i)
  {
    //On remplis la map avec les Fumee au positions aléaoire
    //comme clés et un bit d'apparition en valeur
    mapFumee[new Fumee(Vector2f(POSITION_PLATEAU.x + TAILLE_IMAGE_FUMEE.x, (POSITION_PLATEAU.y)+50*(i-1)))] = 1;

  }
}
