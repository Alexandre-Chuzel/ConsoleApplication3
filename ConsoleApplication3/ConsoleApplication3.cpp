#include "Graphe.h"  
#include "Sommet.h"
#include "Arc.h"
#include <iostream>
int main() {
    Graphe<Sommet, Arc> graphe;

    graphe.ChargerDepuisFichier("C:\\Users\\alexa\\Documents\\Graphe2.txt");


    cout << "Nombre de sommets : " << graphe.GetSommets().size() << endl;
    cout << "Nombre d'arcs : " << graphe.GetArcs().size() << endl;
    graphe.SupprimerSommet(3);
    graphe.SupprimerArc("2","3");
    cout << "Nombre de sommets : " << graphe.GetSommets().size() << endl;
    cout << "Nombre d'arcs : " << graphe.GetArcs().size() << endl;
    graphe.AjouterArc("5", "3");
    graphe.AjouterArc("4", "3");
    graphe.AjouterArc("7", "3");
    graphe.AjouterSommet(4);
    graphe.AjouterSommet(3);
    graphe.AjouterArc("4", "2");
    graphe.AjouterArc("4", "5");
    graphe.AjouterArc("4", "5");
    graphe.AfficherGraphe5();
    //graphe.AfficherGraphe();
    return 0;
}