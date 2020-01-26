    #include "Joueur.hh"
#include "Jeu.hh"

using namespace std;
using namespace sf;


Joueur::Joueur():
position(POS_INIT_JOUEUR), taille(TAILLE_IMAGE_JOUEUR), vitesse(VITESSE_JOUEUR)
{
    if(!joueur_t.loadFromFile("images/joueur.png"))
    {
        cerr << "Erreur de chargement de l'image du personnage " << endl;
    }
    else if (!buffer.loadFromFile("son/walk.wav"))
    {
        cerr << "Erreur du chargement du son" << endl;
    }
    else
    {
        joueur_s.setTexture(joueur_t);
        joueur_s.setTextureRect(sf::IntRect(30, 38, 43, 81));
    }

    marche.setBuffer(buffer);
}

void Joueur::deplacerDroite()
{
    joueur_s.setTextureRect(sf::IntRect(173, 43, 45, 79));
    joueur_s.move(vitesse, 0);
    marche.play();
}

void Joueur::deplacerGauche()
{
    joueur_s.setTextureRect(sf::IntRect(122, 40, 41, 80));
    joueur_s.move(-vitesse, 0);
    marche.play();
}

void Joueur::deplacerHaut()
{
    joueur_s.setTextureRect(sf::IntRect(82, 41, 37, 79));
    joueur_s.move(0,-vitesse);
    marche.play();
}

void Joueur::deplacerBas()
{
    joueur_s.setTextureRect(sf::IntRect(30, 38, 43, 81));
    joueur_s.move(0,vitesse);
    marche.play();
}
