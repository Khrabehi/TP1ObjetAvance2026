
#pragma once

#include "Vegetal.hpp"

class Fleur : public Vegetal
{
	public:
		Fleur(double tailleMax);

		void croissance() override;
		std::string getType() const override;

	private:
		double mTailleMax;
};
