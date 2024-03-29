#pragma once
#include <iostream>
#include <string>
using namespace std;
class Arc
{
private:
	string SommetDepart;
	string SommetArrive;
public:
	Arc(string Depart, string Arrive) : SommetDepart(Depart), SommetArrive(Arrive) {}
    string GetDebut() const {
        return SommetDepart;
    }

    string GetFin() const {
        return SommetArrive;
    }
};

