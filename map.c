#include <stdio.h>
#include "boolean.h"
#include "matriks.h"
#include "engis.h"
#include <math.h>
#include "mesinkar.h"
#include "mesinkata.h"
#include "stackt.h"
#include "map.h"
#include "bintree.h"

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
				printf("%d, %d\n", i, j);
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
				if (CC == 'V')
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
			}
			else if(CC == '0') {
				MChair(*M,i,j) = 0;
				MChairVac(*M,i,j) = 0;
				//MChairNo(*M, i, j) = -1;
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
			
		j++;
		if (j>8) {
			if (i<8){
				i++;
			}
			j = 1;
		}
	}
		
}

void LoadPlayer(Player *P) 
{
	//Kamus
	int i, time, money;
	int sama;
	//Algo
	STARTP();
	sama = 0;
	while ((CC != MARK) && !sama){
		i = 1;
		sama = 1; //boolean sama
		printf("%c\n",Nama(*P, i) );
		while ((CC != '-') && sama) {
			if (Nama(*P, i) == CC) {
				
				i++;
				printf("%c\n",CC );
			}
			else {
				sama = 0;
				
				while (CC != '|') {
					ADV();
				}
				ADV();
			}
		}
	}

		if (sama) {
			ADV();
			Life(*P) = (int) CC - '0';
			ADV(); ADV();
			
			time = (int) CC - '0';
			ADV();
			while (CC != BLANK) {
				time = time * 10;
				time = time + (int) CC - '0';
				ADV();
			}
			Time(*P) = time;
			ADV();
			money = (int) CC - '0';
			ADV();
			while (CC != BLANK) {
				money = money * 10;
				money = money + (int) CC - '0';
				ADV();
			}
			Money(*P) = money;
			ADV();
			PosisiX(*P) = (int) CC - '0';
			ADV(); ADV();
			PosisiY(*P) = (int) CC - '0';
		}
		else {
			
			Life(*P) = 3;
			Time(*P) = 0;
			Money(*P) = 0;
			PosisiX(*P) = 3;
			PosisiY(*P) = 3;
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
		printf("   # ");
		while (j<=8){
			if (PosisiX(*P) == i && PosisiY(*P) == j){
				printf("P  ");
			} else if (MTable(*M, i, j)) {
				if (MTableNum(*M, i, j)<10){
					printf("%d  ", MTableNum(*M, i, j));
				} else {
					printf("%d ", MTableNum(*M, i, j));

				}
			}
			else if (MChair(*M, i, j)) {
				if (MChairVac(*M, i, j)) {
					printf("X  ");
				}
				else if (!MChairVac(*M, i, j))  {
					printf("C  ");
				}
			}
			else if (MStove(*M, i, j)) {
				printf("M  ");
			}
			else if (MTray(*M, i, j)) {
				printf("T  ");
			}
			else{
				printf("   ");
			}
			j++;
		}
		printf(" #\n");
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
	printf("------------------------------------------------------\n");
	printf("   ############################\n");

	PrintDenah(M, P);
	printf("   ############################\n");

	printf("------------------------------------------------------\n");
	//printWaitingCust
	printf("Waiting Cust :\n");

	//printOrder
	printf("Order : \n");

	//printFootStack
	printf("Food Stack: \n");

	//printHand
	printf("Hand : \n");
}

/*ACTIONSSS*/

void GoUp (MATRIKS *M, Player *P)
{
	if (PosisiX(*P)==1) {
		//berarti di ujung atas
		printf("TIDAK BISA GO UP DAH DI ATAS\n");
	}
	else if (!MAvail(*M, (int)PosisiX(*P)-1, (int)PosisiY(*P))){
		printf("TIDAK BISA GO UP ADA SESUATU \n");	
	}
	else {
		//berarti bisa keatas
		PosisiX(*P)--;
		printf("%f, %f", PosisiX(*P), PosisiY(*P));

	}
	Time(*P) ++;
	PrintGame(M, P);
	
}

void GoDown (MATRIKS *M, Player *P)
{
	if (PosisiX(*P)==8) {
		//berarti di ujung atas
		printf("TIDAK BISA GO DOWN UDAH DIBAWAH\n");
	}
	else if (!MAvail(*M, (int)PosisiX(*P)+1, (int)PosisiY(*P))){
		printf("TIDAK BISA GO DOWN ADA SESUATU\n");	
	}
	else {
		//berarti bisa kebawah
		
		PosisiX(*P)++;
		printf("%f, %f", PosisiX(*P), PosisiY(*P));

	}
	Time(*P) ++;
	PrintGame(M, P);
	
}

void PrintStatus(MATRIKS M, Player P) {
	int i, j;

	i = 1;
	if (MAvail(M, (int)PosisiY(P), (int)PosisiX(P))) {
		printf("avail\n");
	}
	else {
		printf("not\n");
	}
	
	
}
void GoLeft (MATRIKS *M, Player *P)
{
		if (PosisiY(*P)==1) {
		//berarti di ujung kiri
		printf("TIDAK BISA GO LEFT UDAH DIKIRI\n");
	}
	else if (!MAvail(*M, (int)PosisiX(*P), (int)PosisiY(*P)-1)){
		printf("TIDAK BISA GO LEFT ADA SESUATU\n");	
	}
	else {
		
		//berarti bisa ke kiri
		PosisiY(*P)--;
		printf("%f, %f", PosisiX(*P), PosisiY(*P));

	}
	Time(*P) ++;
	PrintGame(M, P);
	
}


void GoRight (MATRIKS *M, Player *P)
{
	if (PosisiY(*P)==8) {
		//berarti di ujung atas
		printf("TIDAK BISA GO RIGHT UDAH DIKANAN\n");
	}
	else if (!MAvail(*M, (int)PosisiX(*P), (int)PosisiY(*P)+1)){
		printf("TIDAK BISA GO RIGHT ADA SESUATU\n");	
	}
	else {
		//berarti bisa ke kiri
		
		PosisiY(*P)++;
		printf("%f, %f", PosisiX(*P), PosisiY(*P));

	}
	Time(*P) ++;
	PrintGame(M, P);
	
}

//FOOD MENUS
void LoadMenu(BinTree *Menu) {
    AddDaun(Menu, "Piring", "Sendok", true);
    AddDaun(Menu, "Sendok", "Es Krim", true);
    AddDaun(Menu, "Es Krim", "Pisang", true);
    AddDaun(Menu,  "Pisang", "Banana Split", true);
    AddDaun(Menu, "Es Krim", "Stroberi", false);
    AddDaun(Menu, "Stroberi", "Sundae", true);
    AddDaun(Menu, "Sendok", "Nasi", false);
    AddDaun(Menu, "Nasi", "Telur", true);
    AddDaun(Menu, "Telur", "Nasi Telur Dadar", true);
    AddDaun(Menu, "Nasi", "Ayam Goreng", false);
    AddDaun(Menu, "Ayam Goreng", "Nasi Ayam Goreng", true);
    AddDaun(Menu, "Piring", "Garpu", false);
    AddDaun(Menu, "Garpu", "Roti", true);
    AddDaun(Menu, "Roti", "Patty", true);
    AddDaun(Menu, "Patty", "Burger", true);
    AddDaun(Menu, "Roti", "Sosis", false);
    AddDaun(Menu, "Sosis", "Hot Dog", true);
    AddDaun(Menu, "Garpu", "Spaghetti", false);
    AddDaun(Menu, "Spaghetti", "Bolognese", true);
    AddDaun(Menu, "Bolognese", "Keju", true);
    AddDaun(Menu, "Keju", "Spaghetti Bolognese", true);
    AddDaun(Menu, "Spaghetti", "Carbonara", false);
    AddDaun(Menu, "Carbonara", "Spaghetti Carbonara", true);
    
	//PrintTree(Menu, 4);
}


