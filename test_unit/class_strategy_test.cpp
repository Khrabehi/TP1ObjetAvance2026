#include <gtest/gtest.h>

#include <tp1_cpp/Arbre.hpp>
#include <tp1_cpp/CroissanceStrategy.hpp>

#include <memory>


// Design Pattern Strategy
// Le pattern strategy permet de définir une famille d'algorithmes,
// de les encapsuler et de les rendre interchangeables.
// Ici, les différentes stratégies de croissance encapsulent les règles
// de croissance pour différentes conditions (dormance, printemps, été, sécheresse).


// Test la stratégie de croissance constante par défaut
TEST(StrategyTest, CroissanceConstante) {
    CroissanceConstante strategie(1.0f);
    EXPECT_NEAR(strategie.increment(), 1.0f, 0.00001f);
}

TEST(StrategyTest, CroissanceConstanteValeurPersonnalisee) {
    CroissanceConstante strategie(0.5f);
    EXPECT_NEAR(strategie.increment(), 0.5f, 0.00001f);
}


// Test la stratégie de dormance (pas de croissance)
TEST(StrategyTest, CroissanceDormance) {
    CroissanceDormance strategie;
    EXPECT_NEAR(strategie.increment(), 0.0f, 0.00001f);
}


// Test la stratégie printanière (croissance rapide)
TEST(StrategyTest, CroissancePrintaniere) {
    CroissancePrintaniere strategie;
    EXPECT_NEAR(strategie.increment(), 2.0f, 0.00001f);
}


// Test la stratégie estivale (croissance modérée)
TEST(StrategyTest, CroissanceEstivale) {
    CroissanceEstivale strategie;
    EXPECT_NEAR(strategie.increment(), 1.5f, 0.00001f);
}


// Test la stratégie sécheresse (pas de croissance)
TEST(StrategyTest, CroissanceSecheresse) {
    CroissanceSecheresse strategie;
    EXPECT_NEAR(strategie.increment(), 0.0f, 0.00001f);
}


// Test l'arbre avec stratégie par défaut
TEST(StrategyTest, ArbreAvecStrategieParDefaut) {
    Arbre monArbre;
    EXPECT_NEAR(monArbre.getTaille(), 0.0f, 0.00001f);
    monArbre.croissance();
    EXPECT_NEAR(monArbre.getTaille(), 1.0f, 0.00001f);
    monArbre.croissance();
    EXPECT_NEAR(monArbre.getTaille(), 2.0f, 0.00001f);
}


// Test l'arbre avec stratégie de dormance
TEST(StrategyTest, ArbreAvecDormance) {
    Arbre monArbre;
    monArbre.setStrategieCroissance(std::make_unique<CroissanceDormance>());
    EXPECT_NEAR(monArbre.getTaille(), 0.0f, 0.00001f);
    monArbre.croissance();
    EXPECT_NEAR(monArbre.getTaille(), 0.0f, 0.00001f);
    monArbre.croissance();
    EXPECT_NEAR(monArbre.getTaille(), 0.0f, 0.00001f);
}


// Test l'arbre avec stratégie printanière
TEST(StrategyTest, ArbreAvecCroissancePrintaniere) {
    Arbre monArbre;
    monArbre.setStrategieCroissance(std::make_unique<CroissancePrintaniere>());
    EXPECT_NEAR(monArbre.getTaille(), 0.0f, 0.00001f);
    monArbre.croissance();
    EXPECT_NEAR(monArbre.getTaille(), 2.0f, 0.00001f);
    monArbre.croissance();
    EXPECT_NEAR(monArbre.getTaille(), 4.0f, 0.00001f);
}


// Test l'arbre avec stratégie estivale
TEST(StrategyTest, ArbreAvecCroissanceEstivale) {
    Arbre monArbre;
    monArbre.setStrategieCroissance(std::make_unique<CroissanceEstivale>());
    EXPECT_NEAR(monArbre.getTaille(), 0.0f, 0.00001f);
    monArbre.croissance();
    EXPECT_NEAR(monArbre.getTaille(), 1.5f, 0.00001f);
    monArbre.croissance();
    EXPECT_NEAR(monArbre.getTaille(), 3.0f, 0.00001f);
}


