#pragma once

#include <memory>
#include <string>
#include "Vegetal.hpp"

class IFabrique {
public:
    virtual ~IFabrique() = default;
    virtual std::unique_ptr<Vegetal> creeVegetal(const std::string& ligne) const = 0;
};