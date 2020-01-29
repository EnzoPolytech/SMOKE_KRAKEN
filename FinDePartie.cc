#include "FinDePartie.hh"
// #include "Intro.hh"
// #include "Scene1.hh"
// #include "Scene2.hh"
// #include "JeuVague.hh"
// #include "JeuLabyrinthe.hh"
// #include "JeuBrouillard.hh"

using namespace sf;
using namespace std;

FinDePartie::FinDePartie():nomJoueur(" "),
fenetre(VideoMode(LONGUEUR_FIN_DE_PARTIE,LARGEUR_FIN_DE_PARTIE,32), "Fin de Partie !", Style::Close)
{
  if(!police.loadFromFile("fonts/Arial.ttf"))
  {
    cout << "Erreur durant le chargement de la police" << endl;
  }
  else if (!boutonRejouer_t.loadFromFile("images/boutonRejouer.png"))
  {
    cout << "Erreur durant le chargement de l'image du bouton Rejouer'" << endl;
  }
  else if (!boutonQuitter_t.loadFromFile("images/boutonQuitter.png"))
  {
    cout << "Erreur durant le chargement de l'image du bouton Quiiter'" << endl;
  }
  else
  {

    /* Création du texte de fin de partie */

    message.setString("Vous avez perdu ... Que voulez-vous faire ?");
    message.setFont(police);
    message.setCharacterSize(TAILLE_POLICE_FIN_DE_PARTIE);
    message.setFillColor(Color(0,0,0,255));
    message.setStyle(Text::Bold);

    /* Initialisation da la texture du bouton Rejouer */

    boutonRejouer_s.setTexture(boutonRejouer_t);

    /* Initialisation da la texture du bouton Quitter */

    boutonQuitter_s.setTexture(boutonQuitter_t);

  }
}

FinDePartie::FinDePartie(string nJ):nomJoueur(nJ),
fenetre(VideoMode(LONGUEUR_FIN_DE_PARTIE,LARGEUR_FIN_DE_PARTIE,32), "Fin de Partie !", Style::Close)
{
  if(!police.loadFromFile("fonts/Arial.ttf"))
  {
    cout << "Erreur durant le chargement de la police" << endl;
  }
  else if (!boutonRejouer_t.loadFromFile("images/boutonRejouer.png"))
  {
    cout << "Erreur durant le chargement de l'image du bouton Rejouer'" << endl;
  }
  else if (!boutonQuitter_t.loadFromFile("images/boutonQuitter.png"))
  {
    cout << "Erreur durant le chargement de l'image du bouton Quiiter'" << endl;
  }
  else
  {
    /* Création du texte de fin de partie */

    message.setString("Vous avez perdu ... Que voulez-vous faire ?");
    message.setFont(police);
    message.setCharacterSize(TAILLE_POLICE_FIN_DE_PARTIE);
    message.setFillColor(Color(0,0,0,255));
    message.setStyle(Text::Bold);

    /* Initialisation da la texture du bouton Rejouer */

    boutonRejouer_s.setTexture(boutonRejouer_t);

    /* Initialisation da la texture du bouton Quitter */

    boutonQuitter_s.setTexture(boutonQuitter_t);

  }
}
void FinDePartie::run()
{

  fenetre.clear(Color(255,255,255,255));

  /* Positionnement et Ajout du message à la fenetre */

  message.setPosition(70, (LARGEUR_FIN_DE_PARTIE/4) + 10);
  fenetre.draw(message);


  /* Création du bouton Rejouer */

  boutonRejouer_s.setPosition((LONGUEUR_FIN_DE_PARTIE/5), 4*LARGEUR_FIN_DE_PARTIE/6);

  RectangleShape contourBoutonRejouer;
  contourBoutonRejouer.setPosition(boutonRejouer_s.getPosition());
  contourBoutonRejouer.setSize(Vector2f(155,50));
  contourBoutonRejouer.setOutlineThickness(2);
  contourBoutonRejouer.setOutlineColor(Color(0, 0, 0, 255));

  fenetre.draw(contourBoutonRejouer);
  fenetre.draw(boutonRejouer_s);

  FloatRect limiteBoutonRejouer = boutonRejouer_s.getGlobalBounds();

  /* Création du bouton Quitter */

  boutonQuitter_s.setPosition((2*(LONGUEUR_FIN_DE_PARTIE/4)) + 30, 4*LARGEUR_FIN_DE_PARTIE/6);

  RectangleShape contourBoutonQuitter;
  contourBoutonQuitter.setPosition(boutonQuitter_s.getPosition());
  contourBoutonQuitter.setSize(Vector2f(135,50));
  contourBoutonQuitter.setOutlineThickness(2);
  contourBoutonQuitter.setOutlineColor(Color(0, 0, 0, 255));

  fenetre.draw(contourBoutonQuitter);
  fenetre.draw(boutonQuitter_s);

  FloatRect limiteBoutonQuitter = boutonQuitter_s.getGlobalBounds();

  /* Affichage de la fenetre */

  fenetre.display();

  /* Boucle de gestion d'événement */

  while(fenetre.isOpen())
  {
    Event event;

    while(fenetre.pollEvent(event))
    {
      if (event.type == Event::Closed)
      {
        fenetre.close();
      }
      else if(event.type == Event::MouseButtonPressed)
      {
        if (event.mouseButton.button == Mouse::Left)
        {
          /* Renvoie un vecteur position d'entier */
          Vector2i positionSourisTemp = Mouse::getPosition(fenetre);

          /* Convertis en vecteur position de float */
          Vector2f positionSouris = static_cast<Vector2f>(positionSourisTemp);

          if (limiteBoutonRejouer.contains(positionSouris))
          {
            // Intro intro1;
            // intro1.run();

            // JeuVague app1(nomJoueur, 1);
            // app1.run();

            // Scene1 scene1;
            // scene1.run();

            // JeuBrouillard app2(nomJoueur, 1);
            // app2.run();

            // Scene2 scene2;
            // scene2.run();

            // JeuLabyrinthe app3(nomJoueur, NB_FUMEE, NB_CHRONO);
            // app3.run();

            fenetre.close();
          }
          else if (limiteBoutonQuitter.contains(positionSouris))
          {
            fenetre.close();
          }
          else{}
        }
      }
      else{}
    }
  }
}
