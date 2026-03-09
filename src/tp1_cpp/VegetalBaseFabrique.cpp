#include "VegetalBaseFabrique.hpp"
#include <algorithm>

std::unique_ptr<Vegetal> VegetalBaseFabrique::creeVegetal(const std::string& ligne) const {
    std::istringstream iss(ligne);
    std::string type;
    iss >> type;
    
    // Vérifie si le type est supporté par cette fabrique
    auto typesSupportes = getTypesSupportes();
    auto it = std::find(typesSupportes.begin(), typesSupportes.end(), type);
    
    if (it != typesSupportes.end()) {
        return creerVegetal(type, iss);
    }
    
    return nullptr;
}