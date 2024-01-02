#include <stdio.h>
#include <stdlib.h>

#define SORU_SAYISI 10
#define SORU_MAKS_UZUNLUK 256


char soruSor(char *soru) {
    char cevap;
    printf("%s\n", soru);
    printf("Cevabini Gir (A/B/C/D): ");
    scanf(" %c", &cevap);
    return cevap;
}


int cevapKontrol(char kullaniciCevap, char dogruCevap, int skor) {
    if (kullaniciCevap == dogruCevap) {
        printf("Dogru!\n");
        return skor + 1;
    }
    else {
        printf("Yanlis. Dogru Cevap: %c.\n", dogruCevap);
        return skor;
    }
}


void quizBaslat(FILE *soruDosya, FILE *skorDosya) {
    char soru[SORU_MAKS_UZUNLUK], dogruCevap, kulaniciCevap;
    int skor = 0;
    for (int i = 1; i <= SORU_SAYISI; ++i) {

        fgets(soru, sizeof(soru), soruDosya);
        dogruCevap = fgetc(soruDosya);
        fgetc(soruDosya); //fgets bi bos karakter falan atiyor o yuzden sorulari duzgun okumuyor o karakteri yok etmek icin boyle bisey yaptım
        kulaniciCevap = soruSor(soru);
        skor = cevapKontrol(kulaniciCevap, dogruCevap, skor);
    }
    printf("Skorunuz: %d\n", skor);
    fprintf(skorDosya,"Oyuncu Skoru: %d\n",skor);
}


int main() {
    FILE *soruDosya = fopen("sorular.txt","r"); //Soru dosyasını okuma modunda olucak sekilde acar
    FILE *skorDosya = fopen("skor.txt","a"); //Skor dosyasını append modunda olucak sekilde acar
    if (soruDosya == NULL || skorDosya == NULL) {
        printf("Hata: Dosya acilirken bir sorun olustu.\n");
        return 1; //Error verip cikar
    }
    printf("\n-- Quiz Proje Uygulamasi --\n");
    //printf("\n ! Quizde yapilan en yuksek skor %d'dir ! \n",enYuksekSkor);
    //Beyler Burda Skor dosyasında bi highscore değişkeni oluşturup onu yazdıralım.
    quizBaslat(soruDosya, skorDosya);
    fclose(soruDosya); //Soru dosyasını kapatır
    fclose(skorDosya); //Skor dosyasını kapatır
    return 0;
}
