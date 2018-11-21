#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bintree.h"
#include "listrek.h"


/* *** Konstruktor *** */
BinTree Tree (infotypeT Akar, BinTree L, BinTree R)
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
{
	/* KAMUS LOKAL */
	BinTree T;
	
	/* ALGORITMA */
	T = (BinTree) malloc(sizeof(Node));
	if (T != Nil) {
		strcpy(Akar(T), Akar);
		Left(T) = L;
		Right(T) = R;
	}
	return T; 
}
void MakeTree (infotypeT Akar, BinTree L, BinTree R, BinTree *P)
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R
		jika alokasi berhasil. P = Nil jika alokasi gagal. */
{
	*P = Tree(Akar, L, R);
}


/* Manajemen Memory */
addrNode AlokNode (infotypeT X)
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P,
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	addrNode N = (addrNode) malloc(sizeof(Node));
	if (N != Nil) {
		strcpy(Akar(N), X);
		Left(N) = Nil;
		Right(N) = Nil;
	}
	return N;
}
void DealokNode (addrNode P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */
{
	free(P);
}

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty (BinTree P)
/* Mengirimkan true jika P adalah pohon biner kosong */
{
	return P == Nil;
}
boolean IsTreeOneElmt (BinTree P)
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
{
	return ((P != Nil) && (Left(P) == Nil) && (Right(P) == Nil));
}
boolean IsUnerLeft (BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
{
	return ((P != Nil) && (Left(P) != Nil) && (Right(P) == Nil));
}
boolean IsUnerRight (BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
{
	return ((P != Nil) && (Left(P) == Nil) && (Right(P) != Nil));
}
boolean IsBiner (BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/
{
	return ((P != Nil) && (Left(P) != Nil) && (Right(P) != Nil));
}

/* *** Traversal *** */
void PrintPreorder (BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
{
	printf("(");
	if (!IsTreeEmpty(P)) {
		printf("%s", Akar(P));
		PrintPreorder(Left(P));
		PrintPreorder(Right(P));
	}
	printf(")");
}
void PrintInorder (BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
{
	printf("(");
	if (!IsTreeEmpty(P)) {
		PrintInorder(Left(P));
		printf("%s", Akar(P));
		PrintInorder(Right(P));
	}
	printf(")");
}
void PrintPostorder (BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
{
	printf("(");
	if (!IsTreeEmpty(P)) {
		PrintPostorder(Left(P));
		PrintPostorder(Right(P));
		printf("%s", Akar(P));
	}
	printf(")");
}
void PrintTree (BinTree P, int h)
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
{
	if (!IsTreeEmpty(P)) {
		printf("%s\n", Akar(P));
		if (!IsTreeEmpty(Left(P))) {
			printf("%*s", h, " ");
			PrintTree(Left(P), 2 * h);
        }
        if (!IsTreeEmpty(Right(P))) {
			printf("%*s", h, " ");
			PrintTree(Right(P), 2 * h);
		}
	}
}

/* *** Searching *** */
boolean SearchTree (BinTree P, infotypeT X)
/* Mengirimkan true jika ada node dari P yang bernilai X */
{
	if (IsTreeEmpty(P))
		return false;
	else /* !IsTreeEmpty(P) */ {
		if (Akar(P) == X)
			return true;
		return SearchTree(Left(P), X) || SearchTree(Right(P), X);
	}
}

/* *** Fungsi-Fungsi Lain *** */
int NbElmtT (BinTree P)
/* Mengirimkan banyaknya elemen (node) pohon biner P */
{
	if (IsTreeEmpty(P))
		return 0;
	else /* !IsTreeEmpty(P) */
		return 1 + NbElmtT(Left(P)) + NbElmtT(Right(P));
}
int NbDaun (BinTree P)
/* Mengirimkan banyaknya daun (node) pohon biner P */
/* Prekondisi: P tidak kosong */
{
    if (IsTreeOneElmt(P))
        return 1;
    else /* !IsTreeOneElmt(P) */ {
		if (IsUnerLeft(P))
			return NbDaun(Left(P));
		else if (IsUnerRight(P))
            return NbDaun(Right(P));
		return NbDaun(Left(P)) + NbDaun(Right(P));
	}
}
boolean IsSkewLeft (BinTree P)
/* Mengirimkan true jika P adalah pohon condong kiri */
/* Pohon kosong adalah pohon condong kiri */
{
	if (IsTreeEmpty(P))
		return true;
	else /* !IsTreeEmpty(P) */ {
		if (!IsTreeEmpty(Right(P)))
			return false;
		else /* IsTreeEmpty(Right(P)) */
			return IsSkewLeft(Left(P));
	}
}
boolean IsSkewRight (BinTree P)
/* Mengirimkan true jika P adalah pohon condong kanan */
/* Pohon kosong adalah pohon condong kanan */
{
	if (IsTreeEmpty(P))
		return true;
	else /* !IsTreeEmpty(P) */ {
		if (!IsTreeEmpty(Left(P)))
			return false;
		else /* IsTreeEmpty(Left(P)) */
			return IsSkewRight(Right(P));
    }
}
int Level (BinTree P, infotypeT X)
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P.
   Akar(P) level-nya adalah 1. Pohon P tidak kosong. */
{
	if (Akar(P) == X)
		return 1;
    else /* Akar(P) != X */ {
		if (IsUnerLeft(P))
			return 1 + Level(Left(P), X);
		else if (IsUnerRight(P))
			return 1 + Level(Right(P), X);
		if (SearchTree(Left(P), X))
			return 1 + Level(Left(P), X);
		else /* !SearchTree(Left(P), X) */
			return 1 + Level(Right(P), X);
    }
}
int Tinggi (BinTree P)
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim "height" yaitu tinggi dari pohon */
{
	/* KAMUS LOKAL */
	int l, r;
	
	/* ALGORITMA */
	if (IsTreeEmpty(P))
		return 0;
	else /* !IsTreeEmpty(P) */{
		l = 1 + Tinggi(Left(P));
		r = 1 + Tinggi(Right(P));
		if (l > r)
			return l;
		else /* l <= r */
			return r;
    }
}

/* *** Operasi lain *** */
void AddDaunTerkiri (BinTree *P, infotypeT X)
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
{
	if (IsTreeEmpty(*P))
		*P = AlokNode(X);
	else /* !IsTreeEmpty(P) */
		AddDaunTerkiri(&Left(*P), X);
}
void AddDaun (BinTree *P, infotypeT X, infotypeT Y, boolean Kiri)
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau
        sebagai anak Kanan X (jika Kiri = false) */
/*		Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */
{
	if (!IsTreeEmpty(*P)) {
		if (!strcmp(Akar(*P), X)) {
			if (Kiri) {
				Left(*P)= Tree(Y, Nil, Nil);
			} else {
				Right(*P)= Tree(Y, Nil, Nil);
			}
		} else {
			AddDaun(&Left(*P), X, Y, Kiri);
			AddDaun(&Right(*P), X, Y, Kiri);
		}
	}
}
void DelDaunTerkiri (BinTree *P, infotypeT *X)
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula
        disimpan pada daun terkiri yang dihapus */
{
	if (IsTreeOneElmt(*P)) {
		strcpy(*X, Akar(*P));
		BinTree B = *P;
		*P = Nil;
		DealokNode(B);
	}
	else /* !IsTreeOneElmt(*P) */ {
		if (IsUnerLeft(*P))
			DelDaunTerkiri(&Left(*P), X);
        else if (IsUnerRight(*P))
			DelDaunTerkiri(&Right(*P), X);
		else if (IsBiner(*P))
			DelDaunTerkiri(&Left(*P), X);
	}
}
void DelDaun (BinTree *P, infotypeT X)
/* I.S. P tidak kosong, minimum ada 1 daun bernilai X. */
/* F.S. Semua daun bernilai X dihapus dari P. */
{
	if (IsTreeOneElmt(*P)) {
		if (Akar(*P) == X) {
			BinTree B = *P;
			*P = Nil;
			DealokNode(B);
		}
	}
	else /* !IsTreeOneElmt(*P) */ {
		if (IsUnerLeft(*P))
			DelDaun(&Left(*P), X);
		else if (IsUnerRight(*P))
			DelDaun(&Right(*P), X);
		else /* !IsUnerLeft(*P) && !IsUnerRight(*P) */ {
			DelDaun(&Left(*P), X);
			DelDaun(&Right(*P), X);
        }
	}
}
ListR MakeListDaun (BinTree P)
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua daun pohon P,
   jika semua alokasi list berhasil.
   Daun terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
   Menghasilkan list kosong jika ada alokasi yang gagal. */
{
	if (IsTreeEmpty(P))
		return Nil;
	else if (IsTreeOneElmt(P))
		return AlokasiT(Akar(P));
	else /* !IsTreeEmpty(P) && !IsTreeOneElmt(P) */
		return Concat(MakeListDaun(Left(P)), MakeListDaun(Right(P)));
}
ListR MakeListPreorder (BinTree P)
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P
   dengan urutan preorder, jika semua alokasi berhasil.
   Menghasilkan list kosong jika ada alokasi yang gagal. */
{
	if (IsTreeEmpty(P))
		return Nil;
    else /* !IsTreeEmpty(P) */
		return Konso(Akar(P), Concat(MakeListPreorder(Left(P)), MakeListPreorder(Right(P))));
}
ListR MakeListLevel (BinTree P, int N)
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P
   yang levelnya=N, jika semua alokasi berhasil.
   Elemen terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
   Menghasilkan list kosong jika ada alokasi yang gagal. */
{
	if (IsTreeEmpty(P))
		return Nil;
	else /* !IsTreEmpty(P) */ {
		if (N > 1)
			return Concat(MakeListLevel(Left(P), N - 1), MakeListLevel(Right(P), N - 1));
		else /* N <= 1 */
			return AlokasiT(Akar(P));
	}
}
