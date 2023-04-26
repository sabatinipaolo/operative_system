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

using namespace std;

// MAIN
int main()
{
    // int numeroDiProcessi=nProcessi();
    int numeroDiProcessi = 5;
    processo processi[numeroDiProcessi] = {{0, 2, 1, 1}, {1, 0, 2, 2}, {2, 1, 3, 3}, {3, 3, 2, 2}, {4, 4, 3, 3}};
    // svolgiConFCFSNonPreventive(processi, numeroDiProcessi);
    // inizializza(processi,numeroDiProcessi);
    ordinamentoProcessi(processi, numeroDiProcessi); // ordino i processi per istante di arrivo
    // printProcessi(processi, numeroDiProcessi);
    int tempoTotale = trovaTempoTotale(processi, numeroDiProcessi); // tempo totale per il completamento dei processi
    int prcInArrivo = 0, prcInEsecuzione = processi[0].id;          // numeroCoda serve a tenere il conto nella coda
    vector<processo> coda;                                          // creo coda con vector per poter aggiungere all'arrivo
    int sequenzaTemporale[tempoTotale];
	processo *processiOrdinId=ordinamentoProcessiId(processi, numeroDiProcessi);
    for (int j = 0; j < numeroDiProcessi; j++)
    {
        for (int i = 0; i < numeroDiProcessi; i++)
        {
            if (processiOrdinId[i].id > processiOrdinId[i + 1].id)
            {
                processo swap = processiOrdinId[i];
                processiOrdinId[i] = processiOrdinId[i + 1];
                processiOrdinId[i + 1] = swap;
            }
        }
    }

    for (int i = 0; i < tempoTotale; i++)
    {
        if (processi[prcInArrivo].istanteDiArrivo == i)
        {
            coda.push_back(processi[prcInArrivo]); // quando un processo arriva lo aggiungo alla coda
            prcInArrivo++;                         // aggiungo uno ai prcInArrivo in modo da controllare quando arriva il processo successivo
        }
        if (processiOrdinId[prcInEsecuzione].tempoRimanente == 0)
        {
            coda.erase(coda.begin());                                   // quando un processo finisce lo elimino dalla coda per evitare problemi di ordinamento
            ordinamentoProcessiPerTempoDiEsecuzione(coda, coda.size()); // li riordino
            cout << "esce " << prcInEsecuzione << " a " << i << " ed entra " << coda[0].id << endl;
            prcInEsecuzione = coda[0].id; // il processo in esecuzione diventa il primo della coda
        }
        processiOrdinId[prcInEsecuzione].tempoRimanente--; // il tempo rimanente per il processo in esecuzione diminuisce di uno
        sequenzaTemporale[i] = prcInEsecuzione;     // durante quell'istante c'è quel processo in esecuzione e do quel dato in modo da poterlo stampare dopo
    }
    for (int i = 0; i < tempoTotale; i++)
        cout << "|" << sequenzaTemporale[i] << "|";
    cout << endl;
    // signatureWalterWhite();

    return 0;
}