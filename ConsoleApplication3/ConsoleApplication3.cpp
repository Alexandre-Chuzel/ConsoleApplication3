#include "Graphe.h"  
#include "Graphe2.h"  
#include "Sommet.h"
#include "Arc.h"
#include <iostream>
int main() {
    Graphe<Sommet, Arc> graphe;
    graphe.ChargerDepuisFichier("C:\\Users\\alexa\\Documents\\Graphe2.txt");
   // cout << "Nombre de sommets : " << graphe.GetSommets().size() << endl;
  //  cout << "Nombre d'arcs : " << graphe.GetArcs().size() << endl;
    graphe.SupprimerSommet("3");
    graphe.SupprimerArc("2","3");
   //cout << "Nombre de sommets : " << graphe.GetSommets().size() << endl;
   //cout << "Nombre d'arcs : " << graphe.GetArcs().size() << endl;
    graphe.AjouterArc("5", "3");
    graphe.AjouterArc("4", "3");
    graphe.AjouterArc("7", "3");
    graphe.AjouterSommet("4");
    graphe.AjouterSommet("3");
    graphe.AjouterArc("4", "2");
    graphe.AjouterArc("4", "5");
    graphe.AjouterArc("4", "5");
    graphe.SupprimerSommet("Alpha");
    //graphe.AfficherGraphe5();
    graphe.AfficherGraphe();
    cout << "Arcs du graphe  :" << endl;
    graphe.AfficherGraphe5();
    Graphe<Sommet, Arc> graphe2 = graphe.InverserGraphe();
    cout << "graphe inversé :" << endl;
    graphe2.AfficherGraphe5();
    //Graphe2<Sommet, Arc> graphe3;
   // graphe3.AjouterArc("4", "5");
    //graphe3.AjouterArc("4", "5"); 
    //cout << "" << endl;
   // graphe3.AfficherGraphe();
   // graphe3.AfficherGraphe5();
    return 0;
}