#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <memory>
#include <algorithm>
#include "Arc.h"
#include "Sommet.h"

using namespace std;
struct compare;

template <class Sommet, class Arc>
class Graphe {
private:
    vector<shared_ptr<Arc>> ArcsDuGraphe;
    vector<shared_ptr<Sommet>> SommetsDuGraphe;
    //vector<string>ArcsDuGrapheAffiches;

public:
    Graphe() {}
    ~Graphe() {}
    Graphe(vector<shared_ptr<Sommet>> SommetsDuGraphe,vector<shared_ptr<Arc>> ArcsDuGraphe) {
        this->SommetsDuGraphe = SommetsDuGraphe;
        this->ArcsDuGraphe = ArcsDuGraphe;
    }
    const vector<shared_ptr<Arc>>& GetArcs() const {
        return ArcsDuGraphe;
    }

    const vector<shared_ptr<Sommet>>& GetSommets() const {
        return SommetsDuGraphe;
    }
    void ChargerDepuisFichier(const string& nomFichier) {
        ifstream fichier(nomFichier);

        if (!fichier.is_open()) {
            cerr << "Erreur : Impossible d'ouvrir le fichier." << endl;
            return;
        }

        string ligne;
        while (getline(fichier, ligne)) {
            if (ligne.find("NBSommets=") != string::npos) {
                size_t pos = ligne.find("=");
                int startPos = static_cast<int>(pos) + 1;
                int nombreSommets = stoi(ligne.substr(startPos));
                cerr << nombreSommets << endl;
            }
            else if (ligne.find("NBArcs=") != string::npos) {
                size_t pos = ligne.find("=");
                int nombreArcs = stoi(ligne.substr(pos + 1));
                cerr << nombreArcs << endl;

            }
            else if (ligne.find("Sommets=[") != string::npos) {
                while (getline(fichier, ligne) && ligne.find("]") == string::npos) {
                    if (ligne.find("Numero=") != string::npos) {
                        size_t pos = ligne.find("=");
                        string numeroSommet = ligne.substr(pos + 1);
                        SommetsDuGraphe.push_back(make_shared<Sommet>(numeroSommet));
                    }
                }
            }
            else if (ligne.find("Arcs=[") != string::npos) {
                while (getline(fichier, ligne) && ligne.find("]") == string::npos) {
                    if (ligne.find("Debut=") != std::string::npos && ligne.find("Fin=") != string::npos) {
                        size_t posDebut = ligne.find("=");
                        size_t posDebutFin = ligne.find(",");
                        //size_t posFin = ligne.find("=", posDebut + 1);
                        //size_t posFinFin = ligne.find("D", posDebut + 1);
                        string debutArcStr = ligne.substr(posDebut + 1, posDebutFin - posDebut - 1);
                        string finArcStr = ligne.substr(posDebut + posDebutFin);
                        ArcsDuGraphe.push_back(make_shared<Arc>(debutArcStr, finArcStr));
                    }
                }
            }
        }

        fichier.close();
    }
    void SupprimerSommet(string delsommet) {
        auto it = SommetsDuGraphe.begin();
        while (it != SommetsDuGraphe.end()) {
            if (delsommet == (*it)->GetNumero()) {
                (*it).reset();
                it = SommetsDuGraphe.erase(it);
            }
            else {
                ++it;
            }
        }
        auto it2 = ArcsDuGraphe.begin();
        while (it2 != ArcsDuGraphe.end()) {
            if (delsommet == (*it2)->GetDebut() || delsommet == (*it2)->GetFin()) {
                (*it2).reset();
                it2 = ArcsDuGraphe.erase(it2);
            }
            else {
                ++it2;
            }
        }
    }
    void AjouterSommet(string numSommet) {
        bool sommetExiste = false;
        for (auto it = SommetsDuGraphe.begin(); it != SommetsDuGraphe.end(); ++it) {
            if (numSommet == (*it)->GetNumero()) {
                cout << "Le sommet existe déja" << endl;
                sommetExiste = true;
            }
        }
        if (sommetExiste == false) {
            SommetsDuGraphe.push_back(make_shared<Sommet>(numSommet));
        }

    }
    void SupprimerArc(string delarcdeb, string delarcfin) {
        for (auto it = ArcsDuGraphe.begin(); it != ArcsDuGraphe.end(); ++it) {
            if (delarcdeb == (*it)->GetDebut() and delarcfin == (*it)->GetFin()) {
                (*it).reset();
                ArcsDuGraphe.erase(it);
                break;
            }
        }
    }
    void AjouterArc(string debutArcStr, string finArcStr) {
        bool  arcExiste = false;
        AjouterSommet(finArcStr);
        AjouterSommet(debutArcStr);
        for (auto it = ArcsDuGraphe.begin(); it != ArcsDuGraphe.end(); ++it) {
            if (debutArcStr == (*it)->GetDebut() and finArcStr == (*it)->GetFin()) {
                arcExiste = true;
            }
        }
        if (arcExiste == false) {
            ArcsDuGraphe.push_back(make_shared<Arc>(debutArcStr, finArcStr));
        }
    }
    void AfficherGraphe() const {
        cout << "Liste des sommets :" << endl;
        for (const auto& sommet : SommetsDuGraphe) {
            cout << "Sommet " << sommet->GetNumero() << endl;
        }

        cout << "Liste des arcs :" << endl;
        for (const auto& arc : ArcsDuGraphe) {
            cout << "Arc de " << arc->GetDebut() << " à " << arc->GetFin() << endl;
        }
    }
    void AfficherGraphe2() const {
        for (const auto& arc : ArcsDuGraphe) {
            cout << arc->GetDebut() << " ---> " << arc->GetFin() << endl;
        }
    }
    /*void AfficherGraphe3() const {
        int i = 1;
        while (i < GetArc().size) {
            for (const auto& arc : ArcsDuGraphe) {
                string debutArcStr = arc->GetDebut();
                cout << arc->GetDebut() << " ---> " << endl;
                for (const auto& arc2 : ArcsDuGraphe) {
                    if (debutArcStr == arc2->GetDebut()) {
                        cout << arc2->GetFin() << endl;
                        string debutArcStr = arc->getFin();
                        for (const auto& arc3 : ArcsDuGraphe) {
                            cout << arc3->" ---> " << endl;

                        }
                    }


                }
            }
        }
    }*/
    void AfficherGraphe4() const {
        for (const auto& arc : ArcsDuGraphe) {
            cout << arc->GetDebut() << " ---> ";
            for (const auto& arc2 : ArcsDuGraphe) {
                if (arc->GetDebut() == arc2->GetDebut()) {
                    cout << arc2->GetFin() << ", ";
                }
            }
            cout << endl;
        }
    }
    void AfficherGraphe5() const {
        //vector<shared_ptr<Arc>> ArcsDuGrapheAffiches;
        vector<string>ArcsDuGrapheAffiches;
        for (const auto& arc : ArcsDuGraphe) {
            if (IsGrapheAffiches(ArcsDuGrapheAffiches, arc->GetDebut()) == false) {
                ArcsDuGrapheAffiches.push_back(arc->GetDebut());
                cout << arc->GetDebut() << " ---> ";
                bool first = true;
                for (const auto& arc2 : ArcsDuGraphe) {
                    if (arc->GetDebut() == arc2->GetDebut()) {
                        if (!first)
                            cout << ",";
                        cout << arc2->GetFin();
                        first = false;
                    }
                }
                cout << endl;
            }
        }
    }

