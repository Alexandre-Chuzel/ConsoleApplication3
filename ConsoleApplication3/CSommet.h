#pragma once
#include <iostream>
#include <string>
#include<vector>
#include <memory>
#include <string>
#include "CArc.h"
using namespace std;

class CSommet
{
private:
	string sNumSommet;
	vector<shared_ptr<CArc>>vaPartDuSommet;
	vector<shared_ptr<CArc>>vaArriveAuSommet;
public:
	CSommet(string sNum) : sNumSommet(sNum) {}
	string GetNumero() const {
		return sNumSommet;
	}
	void SetNumero(string sNewNumber ) {
		sNumSommet = sNewNumber;
	}
};

