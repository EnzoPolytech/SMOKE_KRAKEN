#include <iostream>
#include <SFML/Graphics.hpp>
#include "Menu.hh"
// #include "LabyrintheNiv1.hh"
// #include "JeuVague.hh"
// #include "JeuBrouillard.hh"
// #include "Intro.hh"

using namespace sf;
using namespace std;

int main(int argc, char const *argv[])
{

  srand(time(NULL)); // initialisation de rand

	Menu menu;
	menu.run();

  // LabyrintheNiv1 test("enzo");
  // test.run();

  // JeuBrouillard test("enzo", 1);
  // test.run();

  // JeuVague app("enzo", 1);
  // app.run();

  // Intro test;
  // test.run();

	return 0;

}

