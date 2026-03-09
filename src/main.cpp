
#include "tp1_cpp/Terrain.hpp"

#include "tp1_cpp/strategie/Dormance.hpp"
#include "tp1_cpp/strategie/CroissancePrintaniere.hpp"
#include "tp1_cpp/strategie/CroissanceEstivale.hpp"
#include "tp1_cpp/strategie/Secheresse.hpp"

#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	Terrain terrain;
	chargerFichier(terrain, "data/init.txt");

	Dormance dormanceStrategie;
	CroissancePrintaniere printaniereStrategie;
	CroissanceEstivale estivaleStrategie;
	Secheresse secheresseStrategie;

	while (true)
	{
	   int choix = 0;
	   std::cout << "Choix : 0-Quitter, 1-Pas de changement, 2-Dormance, 3-CroissancePrintaniere, 4-CroissanceEstivale, 5-Secheresse" << std::endl;
	   std::cin >> choix;
	   switch (choix)
	   {
	 		case 0: break;
	 		case 1: break;
	 		case 2:
				terrain.setStrategieCroissance(&dormanceStrategie);
				break;
	 		case 3:
				terrain.setStrategieCroissance(&printaniereStrategie);
				break;
	 		case 4:
				terrain.setStrategieCroissance(&estivaleStrategie);
				break;
	 		case 5:
				terrain.setStrategieCroissance(&secheresseStrategie);
				break;
	   }
	   if (choix == 0) break; // Quitte la boucle while (true)

	   terrain.croissance();
		 terrain.afficher();
	}

  return 0;
}
