#pragma once

#include "VegetalBaseFabrique.hpp"
#include "Arbre.hpp"

class ArbreFabrique : public VegetalBaseFabrique {
protected:
    std::vector<std::string> getTypesSupportes() const override {
        return {
            "Arbre",
        };
    }
    
    std::unique_ptr<Vegetal> creerVegetal(const std::string& type, std::istringstream& iss) const override {
        if (type == "Arbre") {
            return std::make_unique<Arbre>();
        }
        return nullptr;
    }
};