#include <stdio.h>


#define SORU_SAYISI 10
#define SORU_MAKS_UZUNLUK 256
int enYuksekskor;
char userisim[21],enisim[21];
char soruSor(char *soru) {
    char cevap;
    printf("%s\n", soru);
    printf("Cevabini Gir (A/B/C/D): ");
    scanf(" %c", &cevap);
    return cevap;
}


int cevapKontrol(char kullaniciCevap, char dogruCevap, int skor) {
    if (kullaniciCevap == dogruCevap) {
        printf("Dogru!\n-------------------------------------------------------------\n");
        return skor + 1;
    }
    else {
        printf("Yanlis. Dogru Cevap: %c.\n-------------------------------------------------------------\n", dogruCevap);
        return skor;
    }
}


void quizBaslat(FILE *soruDosya, FILE *skorDosya) {
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
    if (skor > enYuksekskor){
        printf("Tebrikler, artik en yuksek skorun sahibisiniz.");
        FILE *enskorDosya = fopen("enskor.txt","w");
        enYuksekskor=skor;
        fprintf(enskorDosya,"%d\n%s",skor,userisim);
        fclose(enskorDosya);
    }
    else{}
}


int main() {
    FILE *soruDosya = fopen("sorular.txt","r"); //Soru dosyasını okuma modunda olucak sekilde acar
    FILE *skorDosya = fopen("skor.txt","a"); //Skor dosyasını append modunda olucak sekilde acar
    FILE *enskorDosya = fopen("enskor.txt","r");
    if (soruDosya == NULL || skorDosya == NULL) {
        printf("Hata: Dosya acilirken bir sorun olustu.\n");
        return 1; //Error verip cikar
    }
    fscanf(enskorDosya,"%d ",&enYuksekskor);
    fgets(enisim,sizeof(enisim),enskorDosya);
    fgetc(enskorDosya);
    printf("\n-- Quiz Proje Uygulamasi --\n");
    printf("\nEn Yuksek Skor %s Kullanicisinin Skoru:%d\n\n",enisim,enYuksekskor);
    printf("Isminizi giriniz: \n");
    scanf(" %s",&userisim);
    //Beyler Burda Skor dosyasında bi highscore değişkeni oluşturup onu yazdıralım.
    quizBaslat(soruDosya, skorDosya);
    fclose(soruDosya); //Soru dosyasını kapatır
    fclose(skorDosya); //Skor dosyasını kapatır
    fclose(enskorDosya);
    return 0;
}
