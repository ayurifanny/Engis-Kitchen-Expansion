#include "asd.h"


int randomDateng(){
	srand(time(NULL));
	return (rand()%8) + 5;
}

// merandom order yang diterima
Kata randomOrder(){
	/* KAMUS LOKAL */
	Kata TK[9];
	int rdm, i;
	char *makanan;
	
	/* ALGORITMA */
	makanan = malloc(sizeof(char)*30);
	srand(time(NULL));
	rdm = (rand()%8) + 1;
	
	//INISIALISASI TABEL
	makanan = "Banana Split";
	TK[1].Length = 12;
	for (i=1;i<=TK[1].Length;i++){
		TK[1].TabKata[i] = makanan[i-1];
	}
	
	makanan = "Sundae";
	TK[2].Length = 6;
	for (i=1;i<=TK[2].Length;i++){
		TK[2].TabKata[i] = makanan[i-1];
	}
	
	makanan = "Nasi Telur Dadar";
	TK[3].Length = 16;
	for (i=1;i<=TK[3].Length;i++){
		TK[3].TabKata[i] = makanan[i-1];
	}
	
	makanan = "Nasi Ayam Goreng";
	TK[4].Length = 16;
	for (i=1;i<=TK[4].Length;i++){
		TK[4].TabKata[i] = makanan[i-1];
	}
	
	makanan = "Burger";
	TK[5].Length = 6;
	for (i=1;i<=TK[5].Length;i++){
		TK[5].TabKata[i] = makanan[i-1];
	}
	
	makanan = "Hot Dog";
	TK[6].Length = 7;
	for (i=1;i<=TK[6].Length;i++){
		TK[6].TabKata[i] = makanan[i-1];
	}
	
	makanan = "Spaghetti Bolognese";
	TK[7].Length = 19;
	for (i=1;i<=TK[7].Length;i++){
		TK[7].TabKata[i] = makanan[i-1];
	}
	
	makanan = "Spaghetti Carbonara";
	TK[8].Length = 19;
	for (i=1;i<=TK[8].Length;i++){
		TK[8].TabKata[i] = makanan[i-1];
	}
	
	return TK[rdm];
}


// memasukkan order ke array
void Order(Player P, MATRIKS *M, TabStr *O){
	/* KAMUS LOKAL */
		int i, j;
		ElTypeA Pesanan;
		
	/* ALGORITMA */
    PrintArray(*O);
	if (MValid(*M,Absis((P).Posisi),Ordinat((P).Posisi))){
		//memasukkan indeks meja
		i = GetIdxObjX(*M,Absis((P).Posisi),Ordinat((P).Posisi));
		j = GetIdxObjY(*M,Absis((P).Posisi),Ordinat((P).Posisi));
		if (MTable(*M,i,j)|| MChair(*M,i,j)){ //cek meja atau kursi
			if (!MTableVac(*M,i,j)){ //cek meja kosong
				if (FoodA(*O,MTableNum(*M,i,j),1) == '#'){ //cek udah pesen atau belum
					//mengisi array orderan
					Pesanan.Food = randomOrder(); //ngerandom menu yg dipesen
					Pesanan.Nomer = MTableNum(*M,i,j);
					AddEli(O, MTableNum(*M,i,j),Pesanan); //nyimpen menu orderan
					
					/*
					FoodAPjg(*O,MTableNum(*M,i,j)) = pesan.Length;
					for (k=1;k<=FoodAPjg(*O,MTableNum(*M,i,j));k++){ 
						FoodA(*O,MTableNum(*M,i,j),k) = pesan.TabKata[k];
						MTableOrder(*M,i,j,k) = pesan.TabKata[k];
					}
					*/
					
				} else{
					printf("Sudah pesan\n");
				}
			} else{
				printf("Belom ada orangnya\n");
			}
		} else{
			printf("Bukan meja\n");
		}
	} else{
		printf("Salah tempat\n");
	}
}


//membandingkan antara infotypeT(akar bintree) dan infotypeS(infotop stack)
boolean Compare(infotypeT it, infotypeS is){
	/* KAMUS LOKAL */
	int i;
	boolean cek;

	/* ALGORITMA */
	i = 0;
	cek = true;
	while ((cek) && (i < is.Length)){
		if (it[i] == is.TabKata[i+1]){
			i++;
		} else {
			cek = false;
		}
	}

	return cek;
}

