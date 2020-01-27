#include "Scene6.hh"
using namespace sf;
using namespace std;

Scene6::Scene6():fenetre(VideoMode(LONGUEUR_INTRO,LARGEUR_INTRO,32), "BIG SMOKE", Style::Close | Style::Titlebar)
{

  /* Chargement du Text Scene3 */

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
    else if (!neige.openFromFile("son/snow.wav"))
    {
      cerr << "Erreur du chargement du son" << endl;
    }
    else
    {
      /* Création Text textScene3 */

      ligne1.setFont(fontAdler);
      ligne1.setCharacterSize(22);
      ligne1.setFillColor(Color::Black);
      ligne1.setString("Il semble y avoir une eclaircit a l'ouest de la ville. " );

      ligne2.setFont(fontAdler);
      ligne2.setCharacterSize(22);
      ligne2.setFillColor(Color::Black);
      ligne2.setString("Cette ville maudite est un vrai labyrinthe..." );

      ligne3.setFont(fontAdler);
      ligne3.setCharacterSize(15);
      ligne3.setFillColor(Color::Black);
      ligne3.setString("< Appuyer sur espace pour continuer >" );

      feuille_s.setTexture(feuille_t);
      feuille2_s.setTexture(feuille2_t);
    }
}

void Scene6::run()
{
  /* Coloration de la fenetre en blanc */

  fenetre.clear(Color(255,255,255,255));

  /* Ajout tache d'encre */

  feuille_s.setPosition(LONGUEUR_INTRO/2, LARGEUR_INTRO/10 + 120);
  feuille2_s.setPosition(LONGUEUR_INTRO/2 -900, LARGEUR_INTRO/10 - 400);
  fenetre.draw(feuille_s);
  fenetre.draw(feuille2_s);

  /* Positionnement du texte */

  ligne1.setPosition(LONGUEUR_INTRO/8, LARGEUR_INTRO/3 + 40);
  ligne2.setPosition(LONGUEUR_INTRO/8, LARGEUR_INTRO/3 + 80);
  ligne3.setPosition(LONGUEUR_INTRO/3.5 , LARGEUR_INTRO/3 + 320);


  /* Tracé du Text textScene2 */

  fenetre.draw(ligne1);
  fenetre.draw(ligne2);
  fenetre.draw(ligne3);

  /* Affichage de la fenetre */

  fenetre.display();

  /* Lancement du son de l'intro et de la machine a ecrire */

  vent.play();
  neige.play();


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
            neige.stop();
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
