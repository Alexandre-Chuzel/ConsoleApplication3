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

        // Si les sommets n'existent pas, les ajouter au graphe
        if (!bSommet1Existe) {
            this->GROAjouterSommet(sSommet1);
        }
        if (!bSommet2Existe) {
            this->GROAjouterSommet(sSommet2);
        }

        // Ajouter les arcs dans les deux directions
        this->GROAjouterArc(sSommet1, sSommet2);
        this->GROAjouterArc(sSommet2, sSommet1);
    }


    /*Structures globales :
    Smax, Un ensemble stable maximum
        Entrée :
    Un graphe non orienté G = [S, A].
        Un ensemble stable en cours de calcul Ss
        Sortie : Rien
        1 : function CalcStableMax(G, Ss)
        2 : Si(S = ) Alors
        3 : Si(| Ss | > | Smax | ) Alors
        5 : Smax ← Ss
        6 : FinSi
        7 : Sinon
        8 : Pour i = 1 à | S | Faire
        9 : s ← S[i] // s est le sommet en position i dans la liste des sommets restants S
        10 : Ss ← Ss + {s}
    11 : S ← S - {s}
    12 : Retirer de S tous les sommets ayant une arête commune avec s
        13 : CalcStableMax(G, Ss)
        14 : Annuler les actions des étapes 10 à 12
        15 : Fin Pour
        16 : Fin Si*/





    void GRACalcStableMax(CGraph<CSommet, CArc>& graphe, vector<shared_ptr<CSommet>>& vsEnsemble) {

        vector<shared_ptr<CSommet>> vsEnsemblesommet;
        for (auto it7 = graphe.GetSommets().begin(); it7 != graphe.GetSommets().end(); ++it7) {
            vsEnsemblesommet.push_back(*it7);
        }

        if (vsEnsemblesommet.empty()) {
            if (vsEnsemble.size() > vsEnsemblemax.size()) {
                vsEnsemblemax = vsEnsemble;
                displayVector();
            }
        }
        else {
            for (auto it = vsEnsemblesommet.begin(); it != vsEnsemblesommet.end(); ++it) {
                vector<shared_ptr<CSommet>> vsEnsembleCopy = vsEnsemble;
                vector<shared_ptr<CSommet>> vsEnsemblesommetCopy = vsEnsemblesommet;

                vsEnsembleCopy.push_back(*it);
                auto sDelsommet = (*it)->GetNumero();
                vsEnsemblesommetCopy.erase(remove(vsEnsemblesommetCopy.begin(), vsEnsemblesommetCopy.end(), *it), vsEnsemblesommetCopy.end());

                for (auto it2 = graphe.GetArcs().begin(); it2 != graphe.GetArcs().end(); ) {
                    if ((*it2)->GetDebut() == sDelsommet || (*it2)->GetFin() == sDelsommet) {
                        auto sConnectedSommet = (*it2)->GetDebut() == sDelsommet ? (*it2)->GetFin() : (*it2)->GetDebut();
                        vsEnsemblesommetCopy.erase(
                            remove_if(vsEnsemblesommetCopy.begin(), vsEnsemblesommetCopy.end(),
                                [&sConnectedSommet](shared_ptr<CSommet> sommet) {
                                    return sommet->GetNumero() == sConnectedSommet;
                                }),
                            vsEnsemblesommetCopy.end());
                        it2 = graphe.GetArcs().erase(it2);
                    }
                    else {
                        ++it2;
                    }
                }

                CGraph<CSommet, CArc> newgraphe;
                newgraphe.SetSommets(vsEnsemblesommetCopy);
                newgraphe.SetArcs(graphe.GetArcs());

                GRACalcStableMax(newgraphe, vsEnsembleCopy);
            }
        }
    }
   /*
    int GRACalcStableMax(CGraph<CSommet, CArc>& graphe, vector<shared_ptr<CSommet>>& vsEnsemble ) {
        vector<shared_ptr<CSommet>> vsEnsemblesommet;
        vector <shared_ptr<CArc>> vsEnsemblearc;
        vector<shared_ptr<CSommet>> vsEnsemble2 = vsEnsemble;

        for (auto it7 = graphe.GetSommets().begin(); it7 != graphe.GetSommets().end(); ++it7) {
            vsEnsemblesommet.push_back(make_shared<CSommet>((*it7)->GetNumero()));
        }

        for (auto it6 = graphe.GetArcs().begin(); it6 != graphe.GetArcs().end(); ++it6) {
            vsEnsemblearc.push_back(make_shared<CArc>((*it6)->GetFin(), (*it6)->GetDebut()));
        }

        //if (graphe.size() == 0) {
        if (vsEnsemblesommet.empty()) {
            if (vsEnsemble.size() > vsEnsemblemax.size()) {
                vsEnsemblemax = vsEnsemble;
                displayVector();

            }
        }
        else {
            for (auto it = vsEnsemblesommet.begin(); it != vsEnsemblesommet.end(); ++it) {
                vector<shared_ptr<CSommet>> vsEnsembleCopy = vsEnsemble;
                vector<shared_ptr<CSommet>> vsEnsemblesommetCopy = vsEnsemblesommet;
                vector<shared_ptr<CArc>> vsEnsemblearcCopy = vsEnsemblearc;

                vsEnsembleCopy.push_back(*it);
                auto it2 = vsEnsemblearcCopy.begin();
                auto it3 = vsEnsemblesommetCopy.begin();
                string sDelsommet = (*it)->GetNumero();

                while (it2 != vsEnsemblearcCopy.end()) {
                    if (sDelsommet == (*it2)->GetDebut()) {
                        sDelsommet = (*it2)->GetFin();
                        while (it3 != vsEnsemblesommetCopy.end()) {
                            if (sDelsommet == (*it3)->GetNumero()) {
                                it3 = vsEnsemblesommetCopy.erase(it3);
                            }
                            else {
                                ++it3;
                            }
                        }
                        it2 = vsEnsemblearcCopy.erase(it2);
                    }
                    else {
                        ++it2;
                    }
                }
                CGraph <CSommet, CArc> newgraphe;
                newgraphe.SetSommets(vsEnsemblesommetCopy);
                newgraphe.SetArcs(vsEnsemblearcCopy);
                if (!vsEnsemblesommetCopy.empty()) {
                    GRACalcStableMax(newgraphe, vsEnsembleCopy);
                    /*auto it4 = vsEnsemblearcCopy.begin();
                    while (it4 != vsEnsemblearcCopy.end()){
                        newgraphe.GROAjouterArc((*it4)->GetDebut(), (*it4)->GetFin());
                        it4++;
                    } */
                /*}
                else { 
                    return 1;
                }
                vsEnsemblesommetCopy = vsEnsemblesommet;
                vsEnsembleCopy = vsEnsemble;

            }
        }*/
        //displayVector(vsEnsemblemax);
   // }
    
    /*void GRACalcStableMax(vector<shared_ptr<CSommet>>& vsEnsemble, CGraph& graphe) {
        if (vsEnsemble.empty()) {
            if (vsEnsemble.size() > vsEnsemblemax.size()) {
                vsEnsemblemax = vsEnsemble;
                cout << vsEnsemblemax.size() << endl;
            }
        }
        else {
            for (size_t i = 0; i < vsEnsemble.size(); ++i) {
                shared_ptr<CSommet> s = vsEnsemble[i];

                vector<shared_ptr<CSommet>> Ss = vsEnsemble;
                Ss.erase(Ss.begin() + i);

                vector<shared_ptr<CSommet>> S = vsEnsemble;
                vector<shared_ptr<CArc>> A = graphe.GetArcs();
                auto it = S.begin();
                while (it != S.end()) {
                    for (auto arc : A) {
                        if (arc->GetDebut() == s->GetNumero() || arc->GetFin() == s->GetNumero()) {
                            it = S.erase(it);
                            break;
                        }
                        else {
                            ++it;
                        }
                    }
                }

                GRACalcStableMax(S, graphe);
                Ss.clear();
            }
        }
    }*/
    void displayVector() {
        //cout <<"taille de l'ensemble max :" +vsEnsemblemax.size() << endl;
        cout << "Contents of vsEnsemblemax:" << endl;
        for (const auto& sommet : vsEnsemblemax) {
            cout << sommet->GetNumero() << endl;
        }
    }

};


