
#include "Vegetal.hpp"
Vegetal::Vegetal() 
  : mTaille(0.0)
{}

float Vegetal::getTaille() const
{
  return mTaille;
}

void Vegetal::setTaille(float t)
{
  mTaille = t;
}