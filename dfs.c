// 12.Write a C program to implement Depth-First Search (DFS) traversal on a graph
// and display the order in which the vertices are visited.


#include <stdio.h>
#define MAX 20

int adj[MAX][MAX], visited[MAX];
int n;

void DFS(int v) {
    int i;

    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    printf("DFS Traversal: ");
    DFS(start);

    return 0;
}