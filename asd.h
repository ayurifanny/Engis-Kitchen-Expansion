#ifndef asd_H
#define asd_H

#include "matriks.h"
#include "queue.h"
#include "array.h"
#include "stackt.h"
#include "engis.h"
#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int randomDateng();
/* Merandom interval orang yg dateng */

Kata randomOrder();
/* Merandom makanan yang dipesan customer */

void Order(Player P, MATRIKS *M, TabStr *O);
/* Mengambil orderan pelanggan */
/* I.S. Player, Peta, dan Tabel orderan terdefinisi */
/* F.S. Jika di tempat yang benar dan mejanya ada customer yang beom */
/* pesen nanti isi Tabel orderan bertambah */

boolean Compare(infotypeT it, infotypeS is);
/* Membandingkan yang bertipe infotypeT dengan infotypeS */

void balik(Stack *S1, Stack *S2);
/* Membalik urutan stack */
/* I.S. Stack1 terdefinisi */
/* F.S. Stack2 berisi stack1 yang terbalik urutannya */

void Put(MATRIKS *M, Player *P, BinTree Menu);
/* Mengolah bahan yang ada di tangan menjadi makanan dan memasukkan */
/* ke tray */
/* I.S. Peta, Player, Menu terdefinisi */
/* F.S. Jika di tempat yang benar, tray tidak penuh, dan bahan di */
/* tangan urutannya sesuai tree menu maka bahan di tangan dihapus dan */
/* makanan yang sesuai dimasukkan ke tray */

void Take(MATRIKS M, Player *P);
/* Mengambil bahan dari kompor */
/* I.S. Peta dan Player terdefinisi */
/* F.S. Jika di tempat yang benar maka bahan dimasukkan ke hand */

void CH(Player *P);
/* Mengosongkan tangan */
/* I.S. Player terdefinisi */
/* F.S. Stack tangan menjadi kosong */

void CT(MATRIKS *M, Player P);
/* Mengosongkan tray */
/* I.S. Peta dan Player terdefinisi */
/* F.S. Jika di tempat yang benar, stack tray menjadi kosong */

void Give (Player *P, MATRIKS *M, Stack *S, TabStr *O, Customer AC[13]);
/* Memberikan makanan yang ada di top of tray ke customer yang duduk */
/* I.S. Player, Peta, Tray, Tabel orderan, dan Tabel customer yang */
/* duduk terdefinisi */
/* F.S. Jika di tempat yang benar dan makanan dengan nomor mejanya */
/* sesuai, maka makanan dihapus dari tray, meja kursi kosong, dan uang */
/* bertambah sesuai makanannya */

void Place (MATRIKS MM[5], MATRIKS *M, Player P, Queue *Q, Customer AC[13], TabStr *O);
/* Menempatkan customer yang mengantri ke kursi yang kosong */
/* I.S. Peta, Player, Antrian, Tabel customer yang duduk, Tabel orderan */
/* terdefinisi */
/* F.S. Jika di tempat yang tepat maka antrian terdepan duduk. Kalo gak */
/* ada tempat yang bener buat antrian terdepan, yg belakangnya kalo */
/* tepat bisa duluan duduk */

void randomAntrian(Queue *Q);
/* Merandom jumlah customer yang datang */
/* I.S. Antrian terdefinisi */
/* F.S. Customer dengan jumlah random datang dan masuk antrian */

int strcom(char *str1, char *str2);
/* Membandingkan 2 string, bernilai 0 jika sama */

void strcop (char *str1, char *str2);
/* Menyalin isi string str2 ke str1*/
/* I.S. str2 terdefinisi */
/* F.S. str1 berisi str2 */

void kurangPatience (MATRIKS *M, Queue *Q, Customer duduk[13], Player *P, TabStr *O);
/* Mengurangi patience pelanggan yang di antrian maupun duduk sebanyak */
/* sebanyak 1 */
/* I.S. Peta, Antrian, Tabel customer yang duduk, Player, dan Tabel */
/* orderan terdefinisi */
/* F.S. Patience semua customer di antrian dan yang duduk berkurang 1. */
/* Kalo udah 0 dihapus dari antrian atau tempat duduk dan life berkurang */

boolean cekVacant4 (MATRIKS M);
/* Mengecek apakah semua kursi yang 4 orang terisi. True jika masih */
/* ada yang kosong */

boolean cekAntri2 (Queue Q);
/* Mengecek apakah di antrian belakang head ada yang berjumalah 2 org */
/* True jika ada */

#endif
