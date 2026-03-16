#pragma once 


#include <string>
#include "./IVisiteur.hpp"

class SerializeVisiteur : public IVisiteur
{
public:
    void visit(Arbre& arbre) override;
    void visit(Fleur& fleur) override;
    void visit(ChampignonAdapter& champignon) override;
    std::string getSerializedData() const;
private:
    std::string serializedData;
};