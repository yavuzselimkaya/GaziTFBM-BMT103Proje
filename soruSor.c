
#include <stdio.h> //Standart C Kütüphanesi
#include "quiz.h" //Fonksiyonları kendi dosyalarından çekmek için oluşturduğumuz Header'ı tanımladığımız satır

//Soruyu ekrana yazıp kullanıcının cevabını alan fonksiyon
char soruSor(char *soru) {
    char cevap;
    printf("%s\n", soru);
    printf("Cevabini Gir (A/B/C/D): ");
    scanf(" %c", &cevap);
    return cevap;
}
