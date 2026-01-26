
#pragma once
#include "Vegetal.hpp"

class Fleur : public Vegetal {
private : 
    float mTailleMax;
public :
    Fleur(float tailleMax);
    void croissance() override;
};