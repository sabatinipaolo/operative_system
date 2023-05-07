/*
    Name: algoritmo SJF
    Copyright:
    Author: Albamonte Giuseppe
    Date: 10/04/23 11:45
    Description: funzionamento di un algoritmo SJF senza prelazione
*/

#include <iostream>
#include <vector>
#include "general_scheduling.h"
#include "signature.h"
#include "alghoritm_SJF.h"
using namespace std;

// MAIN
int main()
{

    int numeroDiProcessi = 5;
    processo processi[numeroDiProcessi] = {{0, 2, 4, 4}, {1, 0, 6, 6}, {2, 1, 1, 1}, {3, 3, 4, 4}, {4, 4, 1, 1}};
    inizializza(processi, numeroDiProcessi);

    int tempoTotale;
    int sequenzaTemporale[100]; // TODO : transitorio fino al prossimo refactoring
    esecuzioneSJFPrentive(numeroDiProcessi, processi, tempoTotale, sequenzaTemporale);
    stampaSequenzaTemporale(tempoTotale, sequenzaTemporale);

    // signatureWalterWhite();
    return 0;
}
