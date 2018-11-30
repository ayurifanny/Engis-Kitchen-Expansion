#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>



void menu();
int main() {

	BinTree Menu;
	MakeTree("Menu\0", Nil, Nil, &Menu); //membuat tree
	menu(&Menu);
	PrintTree(Menu, 4); //menuliskan isi tree ke layar

	return 0;
}
void menu(BinTree *Menu) {
	
	
    AddDaun(Menu, "Menu", "Piring", true);
    AddDaun(Menu, "Piring", "Roti", true);
    AddDaun(Menu, "Roti", "Selai Coklat", true);
    AddDaun(Menu, "Selai Coklat", "Roti Coklat", true);
    AddDaun(Menu, "Roti", "Patty", false);
    AddDaun(Menu, "Patty", "Burger", true);
    AddDaun(Menu, "Piring", "Nasi", false);
    AddDaun(Menu, "Nasi", "Daging", true);
    AddDaun(Menu, "Daging", "Kuah Rendang", true);
    AddDaun(Menu, "Kuah Rendang", "Nasi Padang", true);
    AddDaun(Menu, "Nasi", "Telur", false);
    AddDaun(Menu, "Telur", "Nasi Telur Dadar", true);
    AddDaun(Menu, "Menu", "Gelas", false);
    AddDaun(Menu, "Gelas", "Teh", true);
    AddDaun(Menu, "Teh", "Teh Tawar", true);
    AddDaun(Menu, "Teh", "Gula", false);
    AddDaun(Menu, "Gula", "Teh Manis", true);
    AddDaun(Menu, "Gelas", "Sirup", false);
    AddDaun(Menu, "Sirup", "Es Sirup", true);
    AddDaun(Menu, "Sirup", "Buah", false);
    AddDaun(Menu, "Buah", "Es Buah", true);
}