//membalik stack
void balik(Stack *S1, Stack *S2){
	infotypeS temp;
	while(!IsEmptyS(*S1)){
		Pop(S1, &temp);
		Push(S2, temp);
	}
}

void Put(MATRIKS *M, Player *P, BinTree Menu){
	/* KAMUS */ 
	int i, j, f;
	infotypeS K, co;
	boolean sama, daun;
	BinTree temp;
	Stack temp1, temp2; 

	/* ALGORITMA */
	//inisialisasi stack
	CreateEmptyS(&temp1);
	CreateEmptyS(&temp2);
	if (MValid(*M,Absis((*P).Posisi),Ordinat((*P).Posisi))){
		//memasukkan indeks meja
		i = GetIdxObjX(*M,Absis((*P).Posisi),Ordinat((*P).Posisi));
		j = GetIdxObjY(*M,Absis((*P).Posisi),Ordinat((*P).Posisi));
		if(MTray(*M,i,j)){ //cek tray
			if (IsFullS(MT(*M,i,j))) { //cek isi tray
				printf("tray penuh\n"); //dicek dulu apakah tray penuh 
			} else if (IsEmptyS(Hand(*P))){ 
				printf("belum mengambil bahan\n"); //dicek dulu apakah tangan kosong 
			} else { // tray tidak penuh dan tangan tidak kosong
				balik(&Hand(*P), &temp1);
				//ubah hand ke makanan pake tree
				Pop(&temp1, &K);
				Push(&temp2, K);
				if (Compare(Akar(Menu), K)){
					sama = true;
					daun = false;
					while ((sama) && (!daun)){
						if (IsTreeOneElmt(Left(Menu))){ //kalau uner left, berarti leftnya daun, validasi bahan -> makanan selesai
							Menu = Left(Menu);
							daun = true;
						} else {
							if (!IsEmptyS(temp1)){
								Pop(&temp1, &K);
								Push(&temp2, K);
							}
							temp = Left(Menu);
							if (Compare(Akar(temp),K)) {  //kalau left nya dicompare sama, lanjut ke left
								Menu = Left(Menu);
							} else { 
								temp = Right(Menu);
								if (Compare(Akar(temp),K)) { //kalau right nya dicompare sama, lanjut ke right
									Menu = Right(Menu);
								} else {
									sama = false; //udah sampai sini berarti ga sama, langsung keluar
								}
							}
						}
					}

					if (sama){
						f = 0;
						//copy akar ke co yang mempunyai type infotypeS
						while(Akar(Menu)[f] != '\0'){ 
							co.TabKata[f+1] = Akar(Menu)[f];
							f += 1;	
						}
						co.Length = f;
						Push(&MT(*M,i,j), co); //co dipush ke stack tray
					} else {
						balik(&temp2, &temp1);
						printf("Tidak ada menu yang sesuai dengan bahan\n");
					}	
				} else {
					balik(&temp2, &temp1);
					printf("Tidak sesuai dengan bahan\n");
				}
				balik(&temp1, &Hand(*P));
			} 
		} else {
			printf("Tidak ada nampan/n");
		}  
	} else {
		printf("Salah Tempat/n");
	}
}


// mengambil bahan yang bersebelahan
void Take(MATRIKS M, Player *P){
	/* KAMUS */
	int i, j, k;
	Kata K;
	
	/* ALGORITMA */
	if (MValid(M,Absis((*P).Posisi),Ordinat((*P).Posisi))){
		//memasukkan indeks meja
		i = GetIdxObjX(M,Absis((*P).Posisi),Ordinat((*P).Posisi));
		j = GetIdxObjY(M,Absis((*P).Posisi),Ordinat((*P).Posisi));
		if (MStove(M,i,j)){ //cek kompor
			for (k=1;k<=MNamaBhnPjg(M,i,j);k++){
				K.TabKata[k] = MNamaBhn(M,i,j,k);
			}
			if (!IsFullS(Hand(*P))){ //cek isi tangan
				K.Length = MNamaBhnPjg(M,i,j);
				Push(&Hand(*P),K);
			} else{
				printf("Tangan penuh\n");
			}
		} else{
			printf("Bukan kompor\n");
		}
	} else{
		printf("Salah tempat\n");
	}
}


// membuang isi hand
void CH(Player *P){
	CreateEmptyS(&Hand(*P));
}


