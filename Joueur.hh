#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>

// FENETRE

const sf::Vector2f TAILLE_FENETRE_JOUEUR(1024,639);

// PERSONNAGE

const sf::Vector2f TAILLE_IMAGE_JOUEUR(45,81);
const int VITESSE_JOUEUR = 3;
const sf::Vector2f POS_INIT_JOUEUR(TAILLE_FENETRE_JOUEUR.x / 2 - TAILLE_IMAGE_JOUEUR.x/4, TAILLE_FENETRE_JOUEUR.y / 2 - TAILLE_IMAGE_JOUEUR.y/2 );

class Joueur
{
public :

    Joueur();


    void deplacerHaut();
    void deplacerBas();
    void deplacerGauche();
    void deplacerDroite();

    void reinitialiserPosition(){joueur_s.setPosition(POS_INIT_JOUEUR);}
    void reinitialiserSon();

    void modifierPosition(sf::Vector2f position){joueur_s.setPosition(position);}

    sf::Sprite recupererSprite(){return joueur_s;}

    void modifierVitesse(int vit){vitesse = vit;}


private :

    sf::SoundBuffer buffer;
    sf::Sound marche;

    sf::Texture joueur_t;
    sf::Sprite joueur_s;

    sf::Vector2f position;
    sf::Vector2f taille;
    int vitesse;




};
