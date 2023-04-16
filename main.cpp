/*
	Name: algoritmo FCFS
	Copyright: 
	Author: Albamonte Giuseppe
	Date: 10/04/23 11:45
	Description: funzionamento di un algoritmo FCFS senza prelazione
*/

#include <iostream>
#include "mainFCFS.h"

using namespace std;

//MAIN
int main(){
	int numeroDiProcessi=nProcessi();
	processo processi[numeroDiProcessi];
	svolgiConFCFSNonPreventive(processi, numeroDiProcessi);
	return 0;
}


