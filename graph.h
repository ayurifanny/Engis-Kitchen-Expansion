#ifndef _GRAF_H
#define _GRAF_H

#include "boolean.h"
#include "point.h"
#include "engis.h"
#include <stdlib.h>

#define Nil NULL

typedef int infotypeG;
typedef POINT infotypeTr;

typedef struct tNodeG *adrNode;
typedef struct tSuccNodeG *adrSuccNode;

typedef struct tNodeG {
	int id;
	int NPred;
	adrSuccNode Trail;
	adrNode NextP;
} NodeG;

typedef struct tSuccNodeG {
	adrNode Succ;
	adrSuccNode NextT;
	infotypeTr idT;
} SuccNode;

typedef struct {
	adrNode First;
} Graph;


/*SELEKTOR*/
#define First(G) (G).First
#define Id(Pn) (Pn)->id
#define NPred(Pn) (Pn)->NPred
#define Trail(Pn) (Pn)->Trail
#define NextP(Pn) (Pn)->NextP
#define Succ(Pt) (Pt)->Succ
#define NextT(Pt) (Pt)->NextT
#define X(Pt) (Pt)->idT.X
#define Y(Pt) (Pt)->idT.Y

void CreateGraph (int X, Graph *G);
/*IS : Sembarang
FS : Terbentuk graph dnegan first elemen X*/

adrNode AlokNodeG (int X);
/* Mengembalikan addres hasil alokas simpul*/

void DealokNodeG (adrNode P);
/*Dealokasi Nodenya*/

adrSuccNode AlokSuccNode(adrNode Pn);
/*alokasi trail yang menunjuk ke Pn*/

void DealokSuccNode(adrSuccNode Pt);
/*delaokasi trailnya*/

void InsertNode (Graph *G, infotypeG X, adrNode *P );

adrSuccNode SearchTrail(adrNode P, Player Pl);
/*Nyari trail yg mana supaya bisa ke yg selanjutnya *nanti diubah descnya**/

adrNode SearchNode (Graph G, int X);

void InsertEdge(Graph *G, int Prec, int Succ, int X, int Y);

void InitGraph (Graph *G);
#endif



