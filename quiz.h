//Fonksiyonları dışardan çekebilmek için kullandığımız dosya
#ifndef QUIZ_H
#define QUIZ_H

#include <stdio.h>

#define SORU_MAKS_UZUNLUK 256
#define SORU_SAYISI 10

char soruSor(char *soru);
int cevapKontrol(char kullaniciCevap, char dogruCevap, int skor);
void quizBaslat(FILE *soruDosya, FILE *skorDosya, char *userisim, int *enYuksekskor);

#endif
