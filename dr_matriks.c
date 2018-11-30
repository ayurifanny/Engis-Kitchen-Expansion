#include "matriks.h"
#include <stdio.h>



//DRIVER untuk matriks (hanya mencoba berhasil menampilkan lokasi meja)
int main() {
	//KAMUS
	MATRIKS M;

	MakeMATRIKS(9,9, &M); //inisialisasi matriks
	
	printf("Idx valid ada dari idx baris %d sampai %d \n", GetFirstIdxBrs (M), GetLastIdxBrs (M)); //melihat idx valid baris
	printf("Idx valid ada dari idx kolom %d sampai %d \n", GetFirstIdxKol (M), GetLastIdxKol (M)); //melihat idx valid kolom
	
	return 0;


}

