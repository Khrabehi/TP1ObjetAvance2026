
#pragma once
#include "Vegetal.hpp"

class Fleur : public Vegetal
{
public: 
  Fleur(float tailleMax);
  void croissance() override;
private:
  float tailleMax;
};