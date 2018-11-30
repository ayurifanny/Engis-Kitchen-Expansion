#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "engis.h"
#include "matriks.h"
#include "mesinkar.h"
#include "map.h"
#include "bintree.h"
#include "queue.h"
#include "array.h"
#include "asd.h"
#include "graph.h"
#include "jam.h"

void TulisMenu();
void TulisCredit();

int main(){
	
	/* KAMUS */
	int menu, lengthNama, i, n;
	Player Pemain;
	MATRIKS R1, R2, R3, K;
	char *cmd;
	cmd = malloc(sizeof(char)*1000);
	BinTree Menu;
	TabStr Orderan;
	Queue Antrian;
	Customer yangDuduk[13]; //selalu terisi 13. kalo ada kosong mejanya dummy patience dan 0 quant
	Graph G;
	MATRIKS ArrRuang[5];

	/* ALGORITMA */
	MakeMATRIKS(9,9,&R1);
	MakeMATRIKS(9,9,&R2);
	MakeMATRIKS(9,9,&R3);
	MakeMATRIKS(9,9,&K);                                                     

	printf(" _______  __    _  _______  ___   __   _______       ___   _  ___   _______  _______  __   __  _______  __    _ \n");
	printf("|       ||  |  | ||       ||   | |  | |       |     |   | | ||   | |       ||       ||  | |  ||       ||  |  | |\n");
	printf("|    ___||   |_| ||    ___||   | |__| |  _____|     |   |_| ||   | |_     _||       ||  |_|  ||    ___||   |_| |\n");
	printf("|   |___ |       ||   | __ |   |      | |_____      |      _||   |   |   |  |       ||       ||   |___ |       |\n");
	printf("|    ___||  _    ||   ||  ||   |      |_____  |     |     |_ |   |   |   |  |      _||       ||    ___||  _    |\n");
	printf("|   |___ | | |   ||   |_| ||   |       _____| |     |    _  ||   |   |   |  |     |_ |   _   ||   |___ | | |   |\n");
	printf("|_______||_|  |__||_______||___|      |_______|     |___| |_||___|   |___|  |_______||__| |__||_______||_|  |__|\n");
	printf(" _______  __   __  _______  _______  __    _  _______  ___   _______  __    _                                \n");
	printf("|       ||  |_|  ||       ||   _   ||  |  | ||       ||   | |       ||  |  | |                               \n");
	printf("|    ___||       ||    _  ||  |_|  ||   |_| ||  _____||   | |   _   ||   |_| |                               \n");
	printf("|   |___ |       ||   |_| ||       ||       || |_____ |   | |  | |  ||       |                               \n");
	printf("|    ___| |     | |    ___||       ||  _    ||_____  ||   | |  |_|  ||  _    |                               \n");
	printf("|   |___ |   _   ||   |    |   _   || | |   | _____| ||   | |       || | |   |                               \n");
	printf("|_______||__| |__||___|    |__| |__||_|  |__||_______||___| |_______||_|  |__|                               \n");
	printf("\n");
	printf(" _______________________ \n");
	printf("|MAIN MENU:             |\n");
	printf("|                       |\n");
	printf("|1. New Game            |\n");
	printf("|2. Start Game          |\n");
	printf("|3. Load Game           |\n");
	printf("|4. Exit                |\n");
	printf("|_______________________|\n");
	printf("\n");
	printf("Masukkan pilihan:\n");
	scanf("%d", &menu);
	printf("\n");
	
	while ((menu <= 1) && (menu >= 4)){
		TulisMenu();
		scanf("%d", &menu);
		printf("\n");
	}
	while (menu != 4){ //belom keluar game
		if (menu == 1){ //new game
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

		} else if (menu == 2){ //start game
			//inisialisasi
			MakeEmpty(&Orderan);
			CreateEmptyQ(&Antrian, 30);
			CreateEmptyS(&Hand(Pemain));
			for (i=1;i<=12;i++){
				Patience(yangDuduk[i]) = 999;
				Quant(yangDuduk[i]) = 0;
			}             
			if (JAMToDetik(Time(Pemain)) % randomDateng() == 0){
				randomAntrian(&Antrian);
			}
			PrintGame(&ArrRuang[n], &ArrRuang[4], &Pemain, Antrian, Orderan); //menampilkan awal game ke layar
			printf("Command : ");
			scanf("%s", cmd); //menerima inputan command

			while (strcom(cmd, "exit") != 0 && Life(Pemain) != 0){ //belom selesai main
				if (strcmp(cmd, "GU") == 0) { //geser 1 kotak ke atas
					GoUp(&ArrRuang[n], &Pemain, G, &n);
					Time(Pemain) = NextDetik(Time(Pemain));
				}
				else if (strcom(cmd, "GD") == 0) { //geser 1 kotak ke bawah
					GoDown(&ArrRuang[n], &Pemain,G, &n);
					Time(Pemain) = NextDetik(Time(Pemain));
				}
				else if (strcom(cmd, "GL") == 0) { //geser 1 kotak ke kiri
					GoLeft(&ArrRuang[n], &Pemain,G, &n);
					Time(Pemain) = NextDetik(Time(Pemain));
				}
				else if (strcom(cmd, "GR") == 0) { //geser 1 kotak ke kanan
					GoRight(&ArrRuang[n], &Pemain,G, &n);
					Time(Pemain) = NextDetik(Time(Pemain));
				}
				
				/*else if (strcom(cmd, "tayo") == 0) {
					PrintStatus(ArrRuang[n], Pemain, &n);
					Time(Pemain) = NextDetik(Time(Pemain));
				}*/
				
				else if (strcom(cmd, "RECIPE") == 0) { //melihat tree resep
					PrintTree(Menu, 4);
				}
				else if (strcom(cmd, "ORDER") == 0) { //mengambil pesanan dari meja
					Order(Pemain, &ArrRuang[n], &Orderan);
					Time(Pemain) = NextDetik(Time(Pemain)); //menambah tick
				}
				else if (strcom(cmd, "TAKE") == 0) { //mengambil bahan dari kompor
					Take(ArrRuang[n], &Pemain);
					Time(Pemain) = NextDetik(Time(Pemain)); //menambah tick
				}
				else if (strcom(cmd, "CH") == 0) { //mengosongkan tangan
					CH(&Pemain);
					Time(Pemain) = NextDetik(Time(Pemain)); //menambah tick
				}
				else if (strcom(cmd, "CT") == 0) { //mengosongkan tray
					CT(&ArrRuang[n], Pemain);
					Time(Pemain) = NextDetik(Time(Pemain)); //menambah tick
				}
				else if (strcom(cmd, "GIVE") == 0) { //memberi maknan ke meja
					Give(&Pemain, &ArrRuang[n], &MT(ArrRuang[4],1,8), &Orderan, yangDuduk);
					Time(Pemain) = NextDetik(Time(Pemain)); //menambah tick
				}
				else if (strcom(cmd, "PLACE") == 0) { //menempatkan pelanggan ke kursi
					Place(ArrRuang, &ArrRuang[n], Pemain, &Antrian, yangDuduk, &Orderan);
					Time(Pemain) = NextDetik(Time(Pemain)); //menambah tick
				}
				else if (strcom(cmd, "PUT") == 0) { //mengolah bahan menjadi makanan
					Put(&ArrRuang[n], &Pemain, Menu);
					Time(Pemain) = NextDetik(Time(Pemain)); //menambah tick
				}
				else {
					printf("belom ada perintahnya cuy\n"); //kalau salah input
				}
				if (strcmp(cmd, "GU") == 0 || strcmp(cmd, "GD") == 0 || strcmp(cmd, "GL") == 0 || strcmp(cmd, "GR") == 0 || strcom(cmd, "ORDER") == 0 || strcom(cmd, "TAKE") == 0 || strcom(cmd, "CH") == 0 || strcom(cmd, "CT") == 0 || strcom(cmd, "GIVE") == 0 || strcom(cmd, "PLACE") == 0 || strcom(cmd, "PUT") == 0){
					kurangPatience(&ArrRuang[n], &Antrian, yangDuduk, &Pemain, &Orderan); //mengurangi patience yang antri dan duduk setiap tick
				}
				if (JAMToDetik(Time(Pemain)) % randomDateng() == 0){ //mengatur kedatangan pelanggan yang antri
					printf("%d\n", randomDateng());
					randomAntrian(&Antrian);
				}
				PrintGame(&ArrRuang[n], &ArrRuang[4], &Pemain, Antrian, Orderan); //menampilkan game ke layar
				PrintBahan(ArrRuang[n]); //menampilkan bahan-bahan yang ada di dapur
				printf("Command : ");
				scanf("%s", cmd); //menerima inputan command
			}
			if (Life(Pemain) == 0){ //udah mati
				printf("KALAH!!!!!\n");
			}

		} else if (menu == 3) { //load game
			//LoadRuangan
			Loadku(&R1, 1, 'R');
			Loadku(&R2, 2, 'R');
			Loadku(&R3, 3, 'R');
			Loadku(&K, -1, 'K');
			InitGraph(&G);
			//LOAD MENU
			ArrRuang[1] = R1;
			ArrRuang[2] = R2;
			ArrRuang[3] = R3;
			ArrRuang[4] = K;
			MakeTree("Piring\0", Nil, Nil, &Menu);
			LoadMenu(&Menu);
			n = 1;

		}
		TulisMenu();
		scanf("%d", &menu); //menerima input menu
	}

	TulisCredit(); //menampilkan credit
	return 0;	
}

