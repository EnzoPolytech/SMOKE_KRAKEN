#include "JeuLabyrinthe.hh"

using namespace sf;
using namespace std;

JeuLabyrinthe::JeuLabyrinthe(string nomJoueur, int nbFumee, int nbChrono):
Jeu(nomJoueur, "Mode Labyrinthe"), sortie(CHEMIN_IMAGE_SORTIE,TAILLE_IMAGE_SORTIE)
{
  for (int i = 1; i <= nbFumee; ++i)
  {
    tabFumee.push_back(new Fumee());
  }
  for (int i = 1; i <= nbChrono; ++i)
  {
    tabChrono.push_back(new Objet(CHEMIN_IMAGE_CHRONO, TAILLE_IMAGE_CHRONO));
  }
  for (int i = 1; i <= NB_EXTINCTEUR; ++i)
  {
    tabExtincteur.push_back(new Objet(CHEMIN_IMAGE_EXTINCTEUR, TAILLE_IMAGE_EXTINCTEUR));
  }

  int pos_joueur_ini_X = POSITION_PLATEAU.x;
  int pos_joueur_ini_Y = POSITION_PLATEAU.y + (TAILLE_PLATEAU.y / 2);
  Vector2f pos_joueur_ini = Vector2f(pos_joueur_ini_X, pos_joueur_ini_Y);

  joueur.modifierPosition(pos_joueur_ini);

  sortie.modifierPosition(Vector2f(POSITION_PLATEAU.x + 10*TAILLE_IMAGE_FUMEE.x,POSITION_PLATEAU.y + 5));

  //On positionne les fumees

  (*tabFumee[0]).modifierPosition(Vector2f(pos_joueur_ini.x, pos_joueur_ini.y + TAILLE_IMAGE_JOUEUR.y));

  (*tabFumee[1]).modifierPosition(Vector2f(pos_joueur_ini.x + TAILLE_IMAGE_FUMEE.x, pos_joueur_ini.y + TAILLE_IMAGE_JOUEUR.y));

  (*tabFumee[2]).modifierPosition(Vector2f(pos_joueur_ini.x + TAILLE_IMAGE_JOUEUR.x, pos_joueur_ini.y - TAILLE_IMAGE_FUMEE.y));

  (*tabFumee[3]).modifierPosition(Vector2f(pos_joueur_ini.x + TAILLE_IMAGE_JOUEUR.x, pos_joueur_ini.y - 2*(TAILLE_IMAGE_FUMEE.y)));

  (*tabFumee[4]).modifierPosition(Vector2f(pos_joueur_ini.x + 2*(TAILLE_IMAGE_FUMEE.x), pos_joueur_ini.y + TAILLE_IMAGE_JOUEUR.y));

  (*tabFumee[6]).modifierPosition(Vector2f(pos_joueur_ini.x + 3*(TAILLE_IMAGE_FUMEE.x), pos_joueur_ini.y + TAILLE_IMAGE_JOUEUR.y - TAILLE_IMAGE_FUMEE.y));

  (*tabFumee[7]).modifierPosition(Vector2f(pos_joueur_ini.x + TAILLE_IMAGE_JOUEUR.x + TAILLE_IMAGE_FUMEE.x, pos_joueur_ini.y - 2*(TAILLE_IMAGE_FUMEE.y)));

  (*tabFumee[8]).modifierPosition(Vector2f(pos_joueur_ini.x + TAILLE_IMAGE_JOUEUR.x + 2*(TAILLE_IMAGE_FUMEE.x), pos_joueur_ini.y - 2*(TAILLE_IMAGE_FUMEE.y)));

  (*tabFumee[9]).modifierPosition(Vector2f(pos_joueur_ini.x + TAILLE_IMAGE_JOUEUR.x, pos_joueur_ini.y - 3*TAILLE_IMAGE_FUMEE.y));

  (*tabFumee[10]).modifierPosition(Vector2f(pos_joueur_ini.x + TAILLE_IMAGE_JOUEUR.x, pos_joueur_ini.y - 4*TAILLE_IMAGE_FUMEE.y));

  //on positionne des lignes de fumee

  for (int i = 11; i < 17; ++i)
  {
    (*tabFumee[i]).modifierPosition(Vector2f(pos_joueur_ini.x + TAILLE_IMAGE_JOUEUR.x + (i - 9)*TAILLE_IMAGE_FUMEE.x, pos_joueur_ini.y - 3*TAILLE_IMAGE_FUMEE.y - TAILLE_IMAGE_JOUEUR.y));
  }

  (*tabFumee[17]).modifierPosition(Vector2f(pos_joueur_ini.x + TAILLE_IMAGE_JOUEUR.x + 3*(TAILLE_IMAGE_FUMEE.x), pos_joueur_ini.y - 2*(TAILLE_IMAGE_FUMEE.y)));
  (*tabFumee[18]).modifierPosition(Vector2f(pos_joueur_ini.x + TAILLE_IMAGE_JOUEUR.x + 4*(TAILLE_IMAGE_FUMEE.x), pos_joueur_ini.y - 2*(TAILLE_IMAGE_FUMEE.y)));
  (*tabFumee[19]).modifierPosition(Vector2f(pos_joueur_ini.x + 4*(TAILLE_IMAGE_FUMEE.x), pos_joueur_ini.y + TAILLE_IMAGE_JOUEUR.y - TAILLE_IMAGE_FUMEE.y));
  (*tabFumee[20]).modifierPosition(Vector2f(pos_joueur_ini.x + 5*(TAILLE_IMAGE_FUMEE.x), pos_joueur_ini.y + TAILLE_IMAGE_JOUEUR.y - TAILLE_IMAGE_FUMEE.y));

  (*tabFumee[21]).modifierPosition(Vector2f(pos_joueur_ini.x + TAILLE_IMAGE_JOUEUR.x + 7*TAILLE_IMAGE_FUMEE.x, pos_joueur_ini.y - 4*TAILLE_IMAGE_FUMEE.y - TAILLE_IMAGE_JOUEUR.y));
  (*tabFumee[22]).modifierPosition(Vector2f(pos_joueur_ini.x + TAILLE_IMAGE_JOUEUR.x + 7*TAILLE_IMAGE_FUMEE.x, pos_joueur_ini.y - 2*TAILLE_IMAGE_FUMEE.y - TAILLE_IMAGE_JOUEUR.y));
  (*tabFumee[23]).modifierPosition(Vector2f(pos_joueur_ini.x + TAILLE_IMAGE_JOUEUR.x + 7*TAILLE_IMAGE_FUMEE.x, pos_joueur_ini.y - TAILLE_IMAGE_FUMEE.y - TAILLE_IMAGE_JOUEUR.y));

  (*tabFumee[24]).modifierPosition(Vector2f(pos_joueur_ini.x + TAILLE_IMAGE_JOUEUR.x + 5*TAILLE_IMAGE_FUMEE.x - 5, pos_joueur_ini.y - 2*(TAILLE_IMAGE_FUMEE.y)));

  (*tabFumee[25]).modifierPosition(Vector2f(pos_joueur_ini.x + TAILLE_IMAGE_JOUEUR.x + 8*TAILLE_IMAGE_FUMEE.x, pos_joueur_ini.y - TAILLE_IMAGE_FUMEE.y - TAILLE_IMAGE_JOUEUR.y));
  (*tabFumee[26]).modifierPosition(Vector2f(pos_joueur_ini.x + TAILLE_IMAGE_JOUEUR.x + 9*TAILLE_IMAGE_FUMEE.x, pos_joueur_ini.y - TAILLE_IMAGE_FUMEE.y - TAILLE_IMAGE_JOUEUR.y));

  (*tabFumee[27]).modifierPosition(Vector2f(pos_joueur_ini.x + TAILLE_IMAGE_JOUEUR.x + 9*TAILLE_IMAGE_FUMEE.x, pos_joueur_ini.y - TAILLE_IMAGE_JOUEUR.y));
  (*tabFumee[28]).modifierPosition(Vector2f(pos_joueur_ini.x + TAILLE_IMAGE_JOUEUR.x + 9*TAILLE_IMAGE_FUMEE.x, pos_joueur_ini.y + TAILLE_IMAGE_FUMEE.y - TAILLE_IMAGE_JOUEUR.y));

  (*tabFumee[30]).modifierPosition(Vector2f(pos_joueur_ini.x + TAILLE_IMAGE_JOUEUR.x + 8*TAILLE_IMAGE_FUMEE.x, pos_joueur_ini.y + 2*TAILLE_IMAGE_FUMEE.y - TAILLE_IMAGE_JOUEUR.y - 30));
  (*tabFumee[31]).modifierPosition(Vector2f(pos_joueur_ini.x + TAILLE_IMAGE_JOUEUR.x + 7*TAILLE_IMAGE_FUMEE.x, pos_joueur_ini.y + 2*TAILLE_IMAGE_FUMEE.y - TAILLE_IMAGE_JOUEUR.y - 30));

  for (int i = 32; i < 35; ++i)
  {
    (*tabFumee[i]).modifierPosition(Vector2f(pos_joueur_ini.x + TAILLE_IMAGE_JOUEUR.x + 7*TAILLE_IMAGE_FUMEE.x, pos_joueur_ini.y + 2*TAILLE_IMAGE_FUMEE.y - TAILLE_IMAGE_JOUEUR.y - 40 + (i-31)*TAILLE_IMAGE_FUMEE.y));
  }

  (*tabFumee[35]).modifierPosition(Vector2f(pos_joueur_ini.x + TAILLE_IMAGE_JOUEUR.x + 7*TAILLE_IMAGE_FUMEE.x, pos_joueur_ini.y + 2*TAILLE_IMAGE_FUMEE.y - TAILLE_IMAGE_JOUEUR.y - 50 + 4*TAILLE_IMAGE_FUMEE.y));

  for (int i = 36; i < 39; ++i)
  {
    (*tabFumee[i]).modifierPosition(Vector2f(pos_joueur_ini.x + TAILLE_IMAGE_JOUEUR.x + 7*TAILLE_IMAGE_FUMEE.x - (i-35)*TAILLE_IMAGE_FUMEE.x, pos_joueur_ini.y + 2*TAILLE_IMAGE_FUMEE.y - TAILLE_IMAGE_JOUEUR.y - 50 + 4*TAILLE_IMAGE_FUMEE.y));
  }

  (*tabFumee[39]).modifierPosition(Vector2f(pos_joueur_ini.x + TAILLE_IMAGE_JOUEUR.x + 3*TAILLE_IMAGE_FUMEE.x + 10, pos_joueur_ini.y + 2*TAILLE_IMAGE_FUMEE.y - TAILLE_IMAGE_JOUEUR.y - 50 + 4*TAILLE_IMAGE_FUMEE.y));

  (*tabFumee[40]).modifierPosition(Vector2f(pos_joueur_ini.x + 2*(TAILLE_IMAGE_FUMEE.x), pos_joueur_ini.y + 2*TAILLE_IMAGE_JOUEUR.y + TAILLE_IMAGE_FUMEE.y));
  (*tabFumee[41]).modifierPosition(Vector2f(pos_joueur_ini.x + 2*(TAILLE_IMAGE_FUMEE.x), pos_joueur_ini.y + 2*TAILLE_IMAGE_JOUEUR.y + 2*TAILLE_IMAGE_FUMEE.y));

  (*tabFumee[42]).modifierPosition(Vector2f(pos_joueur_ini.x + TAILLE_IMAGE_JOUEUR.x + 8*TAILLE_IMAGE_FUMEE.x, pos_joueur_ini.y + 6*TAILLE_IMAGE_FUMEE.y - TAILLE_IMAGE_JOUEUR.y - 50));
  (*tabFumee[43]).modifierPosition(Vector2f(pos_joueur_ini.x + TAILLE_IMAGE_JOUEUR.x + 9*TAILLE_IMAGE_FUMEE.x, pos_joueur_ini.y + 6*TAILLE_IMAGE_FUMEE.y - TAILLE_IMAGE_JOUEUR.y - 50));
  (*tabFumee[44]).modifierPosition(Vector2f(pos_joueur_ini.x + TAILLE_IMAGE_JOUEUR.x + 9*TAILLE_IMAGE_FUMEE.x, pos_joueur_ini.y + 5*TAILLE_IMAGE_FUMEE.y - TAILLE_IMAGE_JOUEUR.y - 35));

  //On positionne les chrono

  (*tabChrono[0]).modifierPosition(Vector2f(POSITION_PLATEAU.x + 7*TAILLE_IMAGE_CHRONO.x, POSITION_PLATEAU.y));
  (*tabChrono[1]).modifierPosition(Vector2f(POSITION_PLATEAU.x + 9*TAILLE_IMAGE_CHRONO.x, POSITION_PLATEAU.y + 5*TAILLE_IMAGE_CHRONO.y));
  (*tabChrono[2]).modifierPosition(Vector2f(POSITION_PLATEAU.x, POSITION_PLATEAU.y + 11*TAILLE_IMAGE_CHRONO.y));
  (*tabChrono[3]).modifierPosition(Vector2f(POSITION_PLATEAU.x + 9*TAILLE_IMAGE_CHRONO.x, POSITION_PLATEAU.y + 8*TAILLE_IMAGE_CHRONO.y));

  //On positionne les extincteurs

  (*tabExtincteur[0]).modifierPosition(Vector2f(POSITION_PLATEAU.x + 4*TAILLE_IMAGE_EXTINCTEUR.x, POSITION_PLATEAU.y + 5*TAILLE_IMAGE_EXTINCTEUR.y));
  (*tabExtincteur[1]).modifierPosition(Vector2f(POSITION_PLATEAU.x + 5*TAILLE_IMAGE_EXTINCTEUR.x, POSITION_PLATEAU.y + 5));
  (*tabExtincteur[2]).modifierPosition(Vector2f(POSITION_PLATEAU.x + 5, POSITION_PLATEAU.y + 9*TAILLE_IMAGE_EXTINCTEUR.y));
  (*tabExtincteur[3]).modifierPosition(Vector2f(POSITION_PLATEAU.x + 9*TAILLE_IMAGE_EXTINCTEUR.x, POSITION_PLATEAU.y + 2*TAILLE_IMAGE_EXTINCTEUR.y));
}

