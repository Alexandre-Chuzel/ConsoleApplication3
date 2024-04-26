#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <memory>
#include <algorithm>
#include "CSommet.h"
#include "CArc.h"
#include"CChargerfichier.h"

using namespace std;
struct compare;

template <class CSommet, class CArc>
class CGraphOrient {
private:
    vector<shared_ptr<CSommet>> vsGROSommetsDuGraphe;
    vector<shared_ptr<CArc>> vaGROArcsDuGraphe;

public:
    vector<shared_ptr<CSommet>> GetSommets() {
        return vsGROSommetsDuGraphe;
    }
    CGraphOrient();
    CGraphOrient(vector<shared_ptr<CSommet>> vsSommets, vector<shared_ptr<CArc>> vaArcs);
    ~CGraphOrient();
    void GROSupprimerSommet(string sDelsommet);
    void GROAjouterSommet(string sNumSommet);
    void GROSupprimerArc(string sDelarcdeb, string sDelarcfin);
    void GROAjouterArc(string sDebutArcStr, string sFinArcStr);
    void GROAfficherGraphe() const;
    void GROAfficherGraphe2() const;
    void GROAfficherGraphe4() const;
    void GROAfficherGraphe5() const;
    bool GROIsGrapheAffiches(vector<string> vsArcsDuGrapheAffiches, string sSommetActuel) const;
    CGraphOrient GROInverserGraphe();
    void GROChargerDepuisFichier(const string& sNomFichier);
    void GROModifierArc(const string& debutArc, const string& finArc, const string& newDebutArc, const string& newFinArc);
    void GROModifierSommet(const string& ancienNumero, const string& nouveauNumero);
};
#include "CGraphOrient.cpp"