// 11.Write a C program to implement Breadth-First Search (BFS) traversal on a graph
// and display the order in which the vertices are visited


#include <stdio.h>
#define MAX 20

int adj[MAX][MAX], visited[MAX];
int queue[MAX], front = -1, rear = -1;
int n;

void enqueue(int x) {
    if (rear == MAX - 1)
        return;

    if (front == -1)
        front = 0;

    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

void BFS(int start) {
    int i, v;

    visited[start] = 1;
    enqueue(start);

    printf("BFS Traversal: ");

    while (front <= rear) {
        v = dequeue();
        printf("%d ", v);

        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                enqueue(i);
            }
        }
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

    BFS(start);

    return 0;
}