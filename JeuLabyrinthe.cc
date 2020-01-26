#include "JeuLabyrinthe.hh"

using namespace sf;
using namespace std;

JeuLabyrinthe::JeuLabyrinthe(string nomJoueur, int nbFumee, int nbChrono):Jeu(nomJoueur, "Mode Labyrinthe")
{
  for (int i = 1; i <= nbFumee; ++i)
  {
    tabFumee.push_back(new Fumee());
  }
  for (int i = 1; i <= nbChrono; ++i)
  {
    tabChrono.push_back(new Chrono());
  }
}

JeuLabyrinthe::JeuLabyrinthe(string nomJoueur, string titre, int nbFumee, int nbChrono):Jeu(nomJoueur, titre)
{

  for (int i = 1; i <= nbFumee; ++i)
  {
    tabFumee.push_back(new Fumee());
  }
  for (int i = 1; i <= nbChrono; ++i)
  {
    tabChrono.push_back(new Chrono());
  }
}
