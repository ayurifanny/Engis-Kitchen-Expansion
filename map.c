#include <stdio.h>
#include "map.h"
#include "engis.h"

void Loadku(MATRIKS *M, int ruang, char pilihan)
/*Membaca file external dan memasukkkan isinya ke matriks
I.S : Sudah terbentuk matriks kosong ukuran 8x8, ruang antara 1-3
F.S : status pada matriks sudan diisi*/
{
	//Kamus
	int i, j,k;
	
	//Algoritma
	i = 1;
	j = 1;
	
	//Apa akan load Kitchen atau Ruangan
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
				GetIdxObjX(*M, i, j) =  CC - '0';
				ADV();
				GetIdxObjY(*M, i, j) =  CC - '0';
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
				MDoor(*M,3,1) = 1; //masa pintu nya di kursi kalo 2,1 !!??? di 3,1 aja lah ya
				MDoor(*M,8,5) = 1;
			}
			else if (ruang == 3) {
				MDoor(*M,1,5) = 1;
				MDoor(*M,3,1) = 1;
			}
			else if(ruang == -1){
				MDoor(*M, 1, 5) = 1;
				MDoor(*M, 5, 8) = 1;
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
				MTableNum(*M, i, j) = (CC - '0')+4*(ruang-1);
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
				k =1;
				if (CC == 'a'){
					CopyBahan(M, "Piring", 6, i, j);
				}
				else if (CC == 'b'){
					CopyBahan(M, "Sendok", 6, i, j);
				}
				else if (CC == 'c'){
					CopyBahan(M, "Garpu", 5, i, j);
				}
				else if (CC == 'd'){
					CopyBahan(M, "Es Krim", 7, i, j);
				}
				else if (CC == 'e'){
					CopyBahan(M, "Nasi", 4, i, j);
				}
				else if (CC == 'f'){
					CopyBahan(M, "Roti", 4, i, j);
				}
				else if (CC == 'g'){
					CopyBahan(M, "Spaghetti", 9, i, j);
				}
				else if (CC == 'h'){
					CopyBahan(M, "Pisang", 6, i, j);
				}
				else if (CC == 'i'){
					CopyBahan(M, "Stroberi", 8, i, j);
				}
				else if (CC == 'j'){
					CopyBahan(M, "Telur", 5, i, j);
				}
				else if (CC == 'k'){
					CopyBahan(M, "Ayam Goreng", 11, i, j);
				}
				else if (CC == 'l'){
					CopyBahan(M, "Patty", 5, i, j);
				}
				else if (CC == 'm'){
					CopyBahan(M, "Sosis", 5, i, j);
				}
				else if (CC == 'n'){
					CopyBahan(M, "Bolognese", 9, i, j);
				}
				else if (CC == 'o'){
					CopyBahan(M, "Carbonara", 9, i, j);
				}
				else if (CC == 'p'){
					CopyBahan(M, "Keju", 4, i, j);
				}
            }
				
			else {
				MStove(*M,i,j) = 0;
				MNamaBhn(*M, i, j, 1) = '#';
							
			}

			ADV();
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
	
	Life(*P) = 5;
	Time(*P) = MakeJAM(0, 0, 0);
	Money(*P) = 0;
	Absis((*P).Posisi) = 3;
	Ordinat((*P).Posisi) = 3;

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
			if (Absis((*P).Posisi) == i && Ordinat((*P).Posisi) == j){
				printf("P  ");
				//jika tabel
			} else if (MTable(*M, i, j)) {
				if (MTableNum(*M, i, j)<10){
					printf("%d  ", MTableNum(*M, i, j));
				} else {
					printf("%d ", MTableNum(*M, i, j));
				}
			}
			//jika kursi
			else if (MChair(*M, i, j)) {
				if (MChairVac(*M, i, j)) {
					printf("X  ");
				}
				else if (!MChairVac(*M, i, j))  {
					printf("C  ");
				}
			}
			//jika stove
			else if (MStove(*M, i, j)) {
				printf("M  ");
			}
			//jika tray
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

