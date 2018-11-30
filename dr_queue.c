#include "queue.h"
#include <stdio.h>

int main(){
	/* KAMUS */
	Queue Q;
	int i;
	Customer C;
	
	/* ALGORITMA */
	CreateEmptyQ(&Q, 5); //menginisialisasi queue
	printf("Jumlah isi stack: %d\n", NBElmtQ(Q));
	if (IsEmptyQ(Q)){ //mencoba isemptyq
		printf("Stack gak ada isinya\n");
	}
	
	Quant(C) = 2;
	Patience(C) = 5;
	
	for (i=1;i<=5;i++){
		Add(&Q, C); //mengisi queue
	}
	
	if (IsFullQ(Q)){
		printf("Isi queue yang penuh setelah diadd: \n");
		PrintQueue(Q); //menampilkan queue ke layar
	}
	
	for (i=1;i<=5;i++){
		Del(&Q, &C); //menghapus elemen queue
	}
	
	if (IsEmptyQ(Q)){
		printf("Isi queue yang kosong setelah didel: \n");
		PrintQueue(Q); //manmpilkan queue ke layar
	}
	
	DeAlokasiQ(&Q); //dealokasi queue
	
	if (MaxElQ(Q) == Nol){ //cek apakah berhasil delaokasi
		printf("Queue udah ilang\n");
	}
	
	return 0;
	
}
