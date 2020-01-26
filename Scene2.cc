#include "Scene2.hh"
using namespace sf;
using namespace std;

Scene2::Scene2():fenetre(VideoMode(LONGUEUR_INTRO,LARGEUR_INTRO,32), "BIG SMOKE", Style::Close | Style::Titlebar)
{

  /* Chargement du Text Scene2 */

    if (!fontAdler.loadFromFile("fonts/adler.ttf"))
    {
      cerr << "Erreur du chargement de la police" << endl;
    }
    /* Chargement image tache encre  */
    else if (!encre_t.loadFromFile("images/encre.png"))
    {
      cerr << "Erreur du chargement de l'image" << endl;
    }
    /* Chargement des sons */

    else if (!ambiance.openFromFile("son/ambiance.wav"))
    {
      cerr << "Erreur du chargement du son" << endl;
    }
    else if (!sanglot.openFromFile("son/sanglot.wav"))
    {
      cerr << "Erreur du chargement du son" << endl;
    }
    else
    {
      /* Création Text textScene2 */

      ligne1.setFont(fontAdler);
      ligne1.setCharacterSize(22);
      ligne1.setFillColor(Color::Black);
      ligne1.setString("Un profond desespoir m'envahit tout a coup; Je suis " );

      ligne2.setFont(fontAdler);
      ligne2.setCharacterSize(22);
      ligne2.setFillColor(Color::Black);
      ligne2.setString("effroyablement seul." );

      ligne3.setFont(fontAdler);
      ligne3.setCharacterSize(22);
      ligne3.setFillColor(Color::Black);
      ligne3.setString("Ma mort n'est que tres simple." );

      ligne4.setFont(fontAdler);
      ligne4.setCharacterSize(22);
      ligne4.setFillColor(Color::Black);
      ligne4.setString("Celle des autres m'est insupportable." );

      ligne5.setFont(fontAdler);
      ligne5.setCharacterSize(15);
      ligne5.setFillColor(Color::Black);
      ligne5.setString("< Appuyer sur espace pour continuer >" );

      encre_s.setTexture(encre_t);

    }
}

void Scene2::run()
{
  /* Coloration de la fenetre en blanc */

  fenetre.clear(Color(255,255,255,255));

  /* Ajout tache d'encre */

  encre_s.setPosition(LONGUEUR_INTRO/2, LARGEUR_INTRO/10 + 120);
  fenetre.draw(encre_s);

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

  ambiance.play();
  sanglot.play();


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

          case Keyboard::T :
            ambiance.stop();
            sanglot.stop();
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
