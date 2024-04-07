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
	string NumSommet;
	vector<shared_ptr<Arc>>PartDuSommet;
	vector<shared_ptr<Arc>>ArriveAuSommet;
public:
	Sommet(string num) : NumSommet(num) {}
	string GetNumero() const {
		return NumSommet;
	}
};

