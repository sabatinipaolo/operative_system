/*
	Name: algoritmo FCFS
	Copyright: 
	Author: Albamonte Giuseppe
	Date: 10/04/23 11:45
	Description: funzionamento di un algoritmo FCFS senza prelazione
*/

#include <iostream>
#include "alghoritm_FCFS.h"

using namespace std;

//MAIN
int main(){
	int numeroDiProcessi=nProcessi();
	processo processi[numeroDiProcessi];
	for( int i=0; i<numeroDiProcessi; i++){
		(processi[i]).id=i;
		cout<<endl<<(processi[i]).id<<":"<<endl<<"-istante di arrivo: ";
		cin>>(processi[i]).istanteDiArrivo;
		cout<<endl<<"-tempo di esecuzione: ";
		cin>>(processi[i]).tempoDiEsecuzione;	
		cout<<endl<<(processi[i]).id<<":"<<(processi[i]).istanteDiArrivo<<":"<<(processi[i]).tempoDiEsecuzione<<endl;
	}
	ordinamentoProcessi(processi, numeroDiProcessi);
	int tempoTotale = trovaTempoTotale(processi, numeroDiProcessi);
	int *attesa = trovaAttesaSingola(processi, numeroDiProcessi);
	float attesaMedia = trovaAttesaMedia(attesa, numeroDiProcessi);
	int tempoCompletamento = trovaCompletamento(processi, attesa, numeroDiProcessi);
	float completamentoMedia = trovaCompletamentoMedia(tempoCompletamento, numeroDiProcessi);
	cout<<"attesa media: "<<attesaMedia<<endl;
	cout<<"media tempo di completamento "<<completamentoMedia;
	printProcessi(processi, numeroDiProcessi);
	printSequenzaTemporale(processi, attesa, numeroDiProcessi);	

	return 0;
}


