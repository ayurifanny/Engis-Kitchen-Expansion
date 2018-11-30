#include "graph.h"
#include <stdio.h>

int main() {
	//Kamus
	Graph G;
	adrNode Pn;
	adrSuccNode Pt;
	Player P;

	//Algoritma
	InitGraph(&G); //inisialisasi graf
	//pada initgraph sudah di test CreateGraph, AddNode dan AddSuccNode
	printf("Mencari Node dg ID 3:\n");
	Pn = SearchNode(G, 3); //mecoba searchnode
	if (Pn != Nil){
		printf("DAPET COY!\n");
		printf("%d\n", Id(Pn) );
	}
	printf("Mencari Succ dg ID dari 3,1 di node 3:\n");
	PosisiX(P) = 3;
	PosisiY(P) = 1;
	Pn = SearchNode(G, 3);
	if (Pn != Nil){
		Pt = SearchTrail(Pn, P); //mencoba search trail
		printf("%d\n", Id(Succ(Pt)) );
	}

	return 0;
}
