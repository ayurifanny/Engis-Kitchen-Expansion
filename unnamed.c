#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "engis.h"
#include "matriks.h"
#include "mesinkar.h"
#include "map.h"
#include "bintree.h"

void TulisCredit();


int main(){
	
	/* KAMUS */
	int menu, lengthNama;
	Player Pemain;
	MATRIKS K/*, R2, R3, K*/;
	char *cmd;
	cmd = malloc(sizeof(char)*1000);
	BinTree Menu;
	
	/* ALGORITMA */
	MakeMATRIKS(9,9,&K);
	//MakeMATRIKS(9,9,&R2);
	/*MakeMATRIKS(9,9,&R3);
	MakeMATRIKS(9,9,&K);*/
	
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
	while (menu != 4){
		if (menu == 1){
			printf("Masukkan nama pemain : ");
			lengthNama = 0;
			scanf("%c", &CC );
			while (CC != '.'){
				lengthNama++;
				Nama(Pemain, lengthNama) = CC;
				scanf("%c", &CC );
			}
			
			//loadnya belom
			NamaLength(Pemain) = lengthNama;
			LoadPlayer(&Pemain);

		} else if (menu == 2){
			PrintGame(&K, &Pemain);
			printf("Command : ");
			scanf("%s", cmd);

			while (strcmp(cmd, "exit") != 0){
				if (strcmp(cmd, "GU") == 0) {
					GoUp(&K, &Pemain);
				}
				else if (strcmp(cmd, "GD") == 0) {
					GoDown(&K, &Pemain);
				}
				else if (strcmp(cmd, "GL") == 0) {
					GoLeft(&K, &Pemain);
				}
				else if (strcmp(cmd, "GR") == 0) {
					GoRight(&K, &Pemain);
				}
				else if (strcmp(cmd, "tayo") == 0) {
					PrintStatus(K, Pemain);
				}
				else if (strcmp(cmd, "RECIPE") == 0) {
					PrintTree(Menu, 4);
				}
				else {
					printf("belom ada perintahnya cuy\n");
				}
				printf("Command : ");
				scanf("%s", cmd);

			}

		} else if (menu == 3){
			//LoadRuangan
			//Loadku(&R1, 1, 'R');
			//Loadku(&K, 2, 'K');
			//Loadku(&R3, 3, 'R');
			Loadku(&K, -1, 'K');
			
			//LOAD MENU
			MakeTree("Piring\0", Nil, Nil, &Menu);
			LoadMenu(&Menu);

		}
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
	

