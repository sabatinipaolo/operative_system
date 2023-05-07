#pragma once
#include <iostream>

using namespace std;

struct processo{
	int id, istanteDiArrivo, tempoDiEsecuzione, tempoRimanente;
};

void stampaProcesso ( processo p){
	cout<<endl<<"Processo "<<p.id<<":"<<" Istante di arrivo:"<<p.istanteDiArrivo<<" Tempo di esecuzione:"<<p.tempoDiEsecuzione<<endl;
}		