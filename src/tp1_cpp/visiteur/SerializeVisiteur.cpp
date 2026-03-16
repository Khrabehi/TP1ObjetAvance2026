#include "./SerializeVisiteur.hpp"

#include "../Arbre.hpp"
#include "../Fleur.hpp"
#include "../adapter/ChampignonAdapter.hpp"

void SerializeVisiteur::visit(Arbre& arbre)
{
    serializedData = "Arbre:" + std::to_string(arbre.getTaille());
}

void SerializeVisiteur::visit(Fleur& fleur)
{
    serializedData = "Fleur : " + std::to_string(fleur.getTaille());
}

void SerializeVisiteur::visit(ChampignonAdapter& champignon)
{
    serializedData = "Champignon : " + std::to_string(champignon.getTaille());
}

std::string SerializeVisiteur::getSerializedData() const
{
    return serializedData;
}