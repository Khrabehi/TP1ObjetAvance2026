#include "../Vegetal.hpp"
#include "../Champignon.hpp"
#include <memory>

class ChampignonAdapter : public Vegetal {
private: 
    std::unique_ptr<Champignon> champignon;

public: 
    ChampignonAdapter(std::unique_ptr<Champignon> vraiChampi);
    ~ChampignonAdapter();

    double getTaille() const;

    void croissance(); 
    std::string getType() const;

protected:
    void setType(double taille);

};