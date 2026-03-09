#pragma once 

#include <vector>
#include <memory>
#include <string>
#include <tp1_cpp/Vegetal.hpp>
#include <tp1_cpp/IFabrique.hpp>

class Terrain {
private:
    std::vector<std::unique_ptr<Vegetal>> mJardin;

public:
    Terrain();
    static std::unique_ptr<Vegetal> creerVegetal(const std::string& ligne);
    
    void chargerDepuisFichier(const std::string& nomFichier);
    
    void croissanceJardin();

    void ajouterFactory(std::unique_ptr<IFabrique>);
    
    size_t getNombreVegetaux() const { return mJardin.size(); }
    const Vegetal* getVegetal(size_t index) const { return mJardin[index].get(); }
};