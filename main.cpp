/*
	Name: algoritmo FCFS
	Copyright: 
	Author: Albamonte Giuseppe
	Date: 10/04/23 11:45
	Description: funzionamento di un algoritmo FCFS senza prelazione
*/

#include <iostream>
#include <vector>

using namespace std;

//STRUCT
struct processo{
	int id, istanteDiArrivo, tempoDiEsecuzione;
};

//PROTOTIPI DI FUNZIONE
int nProcessi();
void ordinamentoProcessi(processo *processi, int processiLength);
void printProcessi(processo processi[], int processiLength);
void printSequenzaTemporale(processo processi[], int attesaCoda[], int processiLength);
int *trovaAttesaSingola(processo processi[], int processiLength);
int trovaTempoTotale(processo processi[], int numeroDiProcessi);
float trovaAttesaMedia(int attesaCoda[], int processiLength);
int trovaCompletamento(processo processi[], int attesaCoda[], int processiLength);
float trovaCompletamentoMedia(int completamentoTotale, int processiLength);


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


//FUNZIONI 

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