void TulisMenu(){
	printf("\n");
	printf(" _______________________ \n");
	printf("|MAIN MENU:             |\n");
	printf("|                       |\n");
	printf("|1. New Game            |\n");
	printf("|2. Start Game          |\n");
	printf("|3. Load Game           |\n");
	printf("|4. Exit                |\n");
	printf("|_______________________|\n");
	printf("\n");
	printf("Masukkan pilihan:\n");
}

void TulisCredit(){
	printf("\n");
	
	printf("╔╦╗┬ ┬┌─┐┌┐┌┬┌─┌─┐  ┌─┐┌─┐┬─┐  ╔═╗┬  ┌─┐┬ ┬┬┌┐┌┌─┐\n");
	printf(" ║ ├─┤├─┤│││├┴┐└─┐  ├┤ │ │├┬┘  ╠═╝│  ├─┤└┬┘│││││ ┬\n");
	printf(" ╩ ┴ ┴┴ ┴┘└┘┴ ┴└─┘  └  └─┘┴└─  ╩  ┴─┘┴ ┴ ┴ ┴┘└┘└─┘\n");
	
	printf("\n");
	printf("Dibuat oleh:\n");
	printf("13517017 Nisrina Yumna Khairunnisa\n");
	printf("13517038 Ayu Rifanny\n");
	printf("13517110 Christy Grace\n");
	printf("13517134 Renita Napitupulu\n");
	printf("13517140 Fithratulhay Pribadi\n");
}
	

