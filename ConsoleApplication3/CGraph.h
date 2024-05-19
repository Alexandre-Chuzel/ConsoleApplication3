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
private:
    int result;
    vector<shared_ptr<CSommet>> vsEnsemblemax;
public:
    void GRAAjouterArete(string sSommet1, string sSommet2);
    int GRACalcStableMax(CGraph<CSommet, CArc>& graphe, vector<shared_ptr<CSommet>>& vsEnsemble);
    void GRADisplayVector();
    void GRADisplayVector2(vector<shared_ptr<CSommet>>& vsEnsemble);

    vector<shared_ptr<CSommet>>& GetvsEnsemblemax(){
      return vsEnsemblemax;
    }
    int GetResult() {
        return result;
    }

};


