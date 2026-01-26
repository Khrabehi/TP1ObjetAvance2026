
#include "Fleur.hpp"

Fleur::Fleur(float tailleMax): mTailleMax(tailleMax) {}

void Fleur::croissance() {
    if (getTaille() + 0.1f <= mTailleMax) {
        setTaille(getTaille() + 0.1f);
    } else {
        setTaille(mTailleMax);
    }
}