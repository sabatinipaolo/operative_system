#pragma once
#include "struct_processo.h"

using namespace std;

//inizializzazione funzione per far vedere la sequenza temporale
void printSequenzaTemporale(processo processi[], int attesaCoda[], int processiLength);
//funzione per trovare l'attesa di ogni singolo processo, ritorna un vettore
void trovaAttesaSingola(int attesaCoda[], processo processi[], int processiLength);
//ritorna il tempo totale che la cpu ha messo per terminare l'esecuzione
int trovaTempoTotale(processo processi[], int numeroDiProcessi);

//FUNZIONI 

void printSequenzaTemporale(processo processi[], int attesaCoda[], int processiLength){
	int processoSuccessivo = 0;
	int istante=0;
	for (int i=0; i<processiLength; i++){
		for(int j=0; j<processi[i].tempoDiEsecuzione; j++){
			cout<<"|"<<processi[i].id<<"|";
			istante++;
		}
	}
}

void trovaAttesaSingola(int attesaCoda[], processo processi[], int processiLength){

	attesaCoda[0] = 0;
	int tempoDiEsecuzioneTotale = 0;
	for (int i=1; i<processiLength; i++){
		tempoDiEsecuzioneTotale += processi[i-1].tempoDiEsecuzione;
		attesaCoda[i] = tempoDiEsecuzioneTotale-processi[i].istanteDiArrivo;
	}

}

int trovaTempoTotale(processo processi[], int numeroDiProcessi){
	int tempoTotale = 0;
	for (int i=0; i<numeroDiProcessi; i++){
		tempoTotale += processi[i].tempoDiEsecuzione;
	}
	return tempoTotale;
}




