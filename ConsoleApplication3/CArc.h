#pragma once
/*******************************************************************
* CLASSE : Classe pour la gestion d'un arc du graphe
* ******************************************************************
* ROLE : Interface de la classe CArc.
* Cette classe contient la structure ainsi que les getter et setter
* d'un arc du graphe.
* ******************************************************************
* VERSION : 1.0
* AUTEUR :Aissatou CISS - Alexandre CHUZEL-MARMOT
* DATE : 28/04/2024
* ******************************************************************
* INCLUSIONS EXTERNES :
*/
#include <iostream>
#include <string>
using namespace std;
class CArc
{
    //ATTRIBUTS :
private:
	string sSommetDepart;
	string sSommetArrive;
    //Constructeur et Getter/Setter :
public:
	CArc(string sDepart, string sArrive) : sSommetDepart(sDepart), sSommetArrive(sArrive) {}
    string GetDebut() const {
        return sSommetDepart;
    }

    string GetFin() const {
        return sSommetArrive;
    }
    void SetDebut(string sNewBegin)  {
         sSommetDepart=sNewBegin;
    }

    void SetFin(string sNewEnd)  {
         sSommetArrive=sNewEnd;
    }
};

