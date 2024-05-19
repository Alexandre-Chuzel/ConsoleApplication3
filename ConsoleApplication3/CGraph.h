/***********************************************************************
    * CLASSE :CGraph
    * ******************************************************************
    * ROLE : Gestion de graphes non orientés
    * ******************************************************************
    * VERSION : 1.0
    * AUTEUR : Aissatou CISS - Alexandre CHUZEL-MARMOT
    * DATE : 27/04/2024
    * *******************************************************************
    * INCLUSIONS EXTERNES :
    */
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
template <class CSommet, class CArc>
class CGraph : public CGraphOrient<CSommet, CArc> {

    //CONSTRUCTEURS ET MÉTHODES
public:
    int result;
    vector<shared_ptr<CSommet>> vsEnsemblemax;

    /****************************************************************
        *GRAAjouterArete
        * ***********************************************************
        * Entrée : const string& sSommet1, const string& sSommet2
        * Nécessite : Rien
        * Sortie : Rien
        * Entraine : Ajoute une arête au graphe en ajoutant deux arcs
        * entre les deux sommets
    *****************************************************************/
    void GRAAjouterArete(string sSommet1, string sSommet2) {

        bool bSommet1Existe = false;
        bool bSommet2Existe = false;
        for (auto it = this->GetSommets().begin(); it != this->GetSommets().end(); ++it) {
            if ((*it)->GetNumero() == sSommet1) {
                bSommet1Existe = true;
            }
            if ((*it)->GetNumero() == sSommet2) {
                bSommet2Existe = true;
            }
        }

        if (!bSommet1Existe) {
            this->GROAjouterSommet(sSommet1);
        }
        if (!bSommet2Existe) {
            this->GROAjouterSommet(sSommet2);
        }

        this->GROAjouterArc(sSommet1, sSommet2);
        this->GROAjouterArc(sSommet2, sSommet1);
    }



    /****************************************************************
       *GRACalcStableMax
       * ***********************************************************
       * Entrée : CGraph<CSommet, CArc>& graphe, vector<shared_ptr<CSommet>>& vsEnsemble
       * Nécessite : Un graphe non orienté déja rempli.
       * Sortie : Rien
       * Entraine : Ajoute une arête au graphe en ajoutant deux arcs
       * entre les deux sommets
   *****************************************************************/

    int GRACalcStableMax(CGraph<CSommet, CArc>& graphe, vector<shared_ptr<CSommet>>& vsEnsemble) {
        result = 0;
        vector<shared_ptr<CSommet>> vsEnsemblesommet;
        for (auto it7 = graphe.GetSommets().begin(); it7 != graphe.GetSommets().end(); ++it7) {
            vsEnsemblesommet.push_back(*it7);
        }

        if (vsEnsemblesommet.empty()) {
            if (vsEnsemble.size() > vsEnsemblemax.size()) {
                vsEnsemblemax = vsEnsemble;
                displayVector();
                result = -1;
            }
        }
        else {
            for (auto it = vsEnsemblesommet.begin(); it != vsEnsemblesommet.end(); ++it) {
                vector<shared_ptr<CSommet>> vsEnsembleCopy = vsEnsemble;
                vector<shared_ptr<CSommet>> vsEnsemblesommetCopy = vsEnsemblesommet;

                vsEnsembleCopy.push_back(*it);
                auto sDelsommet = (*it)->GetNumero();
                vsEnsemblesommetCopy.erase(remove(vsEnsemblesommetCopy.begin(), vsEnsemblesommetCopy.end(), *it), vsEnsemblesommetCopy.end());

                for (auto it2 = graphe.GetArcs().begin(); it2 != graphe.GetArcs().end(); it2++ ) {
                    if ((*it2)->GetDebut() == sDelsommet || (*it2)->GetFin() == sDelsommet) {
                        auto sConnectedSommet = (*it2)->GetDebut() == sDelsommet ? (*it2)->GetFin() : (*it2)->GetDebut();
                        
                            for (auto it6 = vsEnsemblesommetCopy.begin(); it6 != vsEnsemblesommetCopy.end(); ) {
                                if ((*it6)->GetNumero() == sConnectedSommet) {
                                    it6 = vsEnsemblesommetCopy.erase(it6);
                                    break;
                                }
                                else {
                                    ++it6;
                                }
                            }
                        it2 = graphe.GetArcs().erase(it2);
                    }
                  
                }

                CGraph<CSommet, CArc> newgraphe;
                newgraphe.SetSommets(vsEnsemblesommetCopy);
                newgraphe.SetArcs(graphe.GetArcs());
                if (result == -1) {
                    return result;
                }             
                GRACalcStableMax(newgraphe, vsEnsembleCopy);
                
            }
        }
    }
    void displayVector() {
        cout << "Contenu de vsEnsemblemax:" << endl;
        for (const auto& sommet : vsEnsemblemax) {
            cout << sommet->GetNumero() << endl;
        }
    }
    void displayVector2(vector<shared_ptr<CSommet>>& vsEnsemble) {
        cout << "Contenu de vsEnsemblemax:" << endl;
        for (const auto& sommet : vsEnsemblemax) {
            cout << sommet->GetNumero() << endl;
        }
    }

};


