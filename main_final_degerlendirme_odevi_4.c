#include "logistics.h"

/* Girdi hatalarini (bug) onleyen guvenli sayi alma fonksiyonu */
int guvenliSayiAl() {
    char buffer[100];
    int deger;
    int basarili = 0;

    while (!basarili) {
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            /* Girilen metinden sayi okumaya calis */
            if (sscanf(buffer, "%d", &deger) == 1) {
                basarili = 1;
            } else {
                printf("Hatali giris! Lutfen sadece RAKAM giriniz: ");
            }
        }
    }
    return deger;
}

/* Girdi hatasi onleyici metin alma fonksiyonu */
void guvenliMetinAl(char* hedef, int boyut) {
    fgets(hedef, boyut, stdin);
    /* Satir sonundaki Enter (\n) karakterini temizle */
    hedef[strcspn(hedef, "\n")] = 0; 
}

int main() {
    /* Degisken tanimlamalari (C89 uyumlu) */
    Package hashTable[TABLE_SIZE];
    Graph* logisticsGraph;
    int secim, id, baslangic, bitis;
    char icerik[50];

    initHashTable(hashTable);
    
    /* Dinamik ag icin maksimum 20 sehir kapasiteli graf olusturuldu */
    logisticsGraph = createGraph(20); 

    /* Ana Menu Dongusu */
    while (1) {
        printf("\n==========================================\n");
        printf("       LOJISTIK AGI VE PAKET SISTEMI      \n");
        printf("==========================================\n");
        printf("1. Yeni Paket Ekle (Hash Tablosuna)\n");
        printf("2. Paket Sorgula\n");
        printf("3. Sehirler Arasi Baglanti Ekle (Grafa)\n");
        printf("4. Lojistik Agini Tara (BFS ile)\n");
        printf("5. Cikis\n");
        printf("------------------------------------------\n");
        printf("Seciminiz (1-5): ");
        
        secim = guvenliSayiAl();

        switch (secim) {
            case 1:
                printf("\nEklenecek Paketin ID'si (Orn: 101): ");
                id = guvenliSayiAl();
                printf("Paketin Icerigi: ");
                guvenliMetinAl(icerik, sizeof(icerik));
                insertPackage(hashTable, id, icerik);
                break;

            case 2:
                printf("\nAranacak Paketin ID'si: ");
                id = guvenliSayiAl();
                searchPackage(hashTable, id);
                break;

            case 3:
                printf("\nBaglanti yapilacak 1. Sehir Kodu (0-19 arasi): ");
                baslangic = guvenliSayiAl();
                printf("Baglanti yapilacak 2. Sehir Kodu (0-19 arasi): ");
                bitis = guvenliSayiAl();
                
                if (baslangic >= 0 && baslangic < 20 && bitis >= 0 && bitis < 20) {
                    addEdge(logisticsGraph, baslangic, bitis);
                    printf("Baglanti basariyla eklendi: Sehir %d <---> Sehir %d\n", baslangic, bitis);
                } else {
                    printf("Hata: Gecersiz sehir kodu girdiniz!\n");
                }
                break;

            case 4:
                printf("\nBFS Taramasi Icin Baslangic Sehir Kodu: ");
                baslangic = guvenliSayiAl();
                if (baslangic >= 0 && baslangic < 20) {
                    BFS(logisticsGraph, baslangic);
                } else {
                    printf("Hata: Gecersiz sehir kodu!\n");
                }
                break;

            case 5:
                printf("\nSistemden cikiliyor... Iyi calismalar!\n");
                return 0;

            default:
                printf("\nHata: Gecersiz secim. Lutfen 1 ile 5 arasinda bir islem seciniz.\n");
                break;
        }
    }

    return 0;
}
