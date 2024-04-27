#pragma once
/*******************************************************************
* CLASSE : Classe pour la gestion d'un sommet du graphe
* ******************************************************************
* ROLE : Interface de la classe CSommet.
* Cette classe contient la structure ainsi que les getter et setter
* d'un sommet du graphe.
* ******************************************************************
* VERSION : 1.0
* AUTEUR :Aissatou CISS - Alexandre CHUZEL-MARMOT
* DATE : 28/04/2024
* ******************************************************************
* INCLUSIONS EXTERNES :
*/
#include <iostream>
#include <string>
#include<vector>
#include <memory>
#include <string>
#include "CArc.h"
using namespace std;

class CSommet
{
	//ATTRIBUTS :
private:
	string sNumSommet;
	vector<shared_ptr<CArc>>vaPartDuSommet;
	vector<shared_ptr<CArc>>vaArriveAuSommet;
	//Constructeur et Getter/Setter :
public:
	CSommet(string sNum) : sNumSommet(sNum) {}
	string GetNumero() const {
		return sNumSommet;
	}
	void SetNumero(string sNewNumber ) {
		sNumSommet = sNewNumber;
	}
};