void PrintGame(MATRIKS *M, MATRIKS *MK, Player *P, Queue Q, TabStr O)
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
	TulisJAM(Time(*P));
	printf("\n");
	printf("------------------------------------------------------\n");
	printf("   ############################\n");

	PrintDenah(M, P);
	printf("   ############################\n");

	printf("------------------------------------------------------\n");
	//printWaitingCust
	printf("Waiting Cust :\n");
	PrintQueue(Q);
	printf("\n");

	//printOrder
	printf("Order : \n");
	PrintArray(O);
	printf("\n");

	//printFoodStack
	printf("Food Stack: \n");
	PrintStack(MT(*MK,1,8));
	printf("\n");

	//printHand
	printf("Hand : \n");
	PrintStack(Hand(*P));
	printf("\n");
}
/*ACTIONSSS*/

void GoUp (MATRIKS *M, Player *P, Graph G, int *n)
/*I.S : Pemain berada di indeks yang available, semua sudah terdefinisi
F.S : Pemain bisa berpindah ke atas jika di atasnya available. Jika tidak, diberi pesan kesalahan*/
{
	//KAMUS
	adrNode Pn;
	adrSuccNode Pt;

	//ALGORITMA
	if (Absis((*P).Posisi) == 1 && Ordinat((*P).Posisi) == 5) {
		if (MDoor(*M, Absis((*P).Posisi), Ordinat((*P).Posisi))) {
			Pn = SearchNode(G,*n);
			Pt = SearchTrail(Pn, *P);
			Pn = Succ(Pt);
			*n = Id(Pn);
			Absis((*P).Posisi) = 8;
			Ordinat((*P).Posisi) = 5;
		}
	}
	else if (Absis((*P).Posisi)==1) {
		//berarti di ujung atas
		printf("TIDAK BISA GO UP DAH DI ATAS\n");
	}
	else if (!MAvail(*M, Absis((*P).Posisi)-1, Ordinat((*P).Posisi))){
		printf("TIDAK BISA GO UP ADA SESUATU \n");	
	}
	else {
		//berarti bisa keatas
		Geser(&(*P).Posisi, -1.0, 0.0);
		printf("%d, %d", Absis((*P).Posisi), Ordinat((*P).Posisi));

	}
	printf("%d, %d\n", Absis((*P).Posisi), Ordinat((*P).Posisi) );
	
}

void GoDown (MATRIKS *M, Player *P, Graph G, int *n)
/*I.S : Pemain berada di indeks yang available, semua sudah terdefinisi
F.S : Pemain bisa berpindah ke BAWAH jika di BAWAHnya available. Jika tidak, diberi pesan kesalahan*/

{
	//KAMUS
	adrNode Pn;
	adrSuccNode Pt;
	
	//ALGORITMA
	if (Absis((*P).Posisi) == 8 && Ordinat((*P).Posisi) == 5) {
		if (MDoor(*M, Absis((*P).Posisi), Ordinat((*P).Posisi))) {
			Pn = SearchNode(G,*n);
			Pt = SearchTrail(Pn, *P);
			Pn = Succ(Pt);
			*n = Id(Pn);
			Absis((*P).Posisi) = 1;
			Ordinat((*P).Posisi) = 5;
		}
	}
	else if (Absis((*P).Posisi)==8) {
		//berarti di ujung atas
		printf("TIDAK BISA GO DOWN UDAH DIBAWAH\n");
	}
	else if (!MAvail(*M, Absis((*P).Posisi)+1, Ordinat((*P).Posisi))){
		printf("TIDAK BISA GO DOWN ADA SESUATU\n");	
	}
	else {
		//berarti bisa kebawah
		
		Geser(&(*P).Posisi, 1, 0);
		printf("%d, %d", Absis((*P).Posisi), Ordinat((*P).Posisi));

	}
	
}

void GoLeft (MATRIKS *M, Player *P, Graph G, int *n)
/*I.S : Pemain berada di indeks yang available, semua sudah terdefinisi
F.S : Pemain bisa berpindah ke KIRI jika di KIRInya available. Jika tidak, diberi pesan kesalahan*/

