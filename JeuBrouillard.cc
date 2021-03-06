#include "JeuBrouillard.hh"

using namespace sf;
using namespace std;

JeuBrouillard::JeuBrouillard(string nomJoueur, int niveau, int scoreActuel):
Jeu(nomJoueur, "Mode Brouillard")
{
  score = scoreActuel;
  int vitesse_fumee;

  if (niveau == 1)
  {
    nb_fumee = 5;
    vitesse_fumee = 1;
  }
  else if (niveau == 2)
  {
    nb_fumee = 8;
    vitesse_fumee = 1;
  }
  else
  {
    nb_fumee = 12;
    vitesse_fumee = 2;
  }

  for (int i = 0; i < nb_fumee; ++i)
  {
    int xAlea, yAlea;
    //Permet de retirer de nouvelles coordonnées aléatoire tant que le fumee apparait sur le joueur
    do
    {
      xAlea = alea_a_b_Int(POSITION_PLATEAU.x + 50, POSITION_PLATEAU.x + TAILLE_PLATEAU.x - 50);
      yAlea = alea_a_b_Int(POSITION_PLATEAU.y + 50, POSITION_PLATEAU.y + TAILLE_PLATEAU.y - 50);
    }
    while(FloatRect(xAlea, yAlea, TAILLE_IMAGE_FUMEE.x + 30, TAILLE_IMAGE_FUMEE.y + 30).intersects((joueur.recupererSprite()).getGlobalBounds()));


    int alea = alea_a_b_Int(0,8);

    //On remplis la map avec les Fumee au positions aléaoire
    //comme clés et la direction aléatoire comme valeur
    mapFumee[new Fumee(Vector2f(xAlea, yAlea), vitesse_fumee)] = alea;
  }
}

JeuBrouillard::JeuBrouillard(string nomJoueur, string titre, int niveau, int scoreActuel):
Jeu(nomJoueur, titre)
{
  score = scoreActuel;

  if (niveau == 1)
  {
    nb_fumee = 5;
  }
  else if (niveau == 2)
  {
    nb_fumee = 10;
  }
  else
  {
    nb_fumee = 15;
  }

  for (int i = 0; i < nb_fumee; ++i)
  {
    int xAlea, yAlea;
    //Permet de retirer de nouvelles coordonnées aléatoire tant que le fumee apparait sur le joueur
    do
    {
      xAlea = alea_a_b_Int(POSITION_PLATEAU.x + 50, POSITION_PLATEAU.x + TAILLE_PLATEAU.x - 50);
      yAlea = alea_a_b_Int(POSITION_PLATEAU.y + 50, POSITION_PLATEAU.y + TAILLE_PLATEAU.y - 50);
    }
    while(FloatRect(Vector2f(xAlea,yAlea), TAILLE_IMAGE_FUMEE).intersects((joueur.recupererSprite()).getGlobalBounds()));


    int alea = alea_a_b_Int(0,8);

    //On remplis la map avec les Fumee au positions aléaoire
    //comme clés et la direction aléatoire comme valeur
    mapFumee[new Fumee(Vector2f(xAlea, yAlea))] = alea;
  }
}