int JeuLabyrinthe::run()
{
  int tempsActuel = 0;
  int chrono = 60;
  RectangleShape contourPlateau;

  contourPlateau.setPosition(POSITION_PLATEAU);
  contourPlateau.setSize(TAILLE_PLATEAU);
  contourPlateau.setOutlineThickness(2);
  contourPlateau.setOutlineColor(Color(0, 0, 0, 255));

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
            // exit(EXIT_SUCCESS);
            break;

          case Event::KeyPressed : // Appui sur une touche
            switch(event.key.code)
            {

              // case Keyboard::P : // Touche P : mettre le jeu en Pause
              //   //Ca marche pas !
              //   // pauseChrono();
              //   // joueur.reinitialiserPosition();
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

      //On cree un rectangle autour du joueur pour detecter les collisions
      FloatRect rectJoueur = joueur.recupererSprite().getGlobalBounds();
      rectJoueur.height -= 13;
      rectJoueur.width -= 10;
      for (int i = 1; i <= NB_FUMEE; ++i)
      {
        if (tabFumee[i-1] != NULL)
        {
          if (rectJoueur.intersects((*tabFumee[i-1]).recupererSprite().getGlobalBounds()))
          {
            FinDePartie end;
            end.run();
            fenetre.close();
            return 0;
          }
        }
      }

      fenetre.clear(Color(255,255,255,255));

      if (tempsActuel == (int)mesureTemps())
      {
        tempsActuel++;
        chrono--;
      }

      texteChrono.setString("Temps : " + to_string((int)chrono) + " secs");
      texteChrono.setPosition(0,TAILLE_FENETRE_JEU.y - ((texteChrono.getGlobalBounds()).height)*2);

      texteNomJoueur.setString(nomJoueur);
      texteNomJoueur.setPosition(TAILLE_FENETRE_JEU.x - ((texteNomJoueur.getGlobalBounds()).width)*2,TAILLE_FENETRE_JEU.y - ((texteNomJoueur.getGlobalBounds()).height)*2);

      //On dessine tout nos éléments sur notre fenetre
      fenetre.draw(contourPlateau);
      fenetre.draw(joueur.recupererSprite());
      fenetre.draw(sortie.recupererSprite());
      fenetre.draw(texteChrono);
      fenetre.draw(texteNomJoueur);

      //on parcours notre tableau de fumée
      for (int i = 1; i <= NB_FUMEE; ++i)
      {
        //Si il y a une fumée, alors on la dessine
        if (tabFumee[i-1] != NULL)
        {
          fenetre.draw((*tabFumee[i-1]).recupererSprite());
        }
      }
      //on parcours notre tableau de chrono
      for (int i = 1; i <= NB_CHRONO; ++i)
      {
        //Si il y a un chrono, alors on le dessine
        if (tabChrono[i-1] != NULL)
        {
          fenetre.draw((*tabChrono[i-1]).recupererSprite());

          //Si le joueur touche un chrono il gagne du temps
          if (rectJoueur.intersects((*tabChrono[i-1]).recupererSprite().getGlobalBounds()))
          {
            chrono += 5;
            tabChrono[i-1] = NULL; //on enleve le chrono
          }
        }
      }
      //on parcours notre tableau d'extincteur
      for (int i = 1; i <= NB_EXTINCTEUR; ++i)
      {
        //Si il y a un extincteur, alors on le dessine
        if (tabExtincteur[i-1] != NULL)
        {
          fenetre.draw((*tabExtincteur[i-1]).recupererSprite());

          //Si le joueur touche un extincteur son score augmente
          if (rectJoueur.intersects((*tabExtincteur[i-1]).recupererSprite().getGlobalBounds()))
          {
            score++;
            tabExtincteur[i-1] = NULL; //on enleve le chrono
          }
        }
      }


      //Si le joueur atteint la sortie
      if (rectJoueur.intersects((sortie.recupererSprite()).getGlobalBounds()))
      {
        //Passage a la fenetre suivante !
        fenetre.close();
        return score;
        // exit(EXIT_SUCCESS);
      }

      fenetre.display();
  }
  return 0;
}
