
#pragma once

#include "ICroissance.hpp"

class CroissanceEstivale : public ICroissance
{
	public:
		double nouvelleTaille(double taille) override;
};
