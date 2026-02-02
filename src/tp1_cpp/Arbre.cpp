
#include "Arbre.hpp"

Arbre::Arbre() : Vegetal(), mStrategie(std::make_unique<CroissanceConstante>(1.0f)) {}

void Arbre::setStrategieCroissance(std::unique_ptr<CroissanceStrategy> strategie) {
    mStrategie = std::move(strategie);
}

void Arbre::croissance()
{
    const float delta = mStrategie ? mStrategie->increment() : 1.f;
    setTaille(getTaille() + delta);
}