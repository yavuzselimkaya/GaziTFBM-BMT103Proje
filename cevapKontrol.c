
#include <stdio.h> //Standart C Kütüphanesi
#include "quiz.h" //Fonksiyonları kendi dosyalarından çekmek için oluşturduğumuz Header'ı tanımladığımız satır

//Kullanıcının cevabını kontrol edip ona gore skoru hesaplayan fonksiyon
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
