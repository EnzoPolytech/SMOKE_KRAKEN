#include "JeuVague.hh"

using namespace sf;
using namespace std;

JeuVague::JeuVague(string nomJoueur, int niveau):Jeu(nomJoueur, "Mode Vague")
{
  if (niveau == 1)
  {
    //??
  }
  else if (niveau == 2)
  {
    //??
  }
  else
  {
   //??
  }

  for (int i = 1; i <= NB_FUMEE_LISSAGE; ++i)
  {
    //On remplis la map avec les Fumee au positions aléaoire
    //comme clés et un bit d'apparition en valeur
    mapFumee[new Fumee(Vector2f(POSITION_PLATEAU.x + TAILLE_IMAGE_FUMEE.x, (POSITION_PLATEAU.y)+50*(i-1)))] = 1;

  }
}

void JeuVague::run()
{
  int nbVague = 5;

  map<Fumee *, int>::iterator it2; //Un itérateur sur la mapFumee

  RectangleShape contourPlateau;

  contourPlateau.setPosition(POSITION_PLATEAU);
  contourPlateau.setSize(TAILLE_PLATEAU);
  contourPlateau.setOutlineThickness(2);
  contourPlateau.setOutlineColor(Color(0, 0, 0, 255));
  joueur.reinitialiserPosition();


  //On remplis nos valeurs des fumée, 1 = la fumee est active et 0 elle est inactive
  //Donc ici on désactive un nombre aléatoire de fumee
  for (it2 = mapFumee.begin(); it2 != mapFumee.end(); ++it2)
  {
    float alea = alea_Proba();
    if (alea < PROBA_APPARITION)
    {
      mapFumee[(it2->first)] = 0;
    }
  }

  while (fenetre.isOpen()) //Boucle d'événement principale
  {
    Event event;

      while (fenetre.pollEvent(event)) // Boucle des évènements du jeu
      {
        switch (event.type)
        {
          case Event::Closed : // Croix de fermeture du programme
            fenetre.close();
            return;
            // exit(EXIT_SUCCESS);
            break;

          case Event::KeyReleased : // Appui sur une touche
            switch(event.key.code)
            {
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


      //On parcour notre map de fumee
      for (it2 = mapFumee.begin(); it2 != mapFumee.end(); ++it2)
      {
          FloatRect rectJoueur = joueur.recupererSprite().getGlobalBounds();
          rectJoueur.height -= 10;
          //Si la fumee est active
          if ((it2->second) == 1)
          {
            //Si la fumee touche le joueur, la partie est finie
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

      texteChrono.setString("Vagues Restantes : " + to_string((int)nbVague));
      texteChrono.setPosition(0,TAILLE_FENETRE_JEU.y - ((texteChrono.getGlobalBounds()).height)*2);

      texteNomJoueur.setString(nomJoueur);
      texteNomJoueur.setPosition(TAILLE_FENETRE_JEU.x - ((texteNomJoueur.getGlobalBounds()).width)*2,TAILLE_FENETRE_JEU.y - ((texteNomJoueur.getGlobalBounds()).height)*2);

      fenetre.draw(contourPlateau);
      fenetre.draw(joueur.recupererSprite());
      fenetre.draw(texteChrono);
      fenetre.draw(texteNomJoueur);



      int vague2 = 0;
      int k = 0;
      int z = 0;
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
          else if(z < 1)
          {
            vague2 = 1;
            nbVague--;
            z++;
          }
        }
      }

      //2e VAGUE PLUS RAPIDE
      for (it2 = mapFumee.begin(); it2 != mapFumee.end(); ++it2)
      {
        if(vague2 == 1 && k <= 12)
        {
          //On remet toute les fumee actives sauf la première
          if (it2 != mapFumee.begin())
          {
            mapFumee[(it2->first)] = 1;
          }

          //On repositionne le joueur au milieu du plateau
          joueur.reinitialiserPosition();

          //On les remet au debut du plateau
          (*(it2->first)).modifierPosition(Vector2f(POSITION_PLATEAU.x + TAILLE_IMAGE_FUMEE.x, (POSITION_PLATEAU.y)+50*(k-1)));

          //On accelere les fumee
          (*(it2->first)).modifierVitesse(VITESSE_FUMEE_VAGUE + 1);

          //On desactive des fumee aleatoirement !
          float alea = alea_Proba();
          if (alea < PROBA_APPARITION)
          {
            mapFumee[(it2->first)] = 0;
          }
          k++;
        }
      }

      //Si le chrono arrive a 0, le niveau est reussi
      if (nbVague == 0)
      {
        fenetre.close();
        return;
      }

    fenetre.display();
  }
}
