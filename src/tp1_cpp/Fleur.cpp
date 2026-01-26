
#include "Fleur.hpp"

Fleur::Fleur(float tailleMax): mTailleMax(tailleMax) {}

void Fleur::croissance() {
    float currentTaille = getTaille();
    if (currentTaille + 0.1f <= mTailleMax) {
        setTaille(currentTaille + 0.1f);
    } else {
        setTaille(mTailleMax);
    }
}