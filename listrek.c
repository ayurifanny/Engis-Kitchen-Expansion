/* File: listrek.c */
/* ADT list linier dengan representasi pointer */
/* Implementasi list linier secara rekursif */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"
#include "listrek.h"

/* Deklarasi  nama untuk variabel kerja */ 
/*  	L : List */
/*  	P : address 	*/
/* Maka penulisan First(L) menjadi L */
/*                P.info menjadi Info(P); P.next menjadi Next(P) */

/* Selektor */
#define Info(P) (P)->info
#define Next(P) (P)->next

/* *** Manajemen Memori *** */
address AlokasiT (infotypeT X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, 
  maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	/* KAMUS LOKAL */
	address P;
	
	/* ALGORITMA */
	P = (address) malloc (sizeof (ElmtListR));
	if (P != Nil) {
		strcpy(Info(P), X);
		Next(P) = Nil;
	}
	return P;
}
void DealokasiT (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
	free(P);
}

/* *** Primitif-primitif yang harus direalisasikan *** */

/* Pemeriksaan Kondisi List */
int IsEmpty(ListR L)
/* Mengirimkan 1 jika L kosong dan 0 jika L tidak kosong */
{
	if (L == Nil)
		return 1;
	else /* L != Nil */
		return 0;
}
int IsOneElmt(ListR L)
/* Mengirimkan 1 jika L berisi 1 elemen dan 0 jika > 1 elemen atau kosong */
{
	if (L != Nil) {
		if (Next(L) == Nil)
			return 1;
		else /* Next(L) != Nil */
			return 0;
	}
	else /* L == Nil */
		return 0;
}

ListR TailR(ListR L)
/* Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong */
{
	return Next(L);
}

/* *** Konstruktor *** */
ListR Konso(infotypeT e, ListR L)
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya. 
e dialokasi terlebih dahulu. Jika alokasi gagal, mengirimkan L. */
{
	/* KAMUS LOKAL */
	address P;
	
	/* ALGORITMA */
	P = AlokasiT(e);
	if (P == Nil)
		return L;
	else /* P != Nil */ {
		/* Insert First */
		Next(P) = L;
		return P;
	}
}
ListR KonsB(ListR L, infotypeT e)
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */ 
{
	if (IsEmpty(L))
		return AlokasiT(e);
	else /* !IsEmpty(L) */ {
		Next(L) = KonsB(TailR(L), e);
		return L;
	}
}

/* *** Operasi Lain *** */
ListR Copy (ListR L)
/* Mengirimkan salinan list L (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan L */
{
	if (IsEmpty(L)) /* Basis 0 */
		return Nil;
	else /* !IsEmpty(L) */ /* Rekurens */
		return Konso(Info(L), Copy(TailR(L)));
}
void MCopy (ListR Lin, ListR *Lout)
/* I.S. Lin terdefinisi */
/* F.S. Lout berisi salinan dari Lin */
/* Proses : menyalin Lin ke Lout */
{
	/* KAMUS LOKAL */
	ListR LTemp;
	
	/* ALGORITMA */
	if (IsEmpty(Lin)) /* Basis 0 */
		*Lout = Nil;
	else /* !IsEmpty(Lin) */ /* Rekurens */ {
		MCopy(TailR(Lin), &LTemp);
		*Lout = Konso(Info(Lin), LTemp);
	}
}
ListR Concat (ListR L1, ListR L2)
/* Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan Nil */
{
	if (IsEmpty(L1)) /* Basis 0 */
		return Copy(L2);
	else /* !IsEmpty(L1) */ /* Rekurens */
		return Konso(Info(L1), Concat(TailR(L1), L2));
}
void MConcat (ListR L1, ListR L2, ListR *LHsl)
/* I.S. L1, L2 terdefinisi */
/* F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin" */
/* Proses : Menghasilkan salinan hasil konkatenasi list L1 dan L2 */
{
	/* KAMUS LOKAL */
	ListR LTemp;
	
	/* ALGORITMA */
	if (IsEmpty(L1)) /* Basis 0 */
		*LHsl = Copy(L2);
	else /* !IsEmpty(L1) */ /* Rekurens */ {
		MConcat(TailR(L1), L2, &LTemp);
		*LHsl = Konso(Info(L1), LTemp);
	}
}
void PrintList (ListR L)
/* I.S. L terdefinisi. */
/* F.S. Setiap elemen list dicetak. */
{
	if (IsEmpty(L)) {
		/* Tidak melakukan apa-apa */
	}
	else /* !IsEmpty(L) */ {
		printf ("%s\n",Info(L));
		PrintList(TailR(L));
	}
}
int NbElmtList (ListR L)
/* Mengirimkan banyaknya elemen list L, Nol jika L kosong */
{
	if (IsEmpty(L)) /* Basis 0 */
		return 0;
	else /* !IsEmpty(L) */ /* Rekurens */
		return (1 + NbElmtList(TailR(L)));
}
boolean SearchR (ListR L, infotypeT X)
/* Mengirim true jika X adalah anggota list, false jika tidak */
{
	if (IsEmpty(L)) /* Basis 0 */
		return false;
	else /* !IsEmpty(L) */ /* Rekurens */ {
		if (Info(L) == X)
			return true;
		else /* Info(L) != X */
			return SearchR(TailR(L), X);
	}
}
