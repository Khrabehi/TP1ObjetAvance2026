
#pragma once

#include "Vegetal.hpp"
#include "strategie/IStratCroissance.hpp"

class ICroissance;

class Arbre : public Vegetal, public IStratCroissance
{
	public:
		void croissance() override;
		std::string getType() const override;

		void setStrategieCroissance(ICroissance* croissance) override;

	private:
		ICroissance* mStrategieCroissance = nullptr;
};
