
#include "Fleur.hpp"

#include <algorithm>
#include <string>

Fleur::Fleur(double tailleMax)
	: mTailleMax(tailleMax)
{
}

void Fleur::croissance()
{
	setTaille(std::min(mTailleMax, getTaille() + 0.1));
}

std::string Fleur::getType() const
{
	return "Fleur";
}
