
#include <stdio.h> //Standart C Kütüphanesi
#include "quiz.h" //Fonksiyonları kendi dosyalarından çekmek için oluşturduğumuz Header'ı tanımladığımız satır

int main() {
    FILE *soruDosya = fopen("sorular.txt","r"); //Sorular dosyasını actığımız satır
    FILE *skorDosya = fopen("skor.txt","a"); //Skorlar dosyasını actığımız satır
    FILE *enskorDosya = fopen("enskor.txt","r");  //En yüksek skor dosyasını actığımız satır

    //Dosya düzgün acıldı mı kontrol eden döngü
    if (soruDosya == NULL || skorDosya == NULL) {
        printf("Hata: Dosya acilirken bir sorun olustu.\n");
        return 1;
    }

    //Dosya açılma işlemlerinin yapıldığı ve Quizin ana ekranının oluşturuldupu yer
    int enYuksekskor; //En yüksek skor değişkeninin tanımlanması
    char userisim[21], enisim[21]; //Kullanıcının ve en yuksek skorun sahibinin isminin tanımlanması
    fscanf(enskorDosya,"%d ", &enYuksekskor); //En yüksek skorun dosyadan okunması
    fgets(enisim,sizeof(enisim),enskorDosya); //En yüksek skorun sahibinin isminin dosyadan okunması
    fgetc(enskorDosya); //Bellekte kalan newline karakterinin yok edilmesi
    printf("\n-- Quiz Proje Uygulamasi --\n");
    printf("\nCevaplarinizi buyuk harf olarak giriniz.\n");
    printf("\nEn Yuksek Skor %s Kullanicisinin Skoru:%d\n\n",enisim,enYuksekskor);
    printf("Isminizi giriniz: \n");
    scanf(" %s", &userisim); //Kullanıcıdan ismini sorar

    //Quiz fonksiyonunun başlatılması
    quizBaslat(soruDosya, skorDosya, userisim, &enYuksekskor);

    //Dosyaların kapatılması
    fclose(soruDosya); 
    fclose(skorDosya);
    fclose(enskorDosya);
    //Kullanıcıdan girdi alana kadar programı acık tutar
    printf("Programdan cikmak icin cikis yaziniz\n");
    scanf(" %c");
    return 0;
}