    bool IsGrapheAffiches(vector<string>ArcsDuGrapheAffiches, string a) const {
        bool arcExiste = false;
        for (auto it = ArcsDuGrapheAffiches.begin(); it != ArcsDuGrapheAffiches.end(); ++it) {
            if (a == *it) {
                arcExiste = true;
                break;
            }
        }
        return arcExiste;
    }
 
    /*void InverserGraphe() {
        int i = 0;
        while (i < ArcsDuGraphe.size()) {
            for (auto it = ArcsDuGraphe.begin(); it != ArcsDuGraphe.end(); ++it) {
                string a;
                a = (*it)->GetFin();
                (*it)->GetFin() = (*it)->GetDebut();
                (*it)->GetDebut() = a;
                //(*it).reset();
                ArcsDuGraphe.push_back(make_shared<Arc>((*it)->GetFin(), (*it)->GetDebut()));
                ArcsDuGraphe.erase(ArcsDuGraphe.begin());
                i++;
            }
        }
    }*/
    Graphe InverserGraphe() {
        vector<shared_ptr<Arc>> newArcs;
        vector<shared_ptr<Sommet>> newSommet;
        for (auto it = ArcsDuGraphe.begin(); it != ArcsDuGraphe.end(); ++it) {
            newArcs.push_back(make_shared<Arc>((*it)->GetFin(), (*it)->GetDebut()));
        }
        newSommet = SommetsDuGraphe;
        Graphe newGraphe(newSommet,newArcs);

        return newGraphe;
    }
   
};