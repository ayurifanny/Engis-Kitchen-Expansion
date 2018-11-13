#include <stdio.h>
#include "boolean.h"
#include "point.h"
#include <math.h>

#define PI 3.14

/* *** Definisi ABSTRACT DATA TYPE POINT *** */
/* typedef struct {
	float X;
	float Y;
} POINT; */

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y)
/* Membentuk sebuah POINT dari komponen-komponennya */
{
	/* KAMUS LOKAL */
	POINT P;
	
	/* ALGORITMA */
	Absis(P) = X;
	Ordinat(P) = Y;
	return P;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT *P)
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk POINT P berdasarkan
dari nilai absis dan ordinat tersebut */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
{
	/* KAMUS LOKAL */
	float X;
	float Y;
	
	/* ALGORITMA */
	scanf ("%f %f", &X, &Y);
	Absis(*P) = X;
	Ordinat(*P) = Y;
}
void TulisPOINT (POINT P)
/* Nilai P ditulis ke layar dengan format "(X,Y)" */
/* I.S. P terdefinisi */
/* F.S. P tertulis di layer dengan format "(X,Y)" */
{
	printf ("(%f,%f)", Absis(P), Ordinat(P));
}

/* *** Kelompok operasi relasional terhadap POINT *** */
void Geser (POINT *P, float deltaX, float deltaY)
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
{
	Absis(*P) = Absis(*P) + deltaX;
	Ordinat(*P) = Ordinat(*P) + deltaY;
}
