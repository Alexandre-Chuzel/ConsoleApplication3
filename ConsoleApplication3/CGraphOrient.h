#pragma once
/*******************************************************************
* CLASSE : Classe pour la gestion du graphe orienté
* ******************************************************************
* ROLE : Interface de la classe CGraphOriente.
* Cette classe permet de créer, modifier, ajouter, supprimer et afficher
* différents éléments/objets liés au graphe orienté.
* ******************************************************************
* VERSION : 1.0
* AUTEUR :Aissatou CISS - Alexandre CHUZEL-MARMOT
* DATE : 28/04/2024
* ******************************************************************
* INCLUSIONS EXTERNES :
*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <memory>
#include <algorithm>
#include "CSommet.h"
#include "CArc.h"

using namespace std;
struct compare;

template <class CSommet, class CArc>
class CGraphOrient {
    //ATTRIBUTS :
private:
    vector<shared_ptr<CSommet>> vsGROSommetsDuGraphe;
    vector<shared_ptr<CArc>> vaGROArcsDuGraphe;
    //CONSTRUCTEURS ET MÉTHODES
public:
    vector<shared_ptr<CSommet>>& GetSommets() {
        return vsGROSommetsDuGraphe;
    }
    vector<shared_ptr<CArc>>& GetArcs() {
        return vaGROArcsDuGraphe;
    }
    void SetSommets(vector<shared_ptr<CSommet>>& newliste) {
         vsGROSommetsDuGraphe=newliste;
    }
    void SetArcs(vector<shared_ptr<CArc>>& newliste) {
         vaGROArcsDuGraphe=newliste;
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
    void GROAfficherGraphe5() const;
    bool GROIsGrapheAffiches(vector<string> vsArcsDuGrapheAffiches, string sSommetActuel) const;
    CGraphOrient GROInverserGraphe();
    void GROModifierArc(const string& sDebutArc, const string& sFinArc, const string& sNewDebutArc, const string& sNewFinArc);
    void GROModifierSommet(const string& sAncienNumero, const string& sNouveauNumero);
};
