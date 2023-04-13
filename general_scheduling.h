#pragma once
#include <iostream>
#include "struct_processo.h"


using namespace std;

int nProcessi();
void ordinamentoProcessi(processo *processi, int processiLength);
void printProcessi(processo processi[], int processiLength);
float trovaAttesaMedia(int attesaCoda[], int processiLength);
int trovaCompletamento(processo processi[], int attesaCoda[], int processiLength);
float trovaCompletamentoMedia(int completamentoTotale, int processiLength);

int nProcessi(){
	int n;
	cin>>n;
	return n;
}

void ordinamentoProcessi(processo *processi, int processiLength){
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
