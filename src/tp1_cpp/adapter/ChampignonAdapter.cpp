#include "ChampignonAdapter.hpp"

#include "../visiteur/IVisiteur.hpp"

ChampignonAdapter::ChampignonAdapter(std::unique_ptr<Champignon> vraiChampi)
    : champignon(std::move(vraiChampi))
{

}

ChampignonAdapter::~ChampignonAdapter() = default;

double ChampignonAdapter::getTaille() const {
    return champignon->getHauteurChampignon();
}

void ChampignonAdapter::croissance() {
    champignon->pousse(Champignon::Meteo::Soleil);
    setTaille(champignon->getHauteurChampignon());
}

std::string ChampignonAdapter::getType() const {
    return "Champignon";
}

void ChampignonAdapter::setType(double taille) {
    setTaille(taille);
}

void ChampignonAdapter::accept(IVisiteur* visiteur)
{
    visiteur->visit(*this);
}