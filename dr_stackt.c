#include "stackt.h"
#include <stdio.h>

int main(){
	/* KAMUS */
	Stack Kosong, Isi;
	int i;
	Kata titik;
	
	/* ALGORITMA */
	CreateEmptyS(&Kosong); //inisialisasi queue
	if (IsEmptyS(Kosong)){ //mencoba isemptys
		printf("Stack 'Kosong' gak ada isinya\n");
		printf("Isinya: \n");
		PrintStack(Kosong); //menulis isi stack
	}
	
	titik.TabKata[1] = '.';
	titik.Length = 1;
	
	for (i=1;i<=10;i++){
		Push(&Isi, titik); //mengisi stack
	}
	
	if (IsFullS(Isi)){
		printf("Setelah dipush penuh, isinya: \n");
		PrintStack(Isi); //menulis isi stack setelah disi
	}
	
	for (i=1;i<=10;i++){
		Pop(&Isi, &titik); //mengeluarkan isi stack
	}
	
	if (IsEmptyS(Isi)){
		printf("Setelah dipop kosong, isinya: \n");
		PrintStack(Isi); //menulis isi stack setelah dikeluarkan isinya
	}
	
	return 0;
}
