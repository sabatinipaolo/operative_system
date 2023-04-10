#include <iostream>

using namespace std;

struct processo{
	int id, istanteDiArrivo, tempoDiEsecuzione;
};

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
}

int trovaTempoTotale(processo processi[], int numeroDiProcessi){
	int tempoTotale = 0;
	for (int i=0; i<numeroDiProcessi; i++){
		tempoTotale += processi[i].tempoDiEsecuzione;
	}
	return tempoTotale;
}

float trovaAttesaMedia(processo processi[], int processiLength){
	float attesaMedia = 0;
	int tempoDiEsecuzioneTotale = 0;
	int attesaCoda[processiLength];
	attesaCoda[0] = 0;	
	for (int i=1; i<processiLength; i++){
		tempoDiEsecuzioneTotale += processi[i-1].tempoDiEsecuzione;
		attesaCoda[i] = tempoDiEsecuzioneTotale-processi[i].istanteDiArrivo;
		attesaMedia += attesaCoda[i];
	}	
	attesaMedia/=processiLength;
	return attesaMedia;
}

int main(){
	int numeroDiProcessi=nProcessi();
	processo processi[numeroDiProcessi];
	for( int i=0; i<numeroDiProcessi; i++){
		processi[i].id=i;
		cout<<endl<<processi[i].id<<":"<<endl<<"-istante di arrivo: ";
		cin>>processi[i].istanteDiArrivo;
		cout<<endl<<"-tempo di essecuzione: ";
		cin>>processi[i].tempoDiEsecuzione;
	}
	ordinamentoProcessi(processi, numeroDiProcessi);
	int tempoTotale = trovaTempoTotale(processi, numeroDiProcessi);
	float attesaMedia = trovaAttesaMedia(processi, numeroDiProcessi);
	cout<<attesaMedia;
	//printProcessi(processi, numeroDiProcessi);
	

	return 0;
}
