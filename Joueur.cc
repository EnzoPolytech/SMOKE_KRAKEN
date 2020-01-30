#include "Joueur.hh"
#include "Jeu.hh"

using namespace std;
using namespace sf;


Joueur::Joueur():
position(POS_INIT_JOUEUR), taille(TAILLE_IMAGE_JOUEUR), vitesse(VITESSE_JOUEUR), estAccroupi(0)
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

void Joueur::accroupir(bool b)
{
    if(b == true)
    {
        estAccroupi = 1;
        vitesse = VITESSE_JOUEUR - 2;
        if(!joueur_t.loadFromFile("images/joueur_accroupis.png"))
        {
            cerr << "Erreur de chargement de l'image du personnage " << endl;
        }
        joueur_s.setTexture(joueur_t);
        joueur_s.setTextureRect(sf::IntRect(58, 4, 35, 51));
    }
    else
    {
        estAccroupi = 0;
        vitesse = VITESSE_JOUEUR;
        if(!joueur_t.loadFromFile("images/joueur.png"))
        {
            cerr << "Erreur de chargement de l'image du personnage " << endl;
        }
        joueur_s.setTexture(joueur_t);
        joueur_s.setTextureRect(sf::IntRect(36, 44, 34, 70));
    }


}

void Joueur::deplacerDroite()
{
    if (estAccroupi)
    {
        joueur_s.setTextureRect(sf::IntRect(152, 4, 49, 51));
    }
    else
    {
        joueur_s.setTextureRect(sf::IntRect(176, 47, 36, 72));
    }

    joueur_s.move(vitesse, 0);
    marche.play();

}

void Joueur::deplacerGauche()
{
    if (estAccroupi)
    {
        joueur_s.setTextureRect(sf::IntRect(5, 4, 47, 51));
    }
    else
    {
        joueur_s.setTextureRect(sf::IntRect(127, 47, 33, 70));
    }

    joueur_s.move(-vitesse, 0);
    marche.play();
}

void Joueur::deplacerHaut()
{
    if (estAccroupi)
    {
        joueur_s.setTextureRect(sf::IntRect(104, 4, 35, 51));
    }
    else
    {
        joueur_s.setTextureRect(sf::IntRect(84, 45, 31, 70));
    }

    joueur_s.move(0,-vitesse);
    marche.play();
}

void Joueur::deplacerBas()
{
    if (estAccroupi)
    {
        joueur_s.setTextureRect(sf::IntRect(58, 4, 35, 51));
    }
    else
    {
        joueur_s.setTextureRect(sf::IntRect(36, 44, 34, 70));
    }

    joueur_s.move(0,vitesse);
    marche.play();
}

void Joueur::reinitialiserSon()
{
  marche.stop();
}
