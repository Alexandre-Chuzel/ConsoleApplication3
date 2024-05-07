#include "CGraph.h"

template <class CSommet, class CArc>
void CGraph< CSommet, CArc>::GRACalcStableMax(CGraph<CSommet, CArc>&Graphe, vector<CSommet*> S, vector<CSommet*> Ss) {
        // Vérifier si S est vide
        if (S.empty()) {
            // Vérifier si Ss est plus grand que Smax
            if (Ss.size() > Smax.size()) {
                Smax = Ss; // Mettre à jour Smax
            }
        }
        else {
            // Parcourir tous les sommets restants dans S
            for (size_t i = 0; i < S.size(); ++i) { 
                CSommet* s = S[i]; 
                // Ajouter le sommet s à l'ensemble en cours de calcul Ss
                Ss.push_back(s); 
                // Retirer le sommet s de S
                S.erase(S.begin() + i); 
                // Supprimer de S tous les sommets ayant une arête commune avec s
                for (auto it = S.begin(); it != S.end(); ) { 
                    if (Graphe.GROEstArc(Sommet->GetNumero(), s->GetNumero())) { 
                        it = S.erase(it); 
                    }
                    else {
                        ++it; 
                    }
                }
                // Appeler récursivement la fonction avec le nouveau S et Ss
                GRACalcStableMax(Graphe, S, Ss, Smax);
                // Annuler les actions effectuées sur S et Ss pour le prochain itéré
                S.insert(S.begin() + i, s); 
                Ss.pop_back();
            }
        }
    }
