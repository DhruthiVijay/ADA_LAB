#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define MAX 100
int findMinKey(int key[], bool mstSet[], int n) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < n; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}
void primMST(int graph[MAX][MAX], int n, int start) {
    int parent[MAX];
    int key[MAX];
    bool mstSet[MAX];
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX; 
        mstSet[i] = false;
    }
    key[start] = 0;
    parent[start] = -1;
    for (int count = 0; count < n - 1; count++) {
        int u = findMinKey(key, mstSet, n);
        mstSet[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    int totalWeight = 0;
    printf("\nMinimum Spanning Tree Edges:\n");
    for (int i = 0; i < n; i++) {
        if (i != start && parent[i] != -1) {
            printf("%d - %d (weight %d)\n", parent[i], i, graph[i][parent[i]]);
            totalWeight += graph[i][parent[i]];
        }
    }
    printf("Total weight of MST: %d\n", totalWeight);
}
int main() {
    int n, m, start;
    int graph[MAX][MAX] = {0};
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);
    printf("Enter %d edges (u v weight):\n", m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }
    printf("Enter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    if (start < 0 || start >= n) {
        printf("Invalid start vertex!\n");
        return 1;
    }
    primMST(graph, n, start);
    return 0;
}
