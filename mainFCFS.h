#pragma once
#include <iostream>
#include "general_scheduling.h"
#include "alghoritm_FCFS.h"
#include "struct_processo.h"

using namespace std;

void svolgiConFCFSNonPreventive(processo processi[], int numeroDiProcessi){
	inizializza(processi,numeroDiProcessi);
	ordinamentoProcessi(processi, numeroDiProcessi);
	int tempoTotale = trovaTempoTotale(processi, numeroDiProcessi);
	int attesa[numeroDiProcessi];
	trovaAttesaSingola(attesa, processi, numeroDiProcessi);
	float attesaMedia = trovaAttesaMedia(attesa, numeroDiProcessi);
	int tempoCompletamento = trovaCompletamento(processi, attesa, numeroDiProcessi);
	float completamentoMedia = trovaCompletamentoMedia(tempoCompletamento, numeroDiProcessi);
	cout<<"attesa media: "<<attesaMedia<<endl;
	cout<<"media tempo di completamento "<<completamentoMedia;
	printProcessi(processi, numeroDiProcessi);
	printSequenzaTemporale(processi, attesa, numeroDiProcessi);		
}
