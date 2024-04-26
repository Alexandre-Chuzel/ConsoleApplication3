#pragma once
#include <iostream>
#include <string>
using namespace std;
class CArc
{
private:
	string sSommetDepart;
	string sSommetArrive;
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

