#include "VagueNiv1.hh"

using namespace sf;
using namespace std;

VagueNiv1::VagueNiv1(string nomJoueur):
JeuVague(nomJoueur, "Mode Vague : Niveau 1")
{}

void VagueNiv1::run()
{
  map<Fumee *, int>::iterator it2; //Un itérateur sur la mapFumee

  RectangleShape contourPlateau;

  contourPlateau.setPosition(POSITION_PLATEAU);
  contourPlateau.setSize(TAILLE_PLATEAU);
  contourPlateau.setOutlineThickness(2);
  contourPlateau.setOutlineColor(Color(0, 0, 0, 255));
  joueur.reinitialiserPosition();

  for (it2 = mapFumee.begin(); it2 != mapFumee.end(); ++it2)
  {
    float alea = alea_Proba();
    if (alea < PROBA_APPARITION_NIV_1)
    {
      mapFumee[(it2->first)] = 0;
    }
  }

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
              //Ca marche pas !
              // case Keyboard::P : // Touche P : mettre le jeu en Pause
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


      for (it2 = mapFumee.begin(); it2 != mapFumee.end(); ++it2)
      {
          FloatRect rectJoueur = joueur.recupererSprite().getGlobalBounds();
          rectJoueur.height -= 10;
          if ((it2->second) == 1)
          {
            if (rectJoueur.intersects((*(it2->first)).recupererSprite().getGlobalBounds()))
            {
              FinDePartie end;
              end.run();
              fenetre.close();
              return;
            }
          }
        }

      fenetre.clear(Color(255,255,255,255));

      for (it2 = mapFumee.begin(); it2 != mapFumee.end(); ++it2)
      {
        //Deplacement à droite
        if ((*(it2->first)).recupererSprite().getPosition().x + TAILLE_IMAGE_FUMEE.x < POSITION_PLATEAU.x + TAILLE_PLATEAU.x)
        {
          (*(it2->first)).deplacerDroite();
        }
      }

      texteChrono.setString("Temps : " + to_string((int)mesureTemps()) + " secs");
      texteChrono.setPosition(0,TAILLE_FENETRE_JEU.y - ((texteChrono.getGlobalBounds()).height)*2);

      texteNomJoueur.setString(nomJoueur);
      texteNomJoueur.setPosition(TAILLE_FENETRE_JEU.x - ((texteNomJoueur.getGlobalBounds()).width)*2,TAILLE_FENETRE_JEU.y - ((texteNomJoueur.getGlobalBounds()).height)*2);

      fenetre.draw(contourPlateau);
      fenetre.draw(joueur.recupererSprite());
      fenetre.draw(texteChrono);
      fenetre.draw(texteNomJoueur);


      //On parcours nos fumees
      for (it2 = mapFumee.begin(); it2 != mapFumee.end(); ++it2)
      {
        //Si elle est active
        if ((it2->second) == 1)
        {
          //Si elle n'est pas arrivé au bout du plateau
          if (((*(it2->first)).recupererSprite().getPosition().x + TAILLE_IMAGE_FUMEE.x < POSITION_PLATEAU.x + TAILLE_PLATEAU.x))
          {
            fenetre.draw((*(it2->first)).recupererSprite());
          }
        }
      }
      //2e VAGUE PLUS RAPIDE
      // if(k <= 12)
      // {
      //   //On remet toute les fumee actives
      //   mapFumee[(it2->first)] = 1;

      //   //On les remet au debut du plateau
      //     (*(it2->first)).modifierPosition(Vector2f(POSITION_PLATEAU.x + TAILLE_IMAGE_FUMEE.x, (POSITION_PLATEAU.y)+50*(k-1)));

      //   //On accelere les fumee
      //   (*(it2->first)).modifierVitesse(VITESSE_FUMEE_NIV_1 + 1);

      //   //On change les fumees qui seront actives !
      //   float alea = alea_Proba();
      //   if (alea < PROBA_APPARITION_NIV_1)
      //   {
      //     mapFumee[(it2->first)] = 0;
      //   }
      //   k++;
      // }
      // //Un fois qu'il y a eu 2 vague, le niveau est fini
      // fenetre.close();
      // return;
    fenetre.display();
  }
}
