#include "NomJoueur.hh"
#include "Intro.hh"
#include "Scene1.hh"
#include "Scene2.hh"
#include "Scene3.hh"
#include "Scene6.hh"
#include "JeuVague.hh"
#include "JeuLabyrinthe.hh"
#include "JeuBrouillard.hh"


using namespace sf;
using namespace std;

NomJoueur::NomJoueur():
fenetre(VideoMode(LONGUEUR_NOMJOUEUR,LARGEUR_NOMJOUEUR,32), "Nom du Joueur", Style::Close),
nomJoueur("")
{
  if(!police.loadFromFile("fonts/Arial.ttf"))
  {
    cout << "Erreur durant le chargement de la police" << endl;
  }
  else if (!boutonValider_t.loadFromFile("images/boutonValider.png"))
  {
    cout << "Erreur durant le chargement de l'image du bouton Valider'" << endl;
  }
  else
  {

    /* Création du texte de la question */

    texte_Question.setString("Veuillez entrer votre nom de Joueur : ");
    texte_Question.setFont(police);
    texte_Question.setCharacterSize(TAILLE_POLICE_NOMJOUEUR);
    texte_Question.setFillColor(Color(0,0,0,255));
    texte_Question.setStyle(Text::Bold);

    /* Initialisation du texte pour le nom du Joueur */

    texte_NomJoueur.setFont(police);
    texte_NomJoueur.setCharacterSize(TAILLE_POLICE_NOMJOUEUR);
    texte_NomJoueur.setFillColor(Color(0,0,0,255));
    texte_NomJoueur.setStyle(Text::Bold);

    /* Initialisation da la texture du bouton Valider */

    boutonValider_s.setTexture(boutonValider_t);

  }
}

NomJoueur::NomJoueur(std::string nom):
fenetre(VideoMode(LONGUEUR_NOMJOUEUR,LARGEUR_NOMJOUEUR,32), "Nom du Joueur", Style::Close),
nomJoueur(nom)
{
  if(!police.loadFromFile("fonts/Arial.ttf"))
  {
    cout << "Erreur durant le chargement de la police" << endl;
  }
  else if (!boutonValider_t.loadFromFile("images/boutonValider.png"))
  {
    cout << "Erreur durant le chargement de l'image du bouton Valider'" << endl;
  }
  else
  {

    /* Création du texte de la question */

    texte_Question.setString("Veuillez entrer votre nom de Joueur : ");
    texte_Question.setFont(police);
    texte_Question.setCharacterSize(TAILLE_POLICE_NOMJOUEUR);
    texte_Question.setFillColor(Color(0,0,0,255));
    texte_Question.setStyle(Text::Bold);

    /* Initialisation du texte pour le nom du Joueur */

    texte_NomJoueur.setFont(police);
    texte_NomJoueur.setCharacterSize(TAILLE_POLICE_NOMJOUEUR);
    texte_NomJoueur.setFillColor(Color(0,0,0,255));
    texte_NomJoueur.setStyle(Text::Bold);

    /* Initialisation da la texture du bouton Valider */

    boutonValider_s.setTexture(boutonValider_t);

  }
}

string NomJoueur::run()
{

  fenetre.clear(Color(255,255,255,255));

  /* Positionnement et Ajout du texte de la question à la fenetre */

  texte_Question.setPosition(30, LARGEUR_NOMJOUEUR/3);
  fenetre.draw(texte_Question);


  /* Création du bouton Valider */

  boutonValider_s.setPosition((LONGUEUR_NOMJOUEUR/3)+20, 4*LARGEUR_NOMJOUEUR/6);

  RectangleShape contourBoutonValider;
  contourBoutonValider.setPosition(boutonValider_s.getPosition());
  contourBoutonValider.setSize(Vector2f(135,45));
  contourBoutonValider.setOutlineThickness(2);
  contourBoutonValider.setOutlineColor(Color(0, 0, 0, 255));

  fenetre.draw(contourBoutonValider);
  fenetre.draw(boutonValider_s);

  FloatRect limiteBoutonValider = boutonValider_s.getGlobalBounds();

  /* Affichage de la fenetre */

  fenetre.display();

  /* Boucle de gestion d'événement */

  while(fenetre.isOpen())
  {
    Event event;

    while(fenetre.pollEvent(event))
    {
      if (event.type == Event::Closed)
      {
        fenetre.close();
      }
      else if (event.type == Event::TextEntered)
      {
        if (event.text.unicode == 8) // Correspond à l'unicode de suppr
        {
          /* On supprime le dernier caractere de notre string */
          nomJoueur.erase(nomJoueur.size() - 1);
        }
        else if (event.text.unicode == 10) // Correspond à l'unicode de entrer
        {
          /* Mettre ici le run() de la Fenetre de Jeu ! */
          fenetre.close();
        }
        else
        {
          /* On ajoute le caractere tappé à notre string */
          nomJoueur += static_cast<char> (event.text.unicode);
        }

        /* On affiche le nom du Joueur en "temps réel" */

        texte_NomJoueur.setString(nomJoueur);

        fenetre.clear(Color(255,255,255,255));

        texte_Question.setPosition(30, LARGEUR_NOMJOUEUR/3);
        fenetre.draw(texte_Question);

        texte_NomJoueur.setPosition(400, LARGEUR_NOMJOUEUR/3);
        fenetre.draw(texte_NomJoueur);

        fenetre.draw(contourBoutonValider);
        fenetre.draw(boutonValider_s);

        fenetre.display();

      }
      else if(event.type == Event::MouseButtonPressed)
      {
        if (event.mouseButton.button == Mouse::Left)
        {
          /* Renvoie un vecteur position d'entier */
          Vector2i positionSourisTemp = Mouse::getPosition(fenetre);

          /* Convertis en vecteur position de float */
          Vector2f positionSouris = static_cast<Vector2f>(positionSourisTemp);

          if (limiteBoutonValider.contains(positionSouris))
          {
            /* Mettre ici le run() de la Fenetre de Jeu ! */

            Scene6 scene6;
            scene6.run();

            // Intro intro1;
            // intro1.run();
            //
            // JeuVague app1(nomJoueur, 1);
            // app1.run();
            //
            // Scene1 scene1;
            // scene1.run();
            //
            // JeuBrouillard app2(nomJoueur, 1);
            // app2.run();
            //
            // Scene2 scene2;
            // scene2.run();
            //
            // JeuLabyrinthe app3(nomJoueur, NB_FUMEE, NB_CHRONO);
            // app3.run();

            fenetre.close();

            return nomJoueur;

          }
        }
      }
      else if (event.type == Event::KeyPressed)
      {
        if (event.key.code == sf::Keyboard::Return)
        {
          fenetre.close();
        }
      }
      else{}
    }
  }
  return nomJoueur;
}
