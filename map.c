#include <stdio.h>
#include "boolean.h"
#include "matriks.h"
#include "engis.h"
#include <math.h>
#include "mesinkar.h"
#include "mesinkata.h"
#include "stackt.h"
#include "map.h"

void Loadku(MATRIKS *M, int ruang, char pilihan)
/*Membaca file external dan memasukkkan isinya ke matriks
I.S : Sudah terbentuk matriks kosong ukuran 8x8, ruang antara 1-3
F.S : status pada matriks sudan diisi*/
{
	//Kamus
	int i, j,k;
	Stack T;
	
	//Algoritma
	i = 1;
	j = 1;
	
	if (pilihan == 'K') {
		STARTK();
	}
	else if (pilihan == 'R') {
		STARTR();
	}
	//huruf pertama sdh diakuisisi
	while (CC != MARK) {
		
			//load Avail
			if (CC == '1') {
				MAvail(*M,i,j) = 1;
			}
			else {
				MAvail(*M,i,j) = 0;
			}
			ADV();
			ADV();
			//load valid
			if (CC == '1'){
				MValid(*M, i, j) = 1;
				ADV();
				GetIdxObjX(*M, i, j) = (int) CC - '0';
				ADV();
				GetIdxObjY(*M, i, j) = (int) CC - '0';
			} else {
				MValid(*M, i, j) = 0;
				GetIdxObjX(*M, i, j) = -1;
				GetIdxObjY(*M, i, j) = -1;
			}
			ADV();
			ADV();

			//load door
			if (ruang == 1){
				MDoor(*M,5,8) = 1;
				MDoor(*M,8,5) = 1;
			}
			else if (ruang == 2){
				MDoor(*M,3,1) = 1; //masa pintu nya di kursi kalo 2,1 !!???
				MDoor(*M,8,5) = 1;
			}
			else if (ruang == 3) {
				MDoor(*M,1,5) = 1;
				MDoor(*M,3,1) = 1;
			}
			else {
				MDoor(*M,i,j) = 0;
			}
			ADV();
			ADV();

			//loadTable
			if (CC == '1')
			{
				MTable(*M,i,j) = 1;
				ADV();
				if (CC = 'V')
					MTableVac(*M,i,j) = 1;
				ADV();
				MTableNum(*M, i, j) = ((int)CC - '0')+4*(ruang-1);
				ADV();
				k=1;
				//baca makanan
				while ((CC!= BLANK)) {
				    MTableOrder(*M, i, j, k) = CC;
				    ADV();
				    k++;
				  }
			}
			else {
				MTable(*M, i, j) = 0;
				MTableVac(*M,i,j) = 0;
				MTableNum(*M, i, j) = 999;
				MTableOrder(*M, i, j, 1) = '#';
				ADV();
			}


			ADV();

			//load chair
			if (CC == '1'){
				MChair(*M,i,j) = 1;
				ADV();
				if (CC == 'V') {
					MChairVac(*M,i,j) = 1;
				}
				else {
					MChairVac(*M,i,j) = 0;
				}
			ADV();
			MChairNo(*M, i, j) = ((int) CC - '0') + 4*(ruang-1);
			}
			else if(CC == '0') {
				MChair(*M,i,j) = 0;
				MChairVac(*M,i,j) = 0;
				MChairNo(*M, i, j) = -1;
			}
			
			ADV();
			ADV();

			//load stove
			if (CC == '1'){
				MStove(*M,i,j) = 1;
				ADV();
				k=1;
				//baca makanan
				while ((CC!= BLANK)) {
				    MNamaBhn(*M, i, j, k) = CC;
				    ADV();
				    k++;
				  }
			}
			else {
				MStove(*M,i,j) = 0;
				MNamaBhn(*M, i, j, 1) = '#';
				ADV();			
			}

			
			ADV();

			//load tray *perlu di update bila mau bikin save
			if (CC == '0'){
				MTray(*M,i,j) = 0;
			}
			else if (CC == '1'){
				MTray(*M, i, j) = 1;
				//BELOM HANDLE TRAY
				//CreateEmptyS(&T);

			}

			ADV();
			ADV();
			
			//load edges
			if (CC == '1') {
				MEdge(*M, i, j) = 1;
				ADV();

				//belom selesai
				while (CC != '\n') {
					if (CC == 'L'){
						MEdgeL(*M,i,j) = 1;
					}
					else if (CC == 'R') {
						MEdgeR(*M,i,j) = 1;	
					}
					else if (CC == 'U') {
						MEdgeU(*M,i,j) = 1;	
					}
					else if (CC == 'D') {
						MEdgeD(*M,i,j) = 1;	
					}
					ADV();
				}
			}
			else {
				MEdge(*M, i, j) = 0;
				MEdgeL(*M, i, j) = 0;
				MEdgeR(*M, i, j) = 0;
				MEdgeU(*M, i, j) = 0;
				MEdgeD(*M, i, j) = 0;
				ADV();
			}

		ADV();
		j++;
		if (j>8) {
			i++;
			j = 1;
		}
	}
		
}

void PrintDenah(MATRIKS *M, Player *P)
/* I.S : Matriks telah terbentuk, sudah load
F.S : di print ke layar isi dari denah */
{
	//kamus
	int i,j;

	//algoritma
	i=1;

	while (i<=8) {
		j=1;
		while (j<=8){
			//printf("%d %d %d\n", i, j, MTable(*M,i,j));
			if (PosisiX(*P) == i && PosisiY(*P) == j){
				printf("P  ");
			}

			if (MTable(*M, i, j)) {
				printf("%d  ", MTableNum(*M, i,j));
			}
			else if (MChair(*M, i, j)) {
				if (MChairVac(*M,i,j)) {
					printf("X  ");
				}
				else if (!MChairVac(*M,i,j))  {
					printf("C  ");
				}
			}
			else if (MStove(*M, i, j)) {
				printf("M  ");
			}
			else if (MTray(*M, i,j)) {
				printf("T  ");
			}
			else{
				printf("   ");
			}
			j++;
		}
		printf("\n");
		i++;
	}
}

void PrintGame(MATRIKS *M, Player *P)
/*I.S : Matriks valid, player valid*/
/*F.S : Di layar tampil map sesuai keinginan*/
{
	//Kamus
	int i;

	//Print Nama
	i = 1;
	while (i<=NamaLength(*P)) {
		printf("%c", Nama(*P, i));
		i++;
	}

	printf("     ");

	//print money
	printf("Money : ");
	printf("%d", Money(*P));
	printf("     ");

	//print life
	printf("Life : ");
	printf("%d", Life(*P));
	printf("     ");

	//printTime
	printf("Time : ");
	printf("%d\n", Time(*P));
	printf("##########################################\n");

	PrintDenah(M, P);

	//printWaitingCust
	printf("Waiting Cust :\n");

	//printOrder
	printf("Order : \n");

	//printFootStack
	printf("Foot Stack: \n");

	//printHand
	printf("Hand : \n");

}