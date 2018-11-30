#ifndef _MAPH_
#define _MAPH_

#include <stdio.h>
#include "boolean.h"
#include "matriks.h"
#include <math.h>
#include "mesinkar.h"
#include "mesinkata.h"
#include "stackt.h"
#include "map.h"
#include "bintree.h"
#include "queue.h"
#include "engis.h"
#include "graph.h"
#include "array.h"
#include "jam.h"


void Loadku(MATRIKS *M, int ruang, char pilihan);
/*Membaca file external dan memasukkkan isinya ke matriks
I.S : Sudah terbentuk matriks kosong ukuran 8x8, ruang antara 1 - 3
F.S : status pada matriks sudan diisi*/

void LoadPlayer (Player *P);
/* 
	NTAH JADI DIPAKE APA NGGAK
*/
void PrintDenah(MATRIKS *M, Player *P);
/* I.S : Matriks telah terbentuk, sudah load
	F.S : di print ke layar isi dari denah */

void PrintGame(MATRIKS *M, MATRIKS *MK, Player *P, Queue Q, TabStr O);
/* I.S : Matriks sudah terdefinisi, Peta dan Player sudah di load
	F.s : Status game sudah di print di layar*/

void GoUp (MATRIKS *M, Player *P, Graph G, int *n);
/* I.S : Player berada di matriks yang statusnya Avail
	F.S : Apa bila berhasil : Player bergerak ke atas sebesar satu
		  Bila tidak berhasil : Player berada tetap di tempatnya
		  Waktu bertambah 1 tick
		  Kesabaran customer berkurang 1*/
void GoDown (MATRIKS *M, Player *P, Graph G, int *n);
/* I.S : Player berada di matriks yang statusnya Avail
	F.S : Apa bila berhasil : Player bergerak ke bawah sebesar satu
		  Bila tidak berhasil : Player berada tetap di tempatnya
		  Waktu bertambah 1 tick
		  Kesabaran customer berkurang 1*/
void GoLeft (MATRIKS *M, Player *P, Graph G, int *n);
/* I.S : Player berada di matriks yang statusnya Avail
	F.S : Apa bila berhasil : Player bergerak ke kiri sebesar satu
		  Bila tidak berhasil : Player berada tetap di tempatnya
		  Waktu bertambah 1 tick
		  Kesabaran customer berkurang 1*/
void GoRight (MATRIKS *M, Player *P, Graph G, int *n);
/* I.S : Player berada di matriks yang statusnya Avail
	F.S : Apa bila berhasil : Player bergerak ke kanan sebesar satu
		  Bila tidak berhasil : Player berada tetap di tempatnya
		  Waktu bertambah 1 tick
		  Kesabaran customer berkurang 1*/
void LoadMenu(BinTree *Menu);
/* I.S : Bintree Menu telah terbentuk
	F.S : Bintre Menu di isi dengan menu makanan*/
void CopyBahan (MATRIKS *M, char c[], int i, int X, int Y);
/*I.S : C merupakan string makanan yang akan di masukkan ke identitas namabahan
F.S : nama bahan di tiap-tiap stove telah terisi */

void PrintBahan(MATRIKS M);
/*I.S : Matriks M telah di load
F.S : Print bahan2 apa saja yang ada di stove*/



#endif
