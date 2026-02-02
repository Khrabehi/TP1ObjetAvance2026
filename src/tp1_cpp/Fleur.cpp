
#include "Fleur.hpp"

Fleur::Fleur(float tailleMax)
  : tailleMax(tailleMax)
{}

void Fleur::croissance()
{
  if (getTaille() + 0.1 > tailleMax) 
    setTaille(tailleMax);
  else
    setTaille(getTaille() + 0.1);
}