
#pragma once

#include "ICroissance.hpp"

class Dormance: public ICroissance
{
	public:
		double nouvelleTaille(double taille) override;
};
