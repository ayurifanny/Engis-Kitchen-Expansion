/* ********** Definisi TYPE MATRIKS dengan indeks integer dan elemen character ********** */

#include <stdio.h>
#include "boolean.h"
#include "matriks.h"
#include "engis.h"
#include <math.h>
#include "mesinkar.h"
#include "mesinkata.h"
#include "stackt.h"

/* Ukuran minimum dan maksimum baris dan kolom */
/*#define BrsMin 1
#define BrsMax 100
#define KolMin 1
#define KolMax 100
*/
/* NBrsEff <= 1 dan NKolEff <= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
	(*M).NBrsEff = NB;
	(*M).NKolEff = NK;
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
	return ((i >= BrsMin) && (i <= BrsMax) && (j >= KolMin) && (j <= KolMax));
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
	return BrsMin;
}
indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
	return KolMin;
}
indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
	return NBrsEff(M);
}
indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
	return NKolEff(M);
}
boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
	return ((i >= BrsMin) && (i <= NBrsEff(M)) && (j >= KolMin) && (j <= NKolEff(M)));
}
ElTypeM GetElmtDiagonal (MATRIKS M, indeks i)
 /*Mengirimkan elemen M(i,i) */
{
	return ElmtM(M,i,i);
}

void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
	/* KAMUS LOKAL */
	indeks i, j;
	
	/* ALGORITMA */
	for (i = BrsMin; i <= GetLastIdxBrs(M); i++) {
		for (j = KolMin; j < GetLastIdxKol(M); j++) {
			printf ("%d ",ElmtM(M,i,j));
		}
		if (i == GetLastIdxBrs(M))
			printf ("%d",ElmtM(M,i,GetLastIdxKol(M)));
		else /* i != GetLastIdxBrs(M) */
			printf ("%d\n",ElmtM(M,i,GetLastIdxKol(M)));
	}
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
/* ********** Operasi lain ********** */
int NBElmtM (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
	return (GetLastIdxBrs(M) * GetLastIdxKol(M));
}

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
				MDoor(*M,2,1) = 1;
				MDoor(*M,8,5) = 1;
			}
			else if (ruang == 3) {
				MDoor(*M,1,5) = 1;
				MDoor(*M,2,1) = 1;
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

void PrintDenah(MATRIKS *M)
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
			if (MTable(*M, i, j)) {
				printf("%d ", MTableNum(*M, i,j));
			}
			else if (MChair(*M, i, j)) {
				if (MChairVac(*M,i,j)) {
					printf("X ");
				}
				else if (!MChairVac(*M,i,j))  {
					printf("C ");
				}
			}
			else if (MStove(*M, i, j)) {
				printf("M ");
			}
			else if (MTray(*M, i,j)) {
				printf("T ");
			}
			else{
				printf("  ");
			}
			j++;
		}
		printf("\n");
		i++;
	}
}
