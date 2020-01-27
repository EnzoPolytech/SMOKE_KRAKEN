#include "Scene3.hh"
using namespace sf;
using namespace std;

Scene3::Scene3():fenetre(VideoMode(LONGUEUR_INTRO,LARGEUR_INTRO,32), "BIG SMOKE", Style::Close | Style::Titlebar)
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

    /* Chargement des sons */

    else if (!pluie.openFromFile("son/pluie.wav"))
    {
      cerr << "Erreur du chargement du son" << endl;
    }
    else
    {
      /* Création Text textScene3 */

      ligne1.setFont(fontAdler);
      ligne1.setCharacterSize(22);
      ligne1.setFillColor(Color::White);
      ligne1.setString("La pluie fouette mon vétement de pluie." );

      ligne2.setFont(fontAdler);
      ligne2.setCharacterSize(22);
      ligne2.setFillColor(Color::White);
      ligne2.setString("Il pleut sans discontinuer. Le soleil est masque par une masse permanente de nuages lourds et noirs." );

      ligne3.setFont(fontAdler);
      ligne3.setCharacterSize(22);
      ligne3.setFillColor(Color::White);
      ligne3.setString("C'est a peine si la pluie les dilue." );

      ligne4.setFont(fontAdler);
      ligne4.setCharacterSize(22);
      ligne4.setFillColor(Color::White);
      ligne4.setString("Je dois trouver refuge au plus vite. Je dois fuir avant qu'elles ne m'encerclent." );

      ligne5.setFont(fontAdler);
      ligne5.setCharacterSize(15);
      ligne5.setFillColor(Color::White);
      ligne5.setString("< Appuyer sur espace pour continuer >" );

      feuille_s.setTexture(feuille_t);
    }
}

void Scene3::run()
{
  /* Coloration de la fenetre en blanc */

  fenetre.clear(sf::Color::Black);

  /* Ajout tache d'encre */

  feuille_s.setPosition(LONGUEUR_INTRO/2, LARGEUR_INTRO/10 + 120);
  fenetre.draw(feuille_s);

  /* Positionnement du texte */

  ligne1.setPosition(LONGUEUR_INTRO/8, LARGEUR_INTRO/3);
  ligne2.setPosition(LONGUEUR_INTRO/8, LARGEUR_INTRO/3 + 40);
  ligne3.setPosition(LONGUEUR_INTRO/3.5 , LARGEUR_INTRO/3 + 80);
  ligne4.setPosition(LONGUEUR_INTRO/8, LARGEUR_INTRO/3 + 100);
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

  pluie.play();


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
            pluie.stop();
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
