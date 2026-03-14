
#pragma once

#include "Vegetal.hpp"
#include "strategie/IStratCroissance.hpp"
#include <string>
#include "strategie/ICroissance.hpp"
#include "visiteur/IVisiteur.hpp"

class Arbre : public Vegetal, public IStratCroissance
{
	public:
		void croissance() override;
		std::string getType() const override;

		void setStrategieCroissance(ICroissance* croissance) override;
		void accept(IVisiteur* visiteur) override;

	private:
		ICroissance* mStrategieCroissance = nullptr;
};
