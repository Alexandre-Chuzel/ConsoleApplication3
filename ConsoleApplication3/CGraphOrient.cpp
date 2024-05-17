#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <memory>
#include <algorithm>
#include "CSommet.h"
#include "CArc.h"
#include "CGraphOrient.h"


using namespace std;

//CONSTRUCTEURS ET MÉTHODES
template <class CSommet, class CArc>
CGraphOrient<CSommet, CArc>::CGraphOrient() {
}

template <class CSommet, class CArc>
CGraphOrient< CSommet,  CArc>::~CGraphOrient() {
}

template <class CSommet, class CArc>
CGraphOrient< CSommet,  CArc>::CGraphOrient(vector<shared_ptr<CSommet>> vsSommets, vector<shared_ptr<CArc>> vaArcs){
    this->vsGROSommetsDuGraphe = std::move(vsSommets);
    this->vaGROArcsDuGraphe = std::move(vaArcs);
}

/****************************************************************
    *GRAAjouterArete
    * ***********************************************************
    * Entrée : string sDelsommet
    * Nécessite : Rien
    * Sortie : Rien
    * Entraine : Supprime un sommet du graphe et supprime 
    * un arc si le sommet faisait parti de celui-ci.
*****************************************************************/
template <class CSommet, class CArc>
void CGraphOrient< CSommet,  CArc>::GROSupprimerSommet(string sDelsommet) {
    auto it = vsGROSommetsDuGraphe.begin();
    while (it != vsGROSommetsDuGraphe.end()) {
        if (sDelsommet == (*it)->GetNumero()) {
            (*it).reset();
            it = vsGROSommetsDuGraphe.erase(it);
        }
        else {
            ++it;
        }
    }

    auto it2 = vaGROArcsDuGraphe.begin();
    while (it2 != vaGROArcsDuGraphe.end()) {
        if (sDelsommet == (*it2)->GetDebut() || sDelsommet == (*it2)->GetFin()) {
            (*it2).reset();
            it2 = vaGROArcsDuGraphe.erase(it2);
        }
        else {
            ++it2;
        }
    }
}

/****************************************************************
    *GROAjouterSommet
    * ***********************************************************
    * Entrée : string sNumSommet
    * Nécessite : Rien
    * Sortie : Rien
    * Entraine : Ajoute un sommet au graphe tout en vérifiant 
    * que celui-ci n'existe pas déja.
*****************************************************************/
template <class CSommet, class CArc>
void CGraphOrient< CSommet,  CArc>::GROAjouterSommet(string sNumSommet) {
    bool bSommetExiste = false;
    for (auto it = vsGROSommetsDuGraphe.begin(); it != vsGROSommetsDuGraphe.end(); ++it) {
        if (sNumSommet == (*it)->GetNumero()) {
            bSommetExiste = true;
            break;
        }
    }

    if (bSommetExiste==false) {
        vsGROSommetsDuGraphe.push_back(make_shared<CSommet>(sNumSommet));
    }
}
/****************************************************************
    *GROSupprimerArc
    * ***********************************************************
    * Entrée : string sDelarcdeb, string sDelarcfin
    * Nécessite : Rien
    * Sortie : Rien
    * Entraine : Supprime un arc du graphe.
*****************************************************************/
template <class CSommet, class CArc>
void CGraphOrient< CSommet,  CArc>::GROSupprimerArc(string sDelarcdeb, string sDelarcfin) {
    for (auto it = vaGROArcsDuGraphe.begin(); it != vaGROArcsDuGraphe.end(); ++it) {
        if (sDelarcdeb == (*it)->GetDebut() && sDelarcfin == (*it)->GetFin()) {
            (*it).reset();
            vaGROArcsDuGraphe.erase(it);
            break;
        }
    }
}

/****************************************************************
    *GROAjouterArc
    * ***********************************************************
    * Entrée : string sDebutArcStr, string sFinArcStr
    * Nécessite : Rien
    * Sortie : Rien
    * Entraine : Ajoute un arc au graphe 
    * tout en vérifiant qu'il n'existe pas.
*****************************************************************/
template <class CSommet, class CArc>
void CGraphOrient< CSommet,  CArc>::GROAjouterArc(string sDebutArcStr, string sFinArcStr) {
    bool bArcExiste = false;
    GROAjouterSommet(sFinArcStr);
    GROAjouterSommet(sDebutArcStr);

    for (auto it = vaGROArcsDuGraphe.begin(); it != vaGROArcsDuGraphe.end(); ++it) {
        if (sDebutArcStr == (*it)->GetDebut() && sFinArcStr == (*it)->GetFin()) {
            bArcExiste = true;
            break;
        }
    }

    if (!bArcExiste) {
        vaGROArcsDuGraphe.push_back(make_shared<CArc>(sDebutArcStr, sFinArcStr));
    }
}

/****************************************************************
    *GROAfficherGraphe
    * ***********************************************************
    * Entrée : Rien
    * Nécessite : Rien
    * Sortie : Rien
    * Entraine : Affiche tout les sommets du graphe.
*****************************************************************/
template <class CSommet, class CArc>
void CGraphOrient< CSommet,  CArc>::GROAfficherGraphe() const {
    cout << "Liste des sommets :" << endl;
    for (const auto& CSommet : vsGROSommetsDuGraphe) {
        cout << "CSommet " << CSommet->GetNumero() << endl;
    }
}

