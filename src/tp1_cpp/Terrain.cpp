#include "Terrain.hpp"
#include "Arbre.hpp"
#include "Fleur.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>

Terrain::Terrain() {
}

std::unique_ptr<Vegetal> Terrain::creerVegetal(const std::string& ligne) {
    std::istringstream iss(ligne);
    std::string type;
    iss >> type;
    
    if (type == "Arbre") {
        return std::make_unique<Arbre>();
    } 
    else if (type == "Fleur") {
        float tailleMax;
        if (!(iss >> tailleMax)) {
            throw std::invalid_argument("Fleur nécessite un paramètre tailleMax");
        }
        return std::make_unique<Fleur>(tailleMax);
    }
    else {
        throw std::invalid_argument("Type de végétal inconnu : " + type);
    }
}

void Terrain::chargerDepuisFichier(const std::string& nomFichier) {
    std::ifstream fichier(nomFichier);
    if (!fichier.is_open()) {
        throw std::runtime_error("Impossible d'ouvrir le fichier : " + nomFichier);
    }
    
    std::string ligne;
    while (std::getline(fichier, ligne)) {
        // Ignore les lignes vides
        if (ligne.empty()) {
            continue;
        }
        
        try {
            mJardin.push_back(creerVegetal(ligne));
        } catch (const std::exception& e) {
            // Log l'erreur mais continue le chargement
            // Vous pouvez adapter selon vos besoins
        }
    }
}

void Terrain::croissanceJardin() {
    for (auto& vegetal : mJardin) {
        vegetal->croissance();
    }
}