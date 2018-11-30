
/* File: jam.h */
/* Tanggal: 6 September 2018 */
/* Definisi ADT JAM */

#include "jam.h"
#include "boolean.h"
#include <stdio.h>

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsJAMValid (int H, int M, int S)
/* Mengirim true  jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
{
   return ( (H<24 && H>=0) && (M >= 0 && M < 60) && (S >= 0 && S < 60) );
}

/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
JAM MakeJAM (int HH, int MM, int SS)
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */
{
   /*KAMUS*/
   JAM J;
   /*ALGORITMA*/
   Hour(J) = HH;
   Minute(J) = MM;
   Second(J) = SS;

   return J;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaJAM (JAM * J) 
/* I.S. : J tidak terdefinisi */
/* F.S. : J terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk J */
/* yang valid. Tidak mungkin menghasilkan J yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika JAM tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh: 
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk JAM <1,3,4> */
{
   /*KAMUS*/
   int h, m, s;
   /*ALGORITMA*/
   do
      {
         scanf("%d %d %d", &h, &m, &s);
         if (!IsJAMValid(h,m,s)) {
            printf("Jam tidak valid\n");
         }
      }
   while (!IsJAMValid(h,m,s));
   *J = MakeJAM(h,m,s);

}
   
void TulisJAM (JAM J)
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/ 
{
   printf("%d:%d:%d", Hour(J), Minute(J), Second(J) );
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long JAMToDetik (JAM J)
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */
{
   return (3600*Hour(J)+60*Minute(J)+Second(J));
}
JAM DetikToJAM (long N) 
/* Mengirim  konversi detik ke JAM */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang 
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus: 
   N1 = N mod 86400, baru N1 dikonversi menjadi JAM */
{
   /*KAMUS*/
   int HH, MM, SS;
   /*ALGORITMA*/
   if (N >= 86400) {
      N = N% 86400;
   } else if (N < 0) {
      N = N+86400;
   }

   HH = N/3600;
   N = N%3600;
   MM = N/60;
   SS = N%60;

   return (MakeJAM(HH, MM, SS));

}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Operator aritmatika JAM *** */
JAM NextDetik (JAM J)
/* Mengirim 1 detik setelah J dalam bentuk JAM */
{
   return (DetikToJAM (JAMToDetik(J)+1));
}
