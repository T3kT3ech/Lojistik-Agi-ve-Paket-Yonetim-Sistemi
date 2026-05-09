#include "logistics.h"

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    int i; /* Degisken tanimi disa alindi */
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));
    
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void BFS(Graph* graph, int startVertex) {
    /* Tum degiskenler fonksiyonun en basinda tanimlandi */
    int visited[100] = {0}; 
    int queue[100];
    int front = 0, rear = 0;
    int currentVertex;
    int adjVertex;
    Node* temp;

    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("\nLojistik Agi BFS Tarama Sirasi: ");
    while (front < rear) {
        currentVertex = queue[front++];
        printf("%d ", currentVertex);

        temp = graph->adjLists[currentVertex];
        while (temp) {
            adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}
