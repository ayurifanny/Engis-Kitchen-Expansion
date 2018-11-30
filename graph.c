
#include "graph.h"
#include <stdio.h>


void CreateGraph (int X, Graph *G)
/*IS : Sembarang
FS : Terbentuk graph dnegan first elemen X*/
{
	//Kamus
	adrNode P;

	P = AlokNodeG(X);
	
	if (P != Nil){
		First(*G) = P;
	}


}
adrNode AlokNodeG (int X)
/* Mengembalikan addres hasil alokas simpul*/
{
	//Kamus
	adrNode P;

	//Algoritma
	P = (adrNode) malloc (sizeof(NodeG));

	if (P != Nil) {
		Id(P) = X;
		NPred(P) = 0;
		Trail(P) = Nil;
		NextP(P) = Nil;
	}

	return P;


}
void DealokNodeG (adrNode P)
/*Dealokasi Nodenya*/
{
	free(P);
}
adrSuccNode AlokSuccNode(adrNode Pn)
/*alokasi trail yang menunjuk ke Pn*/
//Kamus
{
	adrSuccNode T;

	//Algoritma
	T = (adrSuccNode) malloc (sizeof(NodeG));

	if (Pn != Nil) {
		Succ(T) = Pn;
		NextT(T) = Nil;
	}

	return T;
}

void DealokSuccNode(adrSuccNode Pt)
/*delaokasi trailnya*/
{
	free(Pt);
}


void InsertNode (Graph *G, infotypeG X, adrNode *P ) {
	/* KAMUS */
	adrNode PLast;
	/* ALGORTIMA */
	PLast = First(*G);
	while (NextP(PLast) != Nil){
		PLast = NextP(PLast);
	}
	*P = AlokNodeG(X);
	if (*P != Nil){
		NextP(PLast) = *P;
	}
}
adrSuccNode SearchTrail(adrNode P, Player Pl)
/*Nyari trail yg mana supaya bisa ke yg selanjutnya *nanti diubah descnya**/
{
	/* KAMUS */
	adrSuccNode Pt;
	boolean found;
	/* ALGORITMA */
	Pt = Trail(P);
	found = false;
	while (!found){
		if (X(Pt) == Absis((Pl).Posisi) && Y(Pt) == Ordinat((Pl).Posisi)){
			found = true;
		} else{
			Pt = NextT(Pt);
		}
	}
	return Pt;
}

adrNode SearchNode (Graph G, int X) {
	/*Kamus*/
	adrNode Pn;
	boolean found;
	/*Algo*/
	found = false;
	Pn = First(G);

	while (Pn != Nil && !(found)) {
		if (Id(Pn) == X) {
			found = true;
		}
		else {
			Pn = NextP(Pn);
		}
	}
	return Pn;
}

void InsertEdge(Graph *G, int Prec, int Succ, int X, int Y) {
	//Kamus
	adrSuccNode Pt, Prev;
	adrNode Ps, Pn;

	//algo
	Ps = SearchNode(*G, Succ);
	Pt = AlokSuccNode(Ps);
	Pn = SearchNode(*G, Prec);

	if (Trail(Pn) == Nil) {
		if (Pt != Nil) {
			Trail(Pn) = Pt;
			X(Pt) = X;
			Y(Pt) = Y;
		}
	}
	else {
		if (Pt != Nil) {
			Prev = Trail(Pn);
			while (NextT(Trail(Pn)) != Nil) {
				Prev = NextT(Prev);
			}
			NextT(Prev) = Pt;
			X(Pt) = X;
			Y(Pt) = Y;

		}
	}
}

void InitGraph (Graph *G) {
	//kamus
	adrNode P;

	CreateGraph(1, G);
	InsertNode(G, 2, &P);
	InsertNode(G, 3, &P);
	InsertNode(G, 4, &P);
	InsertEdge(G, 1, 2, 5, 8);
	InsertEdge(G, 1, 4, 8, 5);
	InsertEdge(G, 2, 1, 3, 1);
	InsertEdge(G, 2, 3, 8, 5);
	InsertEdge(G, 3, 2, 1, 5);
	InsertEdge(G, 3, 4, 3, 1);
	InsertEdge(G, 4, 1, 1, 5);
	InsertEdge(G, 4, 3, 5, 8);


}