{
	//KAMUS
	adrNode Pn;
	adrSuccNode Pt;

	//ALGORITMA
	if (Absis((*P).Posisi) == 3 && Ordinat((*P).Posisi) == 1) {
		if (MDoor(*M, Absis((*P).Posisi), Ordinat((*P).Posisi))) {
			Pn = SearchNode(G,*n);
			Pt = SearchTrail(Pn, *P);
			Pn = Succ(Pt);
			*n = Id(Pn);
			Absis((*P).Posisi) = 5;
			Ordinat((*P).Posisi) = 8;
		}
	}	
	else if (Ordinat((*P).Posisi)==1) {
		//berarti di ujung kiri
		printf("TIDAK BISA GO LEFT UDAH DIKIRI\n");
	}
	else if (!MAvail(*M, Absis((*P).Posisi), Ordinat((*P).Posisi)-1)){
		printf("TIDAK BISA GO LEFT ADA SESUATU\n");	
	}
	else {
		
		//berarti bisa ke kiri
		Geser(&(*P).Posisi, 0, -1);
		printf("%d, %d", Absis((*P).Posisi), Ordinat((*P).Posisi));

	}
	
}


void GoRight (MATRIKS *M, Player *P, Graph G, int *n)
/*I.S : Pemain berada di indeks yang available, semua sudah terdefinisi
F.S : Pemain bisa berpindah ke KANAN jika di KANANnya available. Jika tidak, diberi pesan kesalahan*/
{
	//KAMUS
	adrNode Pn;
	adrSuccNode Pt;

	//ALGORITMA
	if (Absis((*P).Posisi) == 5 && Ordinat((*P).Posisi) == 8) {
		if (MDoor(*M, Absis((*P).Posisi), Ordinat((*P).Posisi))) {
			Pn = SearchNode(G,*n);
			Pt = SearchTrail(Pn, *P);
			Pn = Succ(Pt);
			*n = Id(Pn);
			Absis((*P).Posisi) = 3;
			Ordinat((*P).Posisi) = 1;
		}
	}
	else if (Ordinat((*P).Posisi)==8) {
		//berarti di ujung atas
		printf("TIDAK BISA GO RIGHT UDAH DIKANAN\n");
	}
	else if (!MAvail(*M, Absis((*P).Posisi), Ordinat((*P).Posisi)+1)){
		printf("TIDAK BISA GO RIGHT ADA SESUATU\n");	
	}
	else {
		//berarti bisa ke kiri
		
		Geser(&(*P).Posisi, 0, 1);
		printf("%d, %d", Absis((*P).Posisi), Ordinat((*P).Posisi));

	}
	
}

//FOOD MENUS
void LoadMenu(BinTree *Menu) 
/*I.S : BINTREE TELAH DI MAKE
F.S : DAUN DAUN BINTREE DIISI DENGAN MENU */
{
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
    
}


void CopyBahan (MATRIKS *M, char c[], int i, int X, int Y)
/*I.S : C merupakan string makanan yang akan di masukkan ke identitas namabahan
F.S : nama bahan di tiap-tiap stove telah terisi */

{
	//Kamus
	int j;

	//Algoritma
	for (j = 1; j<=i; j++) {
		MNamaBhn(*M, X, Y, j) = c[j-1];
	}
	MNamaBhnPjg(*M, X, Y) = i;
}


void PrintBahan(MATRIKS M) 
/*I.S : Matriks M telah di load
F.S : Print bahan2 apa saja yang ada di stove*/
{
	//Kamus
	int i,j, k;

	//Algoritma
	i = 1;
	while (i<=8) {
		j = 1;
		while (j <= 8) {
			if (MStove(M, i, j)) {
				printf("%d, %d :", i, j );
				k=1;
				while (k <= MNamaBhnPjg(M, i, j)) {
					printf("%c", MNamaBhn(M, i, j, k) );
					k++;
				}
				printf("\n");
			}
			j++;
		}
		i++;
	}
}
