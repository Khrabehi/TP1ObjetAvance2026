
#pragma once

#include "ICroissance.hpp"

class Secheresse : public ICroissance
{
	public:
		double nouvelleTaille(double taille) override;
};
