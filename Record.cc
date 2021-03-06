#include "Record.hh"

using namespace sf;
using namespace std;

Record::Record():fenetre(VideoMode(LONGUEUR_RECORD,LARGEUR_RECORD,32), "Records", Style::Close)
{
  if(!police.loadFromFile("fonts/Arial.ttf"))
  {
      cout <<"Erreur durant le chargement de la police"<< endl;
  }
  else
  {
    textePremier.setString("1er : ");
    textePremier.setFont(police);
    textePremier.setCharacterSize(TAILLE_POLICE_RECORD);
    textePremier.setFillColor(Color(0,0,0,255));
    textePremier.setStyle(Text::Bold);

    texteDeuxieme.setString("2eme : ");
    texteDeuxieme.setFont(police);
    texteDeuxieme.setCharacterSize(TAILLE_POLICE_RECORD);
    texteDeuxieme.setFillColor(Color(0,0,0,255));
    texteDeuxieme.setStyle(Text::Bold);

    texteTroisieme.setString("3eme : ");
    texteTroisieme.setFont(police);
    texteTroisieme.setCharacterSize(TAILLE_POLICE_RECORD);
    texteTroisieme.setFillColor(Color(0,0,0,255));
    texteTroisieme.setStyle(Text::Bold);

  }
}

Record::Record(std::multimap<int, std::string, std::greater<int>> rec):
fenetre(VideoMode(LONGUEUR_RECORD,LARGEUR_RECORD,32), "Records", Style::Close),
listeRecords(rec)
{

  if(!police.loadFromFile("fonts/Arial.ttf"))
  {
      cout <<"Erreur durant le chargement de la police"<< endl;
  }
  else
  {
    textePremier.setString("1er : ");
    textePremier.setFont(police);
    textePremier.setCharacterSize(TAILLE_POLICE_RECORD);
    textePremier.setFillColor(Color(0,0,0,255));
    textePremier.setStyle(Text::Bold);

    texteDeuxieme.setString("2eme : ");
    texteDeuxieme.setFont(police);
    texteDeuxieme.setCharacterSize(TAILLE_POLICE_RECORD);
    texteDeuxieme.setFillColor(Color(0,0,0,255));
    texteDeuxieme.setStyle(Text::Bold);

    texteTroisieme.setString("3eme : ");
    texteTroisieme.setFont(police);
    texteTroisieme.setCharacterSize(TAILLE_POLICE_RECORD);
    texteTroisieme.setFillColor(Color(0,0,0,255));
    texteTroisieme.setStyle(Text::Bold);

  }
}

void Record::run()
{
  fenetre.clear(Color(255,255,255,255));

  // std::sort(listeRecords.begin(), listeRecords.end());

  multimap<int, std::string, std::greater<int>>::iterator it;
  int pos_y = LARGEUR_RECORD/4;

  for (it = listeRecords.begin(); it != listeRecords.end(); ++it)
  {
    nomTemps += it->second + "       " + to_string(it->first) + " extincteur(s)";
    Text rec(nomTemps,police,TAILLE_POLICE_RECORD);
    rec.setFillColor(Color(0,0,0,255));
    rec.setStyle(Text::Bold);
    rec.setPosition(200,pos_y);
    pos_y += LARGEUR_RECORD/4;
    fenetre.draw(rec);
    nomTemps = "";
  }

  textePremier.setPosition(50, LARGEUR_RECORD/4);
  fenetre.draw(textePremier);

  texteDeuxieme.setPosition(50, LARGEUR_RECORD/2);
  fenetre.draw(texteDeuxieme);

  texteTroisieme.setPosition(50, 3*LARGEUR_RECORD/4);
  fenetre.draw(texteTroisieme);

  fenetre.display();

  while(fenetre.isOpen())
  {
    Event event;

    while(fenetre.pollEvent(event))
    {
      if (event.type == Event::Closed)
      {
        fenetre.close();
      }
    }
  }
}
