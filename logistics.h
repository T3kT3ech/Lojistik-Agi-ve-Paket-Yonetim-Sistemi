#ifndef LOGISTICS_H
#define LOGISTICS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

/* --- HASH TABLOSU YAPISI (Paketler Icin) --- */
typedef struct {
    int package_id;
    char content[50];
    int is_full; 
} Package;

/* --- GRAF YAPISI (Sehir Aglari Icin) --- */
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

/* Fonksiyon Prototipleri */
void initHashTable(Package* table);
void insertPackage(Package* table, int id, const char* content);
void searchPackage(Package* table, int id);

Graph* createGraph(int vertices);
void addEdge(Graph* graph, int src, int dest);
void BFS(Graph* graph, int startVertex);

#endif
