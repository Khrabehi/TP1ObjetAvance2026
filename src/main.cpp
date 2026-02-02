#include <iostream>
#include <tp1_cpp/Arbre.hpp>


int main(int argc, char* argv[])
{

  Arbre arbre;
  std::unique_ptr<CroissanceDormance> strategieDormance = std::make_unique<CroissanceDormance>();
  std::unique_ptr<CroissancePrintaniere> strategiePrintaniere = std::make_unique<CroissancePrintaniere>();
  std::unique_ptr<CroissanceEstivale> strategieEstivale =  std::make_unique<CroissanceEstivale>();
  std::unique_ptr<CroissanceSecheresse> strategieSecheresse = std::make_unique<CroissanceSecheresse>();
  while (true)
  {
      int choix = 0;
      std::cout << "Choix : 0-Quitter, 1-Pas de changement, 2-Dormance, "
                    "3-CroissancePrintaniere, 4-CroissanceEstivale, 5-Secheresse"
                << std::endl;
      std::cin >> choix;
      switch (choix)
      {
          case 0: break;
          case 1: arbre.croissance(); break;
          case 2:  arbre.setStrategieCroissance(std::move(strategieDormance)); break;
          case 3:  arbre.setStrategieCroissance(std::move(strategiePrintaniere)); break;
          case 4:  arbre.setStrategieCroissance(std::move(strategieEstivale)); break;
          case 5:  arbre.setStrategieCroissance(std::move(strategieSecheresse)); break;
          default: std::cout << "Choix invalide\n"; break;
      }
      if (choix == 0) break;
      arbre.croissance();
      std::cout << "Taille actuelle : " << arbre.getTaille() << '\n';
  }
  return 0;
}
