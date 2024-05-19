#include "CSommet.h"
#include "CArc.h"
#include "CGraphOrient.h"  
#include "CGraphOrient.cpp"  
#include "CChargerFile.h"  
#include "CGraph.h"
#include <iostream>
int main(
    int argc, char* argv[]
) {
    cout << "Version finale de l'application :" << endl;
    CGraphOrient<CSommet, CArc> graphe3;
    CChargerFile charger;
    string file_path = argv[1];
    graphe3 = charger.CHAChargerDepuisFichier(file_path);
    graphe3.GROAfficherGraphe();
    cout << "Graphe Orienté  :" << endl;
    graphe3.GROAfficherGraphe5();
    CGraphOrient<CSommet, CArc> graphe2 = graphe3.GROInverserGraphe();
    cout << "graphe inversé :" << endl;
    graphe2.GROAfficherGraphe5();
    CGraph<CSommet, CArc> graphe;
    vector<shared_ptr<CSommet>> vsEnsemble;    
    graphe.GRAAjouterArete("5", "7");
    graphe.GRAAjouterArete("3", "9");
    graphe.GRAAjouterArete("6", "14");
    graphe.GRAAjouterArete("46", "151");
    graphe.GRAAjouterArete("6", "7");
    graphe.GRAAjouterArete("3", "14");
    graphe.GRAAjouterArete("151", "7");
    cout << "Graphe non Orienté  :" << endl;
    graphe.GROAfficherGraphe2();
    int a=graphe.GRACalcStableMax(graphe, vsEnsemble);
    graphe.GRADisplayVector2(graphe.GetvsEnsemblemax());
    return 0;
}