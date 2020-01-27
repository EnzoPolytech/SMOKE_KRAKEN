#include "Scene5.hh"
using namespace sf;
using namespace std;

Scene5::Scene5():fenetre(VideoMode(LONGUEUR_INTRO,LARGEUR_INTRO,32), "BIG SMOKE", Style::Close | Style::Titlebar)
{

  /* Chargement du Text Scene5 */

    if (!fontAdler.loadFromFile("fonts/adler.ttf"))
    {
      cerr << "Erreur du chargement de la police" << endl;
    }
    /* Chargement image feuille  */
    else if (!feuille_t.loadFromFile("images/feuille.png"))
    {
      cerr << "Erreur du chargement de l'image" << endl;
    }
    else if (!feuille2_t.loadFromFile("images/feuille2.png"))
    {
      cerr << "Erreur du chargement de l'image" << endl;
    }
    /* Chargement des sons */

    else if (!vent.openFromFile("son/wind.wav"))
    {
      cerr << "Erreur du chargement du son" << endl;
    }
    else if (!soupire.openFromFile("son/sigh.wav"))
    {
      cerr << "Erreur du chargement du son" << endl;
    }
    else
    {
      /* Création Text textScene5 */

      ligne1.setFont(fontAdler);
      ligne1.setCharacterSize(22);
      ligne1.setFillColor(Color::Black);
      ligne1.setString("La nuit est glacante. Juste avant de sombrer dans" );

      ligne2.setFont(fontAdler);
      ligne2.setCharacterSize(22);
      ligne2.setFillColor(Color::Black);
      ligne2.setString("le sommeil, je vois une morgue remplie de reves, ou" );


      ligne3.setFont(fontAdler);
      ligne3.setCharacterSize(22);
      ligne3.setFillColor(Color::Black);
      ligne3.setString("je me promene sans meme etre capable d'identifier " );

      ligne4.setFont(fontAdler);
      ligne4.setCharacterSize(22);
      ligne4.setFillColor(Color::Black);
      ligne4.setString("les miens." );

      ligne5.setFont(fontAdler);
      ligne5.setCharacterSize(15);
      ligne5.setFillColor(Color::Black);
      ligne5.setString("< Appuyer sur espace pour continuer >" );

      feuille_s.setTexture(feuille_t);
      feuille2_s.setTexture(feuille2_t);
    }
}

void Scene5::run()
{
  /* Coloration de la fenetre en blanc */

  fenetre.clear(Color(255,255,255,255));

  /* Ajout tache d'encre */

  feuille_s.setPosition(LONGUEUR_INTRO/2, LARGEUR_INTRO/10 + 120);
  feuille2_s.setPosition(LONGUEUR_INTRO/2 -900, LARGEUR_INTRO/10 - 400);
  fenetre.draw(feuille_s);
  fenetre.draw(feuille2_s);

  /* Positionnement du texte */

  ligne1.setPosition(LONGUEUR_INTRO/8, LARGEUR_INTRO/3);
  ligne2.setPosition(LONGUEUR_INTRO/8, LARGEUR_INTRO/3 + 40);
  ligne3.setPosition(LONGUEUR_INTRO/8, LARGEUR_INTRO/3 + 80);
  ligne4.setPosition(LONGUEUR_INTRO/8, LARGEUR_INTRO/3 + 120);
  ligne5.setPosition(LONGUEUR_INTRO/3.5 , LARGEUR_INTRO/3 + 320);


  /* Tracé du Text textScene2 */

  fenetre.draw(ligne1);
  fenetre.draw(ligne2);
  fenetre.draw(ligne3);
  fenetre.draw(ligne4);
  fenetre.draw(ligne5);

  /* Affichage de la fenetre */

  fenetre.display();

  /* Lancement du son de l'intro et de la machine a ecrire */

  vent.play();
  soupire.play();


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
            soupire.stop();
            vent.stop();
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
