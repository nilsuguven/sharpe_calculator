#include <stdio.h>

int main (void) {
    double return_pct, riskfree_pct, stddev_pct, sharpe;

    // ---Giriş mesajı ---
    printf("=====================================\n");
    printf("  SHARPE ORANI HESAPLAMA PROGRAMI  \n");
    printf("=====================================\n\n");
    printf("Bu program aldiginiz risk karsiliginda\n");
    printf("elde ettiginiz fazladan getiriyi hesaplar.\n\n");

    // --- Kullanıcıdan verileri al ---
    printf("Yatirim getirisi (%%): ");
    scanf("%lf", &return_pct);

    printf("Risksiz faiz orani (%%): ");
    scanf("%lf", &riskfree_pct);

    printf("Portfoy standart sapmasi (%%): ");
    scanf("%lf", &stddev_pct);

    // --- Risk 0 olamaz kontrolü ---
    if (stddev_pct == 0) {
        printf("Hata: Standart sapma 0 olamaz.\n");
        return 1;
    }
    // --- Hesaplama ---
    sharpe = (return_pct - riskfree_pct) / stddev_pct;

    // --- Sonuçları düzenli göster ---
    printf("\n-------------------------------------\n");
    printf("           SONUÇLAR RAPORU           \n");
    printf("-------------------------------------\n");
    printf("Yatirim getirisi  : %.2f%%\n", return_pct);
    printf("Risksiz faiz orani: %.2f%%\n", riskfree_pct);
    printf("Standart sapma    : %.2f%%\n", stddev_pct);
    printf("-------------------------------------\n");
    printf("Sharpe Orani      : %.2f\n", sharpe);

    // --- Yorum kısmı ---
    if (sharpe < 0)
        printf("Yorum: Negatif Sharpe. Risksiz orandan daha dusuk performans.\n");
    else if (sharpe < 1.0)
        printf("Yorum: Orta duzeyde performans.\n");
    else if (sharpe < 2.0)
        printf("Yorum: Iyi performans.\n");
    else if (sharpe < 3.0)
        printf("Yorum: Cok iyi performans.\n");
    else
        printf("Yorum: Mukemmel performans!\n");

    printf("-------------------------------------\n");

    return 0;

}