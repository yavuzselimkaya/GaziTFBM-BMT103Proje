
#include <stdio.h>
#include "quiz.h"

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
