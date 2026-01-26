
#include "Arbre.hpp"

void Arbre::croissance() {
    float currentTaille = getTaille();
    setTaille(currentTaille + 1.0f);
}