/****************************************************************
    *GROAfficherGraphe2
    * ***********************************************************
    * Entrée : Rien
    * Nécessite : Rien
    * Sortie : Rien
    * Entraine : Affichge simple des différents arcs du graphe.
*****************************************************************/
template <class CSommet, class CArc>
void CGraphOrient< CSommet,  CArc>::GROAfficherGraphe2() const {
    for (const auto& CArc : vaGROArcsDuGraphe) {
        cout << CArc->GetDebut() << " ---> " << CArc->GetFin() << endl;
    }
}

/****************************************************************
    *GROAfficherGraphe5
    * ***********************************************************
    * Entrée : Rien
    * Nécessite : Rien
    * Sortie : Rien
    * Entraine : Affiche les arcs du graphe de façon précise
    * (sommet relié à plusieurs graphe non répété).
*****************************************************************/
template <class CSommet, class CArc>
void CGraphOrient< CSommet,  CArc>::GROAfficherGraphe5() const {
    vector<string> vsArcsDuGrapheAffiches;
    for (const auto& CArc : vaGROArcsDuGraphe) {
        if (GROIsGrapheAffiches(vsArcsDuGrapheAffiches, CArc->GetDebut()) == false) {
            vsArcsDuGrapheAffiches.push_back(CArc->GetDebut());
            cout << CArc->GetDebut() << " ---> ";
            bool bFirst = true;
            for (const auto& arc2 : vaGROArcsDuGraphe) {
                if (CArc->GetDebut() == arc2->GetDebut()) {
                    if (!bFirst)
                        cout << ",";
                    cout << arc2->GetFin();
                    bFirst = false;
                }
            }
            cout << endl;
        }
    }
}

/****************************************************************
    *GROIsGrapheAffiches
    * ***********************************************************
    * Entrée : vector<string> vsArcsDuGrapheAffiches, string sSommetActuel
    * Nécessite : Rien
    * Sortie : bool bArcExiste
    * Entraine : Permet de détecter si un sommet a déja été affiché 
    * ce qui permet de ne pas répéter l'arc dont il fait parti.
    * Par exemple si l'arc 2->3,4,5 est affiché lorsque l'on affiche les arcs liés à 2,
    * lorsque l'on va afficher ceux liés à 3, cet algorithme détecte que 2 est déja affiché et ne va
    * pas répéter l'arc 2->3,4,5 idem lorsque ce sera le tour de 4 et 5.
*****************************************************************/
template <class CSommet, class CArc>
bool CGraphOrient< CSommet,  CArc>::GROIsGrapheAffiches(vector<string> vsArcsDuGrapheAffiches, string sSommetActuel) const {
    bool bArcExiste = false;
    for (auto it = vsArcsDuGrapheAffiches.begin(); it != vsArcsDuGrapheAffiches.end(); ++it) {
        if (sSommetActuel == *it) {
            bArcExiste = true;
            break;
        }
    }
    return bArcExiste;
}

/****************************************************************
    *GROInverserGraphe
    * ***********************************************************
    * Entrée : Rien
    * Nécessite : Avoir un Graphe existant
    * Sortie : CGraphOrient< CSommet,  CArc> newGraphe
    * Entraine : La création d'un nouveau Graphe possédant des arcs inversés.
*****************************************************************/
template <class CSommet, class CArc>
CGraphOrient< CSommet,  CArc> CGraphOrient< CSommet,  CArc>::GROInverserGraphe() {
    vector<shared_ptr<CArc>> vaNewArcs;
    vector<shared_ptr<CSommet>> vsNewSommet;
    for (auto it = vaGROArcsDuGraphe.begin(); it != vaGROArcsDuGraphe.end(); ++it) {
        vaNewArcs.push_back(make_shared<CArc>((*it)->GetFin(), (*it)->GetDebut()));
    }
    vsNewSommet = vsGROSommetsDuGraphe;
    CGraphOrient newGraphe(vsNewSommet, vaNewArcs);

    return newGraphe;
}

/****************************************************************
    *GROModifierArc
    * ***********************************************************
    * Entrée : const string& sDebutArc, const string& sFinArc, const string& sNewDebutArc, const string& sNewFinArc
    * Nécessite : Rien
    * Sortie : Rien
    * Entraine : Modifie un arc en donnant en entrée les anciens
    * sommets de l'arc ainsi que les nouveaux sommets.
*****************************************************************/
template<class CSommet, class CArc>
void CGraphOrient<CSommet, CArc>::GROModifierArc(const string& sDebutArc, const string& sFinArc, const string& sNewDebutArc, const string& sNewFinArc)
{
    typename vector<shared_ptr<CArc>>::iterator itArc;
    for (itArc = vaGROArcsDuGraphe.begin(); itArc != vaGROArcsDuGraphe.end(); ++itArc) {
        if ((*itArc)->GetDebut() == sDebutArc && (*itArc)->GetFin() == sFinArc) {
            (*itArc)->SetDebut(sNewDebutArc);
            (*itArc)->SetFin(sNewFinArc);
            break;
        }
    }
}

/****************************************************************
    *GROModifierSommet
    * ***********************************************************
    * Entrée : const string& sAncienNumero, const string& sNouveauNumero
    * Nécessite : Rien
    * Sortie : Rien
    * Entraine : Modifie la valeur d'un sommet du graphe.
*****************************************************************/
template<class CSommet, class CArc>
void CGraphOrient<CSommet, CArc>::GROModifierSommet(const string& sAncienNumero, const string& sNouveauNumero)
{
    typename vector<shared_ptr<CSommet>>::iterator itSommet;
    for (itSommet = vsGROSommetsDuGraphe.begin(); itSommet != vsGROSommetsDuGraphe.end(); ++itSommet) {
        if ((*itSommet)->GetNumero() == sAncienNumero) {
            (*itSommet)->SetNumero(sNouveauNumero);
            break;
        }
    }
}
