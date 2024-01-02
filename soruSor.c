
#include <stdio.h>
#include "quiz.h"

char soruSor(char *soru) {
    char cevap;
    printf("%s\n", soru);
    printf("Cevabini Gir (A/B/C/D): ");
    scanf(" %c", &cevap);
    return cevap;
}
