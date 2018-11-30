
#include <stdio.h>

#include "map.h"


int main () {
	MATRIKS M;
	int X, Y,i;
	char choice;
	Player P;

	MakeMATRIKS(9,9, &M);
	
	//initialisasi denahnya
	X  = 1;

	while(X <= 8) {
		Y =1;
		while (Y <= 8){
			MAvail(M, X, Y ) = 0;
			MTable(M, X, Y) =0;
			MChair(M, X, Y) = 0;
			MStove(M, X, Y) =0;
			MTray(M, X, Y) = 0;
			Y++;
		}
		X++;
	}


	printf("Mau meja di indeks berapa? Antara 1-8 ya!\n");
	scanf("%d", &X);
	scanf("%d", &Y);

	MTable(M,X,Y) = 1;
	MTableVac(M, X, Y) = 1;
	MTableNum(M, X, Y) = 10;
	
	printf("Mau kursi di indeks berapa? Antara 1-8 ya! dan jangan yg udah dipakai!\n");
	scanf("%d", &X);
	scanf("%d", &Y);
	printf("Mau kursinya kosong apa ngga? 'y' kalau mau kosong, 'n' kalau ga mau\n");
	scanf("%c", &choice);

	MChair(M, X, Y) = 1;
	if (choice == 'y') {
		MChairVac(M, X, Y) = 1;
	}
	else {
		MChairVac(M, X, Y) = 0;
	}	

	Nama(P,1) = 'd';
	Nama(P,2) = 'u';
	Nama(P,3) = 'm';
	Nama(P,4) = 'm';
	Nama(P,5) = 'y';
	NamaLength(P) =5;

	printf("Mau posisi player di indeks berapa? Antara 1-8 ya! dan jangan yg udah dipakai!\n");
	scanf("%d", &X);
	scanf("%d", &Y);

	PosisiX(P) = X;
	PosisiY(P) = Y;

	Life(P) = 3;
	Time(P) = 0;
	Money(P) = 100;

	printf("Ini denahmu!\n");
	i = 1;
	while (i<=NamaLength(P)) {
		printf("%c", Nama(P, i));
		i++;
	}

	printf("     ");

	//print money
	printf("Money : ");
	printf("%d", Money(P));
	printf("     ");

	//print life
	printf("Life : ");
	printf("%d", Life(P));
	printf("     ");

	//printTime
	printf("Time : ");
	printf("%d\n", Time(P));
	printf("------------------------------------------------------\n");
	printf("   ############################\n");
	PrintDenah(&M, &P);
	printf("   ############################\n");
	return 0;

}