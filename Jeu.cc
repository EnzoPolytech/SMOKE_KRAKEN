#include "Jeu.hh"

using namespace sf;
using namespace std;

Jeu::Jeu(string nomJoueur):joueur(), nomJoueur(nomJoueur),
fenetre(VideoMode(TAILLE_FENETRE_JEU.x,TAILLE_FENETRE_JEU.y,32), "BIG SMOKE", Style::Close | Style::Titlebar),
monEtat(Pause),tempsEcoule(),chrono()
{

  if (!font.loadFromFile("fonts/digital-7.ttf"))
  {
    cerr << "Erreur du chargement de la police" << endl;
  }
  else
  {
    texteChrono.setFont(font);
    texteChrono.setCharacterSize(TAILLE_POLICE_JEU);
    texteChrono.setFillColor(Color::Black);

    texteNomJoueur.setFont(font);
    texteNomJoueur.setCharacterSize(TAILLE_POLICE_JEU);
    texteNomJoueur.setFillColor(Color::Black);

    texteScore.setFont(font);
    texteScore.setCharacterSize(TAILLE_POLICE_JEU);
    texteScore.setFillColor(Color::Black);
  }

  fenetre.clear(Color(255,255,255,255));

  // limite la fenêtre à 60 images par seconde
  fenetre.setFramerateLimit(60);
}

Jeu::Jeu(string nomJoueur, string titre):joueur(), nomJoueur(nomJoueur),
fenetre(VideoMode(TAILLE_FENETRE_JEU.x,TAILLE_FENETRE_JEU.y,32), titre, Style::Close | Style::Titlebar),
monEtat(Pause),tempsEcoule(),chrono()
{

  if (!font.loadFromFile("fonts/digital-7.ttf"))
  {
    cerr << "Erreur du chargement de la police" << endl;
  }
  else
  {
    texteChrono.setFont(font);
    texteChrono.setCharacterSize(TAILLE_POLICE_JEU);
    texteChrono.setFillColor(Color::Black);

    texteNomJoueur.setFont(font);
    texteNomJoueur.setCharacterSize(TAILLE_POLICE_JEU);
    texteNomJoueur.setFillColor(Color::Black);

    texteScore.setFont(font);
    texteScore.setCharacterSize(TAILLE_POLICE_JEU);
    texteScore.setFillColor(Color::Black);
  }

  fenetre.clear(Color(255,255,255,255));

  // limite la fenêtre à 60 images par seconde
  fenetre.setFramerateLimit(60);
}

void Jeu::lancerChrono()
{
  if (monEtat != Lance)
  {
    chrono.restart();
    monEtat = Lance;
  }
}

void Jeu::pauseChrono()
{
  if (monEtat != Pause)
  {
    monEtat = Pause;
    tempsEcoule += (chrono.getElapsedTime()).asSeconds();
  }
}

void Jeu::reinitialiserChrono()
{
  chrono.restart();
  pauseChrono();
  tempsEcoule = 0.0;
}

float Jeu::mesureTemps()
{
  float temps;

  if (monEtat == Pause)
  {
    temps = tempsEcoule;
  }
  else
  {
    temps = ((chrono.getElapsedTime()).asSeconds()) + tempsEcoule;
  }
  return temps;
}

float Jeu::mesureTempsMilli()
{
  float temps;

  if (monEtat == Pause)
  {
    temps = tempsEcoule;
  }
  else
  {
    temps = ((chrono.getElapsedTime()).asMilliseconds()) + tempsEcoule;
  }
  return temps;
}





