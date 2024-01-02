
#include <stdio.h>
#include "quiz.h"

int main() {
    FILE *soruDosya = fopen("sorular.txt","r");
    FILE *skorDosya = fopen("skor.txt","a");
    FILE *enskorDosya = fopen("enskor.txt","r");

    if (soruDosya == NULL || skorDosya == NULL) {
        printf("Hata: Dosya acilirken bir sorun olustu.\n");
        return 1;
    }

    int enYuksekskor;
    char userisim[21], enisim[21];
    fscanf(enskorDosya,"%d ", &enYuksekskor);
    fgets(enisim,sizeof(enisim),enskorDosya);
    fgetc(enskorDosya);
    printf("\n-- Quiz Proje Uygulamasi --\n");
    printf("\nEn Yuksek Skor %s Kullanicisinin Skoru:%d\n\n",enisim,enYuksekskor);
    printf("Isminizi giriniz: \n");
    scanf(" %s", &userisim);

    quizBaslat(soruDosya, skorDosya, userisim, &enYuksekskor);

    fclose(soruDosya);
    fclose(skorDosya);
    fclose(enskorDosya);
    printf("Programdan cıkmak icin cikis yazınız\n");
    scanf(" %c");
    return 0;
}