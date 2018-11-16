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
	Kata Nama;
	int Life;
	int Money;
	int Time;
	Stack H;
	POINT Posisi;
} Player;

typedef struct {
	int Patience;
	int Quantity;
} Customer;

typedef struct {
	boolean Meja;
	boolean VacantT;
	int Number;
	Kata Order; //belom fix
} table;

/*Kalo M[x][y] itu adalah kursi, Kursi : boolean = true*/
/*Vacant -> kosong apa ngga kursinya*/
/*Kalo boolean false, vacant false jg*/
typedef struct {
	boolean Kursi;
	boolean VacantC; 
	int No;
} chair;

typedef struct {
	boolean IsValid;
	int XObj;
	int YObj; 
	int No;
} valid;

/*Kalo M[x][y] itu adalah kompor, Kompor : boolean = true*/
/*NamaBhn -> Bahan apa yg di ada di situ*/
/*kalo Kompor false, NamaBhn isi 0*/
typedef struct {
	boolean Kompor;
	Kata NamaBhn; //belomfix 
} stove;

/*Kalo M[x][y] itu adalah tray, Tray : boolean = true*/
/*Full -> full apa ngga nampannya (full itu isinya udh 5 makanan)*/
/*T -> isi stacknya*/
/*Kalo Tray == false, stack empty, full false*/
typedef struct {
	boolean Nampan;
	Stack T;
} tray;
/*Kalo M[x][y] letaknya di tengah2, E = false, yg lain isi false jg*/
typedef struct {
	boolean E; //ngasi tau ini edge apa ngga, kalo bukan gosah cek L,R,U,D
	boolean L;
	boolean R;
	boolean U;
	boolean D;
} edge;

typedef struct {
	boolean Avail; //bisa di lewati player apa ngga
	valid Valid;
	boolean Door;
	table Table;
	chair Chair;
	stove Stove; 
	tray Tray;
	edge Edge;
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
#define MEdge(M,i,j) (M).Mem[(i)][(j)].Edge.E

#define MValid(M,i,j) (M).Mem[(i)][(j)].Valid.IsValid
#define GetIdxObjX(M,i,j) (M).Mem[(i)][(j)].Valid.XObj
#define GetIdxObjY(M,i,j) (M).Mem[(i)][(j)].Valid.YObj


#define MTableVac(M,i,j) (M).Mem[(i)][(j)].Table.VacantT
#define MTableNum(M,i,j) (M).Mem[(i)][(j)].Table.Number
#define MTableOrder(M,i,j,k) (M).Mem[(i)][(j)].Table.Order.TabKata[k]

#define MChairVac(M,i,j) (M).Mem[(i)][(j)].Chair.VacantC
#define MChairNo(M,i,j) (M).Mem[(i)][(j)].Chair.No


#define MNamaBhn(M,i,j,k) (M).Mem[(i)][(j)].Stove.NamaBhn.TabKata[k]

#define MT(M,i,j) (M).Mem[(i)][(j)].Tray.T
#define MTopT(M,i,j) (M).Mem[(i)][(j)].Tray.T.TOP
#define MInfoTopT(M,i,j) (M).Mem[(i)][(j)].Tray.T.T[(M).Mem[(i)][(j)].Tray.T.TOP]

#define MEdgeL(M,i,j) (M).Mem[(i)][(j)].Edge.L
#define MEdgeU(M,i,j) (M).Mem[(i)][(j)].Edge.U
#define MEdgeR(M,i,j) (M).Mem[(i)][(j)].Edge.R
#define MEdgeD(M,i,j) (M).Mem[(i)][(j)].Edge.D


/*SELEKTOR PLAYER*/
#define Nama(P) (P).Nama
#define Life(P) (P).Life
#define Time(P) (P).Time
#define Money(P) (P).Money
#define Posisi(P) (P).Posisi
#define Hand(P) (P).H
#define TopH(P) (P).H.TOP
#define InfoTopH(P) (P).H.T[(P).H.TOP]

/*SELEKTOR CUSTOMER*/
#define Patience(C) (P).Patience
#define Quant(C) (P).Quantity


/*Pake Macros Kuy*/



#endif