int JeuBrouillard::run()
{
  int tempsActuel = 0;
  int chrono = 30;
  int visibleExtincteur = 0;
  int xAlea, yAlea;

  joueur.reinitialiserPosition();
  fenetre.setFramerateLimit(60); // limite la fenêtre à 60 images par seconde
  RectangleShape contourPlateau;

  contourPlateau.setPosition(POSITION_PLATEAU);
  contourPlateau.setSize(TAILLE_PLATEAU);
  contourPlateau.setOutlineThickness(2);
  contourPlateau.setOutlineColor(Color(0, 0, 0, 255));

  // /* Gestion Sprite nuit */
  // if (!nuit_t.loadFromFile("images/nuit.png"))
  // {
  //   cout << "Erreur durant le chargement de l'image nuit" << endl;
  // }
  // nuit_s.setTexture(nuit_t);
  // nuit_s.setPosition(LONGUEUR_MENU/3, LARGEUR_MENU/10);
  // fenetre.draw(nuit_s);

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
            return 0;
            break;

          case Event::KeyPressed : // Appui sur une touche
            switch(event.key.code)
            {
              //CA MARCHE PAS !

              // case Keyboard::P : // Touche P : mettre le jeu en Pause
              //   pauseChrono();
              //   joueur.reinitialiserPosition();
                // break;

                case Keyboard::C : //Touche C ; s'accroupir

                  if (joueur.getEstAccroupi() == 0)
                  {
                    joueur.accroupir(true);
                  }
                  else
                  {
                    joueur.accroupir(false);
                  }
                  break;

                default:
                  break;
            }
          break;

          default :
            break;
        }
      }

      fenetre.clear(Color(255,255,255,255));

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
      {
        if (joueur.recupererSprite().getPosition().y > POSITION_PLATEAU.y)
        {
          joueur.deplacerHaut();
        }
      }
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
      {
        if(joueur.getEstAccroupi() == 0)
        {
          if (joueur.recupererSprite().getPosition().y + TAILLE_IMAGE_JOUEUR.y < POSITION_PLATEAU.y + TAILLE_PLATEAU.y)
          {
            joueur.deplacerBas();
          }
        }
        else
        {
          if (joueur.recupererSprite().getPosition().y + TAILLE_IMAGE_JOUEUR_ACCROUPI.y < POSITION_PLATEAU.y + TAILLE_PLATEAU.y)
          {
            joueur.deplacerBas();
          }
        }
      }
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
      {
        if(joueur.getEstAccroupi() == 0)
        {
          if (joueur.recupererSprite().getPosition().x + TAILLE_IMAGE_JOUEUR.x < POSITION_PLATEAU.x + TAILLE_PLATEAU.x)
          {
            joueur.deplacerDroite();
          }
        }
        else
        {
          if (joueur.recupererSprite().getPosition().x + TAILLE_IMAGE_JOUEUR_ACCROUPI.x < POSITION_PLATEAU.x + TAILLE_PLATEAU.x)
          {
            joueur.deplacerDroite();
          }
        }
      }
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
      {
        if (joueur.recupererSprite().getPosition().x > POSITION_PLATEAU.x)
        {
          joueur.deplacerGauche();
        }
      }

      if (tempsActuel == (int)mesureTemps())
      {
        tempsActuel++;
        chrono--;
      }
      if (chrono == 0)
      {
        fenetre.close();
        return score;
      }

      map<Fumee *, int>::iterator it2; //Un itérateur sur la mapFumee

      //On parcour notre map de fumee
      for (it2 = mapFumee.begin(); it2 != mapFumee.end(); ++it2)
      {
          FloatRect rectJoueur = joueur.recupererSprite().getGlobalBounds();
          rectJoueur.height -= 10;
          rectJoueur.top -= 10;

            FloatRect rectFumee = ((*(it2->first)).recupererSprite()).getGlobalBounds();
            rectFumee.height -= 10;
            rectFumee.width -= 2;
            rectFumee.top -= 10;
            //Si la fumee touche le joueur, la partie est finie
            if (rectJoueur.intersects(rectFumee))
            {
              FinDePartie end;
              end.run();
              fenetre.close();
              return 0;
            }
        }

        for (it2 = mapFumee.begin(); it2 != mapFumee.end(); ++it2)
        {
          switch (it2->second)
          {
            case 0 : //Deplacement à droite
              if (((*(it2->first)).recupererSprite().getPosition().x + TAILLE_IMAGE_FUMEE.x) < (POSITION_PLATEAU.x + TAILLE_PLATEAU.x))
              {
                (*(it2->first)).deplacerDroite();
              }
              else{mapFumee[it2->first] = 1;}
              break;

            case 1 : //Deplacement à gauche
              if (((*(it2->first)).recupererSprite().getPosition().x) > (POSITION_PLATEAU.x))
              {
                (*(it2->first)).deplacerGauche();
              }
              else{mapFumee[it2->first] = 0;}
              break;

            case 2 : //Deplacement en haut
              if ((*(it2->first)).recupererSprite().getPosition().y > POSITION_PLATEAU.y)
              {
                (*(it2->first)).deplacerHaut();
              }
              else{mapFumee[it2->first] = 3;}
              break;

            case 3 : //Deplacement en Bas
              if ((*(it2->first)).recupererSprite().getPosition().y + TAILLE_IMAGE_FUMEE.y < POSITION_PLATEAU.y + TAILLE_PLATEAU.y)
              {
                (*(it2->first)).deplacerBas();
              }
              else{mapFumee[it2->first] = 2;}
              break;

            case 4 : //Deplacement en NW
              if ((*(it2->first)).recupererSprite().getPosition().y > POSITION_PLATEAU.y)
              {
                if (((*(it2->first)).recupererSprite().getPosition().x) > (POSITION_PLATEAU.x))
                {
                  (*(it2->first)).deplacerHaut();
                  (*(it2->first)).deplacerGauche();
                }
                else{mapFumee[it2->first] = 7;}
              }
              else{mapFumee[it2->first] = 7;}
              break;

            case 5 : //Deplacement en NE
              if ((*(it2->first)).recupererSprite().getPosition().y > POSITION_PLATEAU.y)
              {
                if (((*(it2->first)).recupererSprite().getPosition().x + TAILLE_IMAGE_FUMEE.x) < (POSITION_PLATEAU.x + TAILLE_PLATEAU.x))
                {
                  (*(it2->first)).deplacerHaut();
                  (*(it2->first)).deplacerDroite();
                }
                else{mapFumee[it2->first] = 6;}
              }
              else{mapFumee[it2->first] = 6;}
              break;

            case 6 : //Deplacement en SW
              if ((*(it2->first)).recupererSprite().getPosition().y + TAILLE_IMAGE_FUMEE.y < POSITION_PLATEAU.y + TAILLE_PLATEAU.y)
              {
                if (((*(it2->first)).recupererSprite().getPosition().x) > (POSITION_PLATEAU.x))
                {
                  (*(it2->first)).deplacerBas();
                  (*(it2->first)).deplacerGauche();
                }
                else{mapFumee[it2->first] = 5;}
              }
              else{mapFumee[it2->first] = 5;}
              break;

            case 7 : //Deplacement en SE
              if ((*(it2->first)).recupererSprite().getPosition().y + TAILLE_IMAGE_FUMEE.y < POSITION_PLATEAU.y + TAILLE_PLATEAU.y)
              {
                if (((*(it2->first)).recupererSprite().getPosition().x + TAILLE_IMAGE_FUMEE.x) < (POSITION_PLATEAU.x + TAILLE_PLATEAU.x))
                {
                  (*(it2->first)).deplacerBas();
                  (*(it2->first)).deplacerDroite();
                }
                else{mapFumee[it2->first] = 4;}
              }
              else{mapFumee[it2->first] = 4;}
              break;

            default :
              break;
          }
        }

      texteChrono.setString("Temps : " + to_string(chrono) + " secs");
      texteChrono.setPosition(0,TAILLE_FENETRE_JEU.y - ((texteChrono.getGlobalBounds()).height)*2);

      texteNomJoueur.setString(nomJoueur);
      texteNomJoueur.setPosition(TAILLE_FENETRE_JEU.x - ((texteNomJoueur.getGlobalBounds()).width)*2,TAILLE_FENETRE_JEU.y - ((texteNomJoueur.getGlobalBounds()).height)*2);

      texteScore.setString("Score : " + to_string(score));
      texteScore.setPosition(TAILLE_FENETRE_JEU.x - ((texteScore.getGlobalBounds()).width)*2, ((texteScore.getGlobalBounds()).height)*2);

      fenetre.draw(contourPlateau);
      fenetre.draw(joueur.recupererSprite());
      fenetre.draw(texteChrono);
      fenetre.draw(texteNomJoueur);
      fenetre.draw(texteScore);

      for (it2 = mapFumee.begin(); it2 != mapFumee.end(); ++it2)
      {
        fenetre.draw((*(it2->first)).recupererSprite());
      }

      //On cree un rectangle autour du joueur pour detecter les collisions
      FloatRect rectJoueur = joueur.recupererSprite().getGlobalBounds();
      rectJoueur.height -= 13;
      rectJoueur.width -= 10;

      if(visibleExtincteur == 0)
      {
        //On tire des coordonnée aléatoire
        xAlea = alea_a_b_Int(POSITION_PLATEAU.x + 50, POSITION_PLATEAU.x + TAILLE_PLATEAU.x - 50);
        yAlea = alea_a_b_Int(POSITION_PLATEAU.y + 50, POSITION_PLATEAU.y + TAILLE_PLATEAU.y - 50);

        extincteur = new Objet(CHEMIN_IMAGE_EXTINCTEUR, TAILLE_IMAGE_EXTINCTEUR, Vector2f(xAlea, yAlea));

        visibleExtincteur = 1;
      }

      //On fait apparaitre l'objet créer sur la fenetre
      if (extincteur != NULL)
      {
        fenetre.draw((*extincteur).recupererSprite());

        //Si le joueur touche un extincteur, son score augmente
        if (rectJoueur.intersects((*extincteur).recupererSprite().getGlobalBounds()))
        {
          score++;

          xAlea = alea_a_b_Int(POSITION_PLATEAU.x + 50, POSITION_PLATEAU.x + TAILLE_PLATEAU.x - 50);
          yAlea = alea_a_b_Int(POSITION_PLATEAU.y + 50, POSITION_PLATEAU.y + TAILLE_PLATEAU.y - 50);
          (*extincteur).modifierPosition(Vector2f(xAlea, yAlea)); //on retire l'objet de la fenetre
          visibleExtincteur = 0;
        }
      }

      fenetre.display();
  }
  return 0;
}

