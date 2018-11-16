/* MODUL TABEL STRING */
/* Berisi definisi dan semua primitif pemrosesan tabel string */
/* Penempatan elemen selalu rapat kiri */
/* Versi I : dengan banyaknya elemen didefinisikan secara eksplisit, 
   memori tabel statik */

#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <string.h>
#include "boolean.h"
#include "array.h"
#include "mesinkata.h"


/*  Kamus Umum */
#define IdxMax 100
/* Indeks maksimum array, sekaligus ukuran maksimum array dalam C */
#define IdxMin 1
/* Indeks minimum array */
#define IdxUndef -999 
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;  /* type indeks */
typedef Kata ElTypeA[20];   /* type elemen tabel */
typedef struct { 
	ElTypeA TS[IdxMax+1]; /* memori tempat penyimpan elemen (container) */
	int Neff; /* >=0, banyaknya elemen efektif */
} TabInt;
/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses: 
   T.Neff  untuk mengetahui banyaknya elemen 
   T.TS    untuk mengakses seluruh nilai elemen tabel 
   T.TS[i] untuk mengakses elemen ke-i */
/* Definisi : 
  Tabel kosong: T.Neff = 0
  Definisi elemen pertama : T.TS[i] dengan i=1 
  Definisi elemen terakhir yang terdefinisi: T.TS[i] dengan i=T.Neff */
  
/* ********** SELEKTOR ********** */
#define Neff(T)   (T).Neff
#define TS(T)     (T).TS
#define ElmtA(T,i) (T).TS[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
	(*T).Neff = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtA (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
	return T.Neff;
}
/* *** Daya tampung container *** */
int MaxNbEl (TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
	return (IdxMax - IdxMin + 1);
}
/* *** Selektor INDEKS *** */
IdxType GetFirstIdxA (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
	return IdxMin;
}
IdxType GetLastIdxA (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
	return (T.Neff + IdxMin - 1);
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidA (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
	return ((i >= IdxMin) && (i <= IdxMax));
}
boolean IsIdxEffA (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
	return ((i >= GetFirstIdxA(T)) && (i <= GetLastIdxA(T)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyA (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
	return (T.Neff == 0);
}
/* *** Test tabel penuh *** */
boolean IsFullA (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
	return (T.Neff == MaxNbEl(T));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks 
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
	/* KAMUS LOKAL */
	int N;
	IdxType i;
	
	/* ALGORITMA */
	do {
		scanf("%d",&N);
	} while ((N < 0) || (N > MaxNbEl(*T)));
	MakeEmpty(T);
	if (N != 0) {
		for (i = IdxMin; i <= N; i++) {
			scanf("%s",ElmtA(*T,i));
		}
		(*T).Neff = N;
	}
}
void TulisIsi (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/*      Jika T kosong : Hanya menulis "Tabel kosong" */
/* Contoh: Jika isi Tabel: [1, 20, 30, 50]
   Maka tercetak di layar:
   [1]1
   [2]20
   [3]30
   [4]50
*/
{
	/* KAMUS LOKAL */
	IdxType i;
	
	/* ALGORITMA */
	if (IsEmptyA(T))
		printf ("Tabel kosong\n");
	else /* !IsEmptyA(T) */ {
		for (i = IdxMin; i <= GetLastIdxA(T); i++)
			printf ("[%d]%s\n",i,ElmtA(T,i));
	}
}
void TulisIsiTab (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; 
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
	/* KAMUS LOKAL */
	IdxType i;
	
	/* ALGORITMA */
	if (IsEmptyA(T))
		printf ("[]");
	else /* !IsEmptyA(T) */ {
		printf ("[");
		for (i = IdxMin; i <= (GetLastIdxA(T) - 1); i++) {
			printf ("%s,",ElmtA(T,i));
		}
		printf ("%s]",ElmtA(T,i));
	}
}

boolean SearchB (TabInt T, ElTypeA X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Memakai Skema search DENGAN boolean */
{
	/* KAMUS LOKAL */
	boolean Found;
	IdxType i;
	
	/* ALGORITMA */
	if (GetLastIdxA(T) == 0)
		return false;
	else /* GetLastIdxA(T) != 0 */ {
		Found = false;
		i = IdxMin;
		while ((i <= GetLastIdxA(T)) && !Found) {
			if (ElmtA(T,i) == X)
				Found = true;
			else /* ElmtA(T,i) != X */
				i++;
		} /* (i > GetLastIdxA(T) || Found */
		return Found;
	}
}
void AddEli (TabInt * T, ElTypeA X, IdxType i)
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas 
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */
{
	/* KAMUS LOKAL */
	IdxType j;
	
	/* ALGORITMA */
	if (i == GetLastIdxA(*T)) {
		AddAsLastEl(T,X);
	}
	else /* i != GetLastIdxA(*T) */ {
		for (j = GetLastIdxA(*T); j >= i; j--) 
			strcpy(ElmtA(*T,j + 1), ElmtA(*T,j));
		strcpy(ElmtA(*T,i), X);
	}
	(*T).Neff++;
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelEli (TabInt * T, IdxType i, ElTypeA * X)
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */
{
	/* KAMUS LOKAL */
	IdxType j;
	
	/* ALGORITMA */
	strcpy(*X, ElmtA(*T,i));
	if (i != GetLastIdxA(*T))	
	for (j = i; j <= GetLastIdxA(*T); j++)
		strcpy(ElmtA(*T,j), ElmtA(*T,j + 1));
	(*T).Neff--;
}

/* ********** TABEL DGN ELEMEN UNIK (SETIAP ELEMEN HANYA MUNCUL 1 KALI) ********** */



