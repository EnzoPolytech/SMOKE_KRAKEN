#include "Intro.hh"
using namespace sf;
using namespace std;

Intro::Intro():fenetre(VideoMode(LONGUEUR_INTRO,LARGEUR_INTRO,32), "BIG SMOKE", Style::Close | Style::Titlebar)
{

  /* Chargement du Text textIntro */

    if (!fontAdler.loadFromFile("fonts/adler.ttf"))
    {
      cerr << "Erreur du chargement de la police" << endl;
    }

    /* Chargement du son */

    else if (!music.openFromFile("son/intro_sound.wav"))
    {
      cerr << "Erreur du chargement du son" << endl;
    }
    else if (!machine.openFromFile("son/machine_a_ecrire.wav"))
    {
      cerr << "Erreur du chargement du son" << endl;
    }
    else
    {
      /* Création Text textIntro */

      date.setFont(fontAdler);
      date.setCharacterSize(TAILLE_POLICE_INTRO);
      date.setFillColor(Color::Black);
      date.setString("Mardi 4 janvier 2032");

      ligne1.setFont(fontAdler);
      ligne1.setCharacterSize(22);
      ligne1.setFillColor(Color::Black);
      ligne1.setString("Deja un mois que la ville a ete ravagee par de mysterieuses" );

      ligne2.setFont(fontAdler);
      ligne2.setCharacterSize(22);
      ligne2.setFillColor(Color::Black);
      ligne2.setString("fumees toxique. Dehors, ce n\'est certes que mort et desolation;" );

      ligne3.setFont(fontAdler);
      ligne3.setCharacterSize(22);
      ligne3.setFillColor(Color::Black);
      ligne3.setString("mais combien reste-il de refuges comme le mien? Je ne suis" );

      ligne4.setFont(fontAdler);
      ligne4.setCharacterSize(22);
      ligne4.setFillColor(Color::Black);
      ligne4.setString("plus que l'ombre de moi meme." );

      ligne5.setFont(fontAdler);
      ligne5.setCharacterSize(22);
      ligne5.setFillColor(Color::Black);
      ligne5.setString("Trop de hurlements le jour." );

      ligne6.setFont(fontAdler);
      ligne6.setCharacterSize(22);
      ligne6.setFillColor(Color::Black);
      ligne6.setString("Trop d'angoisse la nuit." );

      ligne7.setFont(fontAdler);
      ligne7.setCharacterSize(22);
      ligne7.setFillColor(Color::Black);
      ligne7.setString("Il faut que je sorte d'ici avant de devenir fou..." );

      ligne8.setFont(fontAdler);
      ligne8.setCharacterSize(15);
      ligne8.setFillColor(Color::Black);
      ligne8.setString("< Appuyer sur espace pour continuer >" );

      /* Réglage des parametres du son */
      // music.setPosition(0, 1, 10); // change its 3D position
      // music.setPitch(2);           // increase the pitch
      // music.setVolume(50);         // reduce the volume
      // music.setLoop(true);

    }
}

void Intro::run()
{
  /* Coloration de la fenetre en blanc */

  fenetre.clear(Color(255,255,255,255));

  /* Positionnement du texte */

  date.setPosition(LONGUEUR_INTRO/10, LARGEUR_INTRO/5);
  ligne1.setPosition(LONGUEUR_INTRO/8, LARGEUR_INTRO/3);
  ligne2.setPosition(LONGUEUR_INTRO/8, LARGEUR_INTRO/3 + 40);
  ligne3.setPosition(LONGUEUR_INTRO/8, LARGEUR_INTRO/3 + 80);
  ligne4.setPosition(LONGUEUR_INTRO/8, LARGEUR_INTRO/3 + 120);
  ligne5.setPosition(LONGUEUR_INTRO/8, LARGEUR_INTRO/3 + 160);
  ligne6.setPosition(LONGUEUR_INTRO/8, LARGEUR_INTRO/3 + 200);
  ligne7.setPosition(LONGUEUR_INTRO/8, LARGEUR_INTRO/3 + 240);
  ligne8.setPosition(LONGUEUR_INTRO/3.5 , LARGEUR_INTRO/3 + 340);

  /* Tracé du Text textIntro */

  fenetre.draw(date);
  fenetre.draw(ligne1);
  fenetre.draw(ligne2);
  fenetre.draw(ligne3);
  fenetre.draw(ligne4);
  fenetre.draw(ligne5);
  fenetre.draw(ligne6);
  fenetre.draw(ligne7);
  fenetre.draw(ligne8);

  /* Affichage de la fenetre */

  fenetre.display();

  /* Lancement du son de l'intro et de la machine a ecrire */

  music.play();
  machine.play();

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
            music.stop();
            machine.stop();
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
