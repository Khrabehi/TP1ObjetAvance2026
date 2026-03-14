
#include "Arbre.hpp"


void Arbre::croissance()
{
	if (mStrategieCroissance)
	{
		setTaille(mStrategieCroissance->nouvelleTaille(getTaille()));
	}
	else
	{
		// Fallback par defaut
		setTaille(getTaille() + 1.);
	}
}

[[deprecated]]
std::string Arbre::getType() const
{
	return "Arbre";
}

void Arbre::setStrategieCroissance(ICroissance* croissance)
{
	mStrategieCroissance = croissance;
}

void Arbre::accept(IVisiteur* visiteur)
{
	visiteur->visit(*this);
}

