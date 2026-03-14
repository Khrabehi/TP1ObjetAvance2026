#pragma once 

class Arbre;
class Fleur;
class ChampignonAdapter;

class IVisiteur {
public:
    virtual void visit(Arbre& arbre) = 0;
    virtual void visit(Fleur& fleur) = 0;
    virtual void visit(ChampignonAdapter& champignon) = 0;
};