// Test l'arbre avec stratégie sécheresse
TEST(StrategyTest, ArbreAvecSecheresse) {
    Arbre monArbre;
    monArbre.setStrategieCroissance(std::make_unique<CroissanceSecheresse>());
    EXPECT_NEAR(monArbre.getTaille(), 0.0f, 0.00001f);
    monArbre.croissance();
    EXPECT_NEAR(monArbre.getTaille(), 0.0f, 0.00001f);
    monArbre.croissance();
    EXPECT_NEAR(monArbre.getTaille(), 0.0f, 0.00001f);
}


// Test le changement de stratégie en cours de croissance
TEST(StrategyTest, ChangementDeStrategieEnCours) {
    Arbre monArbre;
    // Commence avec croissance constante
    EXPECT_NEAR(monArbre.getTaille(), 0.0f, 0.00001f);
    monArbre.croissance();
    EXPECT_NEAR(monArbre.getTaille(), 1.0f, 0.00001f);
    
    // Bascule vers dormance
    monArbre.setStrategieCroissance(std::make_unique<CroissanceDormance>());
    monArbre.croissance();
    EXPECT_NEAR(monArbre.getTaille(), 1.0f, 0.00001f);
    monArbre.croissance();
    EXPECT_NEAR(monArbre.getTaille(), 1.0f, 0.00001f);
    
    // Bascule vers printanière
    monArbre.setStrategieCroissance(std::make_unique<CroissancePrintaniere>());
    monArbre.croissance();
    EXPECT_NEAR(monArbre.getTaille(), 3.0f, 0.00001f);
}


// Test le changement cyclique de stratégies (simulation des saisons)
TEST(StrategyTest, CycleDesSeasons) {
    Arbre monArbre;
    // Printemps
    monArbre.setStrategieCroissance(std::make_unique<CroissancePrintaniere>());
    monArbre.croissance();
    monArbre.croissance();
    EXPECT_NEAR(monArbre.getTaille(), 4.0f, 0.00001f);
    
    // Été
    monArbre.setStrategieCroissance(std::make_unique<CroissanceEstivale>());
    monArbre.croissance();
    monArbre.croissance();
    EXPECT_NEAR(monArbre.getTaille(), 7.0f, 0.00001f);
    
    // Automne (dormance)
    monArbre.setStrategieCroissance(std::make_unique<CroissanceDormance>());
    monArbre.croissance();
    monArbre.croissance();
    EXPECT_NEAR(monArbre.getTaille(), 7.0f, 0.00001f);
    
    // Hiver (sécheresse)
    monArbre.setStrategieCroissance(std::make_unique<CroissanceSecheresse>());
    monArbre.croissance();
    monArbre.croissance();
    EXPECT_NEAR(monArbre.getTaille(), 7.0f, 0.00001f);
}


// Test avec stratégie personnalisée
TEST(StrategyTest, ArbreAvecStrategiePersonnalisee) {
    Arbre monArbre;
    monArbre.setStrategieCroissance(std::make_unique<CroissanceConstante>(0.5f));
    EXPECT_NEAR(monArbre.getTaille(), 0.0f, 0.00001f);
    monArbre.croissance();
    EXPECT_NEAR(monArbre.getTaille(), 0.5f, 0.00001f);
    monArbre.croissance();
    EXPECT_NEAR(monArbre.getTaille(), 1.0f, 0.00001f);
}


// Test interchangeabilité des stratégies
TEST(StrategyTest, InterchangeabiliteDesStrategies) {
    Arbre monArbre1;
    Arbre monArbre2;
    
    monArbre1.setStrategieCroissance(std::make_unique<CroissancePrintaniere>());
    monArbre2.setStrategieCroissance(std::make_unique<CroissanceEstivale>());
    
    // Les deux arbres croissent indépendamment
    monArbre1.croissance();
    EXPECT_NEAR(monArbre1.getTaille(), 2.0f, 0.00001f);
    
    monArbre2.croissance();
    EXPECT_NEAR(monArbre2.getTaille(), 1.5f, 0.00001f);
    
    // Inversion des stratégies
    auto strategie1 = std::make_unique<CroissancePrintaniere>();
    auto strategie2 = std::make_unique<CroissanceEstivale>();
    
    monArbre1.setStrategieCroissance(std::move(strategie2));
    monArbre2.setStrategieCroissance(std::move(strategie1));
    
    monArbre1.croissance();
    EXPECT_NEAR(monArbre1.getTaille(), 3.5f, 0.00001f);
    
    monArbre2.croissance();
    EXPECT_NEAR(monArbre2.getTaille(), 3.5f, 0.00001f);
}
