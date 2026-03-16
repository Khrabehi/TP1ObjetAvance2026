#include <gtest/gtest.h>

#include <memory>

#include <tp1_cpp/Arbre.hpp>
#include <tp1_cpp/Champignon.hpp>
#include <tp1_cpp/Fleur.hpp>
#include <tp1_cpp/adapter/ChampignonAdapter.hpp>
#include <tp1_cpp/visiteur/AffichageVisiteur.hpp>
#include <tp1_cpp/visiteur/SerializeVisiteur.hpp>

namespace {

constexpr float TP1_EPSILON = 0.00001f;

} // namespace

TEST(VisiteurTest, Quand_Affichage_Visite_Arbre_Affiche_Type_Arbre_Et_Taille) {
    Arbre arbre;
    arbre.croissance();

    AffichageVisiteur visiteur;
    arbre.accept(&visiteur);

    EXPECT_EQ(visiteur.getTypeAffiche(), "Ceci est un arbre de taille 1.000000");
}

TEST(VisiteurTest, Quand_Affichage_Visite_Fleur_Affiche_Type_Fleur) {
    Fleur fleur(/*tailleMax=*/2.0);

    AffichageVisiteur visiteur;
    fleur.accept(&visiteur);

    EXPECT_EQ(visiteur.getTypeAffiche(), "Ceci est une fleur");
}

TEST(VisiteurTest, Quand_Affichage_Visite_Champignon_Affiche_Type_Champignon) {
    auto vraiChampignon = std::make_unique<Champignon>(0.2f);
    ChampignonAdapter champignon(std::move(vraiChampignon));

    AffichageVisiteur visiteur;
    champignon.accept(&visiteur);

    EXPECT_EQ(visiteur.getTypeAffiche(), "Ceci est un champignon");
}

TEST(VisiteurTest, Quand_Serialize_Visite_Arbre_Serialize_Arbre_Et_Taille) {
    Arbre arbre;
    arbre.croissance();

    SerializeVisiteur visiteur;
    arbre.accept(&visiteur);

    EXPECT_EQ(visiteur.getSerializedData(), "Arbre:1.000000");
}

TEST(VisiteurTest, Quand_Serialize_Visite_Fleur_Serialize_Fleur_Et_Taille) {
    Fleur fleur(/*tailleMax=*/2.0);
    fleur.croissance();
    EXPECT_NEAR(fleur.getTaille(), 0.1, TP1_EPSILON);

    SerializeVisiteur visiteur;
    fleur.accept(&visiteur);

    EXPECT_EQ(visiteur.getSerializedData(), "Fleur : 0.100000");
}

TEST(VisiteurTest, Quand_Serialize_Visite_Champignon_Serialize_Champignon_Et_Taille) {
    auto vraiChampignon = std::make_unique<Champignon>(0.2f);
    ChampignonAdapter champignon(std::move(vraiChampignon));
    champignon.croissance();

    SerializeVisiteur visiteur;
    champignon.accept(&visiteur);

    EXPECT_EQ(visiteur.getSerializedData(), "Champignon : 0.200000");
}

TEST(VisiteurTest, Quand_On_Passe_Par_Vegetal_Accept_Fait_Bien_Double_Dispatch) {
    Arbre arbre;
    Fleur fleur(/*tailleMax=*/2.0);

    auto vraiChampignon = std::make_unique<Champignon>(0.5f);
    ChampignonAdapter champignon(std::move(vraiChampignon));

    Vegetal* v1 = &arbre;
    Vegetal* v2 = &fleur;
    Vegetal* v3 = &champignon;

    AffichageVisiteur affichage;

    v1->accept(&affichage);
    EXPECT_EQ(affichage.getTypeAffiche(), "Ceci est un arbre de taille 0.000000");

    v2->accept(&affichage);
    EXPECT_EQ(affichage.getTypeAffiche(), "Ceci est une fleur");

    v3->accept(&affichage);
    EXPECT_EQ(affichage.getTypeAffiche(), "Ceci est un champignon");
}
