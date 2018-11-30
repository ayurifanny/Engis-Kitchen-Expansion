#include "boolean.h"
#include "point.h"
#include <stdio.h>

//DRIVER Point

int main() {
	//Kamus
	int X, Y;
	POINT P;

	//Algoritma
	scanf("%d", &X); //menerima inputan absis
	scanf("%d", &Y); //menerima inputan ordinat
	P = MakePOINT(X, Y); //membuat point dengan absis dan ordinat yg telah dibaca

	Geser(&P, -1, 4); //menggeser point
	printf("%d, %d", Absis(P), Ordinat(P)); //menuliskan point ke layar

	return 0;
}
