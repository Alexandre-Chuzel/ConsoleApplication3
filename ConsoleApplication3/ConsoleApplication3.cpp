#include "CSommet.h"
#include "CArc.h"
#include "CGraphOrient.h"  
#include "CGraphOrient.cpp"  
#include "CChargerfichier.h"
#include "CGraph.h"
#include <iostream>
int main(int argc, char* argv[]) {
  CGraphOrient<CSommet, CArc> graphe;
  //CChargerfichier charger;
  //charger.CHAChargerDepuisFichier("C:\\Users\\alexa\\Documents\\Graphe2.txt");
  graphe.GROChargerDepuisFichier("C:\\Users\\alexa\\Documents\\Graphe2.txt");
  // cout << "Nombre de sommets : " << graphe.GetSommets().size() << endl;
  //  cout << "Nombre d'arcs : " << graphe.GetArcs().size() << endl;
    //string file_path = argv[1];
    //graphe.CHAChargerDepuisFichier(file_path);
    graphe.GROSupprimerSommet("3");
    graphe.GROSupprimerArc("2","3");
   //cout << "Nombre de sommets : " << graphe.GetSommets().size() << endl;
   //cout << "Nombre d'arcs : " << graphe.GetArcs().size() << endl;
    graphe.GROAjouterArc("5", "3");
    graphe.GROAjouterArc("4", "3");
    graphe.GROAjouterArc("7", "3");
    graphe.GROAjouterSommet("4");
    graphe.GROAjouterSommet("3");
    graphe.GROAjouterArc("4", "2");
    graphe.GROAjouterArc("4", "5");
    graphe.GROAjouterArc("5", "4");
    graphe.GROAjouterArc("4", "5");
    graphe.GROSupprimerSommet("Alpha");
    //graphe.GROAfficherGraphe5();
    //graphe.GROAfficherGraphe();
    cout << "Arcs du graphe  :" << endl;
    //graphe.GROAfficherGraphe5();
    CGraphOrient<CSommet, CArc> graphe2 = graphe.GROInverserGraphe();
    cout << "graphe inversé :" << endl;
    //graphe2.GROAfficherGraphe5();
    CGraph<CSommet, CArc> graphe3;
    graphe3.GROChargerDepuisFichier("C:\\Users\\alexa\\Documents\\Graphe2.txt");
    graphe3.GRAAjouterArete("4", "2");
    graphe3.GROModifierArc("4", "2", "6", "3");
    graphe3.GROAfficherGraphe5();
    //Graphe2<CSommet, CArc> graphe3;
    //graphe3.GROAjouterArc("4", "5");
    //graphe3.GROAjouterArc("4", "5"); 
    //cout << "" << endl;
    //graphe3.GROAfficherGraphe();
   // graphe3.GROAfficherGraphe5();
    return 0;
}