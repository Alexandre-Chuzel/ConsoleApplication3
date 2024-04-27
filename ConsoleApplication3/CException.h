#pragma once
/*******************************************************************
* CLASSE : Classe pour la gestion des exceptions
* ******************************************************************
* ROLE : Interface de la classe CException.
* Cette classe permet de créer des objets qui sont remontés
* lors de la levée d'exceptions dans votre programme
* ******************************************************************
* VERSION : 1.0
* AUTEUR :Aissatou CISS - Alexandre CHUZEL-MARMOT
* DATE : 28/04/2024
* ******************************************************************
* INCLUSIONS EXTERNES :
*/
#include <iostream>
#include <exception>
#include <string>
using namespace std;

//Définition de la valeur initiale d'une variable
#define FAUX 0

class CException
{
    //ATTRIBUTS :
private:
    unsigned int uiEXCValeur;

    //CONSTRUCTEURS ET DESTRUCTEURS
public:
    /*****************************************************************
    * CEXCEPTION
    * ****************************************************************
    * Entrée : Rien
    * Nécessite : Rien
    * Sortie : Rien
    * Entraine : L'exception est initialisé à FAUX
    * ****************************************************************/
    CException();

    /******************************************************************
    * EXCModifierValeur
    * *****************************************************************
    * Entrée : uiP, unsigned int, la nouvelle valeur
    * Nécessite : Rien
    * Sortie : Rien
    * Entraine : La valeur de l'exception est modifiée
    * *****************************************************************/
    void EXCModifierValeur(unsigned int uiP) { uiEXCValeur = uiP; }

    /******************************************************************
    * EXCLireValeur
    * *****************************************************************
    * Entrée : Rien
    * Nécessite : Rien
    * Sortie : Un unsigned int, la nouvelle valeur de l'exception
    * Entraine : La valeur de l'exception est retournée
    * *****************************************************************/
    unsigned int EXCLireValeur() const { return (uiEXCValeur); }
};