// membuang isi tray
void CT(MATRIKS *M, Player P){
	/* KAMUS */
	int i, j;
	
	/* ALGORITMA */
	if (MValid(*M,Absis((P).Posisi),Ordinat((P).Posisi))){
		//memasukkan indeks tray
		i = GetIdxObjX(*M,Absis((P).Posisi),Ordinat((P).Posisi));
		j = GetIdxObjY(*M,Absis((P).Posisi),Ordinat((P).Posisi));
		if (MTray(*M,i,j)){ //cek tray
			CreateEmptyS(&MT(*M,1,8));
		} else{
			printf("Bukan tray\n");
		}
	}
}


void Give (Player *P, MATRIKS *M, Stack *S, TabStr *O, Customer AC[13]){ //blm nambah uang
  /*I.S : Tumpukkan pada tray terdefinisi*/
  /*F.S : Orderan pada top of tray diberikan ke pelanggan*/

 	/* KAMUS */
 	int mejaX, mejaY;
 	int i, j, k;
 	boolean found, sama, mahal;
 	infotypeS Order_done1;
 	Kata TK;
 	char * makanan;
 	ElTypeA A;

 	/* ALGORITMA */
 	if (MValid(*M,Absis((*P).Posisi),Ordinat((*P).Posisi))){
		//memasukkan indeks meja
		mejaX = GetIdxObjX(*M,Absis((*P).Posisi),Ordinat((*P).Posisi));
		mejaY = GetIdxObjY(*M,Absis((*P).Posisi),Ordinat((*P).Posisi));
		found = false;
		if (MTable(*M,mejaX,mejaY) || MChair(*M,mejaX,mejaY)){ //cek meja atau kursi
			i = IdxMin;
			//cari makanan yg sama dgn infotop
			while (!found && i<=12){
				if (InfoTop(*S).Length == FoodAPjg(*O,i)){
					sama = true;
					j = 1;
					while (sama && j<=FoodAPjg(*O,i)){
						if (InfoTop(*S).TabKata[j] != FoodA(*O,i,j)){
							sama = false;
						} else{
							j++;
						}
					}
				} else{
					sama = false;
				}	
				if (sama){
					found = true;
				} else{
					i++;
				}
			}
		} else{
			printf("Bukan meja\n");
		}
		if (found){ //kalo ada yang sama kayak infotop baru bisa kasih
			if (MTableNum(*M, mejaX, mejaY) == NoA(*O,i)){ //cek ngasih ke meja yg bener apa enggak
				Pop(S, &Order_done1);
				//cek bolognese bukan, kalo iya uangnya lebih banyak dapetnya
				mahal = true;
				makanan = malloc(sizeof(char)*20);
				makanan = "Spaghetti Bolognese";
				TK.Length = 19;
				for (i=1;i<=TK.Length;i++){
					TK.TabKata[i] = makanan[i-1];
				}
				k = 1;
				//cek makanan yg dikasih apa karena harga spaghetti bolognese beda
				while (k<=TK.Length && mahal){
					if (FoodA(*O,MTableNum(*M, mejaX, mejaY),k) != TK.TabKata[k]){
						 mahal = false;
					} else{
						k++;
					}
				}
				if (mahal){
					Money(*P) += 100; //kalo spaghetti bolognese
				} else{
					Money(*P) += 70; //yang lainnya
				}
				DelEli(O, MTableNum(*M,mejaX,mejaY),&A); //inisialisasiin lg array of ordernya
				
				/*
				FoodA(*O,MTableNum(*M, mejaX, mejaY),1) = '#'; 
				FoodAPjg(*O,MTableNum(*M, mejaX, mejaY)) = 1; //ganti
				*/
				
				//kosongin meja dan kursi
				MTableVac(*M, mejaX, mejaY) = true;
				if (MTableNum(*M,mejaX,mejaY) % 2 == 0 ){
					MChairVac(*M,mejaX,mejaY-1) = true;
					MChairVac(*M,mejaX,mejaY+1) = true;
				} else {
					MChairVac(*M,mejaX-1,mejaY) = true;
					MChairVac(*M,mejaX+1,mejaY) = true;
					MChairVac(*M,mejaX,mejaY-1) = true;
					MChairVac(*M,mejaX,mejaY+1) = true;
				}
				AC[MTableNum(*M,mejaX,mejaY)].Patience = 999; //inisialisasiin lg array of customers' patience
				AC[MTableNum(*M,mejaX,mejaY)].Quantity = 0;
			} else{
				printf("Salah tempat\n");
			}
		} else{
			printf("Salah tempat\n");
		}
	} else{
		printf("Salah tempat\n");
	}
}


