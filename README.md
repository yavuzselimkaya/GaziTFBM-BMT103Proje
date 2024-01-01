#include <stdio.h>
    int main() {
        int secim;
        char secenek;

        do {
            printf("\n-- Quiz Proje Uygulamasi --\n");
            printf("\n ! Quizzde yapilan en yuksek skor 90'dir ! \n");

            printf("Seciminizi yapin (1-3): ");
            scanf("%d", &secim);

            switch (secim) {
                case 1:
                    // İlk switch case yapısı
                    printf("\n1. Menu\n");
                    printf("Fonksiyonu seciniz lutfen (1-3): ");
                    scanf("%d", &secim);

                    switch (secim) {
                        case 1:
                           skoralmafonksiyonu(); // Quiz scorunu alma fonksiyonu
                            break;
                        case 2:
                            Sorulariincelemefonksiyonu(); // Soruları inceleme fonksiyonu
                            break;
                        case 3:
                            Sorulariyazdirmafonksiyonu(); // Soruları yazdırma fonksiyonu
                            break;
                        default:
                            printf("Gecersiz secenek. Lutfen tekrar deneyin.\n");
                    }
                    break;

                case 2:
                    // İkinci switch case yapısı
                    printf("\n2. Menu\n");
                    printf("Seceneginizi giriniz lutfen (A-D): ");
                    scanf(" %c", &secenek);

                    switch (secenek) {
                        case 'A':
                            printf("A secenigini sectiniz\n");
                            break;
                        case 'B':
                            printf("B secenegini sectiniz\n");
                            break;
                        case 'C':
                            printf("C secenegini sectiniz\n");
                            break;
                        case 'D':
                            printf("D seceneginiz sectiniz\n");
                            break;
                        default:
                            printf("Gecersiz secenek girdiniz\n");
                    }
                    break;



                default:
                    printf("Gecersiz secenek. Lutfen tekrar deneyin.\n");
            }

            while ((getchar()) != '\n');

        } while (secim != 3);

        return 0;
    }
# GaziTFBM-BMT103Proje
