#include "Menu.hh"
#include "NomJoueur.hh"
#include "Record.hh"
#include "Jeu.hh"

using namespace sf;
using namespace std;

Menu::Menu():fenetre(VideoMode(LONGUEUR_MENU,LARGEUR_MENU,32), "BIG SMOKE", Style::Close | Style::Titlebar)
{

  /* Chargement des Sprites et Textures : ville_fumee, bouton Joueur/Record et titre*/

  if (!imageFond_t.loadFromFile("images/ville_fumee.png"))
  {
    cout <<"Erreur durant le chargement de l'image de fond"<< endl;
  }
  else if (!boutonJouer_t.loadFromFile("images/boutonJouer.png"))
  {
    cout <<"Erreur durant le chargement de l'image du bouton jouer"<< endl;
  }
  else if (!boutonRecord_t.loadFromFile("images/boutonRecord.png"))
  {
    cout <<"Erreur durant le chargement de l'image du bouton record"<< endl;
  }
  else if (!perso_t.loadFromFile("images/menu_perso.png"))
  {
    cout <<"Erreur durant le chargement de l'image du perso grand format"<< endl;
  }
  else if (!titre_t.loadFromFile("images/bigSmoke.png"))
  {
    cout <<"Erreur durant le chargement de l'image du titre"<< endl;
  }
  else
  {
    imageFond_s.setTexture(imageFond_t);
    boutonJouer_s.setTexture(boutonJouer_t);
    boutonRecord_s.setTexture(boutonRecord_t);
    titre_s.setTexture(titre_t);
    perso_s.setTexture(perso_t);
  }

}

void Menu::run()
{
  /* Ajout de l'image de fond sur la fenetre */

  fenetre.draw(imageFond_s);

  /* Ajout du titre sur la fenetre */

  titre_s.setPosition(LONGUEUR_MENU/3, LARGEUR_MENU/10);
  fenetre.draw(titre_s);

  /* Ajout personnage principale */

  perso_s.setPosition((LONGUEUR_MENU/2)-50,  LARGEUR_MENU/2 -30);
  fenetre.draw(perso_s);

  /* Création du bouton jouer */

  boutonJouer_s.setPosition((LONGUEUR_MENU/2)-50, (5*LARGEUR_MENU/6)-30);

  RectangleShape contourBoutonJouer;
  contourBoutonJouer.setPosition(boutonJouer_s.getPosition());
  contourBoutonJouer.setSize(Vector2f(110,45));
  contourBoutonJouer.setOutlineThickness(2);
  contourBoutonJouer.setOutlineColor(Color(0, 0, 0, 255));

  fenetre.draw(contourBoutonJouer);
  fenetre.draw(boutonJouer_s);

  FloatRect limiteBoutonJouer = boutonJouer_s.getGlobalBounds();

  /* Création du bouton record */

  boutonRecord_s.setPosition((LONGUEUR_MENU/2)-65, (5*LARGEUR_MENU/6)+35);

  RectangleShape contourBoutonRecord;
  contourBoutonRecord.setPosition(boutonRecord_s.getPosition());
  contourBoutonRecord.setSize(Vector2f(140,45));
  contourBoutonRecord.setOutlineThickness(2);
  contourBoutonRecord.setOutlineColor(Color(0, 0, 0, 255));

  fenetre.draw(contourBoutonRecord);
  fenetre.draw(boutonRecord_s);

  FloatRect limiteBoutonRecord = boutonRecord_s.getGlobalBounds();

  // Affichage de la fenetre
  fenetre.display();

  /* Boucle de détéction d'événement */

  while(fenetre.isOpen())
  {
    Event event;

    while(fenetre.pollEvent(event))
    {
      if (event.type == Event::Closed)
      {
        fenetre.close();
      }
      else if(event.type == Event::MouseButtonPressed)
      {
        if (event.mouseButton.button == Mouse::Left)
        {

          Vector2i positionSourisTemp = Mouse::getPosition(fenetre); // renvoie un vecteur position d'entier
          Vector2f positionSouris = static_cast<Vector2f>(positionSourisTemp); //convertis en vecteur position de float

          if (limiteBoutonJouer.contains(positionSouris))
          {
            NomJoueur pop;
            string nomTemp = pop.run();
            recordGlobal.insert(std::make_pair(nomTemp, 0));
          }
          else if (limiteBoutonRecord.contains(positionSouris))
          {
            Record rec(recordGlobal);
            rec.run();
          }
          else{}
        }
      }
      else{}
    }
  }
}
