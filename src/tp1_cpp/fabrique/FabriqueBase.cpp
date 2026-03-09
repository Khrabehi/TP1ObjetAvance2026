
#include "FabriqueBase.hpp"

#include "tp1_cpp/Arbre.hpp"
#include "tp1_cpp/Fleur.hpp"

#include <memory>
#include <optional>
#include <sstream>
#include <string>

static std::unique_ptr<Vegetal> creerArbre()
{
	return std::make_unique<Arbre>();
}

static std::unique_ptr<Vegetal> creerFleur(double tailleMax)
{
	return std::make_unique<Fleur>(tailleMax);
}

std::optional<std::unique_ptr<Vegetal>>
	FabriqueBase::creerVegetal(const std::string& donnees)
{
	std::istringstream iss(donnees);
	std::string type;
	iss >> type;
	if (type == "Arbre")
	{
		return creerArbre();
	}
	else if (type == "Fleur")
	{
		double taille;
		iss >> taille;
		if (taille > 0)
		{
			return creerFleur(taille);
		}
		return nullptr;
	}
	return std::nullopt;
}
