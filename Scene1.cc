#include "Scene1.hh"
using namespace sf;
using namespace std;

Scene1::Scene1():fenetre(VideoMode(LONGUEUR_INTRO,LARGEUR_INTRO,32), "BIG SMOKE", Style::Close | Style::Titlebar)
{

  /* Chargement du Text Scene2 */

    if (!fontAdler.loadFromFile("fonts/adler.ttf"))
    {
      cerr << "Erreur du chargement de la police" << endl;
    }
    /* Chargement image ville */
    else if (!dessin_ville_t.loadFromFile("images/dessin_ville.png"))
    {
      cerr << "Erreur du chargement de l'image" << endl;
    }

    /* Chargement des sons */

    else if (!marcher.openFromFile("son/snow.wav"))
    {
      cerr << "Erreur du chargement du son marche" << endl;
    }
    else if (!dessiner.openFromFile("son/dessiner.wav"))
    {
      cerr << "Erreur du chargement du son dessin" << endl;
    }
    else
    {
      /* Création Text textScene2 */

      ligne1.setFont(fontAdler);
      ligne1.setCharacterSize(22);
      ligne1.setFillColor(Color::Black);
      ligne1.setString("Les buildings defilent de " );

      ligne1bis.setFont(fontAdler);
      ligne1bis.setCharacterSize(22);
      ligne1bis.setFillColor(Color::Black);
      ligne1bis.setString("part et d autre de l avenue" );

      ligne1ter.setFont(fontAdler);
      ligne1ter.setCharacterSize(22);
      ligne1ter.setFillColor(Color::Black);
      ligne1ter.setString("deserte et verglacee." );

      ligne2.setFont(fontAdler);
      ligne2.setCharacterSize(15);
      ligne2.setFillColor(Color::Black);
      ligne2.setString("< Appuyer sur espace pour continuer >" );

      dessin_ville_s.setTexture(dessin_ville_t);
      //marcher.setVolume(50.f);
      //dessin.setVolume(100.f);

    }
}

void Scene1::run()
{

  /* Coloration de la fenetre en blanc */

  fenetre.clear(Color(255,255,255,255));

  /* Positionnement et tracé des dessins */

  //dessin_ville_s.setPosition(LONGUEUR_INTRO/2, LARGEUR_INTRO/2 - 300);
  fenetre.draw(dessin_ville_s);


  /* Positionnement du texte */

  ligne1.setPosition(LONGUEUR_INTRO/8, LARGEUR_INTRO/2 - 100);
  ligne2.setPosition(LONGUEUR_INTRO/3.5 , LARGEUR_INTRO/3 + 320);
  ligne1bis.setPosition(LONGUEUR_INTRO/8, LARGEUR_INTRO/2 + 40 -100);
  ligne1ter.setPosition(LONGUEUR_INTRO/8, LARGEUR_INTRO/2 + 80 -100);

  /* Tracé du Text textScene2 */

  fenetre.draw(ligne1);
  fenetre.draw(ligne2);
  fenetre.draw(ligne1bis);
  fenetre.draw(ligne1ter);

  /* Affichage de la fenetre */

  fenetre.display();

  /* Lancement du son de l'intro et de la machine a ecrire */

  marcher.play();
  dessiner.play();


  /* Boucle de détection d'événement */

  while(fenetre.isOpen())
  {
    Event event;

    while(fenetre.pollEvent(event))
    {
      if (event.type == Event::Closed)
      {
        fenetre.close();
      }
      if(event.type == Event::KeyPressed) // Appui sur une touche
      {
        switch(event.key.code)
        {

          case Keyboard::Space :
            marcher.stop();
            dessiner.stop();
            fenetre.close();
            return;
            // exit(EXIT_SUCCESS);
            break;

          default :
            break;
        }
      }
    }
  }
}
