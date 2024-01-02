#include <stdio.h>
#include <stdlib.h>

#define SORU_SAYISI 10
#define SORU_MAKS_UZUNLUK 256


char soruSor(char *soru) {
    char cevap;
    printf("%s\n", soru);
    printf("Cevabını Gir (A/B/C/D): ");
    scanf(" %c", &cevap);
    return cevap;
}


int cevapKontrol(char kullaniciCevap, char dogruCevap, int skor) {
    if (kullaniciCevap == dogruCevap) {
        printf("Dogru!\n");
        return skor + 1;
    }
    else {
        printf("Yanlıs. Dogru Cevap: %c.\n", dogruCevap);
        return skor;
    }
}


void quizBaslat(FILE *soruDosya, FILE *skorDosya) {
    char soru[SORU_MAKS_UZUNLUK], dogruCevap, kulaniciCevap;
    int skor = 0;
    for (int i = 1; i <= SORU_SAYISI; ++i) {

        //soruyu çek************************
        //cevabı çek****************************
        kulaniciCevap = soruSor(soru);
        skor = cevapKontrol(kulaniciCevap, dogruCevap, skor);


    }



    printf("Skorunuz: %d\n", skor);
    //DOSYAYA SKOR YAZDIRMA//////////////////////*********************
}

int main() {
            printf("\n-- Quiz Proje Uygulamasi --\n");
            printf("\n ! Quizde yapilan en yuksek skor %d'dir ! \n",enYuksekSkor);
            //Beyler Burda Skor dosyasında bi highscore değişkeni oluşturup onu yazdıralım.
            //DOSYALARI AÇ********************
            quizBaslat(soruDosya, skorDosya);
            //*******DOSYA KAPA*********

    return 0;
}

