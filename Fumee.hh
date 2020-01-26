#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

//Nb de déplacement max ?
//Durée de vie limité
//Augmenter la transparence a chaque déplacement
//Disparait quand elle rencontre un bord
//Les creer sur les bords de manière aléatoire
//(peut permettre de moduler la difficulté du jeu)
//elles avancent vers le bord opposé

// FENETRE

const sf::Vector2f TAILLE_FENETRE_FUMEE(1024,639);

// FUMEE

const std::string CHEMIN_IMAGE_FUMEE = "images/fumee.png";
const sf::Vector2f TAILLE_IMAGE_FUMEE(51,51);
const int VITESSE_FUMEE = 1;
const sf::Vector2f POS_INIT_FUMEE(TAILLE_FENETRE_FUMEE.x / 2 - TAILLE_IMAGE_FUMEE.x/2, TAILLE_FENETRE_FUMEE.y / 2 - TAILLE_IMAGE_FUMEE.y/2 );


class Fumee
{
public:
  Fumee();
  Fumee(sf::Vector2f position);
  Fumee(sf::Vector2f position, int vit);

  void modifierPosition(sf::Vector2f position);

  sf::Sprite recupererSprite();

  void toString();

  void modifierVitesse(int vit){vitesse = vit;}

  void deplacerDroite();
  void deplacerGauche();
  void deplacerHaut();
  void deplacerBas();

private :

  sf::Texture fumee_t;
  sf::Sprite fumee_s;

  sf::Vector2f position;
  sf::Vector2f taille;

  int vitesse;

};
