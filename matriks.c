/* ********** Definisi TYPE MATRIKS dengan indeks integer dan elemen character ********** */

#include <stdio.h>
#include "boolean.h"
#include "matriks.h"
#include "engis.h"
#include <math.h>

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

