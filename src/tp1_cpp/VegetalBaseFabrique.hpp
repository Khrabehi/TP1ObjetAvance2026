#pragma once

#include <tp1_cpp/IFabrique.hpp>
#include <memory>
#include <string>
#include <sstream>
#include <vector>

class VegetalBaseFabrique : public IFabrique {
public:
    virtual ~VegetalBaseFabrique() = default;
    
    std::unique_ptr<Vegetal> creeVegetal(const std::string& ligne) const override;
    
protected:
    virtual std::vector<std::string> getTypesSupportes() const = 0;
    virtual std::unique_ptr<Vegetal> creerVegetal(const std::string& type, std::istringstream& iss) const = 0;
};