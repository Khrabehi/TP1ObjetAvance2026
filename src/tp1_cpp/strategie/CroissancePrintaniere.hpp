
#pragma once

#include "ICroissance.hpp"

class CroissancePrintaniere : public ICroissance
{
	public:
		double nouvelleTaille(double taille) override;
};
