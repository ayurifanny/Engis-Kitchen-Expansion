/* File: dr-mesinkarkata.c */
/* driver dari  mesin karakter */

#include "mesinkar.h"
#include "mesinkata.h"
#include <stdio.h>

int main(){
    int i;
    char cAwal, cAkhir;
    printf("mencoba STARTR()\n"); //mencoba startr
    STARTR();
    printf("ini karakter pertama dari hasil membaca initruang.txt : %c\n", CC);
    ADV(); //mecoba adv
    printf("karakter setelah ADV() : %c\n", CC);
    ADV();
    printf("karakter setelah ADV() kembali : %c\n", CC);
    IgnoreBlank(); //mencoba ignore blank
    printf("karakter setelah IgnoreBlank() : %c\n", CC);
    SalinKata();
    printf("kata setelah SalinKata() : "); //mengecek apakaha salinan benar
    for(i=1; i<= CKata.Length; i++){
        printf("%c", CKata.TabKata[i]);
    }
    printf("\n");
    ADVKATA();
    printf("kata setelah ADVKATA() : "); //mengecek advkata
    for(i=1; i<= CKata.Length; i++){
        printf("%c", CKata.TabKata[i]);
    };
    printf("\n\n");


    printf("mencoba STARTK()\n"); //mencoba startk
    STARTK();
    printf("ini karakter pertama dari hasil membaca initkitchen.txt : %c\n", CC);
    ADV(); //mencoba adv
    printf("karakter setelah ADV() : %c\n", CC);
    ADV();
    printf("karakter setelah ADV() kembali : %c\n", CC);
    IgnoreBlank(); //mencoba ignore blank
    printf("karakter setelah IgnoreBlank() : %c\n", CC);
    SalinKata();
    printf("kata setelah SalinKata() : "); //mengecek apakah salinan benar
    for(i=1; i<= CKata.Length; i++){
        printf("%c", CKata.TabKata[i]);
    }
    printf("\n");
    ADVKATA();
    printf("kata setelah ADVKATA() : "); //mengecek advkata
    for(i=1; i<= CKata.Length; i++){
        printf("%c", CKata.TabKata[i]);
    };
    printf("\n\n");


    printf("mencoba STARTP()\n");
    STARTP(); //mencoba startp
    printf("ini karakter pertama dari hasil membaca player.txt : %c\n", CC);
    ADV(); //mencoba adv
    printf("karakter setelah ADV() : %c\n", CC);
    ADV();
    printf("karakter setelah ADV() kembali : %c\n", CC);
    IgnoreBlank(); //mencoba ignore blank
    printf("karakter setelah IgnoreBlank() : %c\n", CC);
    SalinKata();
    printf("kata setelah SalinKata() : "); //mengecek apakah salinan benar
    for(i=1; i<= CKata.Length; i++){
        printf("%c", CKata.TabKata[i]);
    }
    printf("\n");
    ADVKATA();
    printf("kata setelah ADVKATA() : "); //mengecek advkata
    for(i=1; i<= CKata.Length; i++){
        printf("%c", CKata.TabKata[i]);
    };
    printf("\n\n");


    return 0;
}


