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
    // int numeroDiProcessi=nProcessi();
    int numeroDiProcessi = 5;
    processo processi[numeroDiProcessi] = {{0, 2, 3, 3}, {1, 0, 2, 2}, {2, 1, 3, 3}, {3, 3, 2, 2}, {4, 4, 1, 1}};
    // svolgiConFCFSNonPreventive(processi, numeroDiProcessi);
    // inizializza(processi,numeroDiProcessi);
    ordinamentoProcessi(processi, numeroDiProcessi); // ordino i processi per istante di arrivo
    // printProcessi(processi, numeroDiProcessi);
    int tempoTotale = trovaTempoTotale(processi, numeroDiProcessi); // tempo totale per il completamento dei processi
    int sequenzaTemporale[tempoTotale];
    esecuzioneSJF(numeroDiProcessi, processi, tempoTotale, sequenzaTemporale);
    for (int i = 0; i < tempoTotale; i++)
        cout << "|" << sequenzaTemporale[i] << "|";
    cout << endl;
    // signatureWalterWhite();

    return 0;
}
