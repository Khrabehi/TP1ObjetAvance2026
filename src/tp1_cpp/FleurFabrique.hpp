#pragma once

#include "VegetalBaseFabrique.hpp"
#include "Fleur.hpp"

class FleurFabrique : public VegetalBaseFabrique {
protected:
    std::vector<std::string> getTypesSupportes() const override {
        return {
            "Fleur",
        };
    }
    
    std::unique_ptr<Vegetal> creerVegetal(const std::string& type, std::istringstream& iss) const override {
        if (type == "Fleur") {
            float tailleMax;
            if (iss >> tailleMax) {
                return std::make_unique<Fleur>(tailleMax);
            }
            return nullptr;
        }
        
        return nullptr;
    }
};