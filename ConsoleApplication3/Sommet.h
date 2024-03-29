#pragma once
#include <iostream>
#include <string>
#include<vector>
#include <memory>
#include "Arc.h"
using namespace std;

class Sommet
{
private:
	int NumSommet;
	vector<shared_ptr<Arc>>PartDuSommet;
	vector<shared_ptr<Arc>>ArriveAuSommet;
public:
	Sommet(int num) : NumSommet(num) {}
	int GetNumero() const {
		return NumSommet;
	}
};