void Place (MATRIKS MM[5], MATRIKS *M, Player P, Queue *Q, Customer AC[13], TabStr *O){
	/* KAMUS */
	int mejaX, mejaY;
 	boolean berhasil;
 	infotypeQ sudahDuduk;
 	Queue QBaru;
 	boolean ketemu;
 	Customer X;

	/* ALGORITMA */
	if (MValid(*M,Absis((P).Posisi),Ordinat((P).Posisi))){ //cek valid
		//memasukkan indeks meja
		mejaX = GetIdxObjX(*M,Absis((P).Posisi),Ordinat((P).Posisi));
		mejaY = GetIdxObjY(*M,Absis((P).Posisi),Ordinat((P).Posisi));
		if (MTable(*M, mejaX, mejaY) || MChair(*M, mejaX, mejaY)){ //cek meja apa bukan
			if (MTableVac(*M,mejaX,mejaY)){
				berhasil = false;
				if (Quant(InfoHead(*Q)) == 2) { //kalo yg duduk 2 org
					//mengisi kursi
					MChairVac(*M,mejaX,mejaY-1) = false;
					MChairVac(*M,mejaX,mejaY+1) = false;
					Del(Q, &sudahDuduk); //menghapus head dari queue
					berhasil = true;
				}else if (Quant(InfoHead(*Q)) == 4 && MTableNum(*M,mejaX,mejaY) % 2 == 1){ //kalo yg duduk 4 org harus di meja yg ganjil nomernya
					//mengisi kursi
					MChairVac(*M,mejaX-1,mejaY) = false;
					MChairVac(*M,mejaX+1,mejaY) = false;
					MChairVac(*M,mejaX,mejaY-1) = false;
					MChairVac(*M,mejaX,mejaY+1) = false;
					berhasil = true;
					Del(Q, &sudahDuduk); //meghapus head dari queue
				} else {
					if (Quant(InfoHead(*Q)) == 4 && (!cekVacant4(MM[1]) && !cekVacant4(MM[2]) && !cekVacant4(MM[3]))){ //kalo udh gak ada yg 4 kursi tp headnya 4 dan belakangnya ada yg gak 4
						if (cekAntri2(*Q)){ //cek ada yg 2 org gak di belakang
							CreateEmptyQ(&QBaru, 30);
							ketemu = false;
							//menghapus customer terdepan yg quantitynya 2dari antrian
							while (Head(*Q) != Tail(*Q)){
								Del(Q, &X);
								if (!ketemu && Quant(X) != 2){
									Add(&QBaru, X);
								} else if (!ketemu && Quant(X) == 2){
									ketemu = true;
								} else if (ketemu){
									Add(&QBaru, X);
								}
							}
							Del(Q, &X);
							if (!ketemu && Quant(X) != 2){
									Add(&QBaru, X);
								} else if (!ketemu && Quant(X) == 2){
									ketemu = true;
								} else if (ketemu){
									Add(&QBaru, X);
								}
							//mengisi kursi
							MChairVac(*M,mejaX,mejaY-1) = false;
							MChairVac(*M,mejaX,mejaY+1) = false;
							DeAlokasiQ(Q);
							*Q = QBaru;
							Quant(sudahDuduk) = 2;
							berhasil = true;
						}
					}
				}
				if (berhasil){ //kalo bisa duduk
					MTableVac(*M,mejaX,mejaY) = false;
					//array of customer yg duduk diisi
					Patience(AC[MTableNum(*M,mejaX,mejaY)]) = 100; //JANGAN LUBA BENERIN LAGI KE 50/70 ATAU BERAPAPUN
					Quant(AC[MTableNum(*M,mejaX,mejaY)]) = Quant(sudahDuduk);
				} else{
					printf("Salah tempat.\n");
				}
			} else{
				printf("Salah tempat\n");
			}	
		} else{
			printf("Bukan meja\n");
		}
	} else{
		printf("Tidak Valid\n");
	}
}

