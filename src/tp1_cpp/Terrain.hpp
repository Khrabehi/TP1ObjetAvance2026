
#pragma once

#include "Vegetal.hpp"

#include <memory>
#include <vector>

class ICroissance;

class Terrain
{
	public:
		void ajoutVegetal(std::unique_ptr<Vegetal> vegetal);

		void croissance();

		void setStrategieCroissance(ICroissance* croissance);

		void afficher();

	private:
		std::vector<std::unique_ptr<Vegetal>> mVegetals;
};

void chargerFichier(Terrain& terrain, const std::string& path);
