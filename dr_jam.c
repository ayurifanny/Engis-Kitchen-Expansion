#include "boolean.h"
#include "jam.h"
#include <stdio.h>

//DRIVER Point

int main() {
	//Kamus
	int H, M, S;
	JAM J, JA;

	//Algoritma
	BacaJAM(&J); //menerima inputan jam
	J = NextDetik(J); //menambahkan 1 detil
	TulisJAM(J); //menulis hasil akhir
	return 0;
}
