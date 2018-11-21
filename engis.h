#ifndef ENGIS_K
#define ENGIS_K

#include "point.h"
#include "stackt.h"
#include "boolean.h"
#include "mesinkata.h"
#include "mesinkar.h"



/*Kalo M[x][y] itu adalah meja, Meja : boolean = true*/
/*Vacant -> kosong apa ngga mejanya*/
/*Number -> nomor meja*/
/*Order[20] -> string kalo ada yg order*/
/*Kalo meja false, isi semua sama 0*/


typedef struct {
	Stack H;
	Kata Nama;
	POINT Posisi;
	int Life;
	int Money;
	int Time;
} Player;

typedef struct {
	int Patience;
	int Quantity;
} Customer;

typedef struct {
	Kata Order; //belom fix
	int Number;
	boolean Meja;
	boolean VacantT;
	
} table;

/*Kalo M[x][y] itu adalah kursi, Kursi : boolean = true*/
/*Vacant -> kosong apa ngga kursinya*/
/*Kalo boolean false, vacant false jg*/
typedef struct {
	//int No;
	boolean Kursi;
	boolean VacantC; 
} chair;

typedef struct {
	POINT IdxObj;
	boolean IsValid;
} valid;

/*Kalo M[x][y] itu adalah kompor, Kompor : boolean = true*/
/*NamaBhn -> Bahan apa yg di ada di situ*/
/*kalo Kompor false, NamaBhn isi 0*/
typedef struct {
	Kata NamaBhn;
	boolean Kompor;
	 //belomfix 
} stove;

/*Kalo M[x][y] itu adalah tray, Tray : boolean = true*/
/*Full -> full apa ngga nampannya (full itu isinya udh 5 makanan)*/
/*T -> isi stacknya*/
/*Kalo Tray == false, stack empty, full false*/
typedef struct {
	Stack T;
	boolean Nampan;
} tray;

typedef struct {
	
	table Table;
	chair Chair;
	stove Stove; 
	tray Tray;
	valid Valid;
	boolean Avail;
	boolean Door;
	 //bisa di lewati player apa ngga
} Status;


/* *** Selektor *** */
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define ElmtM(M,i,j) (M).Mem[(i)][(j)]

#define MAvail(M,i,j) (M).Mem[(i)][(j)].Avail
#define MDoor(M,i,j) (M).Mem[(i)][(j)].Door
#define MTable(M,i,j) (M).Mem[(i)][(j)].Table.Meja
#define MChair(M,i,j) (M).Mem[(i)][(j)].Chair.Kursi
#define MStove(M,i,j) (M).Mem[(i)][(j)].Stove.Kompor
#define MTray(M,i,j) (M).Mem[(i)][(j)].Tray.Nampan

#define MValid(M,i,j) (M).Mem[(i)][(j)].Valid.IsValid
#define GetIdxObjX(M,i,j) (M).Mem[(i)][(j)].Valid.IdxObj.X
#define GetIdxObjY(M,i,j) (M).Mem[(i)][(j)].Valid.IdxObj.Y

#define MTableVac(M,i,j) (M).Mem[(i)][(j)].Table.VacantT
#define MTableNum(M,i,j) (M).Mem[(i)][(j)].Table.Number
#define MTableOrder(M,i,j,k) (M).Mem[(i)][(j)].Table.Order.TabKata[k]
#define MTableOrderPjg(M,i,j) (M).Mem[(i)][(j)].Table.Order.Length

#define MChairVac(M,i,j) (M).Mem[(i)][(j)].Chair.VacantC

#define MNamaBhn(M,i,j,k) (M).Mem[(i)][(j)].Stove.NamaBhn.TabKata[k]
#define MNamaBhnPjg(M,i,j) (M).Mem[(i)][(j)].Stove.NamaBhn.Length

#define MT(M,i,j) (M).Mem[(i)][(j)].Tray.T
#define MTopT(M,i,j) (M).Mem[(i)][(j)].Tray.T.TOP
#define MInfoTopT(M,i,j) (M).Mem[(i)][(j)].Tray.T.T[(M).Mem[(i)][(j)].Tray.T.TOP]


/*SELEKTOR PLAYER*/
#define Nama(P,i) (P).Nama.TabKata[i]
#define NamaLength(P) (P).Nama.Length

#define Life(P) (P).Life
#define Time(P) (P).Time
#define Money(P) (P).Money
#define PosisiX(P) (P).Posisi.X
#define PosisiY(P) (P).Posisi.Y

#define Hand(P) (P).H
#define TopH(P) (P).H.TOP
#define InfoTopH(P) (P).H.T[(P).H.TOP]


/*SELEKTOR CUSTOMER*/
#define Patience(C) (P).Patience
#define Quant(C) (P).Quantity


/*Pake Macros Kuy*/


#endif
