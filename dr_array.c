#include "boolean.h"
#include "mesinkata.h"
#include "array.h"
#include "engis.h"
#include <stdio.h>
//BELOM YA

int main() {
	//Kamus
	TabStr T;
	ElTypeA A, B, C;
	int i;

	MakeEmpty(&T); //menginisialisasi arrau
	
	for (i = 1; i<=4; i++) { //mengisi array
		B.Food.TabKata[i] = 'a';
	}	
	B.Food.Length = 4;
	B.Nomer = 1;
    AddEli(&T, 1, B); //mengisi array

	for (i = 1; i<=7; i++) {
		C.Food.TabKata[i] = 'b';
	}	
	C.Food.Length = 7;
	C.Nomer = 2;
    AddEli(&T, 2, C); //mengisi array

	T.Neff = 3;
	//tulisdulu
	printf("Sebelum :\n");
	PrintArray(T); //menulis array ke layar

	//setelah dikurang 1
	DelEli(&T, 2, &A); //menghapus elemen array
	printf("Sesudah di hapus:\n");
	PrintArray(T); //menulis isi array yang baru
}
