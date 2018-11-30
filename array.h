/* MODUL TABEL STRING */
/* Berisi definisi dan semua primitif pemrosesan tabel string */
/* Penempatan elemen selalu rapat kiri */
/* Versi I : dengan banyaknya elemen didefinisikan secara eksplisit, 
   memori tabel statik */

#ifndef ARRAY_H
#define ARRAY_H

#include "boolean.h"
#include "mesinkata.h"
#include "engis.h"

/*  Kamus Umum */
#define IdxMax 100
/* Indeks maksimum array, sekaligus ukuran maksimum array dalam C */
#define IdxMin 1
/* Indeks minimum array */
#define IdxUndef -999 
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;  /* type indeks */
typedef struct{
  Kata Food;
  int Nomer;
} ElTypeA;   /* type elemen tabel */

typedef struct { 
  ElTypeA TS[IdxMax+1]; /* memori tempat penyimpan elemen (container) */
  int Neff; /* >=0, banyaknya elemen efektif */
} TabStr;

  
/* ********** SELEKTOR ********** */
#define Neff(T)   (T).Neff
#define TC(T)     (T).TC
#define FoodA(T,i,k) (T).TS[(i)].Food.TabKata[k]
#define FoodAPjg(T,i) (T).TS[(i)].Food.Length
#define NoA(T,i) (T).TS[(i)].Nomer

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabStr * T);
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void PrintArray (TabStr T);


/* ********** TAMBAH/MENGHAPUS ELEMEN ********** */
void AddEli (TabStr * T, IdxType i, ElTypeA X);
void DelEli (TabStr * T, IdxType i, ElTypeA * X);
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */


#endif



