
#include <stdio.h> //Standart C Kütüphanesi
#include "quiz.h" //Fonksiyonları kendi dosyalarından çekmek için oluşturduğumuz Header'ı tanımladığımız satır

//Quizi başlatan ana fonksiyon
void quizBaslat(FILE *soruDosya, FILE *skorDosya, char *userisim, int *enYuksekskor) {
    char soru[SORU_MAKS_UZUNLUK], dogruCevap, kullaniciCevap; //Soru ve cevap değişkenlerini tanımlar
    int skor = 0; //Başlangıç skorunu 0 olarak ayarlar
    //Sıra sıra her sorunun çalışmasını sağlayan for döngüsü
    for (int i = 1; i <= SORU_SAYISI; ++i) {
        fgets(soru, sizeof(soru), soruDosya); //Soru dosyasından soruyu okur
        dogruCevap = fgetc(soruDosya); //Soru dosyasından doğru cevabı okur
        fgetc(soruDosya); //Okuduktan sonra gelen newline karakterini yutar
        kullaniciCevap = soruSor(soru); //Soru sorma fonksiyonundan gelen değeri kullanıcıCevap değişkenine atar
        skor = cevapKontrol(kullaniciCevap, dogruCevap, skor); //Cevap kontrol fonksiyonundan gelen değeri skor değişkenine atar
    }
    printf("Skorunuz: %d\n", skor); 
    fprintf(skorDosya,"%s Kullanicisinin Skoru: %d\n",userisim,skor); //Kullanıcının skorunu ismiyle beraber Skor dosyasına yazar
    //Kullanıcının yeni bir en yüksek skor yapıp yapmadığına bakar, duruma gore bunu en yuksek skor dosyasına kaydeder
    if (skor > *enYuksekskor){
        printf("Tebrikler, artik en yuksek skorun sahibisiniz.\n\n");
        FILE *enskorDosya = fopen("enskor.txt","w");
        *enYuksekskor=skor;
        fprintf(enskorDosya,"%d\n%s",skor,userisim);
        fclose(enskorDosya);

    }
}
