
#include <stdio.h>
#include "quiz.h"

void quizBaslat(FILE *soruDosya, FILE *skorDosya, char *userisim, int *enYuksekskor) {
    char soru[SORU_MAKS_UZUNLUK], dogruCevap, kullaniciCevap;
    int skor = 0;
    for (int i = 1; i <= SORU_SAYISI; ++i) {
        fgets(soru, sizeof(soru), soruDosya);
        dogruCevap = fgetc(soruDosya);
        fgetc(soruDosya);
        kullaniciCevap = soruSor(soru);
        skor = cevapKontrol(kullaniciCevap, dogruCevap, skor);
    }
    printf("Skorunuz: %d\n", skor);
    fprintf(skorDosya,"%s Kullanicisinin Skoru: %d\n",userisim,skor);
    if (skor > *enYuksekskor){
        printf("Tebrikler, artik en yuksek skorun sahibisiniz.");
        FILE *enskorDosya = fopen("enskor.txt","w");
        *enYuksekskor=skor;
        fprintf(enskorDosya,"%d\n%s",skor,userisim);
        fclose(enskorDosya);

    }
}