//merandom quantity customer yg datang
void randomAntrian(Queue *Q){
	/* KAMUS */
	int rdm;
	infotypeQ custBaru;
	
	/* ALGORITMA */
	srand(time(NULL));
	rdm = (rand()%2) + 1;
	Patience(custBaru) = 30; //JANGAN LUPA BALIKIN KE 30 YA
	Quant(custBaru) = 2*rdm;
	Add(Q, custBaru);
}

//mengcompare 2 string
int strcom (char *str1, char *str2){
	/* KAMUS */
	int i;
	boolean sama;
	
	/* ALGORITMA */
	i = 0;
	sama = true;
	while (str1[i] != '\0' && str2[i] != '\0' && sama){
		if (str1[i] != str2[i]){
			sama = false;
		} else{
			i++;
		}
	}
	if (sama){
		return 0;
	} else{
		return 1;
	}
}

//mengcopy string ke strign
void strcop (char *str1, char *str2){
	/* KAMUS */
	int i;
	/* ALGORITMA */
	i = 0;
	while (str2[i] != '\0'){
		str1[i] = str2[i];
		i++;
	}
}

//mengurangi patience dari customer 1 tick sambil mengecek udh 0 apa belom, kalo udh dihapus
void kurangPatience (MATRIKS *M, Queue *Q, Customer duduk[13], Player *P, TabStr *O){ 
	/* KAMUS */
	Customer X;
	int i, mejaX, mejaY;
	Queue QBaru;
	ElTypeA A;
	
	/* ALGORITMA */
	//kurangin semua patience yg ada di queue
	if (!IsEmptyQ(*Q)){ 
		CreateEmptyQ(&QBaru, 30);
		while (Head(*Q) != Tail(*Q)){
			Del(Q, &X);
			Patience(X)--;
			Add(&QBaru, X);
		}
		Del(Q, &X);
		Patience(X)--;
		Add(&QBaru, X);
		DeAlokasiQ(Q);
		*Q = QBaru;
		//ngilangin kalo udah 0 patiencenya antri
		if (Patience(InfoHead(*Q)) == 0){ 
			printf("Yah pergi yang antri\n");
			Life(*P)--;
			Del(Q, &X);
		}
	}
	//ngurangin patience yg duduk
	for (i=1;i<=12;i++){ 
		if (Patience(duduk[i]) != 999){
			Patience(duduk[i])--;
		}
		//ngilangin kalo udah 0 patience yg duduk
		if (Patience(duduk[i]) == 0){ 
			Life(*P)--;
			Patience(duduk[i]) = 999;
			Quant(duduk[i]) = 0;
			if (i % 2 == 0) {
				if (i == 2 || i == 6 || i == 10){
					mejaX = 2;
					mejaY = 7;
				} else if (i == 4 || i == 8 || i == 12){
					mejaX = 7;
					mejaY = 7;
				}
				MChairVac(*M,mejaX,mejaY-1) = true;
				MChairVac(*M,mejaX,mejaY+1) = true;
			}else{
				if (i == 1 || i == 5 || i == 9){
					mejaX = 2;
					mejaY = 2;
				} else if (i == 3 || i == 7 || i == 11){
					mejaX = 7;
					mejaY = 2;
				}
				//ngosoingin kursi
				MChairVac(*M,mejaX-1,mejaY) = true;
				MChairVac(*M,mejaX+1,mejaY) = true;
				MChairVac(*M,mejaX,mejaY-1) = true;
				MChairVac(*M,mejaX,mejaY+1) = true;
			}
			MTableVac(*M,mejaX,mejaY) = true; //ngosongin meja
			DelEli(O, MTableNum(*M,mejaX,mejaY), &A); //ngapus orderan
		}
	}	
}


//ngecek yg kursinya 4 org ada yg masih kosong apa enggak. kalo true berarti ada
boolean cekVacant4 (MATRIKS M){
	return (MTableVac(M, 2, 2) || MTableVac(M, 7, 2));
}


//ngecek di antrian ada yg quantity nya 2 apa enggak. kalo true berarti ada
boolean cekAntri2 (Queue Q){
	/* KAMUS */
	boolean found;
	
	/* ALGORITMA */
	found = false;
	while (Head(Q) != Tail(Q) && !found){
		if (Quant(InfoHead(Q)) == 2){
			found = true;
		} else{
			Head(Q)++;
		}
	}
	if (Quant(InfoHead(Q)) == 2){
		return true;
	} else{
		return found;
	}
}

