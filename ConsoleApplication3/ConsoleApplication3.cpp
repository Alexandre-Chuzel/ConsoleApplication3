#include "CSommet.h"
#include "CArc.h"
#include "CGraphOrient.h"  
#include "CGraphOrient.cpp"  
#include "CChargerFile.h"  
#include "CGraph.h"
#include <iostream>
int main(
    //int argc, char* argv[]
) {
    /*cout << "Version finale de l'application :" << endl;
    CGraphOrient<CSommet, CArc> graphe;
    CChargerFile charger;
    string file_path = argv[1];
    graphe = charger.CHAChargerDepuisFichier(file_path);
    graphe.GROAfficherGraphe();
    cout << "Graphe Orienté  :" << endl;
    graphe.GROAfficherGraphe5();
    CGraphOrient<CSommet, CArc> graphe2 = graphe.GROInverserGraphe();
    cout << "graphe inversé :" << endl;
    graphe2.GROAfficherGraphe5();*/
    CGraph<CSommet, CArc> graphe;
    vector<shared_ptr<CSommet>> vsEnsemble;    
    graphe.GRAAjouterArete("5", "7");
    graphe.GRAAjouterArete("3", "9");
    graphe.GRAAjouterArete("6", "14");
    graphe.GRAAjouterArete("46", "151");
    graphe.GRAAjouterArete("6", "7");
    graphe.GRAAjouterArete("3", "14");
    graphe.GRAAjouterArete("151", "7");
    graphe.GROAfficherGraphe2();
    int a=graphe.GRACalcStableMax(graphe, vsEnsemble);
    //graphe.displayVector();
    //graphe.displayVector2(newEnsemble);


    return 0;
}