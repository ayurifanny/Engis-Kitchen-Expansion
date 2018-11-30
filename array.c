/* MODUL TABEL STRING */
/* Berisi definisi dan semua primitif pemrosesan tabel string */
/* Penempatan elemen selalu rapat kiri */
/* Versi I : dengan banyaknya elemen didefinisikan secara eksplisit, 
   memori tabel statik */

#include <stdio.h>
#include "boolean.h"
#include "array.h"
#include "mesinkata.h"


/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabStr * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
	/* KAMUS */
	int i;
	/* ALGORITMA */
	(*T).Neff = 12;
	for (i=1;i<=12;i++){
		FoodA(*T,i,1) = '#';
		FoodAPjg(*T,i) = 1;
		NoA(*T,i) = i;
	}
	
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void PrintArray (TabStr T){
	/* KAMUS */
	int i, j;
	/* ALGORITMA */
	for (i=1;i<=Neff(T);i++){
		if (FoodA(T,i,1) != '#'){
			for(j=1;j<=FoodAPjg(T,i);j++){
				printf("%c", FoodA(T,i,j));
			}
			printf(", %d\n", NoA(T,i));
		}
	}
}

/* ********** MENGHAPUS ELEMEN ********** */
void AddEli (TabStr * T, IdxType i, ElTypeA X)
{
	/* KAMUS LOKAL */
	int j;
	
	/* ALGORTIMA */
	FoodAPjg(*T,i) = X.Food.Length;
	for (j=1;j<=FoodAPjg(*T,i);j++){
		FoodA(*T,i,j) = X.Food.TabKata[j];
	}
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelEli (TabStr * T, IdxType i, ElTypeA * X)
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/* Proses : Mengubah isi menjadi '#' */
{
	/* KAMUS LOKAL */
	IdxType j;
	
	/* ALGORITMA */
	(*X).Food.Length = FoodAPjg(*T,i);
	for (j=1;j<=FoodAPjg(*T,i);j++){
		(*X).Food.TabKata[j] = FoodA(*T,i,j);
	}
	FoodAPjg(*T,i) = 1;
	FoodA(*T,i,1) = '#';
}

