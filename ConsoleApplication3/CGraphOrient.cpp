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
#include"CChargerfichier.h"


using namespace std;

template <class CSommet, class CArc>
CGraphOrient<CSommet, CArc>::CGraphOrient() {
}

template <class CSommet, class CArc>
CGraphOrient< CSommet,  CArc>::~CGraphOrient() {
}

template <class CSommet, class CArc>
CGraphOrient< CSommet,  CArc>::CGraphOrient(vector<shared_ptr<CSommet>> vsSommets, vector<shared_ptr<CArc>> vaArcs){
    this->vsGROSommetsDuGraphe = vsSommets;
    this->vaGROArcsDuGraphe = vaArcs;
}

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
template <class CSommet, class CArc>
void CGraphOrient< CSommet,  CArc>::GROAfficherGraphe() const {
    cout << "Liste des sommets :" << endl;
    for (const auto& CSommet : vsGROSommetsDuGraphe) {
        cout << "CSommet " << CSommet->GetNumero() << endl;
    }
}
template <class CSommet, class CArc>
void CGraphOrient< CSommet,  CArc>::GROAfficherGraphe2() const {
    for (const auto& CArc : vaGROArcsDuGraphe) {
        cout << CArc->GetDebut() << " ---> " << CArc->GetFin() << endl;
    }
}
template <class CSommet, class CArc>
void CGraphOrient< CSommet,  CArc>::GROAfficherGraphe4() const {
    for (const auto& CArc : vaGROArcsDuGraphe) {
        cout << CArc->GetDebut() << " ---> ";
        for (const auto& arc2 : vaGROArcsDuGraphe) {
            if (CArc->GetDebut() == arc2->GetDebut()) {
                cout << arc2->GetFin() << ", ";
            }
        }
        cout << endl;
    }
}
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
template <class CSommet, class CArc>
void CGraphOrient< CSommet,  CArc>::GROChargerDepuisFichier(const string& sNomFichier) {
    ifstream fichier(sNomFichier);

    if (!fichier.is_open()) {
        cerr << "Erreur : Impossible d'ouvrir le fichier." << endl;
        return;
    }
    string ligne;
    while (getline(fichier, ligne)) {
        size_t pos = ligne.find("=");
        if (pos != string::npos) {
            transform(ligne.begin(), ligne.begin() + pos, ligne.begin(), ::tolower);
        }
        if (ligne.find("nbsommets=") != string::npos) {
            int startPos = static_cast<int>(pos) + 1;
            int nombreSommets = stoi(ligne.substr(startPos));
            cerr << nombreSommets << endl;
        }
        else if (ligne.find("nbarcs=") != string::npos) {
            int nombreArcs = stoi(ligne.substr(pos + 1));
            cerr << nombreArcs << endl;

        }
        else if (ligne.find("sommets=[") != string::npos) {
            while (getline(fichier, ligne) && ligne.find("]") == string::npos) {
                pos = ligne.find("=");
                if (pos != string::npos) {
                    transform(ligne.begin(), ligne.begin() + pos, ligne.begin(), ::tolower);
                }
                if (ligne.find("numero=") != string::npos) {
                    string numeroSommet = ligne.substr(pos + 1);
                    vsGROSommetsDuGraphe.push_back(make_shared<CSommet>(numeroSommet));
                }
            }
        }
        else if (ligne.find("arcs=[") != string::npos) {
            while (getline(fichier, ligne) && ligne.find("]") == string::npos) {
                size_t posDebut = ligne.find("=");
                size_t posDebutFin = ligne.find(",");
                size_t posFin = ligne.find("=", posDebut + 1);
                if (posDebut != string::npos && posDebutFin != string::npos && posFin != string::npos) {
                    transform(ligne.begin(), ligne.begin() + posDebut, ligne.begin(), ::tolower);
                    transform(ligne.begin() + posDebutFin, ligne.begin() + posFin, ligne.begin() + posDebutFin, ::tolower);
                    if (ligne.find("debut=") != std::string::npos && ligne.find("fin=") != string::npos) {
                        string sDebutArcStr = ligne.substr(posDebut + 1, posDebutFin - posDebut - 1);
                        string sFinArcStr = ligne.substr(posDebut + posDebutFin);
                        vaGROArcsDuGraphe.push_back(make_shared<CArc>(sDebutArcStr, sFinArcStr));
                    }
                }
            }
        }
    }

    fichier.close();
}
template<class CSommet, class CArc>
void CGraphOrient<CSommet, CArc>::GROModifierArc(const string& debutArc, const string& finArc, const string& newDebutArc, const string& newFinArc)
{
    typename vector<shared_ptr<CArc>>::iterator itArc;
    for (itArc = vaGROArcsDuGraphe.begin(); itArc != vaGROArcsDuGraphe.end(); ++itArc) {
        if ((*itArc)->GetDebut() == debutArc && (*itArc)->GetFin() == finArc) {
            (*itArc)->SetDebut(newDebutArc);
            (*itArc)->SetFin(newFinArc);
            break;
        }
    }
}

template<class CSommet, class CArc>
void CGraphOrient<CSommet, CArc>::GROModifierSommet(const string& ancienNumero, const string& nouveauNumero)
{
    typename vector<shared_ptr<CSommet>>::iterator itSommet;
    for (itSommet = vsGROSommetsDuGraphe.begin(); itSommet != vsGROSommetsDuGraphe.end(); ++itSommet) {
        if ((*itSommet)->GetNumero() == ancienNumero) {
            (*itSommet)->SetNumero(nouveauNumero);
            break;
        }
    }
}
