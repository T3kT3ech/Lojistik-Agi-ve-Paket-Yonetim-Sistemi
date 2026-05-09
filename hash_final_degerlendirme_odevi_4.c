#include "logistics.h"

int hashFunctionA(int key) {
    return key % TABLE_SIZE;
}

void initHashTable(Package* table) {
    int i; /* Degisken tanimi disa alindi */
    for (i = 0; i < TABLE_SIZE; i++) {
        table[i].is_full = 0;
    }
}

void insertPackage(Package* table, int id, const char* content) {
    int index = hashFunctionA(id);
    int original_index = index;

    while (table[index].is_full) {
        index = (index + 1) % TABLE_SIZE; 
        if (index == original_index) {
            printf("Hata: Hash tablosu dolu!\n");
            return;
        }
    }
    table[index].package_id = id;
    strcpy(table[index].content, content);
    table[index].is_full = 1;
    printf("Paket %d basariyla %d indeksine eklendi.\n", id, index);
}

void searchPackage(Package* table, int id) {
    int index = hashFunctionA(id);
    int original_index = index;

    while (table[index].is_full) {
        if (table[index].package_id == id) {
            printf("Sorgu Sonucu -> ID: %d | Icerik: %s | Bellek Indeksi: %d\n", id, table[index].content, index);
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == original_index) break;
    }
    printf("Paket %d agda bulunamadi.\n", id);
}
