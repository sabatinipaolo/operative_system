#pragma once
#include "struct_processo.h"

using namespace std;

void printSequenzaTemporale(processo processi[], int attesaCoda[], int processiLength);
int *trovaAttesaSingola(processo processi[], int processiLength);
int trovaTempoTotale(processo processi[], int numeroDiProcessi);

//FUNZIONI 

void printSequenzaTemporale(processo processi[], int attesaCoda[], int processiLength){
	int processoSuccessivo = 0;
	int istante=0;
	for (int i=0; i<processiLength; i++){
		for(int j=0; j<processi[i].tempoDiEsecuzione; j++){			
			if(processi[processoSuccessivo].istanteDiArrivo == istante){
				cout<<"arriva:"<<processi[processoSuccessivo].id;
				processoSuccessivo++;
			}
			cout<<"|"<<processi[i].id<<"|";
			istante++;
		}
	}
}

int *trovaAttesaSingola(processo processi[], int processiLength){
	int attesaCoda[processiLength];
	attesaCoda[0] = 0;
	int tempoDiEsecuzioneTotale = 0;
	for (int i=1; i<processiLength; i++){
		tempoDiEsecuzioneTotale += processi[i-1].tempoDiEsecuzione;
		attesaCoda[i] = tempoDiEsecuzioneTotale-processi[i].istanteDiArrivo;
	}
	return attesaCoda;
}

int trovaTempoTotale(processo processi[], int numeroDiProcessi){
	int tempoTotale = 0;
	for (int i=0; i<numeroDiProcessi; i++){
		tempoTotale += processi[i].tempoDiEsecuzione;
	}
	return tempoTotale;
}




