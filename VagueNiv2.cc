#include "VagueNiv2.hh"

using namespace sf;
using namespace std;

VagueNiv2::VagueNiv2(string nomJoueur):
JeuVague(nomJoueur, "Mode Vague : Niveau 2")
{}

void VagueNiv2::run()
{
  int tempsActuel = 0;
  RectangleShape contourPlateau;

  contourPlateau.setPosition(POSITION_PLATEAU);
  contourPlateau.setSize(TAILLE_PLATEAU);
  contourPlateau.setOutlineThickness(2);
  contourPlateau.setOutlineColor(Color(0, 0, 0, 255));
  joueur.reinitialiserPosition();

  while (fenetre.isOpen()) //Boucle d'événement principale
  {
    Event event;
    lancerChrono();

      while (fenetre.pollEvent(event)) // Boucle des évènements du jeu
      {
        switch (event.type)
        {
          case Event::Closed : // Croix de fermeture du programme
            fenetre.close();
            return;
            // exit(EXIT_SUCCESS);
            break;

          case Event::KeyPressed : // Appui sur une touche
            switch(event.key.code)
            {

              // case Keyboard::P : // Touche P : mettre le jeu en Pause
              //   //Ca marche pas !
              //   pauseChrono();
              //   joueur.reinitialiserPosition();
              //   break;

              default :
                break;
            }
          break;

        default :
          break;
        }
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
      {
        if (joueur.recupererSprite().getPosition().y > POSITION_PLATEAU.y)
        {
          joueur.deplacerHaut();
        }
      }
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
      {
        if (joueur.recupererSprite().getPosition().y + TAILLE_IMAGE_JOUEUR.y < POSITION_PLATEAU.y + TAILLE_PLATEAU.y)
        {
          joueur.deplacerBas();
        }
      }
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
      {
        if (joueur.recupererSprite().getPosition().x + TAILLE_IMAGE_JOUEUR.x < POSITION_PLATEAU.x + TAILLE_PLATEAU.x)
        {
          joueur.deplacerDroite();
        }
      }
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
      {
        if (joueur.recupererSprite().getPosition().x > POSITION_PLATEAU.x)
        {
          joueur.deplacerGauche();
        }
      }
      else{}

      for (int i = 1; i <= NB_FUMEE_LISSAGE; ++i)
      {
        if (tabFumee[i-1] != NULL)
        {
          FloatRect rectJoueur = joueur.recupererSprite().getLocalBounds();
          rectJoueur.height -= 10;
          if (rectJoueur.intersects((*tabFumee[i-1]).recupererSprite().getGlobalBounds()))
          {
            FinDePartie end;
            end.run();
            fenetre.close();
            return;
            // exit(EXIT_SUCCESS);
          }
        }
      }

      fenetre.clear(Color(255,255,255,255));

      if (tempsActuel == (int)mesureTemps())
      {
        for (int i = 1; i <= NB_FUMEE_LISSAGE; ++i)
        {
          if(tabFumee[i-1] != NULL)
          {
            //Deplacement à droite
            if ((*tabFumee[i-1]).recupererSprite().getPosition().x + TAILLE_IMAGE_FUMEE.x < POSITION_PLATEAU.x + TAILLE_PLATEAU.x)
            {
              (*tabFumee[i-1]).deplacerDroite();
            }
          }
        }
        tempsActuel++;
      }

      texteChrono.setString("Temps : " + to_string((int)mesureTemps()) + " secs");
      texteChrono.setPosition(0,TAILLE_FENETRE_JEU.y - ((texteChrono.getGlobalBounds()).height)*2);

      texteNomJoueur.setString(nomJoueur);
      texteNomJoueur.setPosition(TAILLE_FENETRE_JEU.x - ((texteNomJoueur.getGlobalBounds()).width)*2,TAILLE_FENETRE_JEU.y - ((texteNomJoueur.getGlobalBounds()).height)*2);

      fenetre.draw(contourPlateau);
      fenetre.draw(joueur.recupererSprite());
      fenetre.draw(texteChrono);
      fenetre.draw(texteNomJoueur);

      for (int i = 1; i <= NB_FUMEE_LISSAGE; ++i)
      {
        if ((tabFumee[i-1] != NULL) && ((*tabFumee[i-1]).recupererSprite().getPosition().x + TAILLE_IMAGE_FUMEE.x < POSITION_PLATEAU.x + TAILLE_PLATEAU.x))
        {
          fenetre.draw((*tabFumee[i-1]).recupererSprite());
        }
        else if(tabFumee[i-1] != NULL)
        {
          fenetre.close();
          // exit(EXIT_SUCCESS);
          return;
        }
      }
     fenetre.display();
  }
}
