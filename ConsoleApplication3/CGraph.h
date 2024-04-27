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
};


