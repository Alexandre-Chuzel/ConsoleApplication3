#include "CSommet.h"
#include "CArc.h"
#include "CGraphOrient.h"  
#include "CGraphOrient.cpp"  
#include "CGraph.h"
#include <iostream>
int main(int argc, char* argv[]) {
  CGraphOrient<CSommet, CArc> graphe;
    string file_path = argv[1];
    graphe.GROChargerDepuisFichier(file_path);
    graphe.GROAfficherGraphe();
    cout << "Graphe Orienté  :" << endl;
    graphe.GROAfficherGraphe5();
    CGraphOrient<CSommet, CArc> graphe2 = graphe.GROInverserGraphe();
    cout << "graphe inversé :" << endl;
    graphe2.GROAfficherGraphe5();
    return 0;
}