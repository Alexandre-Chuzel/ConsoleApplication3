#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "Graphe.h" // Assurez-vous d'inclure votre classe CGraphOrient.h

using namespace std;

template<class Sommet, class Arc>
class Graphe2 : public Graphe<Sommet, Arc> {
public:
    Graphe2() : Graphe<Sommet, Arc>() {}

    void AjouterArc(string debutArcStr, string finArcStr) {
        this->AjouterSommet(finArcStr);
        this->AjouterSommet(debutArcStr);
        this->AjouterArc(debutArcStr, finArcStr);
    }
};
