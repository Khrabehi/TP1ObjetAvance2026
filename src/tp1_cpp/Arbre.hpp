
#pragma once

#include <memory>
#include "CroissanceStrategy.hpp"
#include "Vegetal.hpp"

class Arbre : public Vegetal 
{
public:
  Arbre();
  void setStrategieCroissance(std::unique_ptr<CroissanceStrategy> strategie);
  void croissance() override;
private:
  std::unique_ptr<CroissanceStrategy> mStrategie;
};