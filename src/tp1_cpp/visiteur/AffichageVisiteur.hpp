#pragma once 

#include <string>
#include "./IVisiteur.hpp"

class AffichageVisiteur : public IVisiteur
{
private:
    std::string typeAffiche;
public:
    void visit(Arbre& arbre) override;
    void visit(Fleur& fleur) override;
    void visit(ChampignonAdapter& champignon) override;
    std::string getTypeAffiche() const;
};