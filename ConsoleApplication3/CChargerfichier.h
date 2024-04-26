/*#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <memory>
#include <algorithm>
#include "CSommet.h"
#include "CArc.h"
#include "CGraphOrient.h"
//#include "CGraphOrient.cpp"


using namespace std;

class CChargerfichier {
private:

public:
    class CChargerfichier(){}


    void CHAChargerDepuisFichier(const string& nomFichier) {
        CGraphOrient<CSommet, CArc> graphe;
        ifstream fichier(nomFichier);

        if (!fichier.is_open()) {
            cerr << "Erreur : Impossible d'ouvrir le fichier." << endl;
            return;
        }
        string ligne;
        while (getline(fichier, ligne)) {
            size_t pos = ligne.find("=");
            if (pos != string::npos) {
                transform(ligne.begin(), ligne.begin() + pos, ligne.begin(), ::tolower);
            }
            if (ligne.find("nbsommets=") != string::npos) {
                int startPos = static_cast<int>(pos) + 1;
                int nombreSommets = stoi(ligne.substr(startPos));
                cerr << nombreSommets << endl;
            }
            else if (ligne.find("nbarcs=") != string::npos) {
                int nombreArcs = stoi(ligne.substr(pos + 1));
                cerr << nombreArcs << endl;

            }
            else if (ligne.find("sommets=[") != string::npos) {
                while (getline(fichier, ligne) && ligne.find("]") == string::npos) {
                    pos = ligne.find("=");
                    if (pos != string::npos) {
                        transform(ligne.begin(), ligne.begin() + pos, ligne.begin(), ::tolower);
                    }
                    if (ligne.find("numero=") != string::npos) {
                        string numeroSommet = ligne.substr(pos + 1);
                        graphe.GROAjouterSommet(numeroSommet);
                    }
                }
            }
            else if (ligne.find("arcs=[") != string::npos) {
                while (getline(fichier, ligne) && ligne.find("]") == string::npos) {
                    size_t posDebut = ligne.find("=");
                    size_t posDebutFin = ligne.find(",");
                    size_t posFin = ligne.find("=", posDebut + 1);
                    if (posDebut != string::npos && posDebutFin != string::npos && posFin != string::npos) {
                        transform(ligne.begin(), ligne.begin() + posDebut, ligne.begin(), ::tolower);
                        transform(ligne.begin() + posDebutFin, ligne.begin() + posFin, ligne.begin() + posDebutFin, ::tolower);
                        if (ligne.find("debut=") != std::string::npos && ligne.find("fin=") != string::npos) {
                            string sDebutArcStr = ligne.substr(posDebut + 1, posDebutFin - posDebut - 1);
                            string sFinArcStr = ligne.substr(posDebut + posDebutFin);
                            graphe.GROAjouterArc(sDebutArcStr, sFinArcStr);
                        }
                    }
                }
            }
        }

        fichier.close();
    }
};*/