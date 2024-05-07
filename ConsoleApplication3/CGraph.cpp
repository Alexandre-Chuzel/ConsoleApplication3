#include "CGraph.h"

template <class CSommet, class CArc>
void CGraph< CSommet, CArc>::GRACalcStableMax(CGraph<CSommet, CArc>&Graphe, vector<CSommet*> S, vector<CSommet*> Ss) {
        // V�rifier si S est vide
        if (S.empty()) {
            // V�rifier si Ss est plus grand que Smax
            if (Ss.size() > Smax.size()) {
                Smax = Ss; // Mettre � jour Smax
            }
        }
        else {
            // Parcourir tous les sommets restants dans S
            for (size_t i = 0; i < S.size(); ++i) { 
                CSommet* s = S[i]; 
                // Ajouter le sommet s � l'ensemble en cours de calcul Ss
                Ss.push_back(s); 
                // Retirer le sommet s de S
                S.erase(S.begin() + i); 
                // Supprimer de S tous les sommets ayant une ar�te commune avec s
                for (auto it = S.begin(); it != S.end(); ) { 
                    if (Graphe.GROEstArc(Sommet->GetNumero(), s->GetNumero())) { 
                        it = S.erase(it); 
                    }
                    else {
                        ++it; 
                    }
                }
                // Appeler r�cursivement la fonction avec le nouveau S et Ss
                GRACalcStableMax(Graphe, S, Ss, Smax);
                // Annuler les actions effectu�es sur S et Ss pour le prochain it�r�
                S.insert(S.begin() + i, s); 
                Ss.pop_back();
            }
        }
    }
