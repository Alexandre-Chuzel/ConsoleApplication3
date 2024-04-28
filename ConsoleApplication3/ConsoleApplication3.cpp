#include "CSommet.h"
#include "CArc.h"
#include "CGraphOrient.h"  
#include "CGraphOrient.cpp"  
#include "CChargerFile.h"  
#include "CGraph.h"
#include <iostream>
int main(int argc, char* argv[]) {
    cout << "Version finale de l'application :" << endl;
    CGraphOrient<CSommet, CArc> graphe;
    CChargerFile charger;
    string file_path = argv[1];
    graphe = charger.CHAChargerDepuisFichier(file_path);
    graphe.GROAfficherGraphe();
    cout << "Graphe Orienté  :" << endl;
    graphe.GROAfficherGraphe5();
    CGraphOrient<CSommet, CArc> graphe2 = graphe.GROInverserGraphe();
    cout << "graphe inversé :" << endl;
    graphe2.GROAfficherGraphe5();
    return 0;
}