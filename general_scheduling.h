#pragma once
#include <iostream>
#include <vector>
#include "struct_processo.h"


using namespace std;

//inizializzazin�one funzione per far scrivere nel terminale il numero totale di processi
int nProcessi();
//inizializzazione funzione per inizializzare i processi da parte dell'utente
void inizializza(processo processi[], int numeroDiProcessi);
//inizializzazione funzione per ordinare i processi in base all'istante di arrivo (bubbleSort)
void ordinamentoProcessi(processo processi, int processiLength);
//inizializzazione funzione per ordinare i processi in base al tempo di esecuzione (bubbleSort)
void ordinamentoProcessiPerTempoDiEsecuzione(vector<processo> processi, int processiLength);
//inizializzazione funzione per scrivere i processi con il loro istante di arrivo ed il loro cpuBurst
void printProcessi(processo processi[], int processiLength);
//inizializzazione funzione per trovare l'attesa media dei processi
float trovaAttesaMedia(int attesaCoda[], int processiLength);
//inizializzazione funzione per trovare il tempo totale di completamento
int trovaCompletamento(processo processi[], int attesaCoda[], int processiLength);
//inizializzazione funzione per trovare la media di completamento di un processo singolo
float trovaCompletamentoMedia(int completamentoTotale, int processiLength);
//ritorna il tempo totale che la cpu ha messo per terminare l'esecuzione
int trovaTempoTotale(processo processi[], int numeroDiProcessi);

int nProcessi(){
	int n;
	cin>>n;
	return n;
}

void inizializza(processo processi[], int numeroDiProcessi){	
	for( int i=0; i<numeroDiProcessi; i++){
		(processi[i]).id=i;
		cout<<endl<<"Processo "<<(processi[i]).id<<":"<<endl<<"-istante di arrivo: ";
		cin>>(processi[i]).istanteDiArrivo;
		cout<<endl<<"-tempo di esecuzione: ";
		cin>>(processi[i]).tempoDiEsecuzione;	
		cout<<endl<<"Processo "<<(processi[i]).id<<":"<<" Istante di arrivo:"<<(processi[i]).istanteDiArrivo<<" Tempo di esecuzione:"<<(processi[i]).tempoDiEsecuzione<<endl;
		processi[i].tempoRimanente=processi[i].tempoDiEsecuzione;
	}	
}

void ordinamentoProcessi(processo processi[], int processiLength){
	for(int j=0; j<processiLength; j++){
		for (int i=0; i<processiLength-(j+1); i++){
			if(processi[i].istanteDiArrivo>processi[i+1].istanteDiArrivo){
				processo swap = processi[i];
				processi[i] = processi[i+1];
				processi[i+1] = swap;
			}
		}
	}
}

void ordinamentoProcessiPerTempoDiEsecuzione(vector<processo> processi, int processiLength){
	for(int j=0; j<processiLength; j++){
		for (int i=0; i<processiLength-(j+1); i++){
			if(processi[i].tempoDiEsecuzione>processi[i+1].tempoDiEsecuzione){
				processo swap = processi[i];
				processi[i] = processi[i+1];
				processi[i+1] = swap;
			}
		}
	}
}

void printProcessi(processo processi[], int processiLength){	
	for( int i=0; i<processiLength; i++){
		cout<<"processo "<<processi[i].id<<endl<<"   -istante di arrivo: "<<processi[i].istanteDiArrivo<<endl<<"   -tempo di esecuzione: "<<processi[i].tempoDiEsecuzione<<endl;
	}
	cout<<endl;
}

float trovaAttesaMedia(int attesaCoda[], int processiLength){
	float attesaMedia = 0;
	for (int i=1; i<processiLength; i++){
		attesaMedia += attesaCoda[i];
	}	
	attesaMedia/=processiLength;
	return attesaMedia;
}

int trovaCompletamento(processo processi[], int attesaCoda[], int processiLength){
	float tempoCompletamento = 0;
	for (int i=1; i<processiLength; i++){
		tempoCompletamento += attesaCoda[i] + processi[i].tempoDiEsecuzione;
	}
	return tempoCompletamento;
}

float trovaCompletamentoMedia(int completamentoTotale, int processiLength){
	float completamentoMedia = (float)completamentoTotale/processiLength;
	return completamentoMedia;
}

int trovaTempoTotale(processo processi[], int numeroDiProcessi){
	int tempoTotale = 0;
	for (int i=0; i<numeroDiProcessi; i++){
		tempoTotale += processi[i].tempoDiEsecuzione;
	}
	return tempoTotale;
}
