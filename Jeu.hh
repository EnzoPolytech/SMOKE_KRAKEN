#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <time.h>
#include "Joueur.hh"
#include "Fumee.hh"
#include "FinDePartie.hh"

#define TAILLE_POLICE_JEU 25

const sf::Vector2f TAILLE_FENETRE_JEU(1024,639);
const sf::Vector2f MILIEU(TAILLE_FENETRE_JEU.x/2,TAILLE_FENETRE_JEU.y/2);
const sf::Vector2f POSITION_PLATEAU(MILIEU.x - 288, MILIEU.y - 310);
const sf::Vector2f TAILLE_PLATEAU(620,620);

class Jeu{

  public:
    Jeu(std::string nom);
    Jeu(std::string nom, std::string titre);

    virtual int run() = 0;

    void lancerChrono();
    void pauseChrono();
    void reinitialiserChrono();
    float mesureTemps();
    float mesureTempsMilli();

  protected:

    std::vector<Fumee *> tabFumee;

    enum EtatsChrono {Lance, Pause};

    class Joueur joueur;

    std::string nomJoueur;

    sf::RenderWindow fenetre;

    EtatsChrono monEtat;

    float tempsEcoule;

    sf::Clock chrono;

    sf::Font font;

    sf::Text texteChrono;
    sf::Text texteNomJoueur;

    int score;

};
