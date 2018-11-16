#include <stdio.h>
#include <string.h>
#include "engis.h"
#include "matriks.h"
#include "mesinkar.h"
#include "map.h"

void TulisCredit();


int main(){
	
	/* KAMUS */
	int menu, lengthNama;
	Player Pemain;
	MATRIKS R1, R2, R3, K;
	/*MATRIKS Hu, Ha;*/
	/* K*/
	
	/* ALGORITMA */
	MakeMATRIKS(8,8,&R1);
	MakeMATRIKS(8,8,&R2);
	MakeMATRIKS(8,8,&R3);
	MakeMATRIKS(8,8,&K);
	
	printf("Main Menu:\n");
	printf("1. New Game\n");
	printf("2. Start Game\n");
	printf("3. Load Game\n");
	printf("4. Exit\n");
	printf("Masukkan pilihan: ");
	scanf("%d", &menu);
	printf("\n");
	
	while ((menu <= 1) && (menu >= 4)){
		printf("Masukkan pilihan: ");
		scanf("%d", &menu);
		printf("\n");
	}
	//BELOM VALIDASI SAMASEKALI
	while (menu != 4 || menu != 2){
		if (menu == 1){
			printf("Masukkan nama pemain : ");
			lengthNama = 0;
			scanf("%c", &CC );
			while (CC != '.'){
				lengthNama++;
				Nama(Pemain, lengthNama) = CC;
				scanf("%c", &CC );
				 //loadnya belom
			}
			NamaLength(Pemain) = lengthNama;
			Life(Pemain) = 3;
			Time(Pemain) = 0;
			Money(Pemain) = 0;
			PosisiX(Pemain) = 5;
			PosisiY(Pemain) = 5;	

		} else if (menu == 2){
			PrintGame(&R1, &Pemain);

		} else if (menu == 3){
			//LoadRuangan
			Loadku(&R1, 1, 'R');
			Loadku(&K, 2, 'K');
			/*Loadku(&R3, 3, 'R');
			Loadku(&K, -1, 'K');
*/		}
		printf("Masukkan pilihan: ");
		scanf("%d", &menu);
	}


	TulisCredit();
	return 0;	
}


void TulisCredit(){
	printf("Thanks For Playing!\n");
	printf("\n");
	printf("Dibuat oleh:\n");
	printf("13517017 Nisrina Yumna Khairunnisa\n");
	printf("13517038 Ayu Rifanny\n");
	printf("13517110 Christy Grace\n");
	printf("13517134 Renita Napitupulu\n");
	printf("13517140 Fithratulhay Pribadi\n");
}
	
