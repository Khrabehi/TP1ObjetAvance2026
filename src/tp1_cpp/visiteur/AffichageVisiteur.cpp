#include "./AffichageVisiteur.hpp"

#include "../Arbre.hpp"
#include "../Fleur.hpp"
#include "../adapter/ChampignonAdapter.hpp"

void AffichageVisiteur::visit(Arbre& arbre)
{
    typeAffiche = "Ceci est un arbre de taille " + std::to_string(arbre.getTaille());
}

void AffichageVisiteur::visit(Fleur& fleur)
{
    typeAffiche = "Ceci est une fleur";
}

void AffichageVisiteur::visit(ChampignonAdapter& champignon)
{
    typeAffiche = "Ceci est un champignon";
}

std::string AffichageVisiteur::getTypeAffiche() const
{
    return typeAffiche;
}
