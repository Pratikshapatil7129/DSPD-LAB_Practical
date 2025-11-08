#include <stdio.h>

int adj[20][20], visited[20];
int n;

void BFS(int start) {
    int queue[20], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal: ");
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 1; i <= n; i++) {
            if (adj[node][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

void DFS(int node) {
    printf("%d ", node);
    visited[node] = 1;

    for (int i = 1; i <= n; i++) {
        if (adj[node][i] && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    int edges, u, v, start;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            adj[i][j] = 0;

    printf("Enter each edge (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }

    printf("Enter starting node: ");
    scanf("%d", &start);

    for (int i = 1; i <= n; i++)
        visited[i] = 0;
    BFS(start);

    for (int i = 1; i <= n; i++)
        visited[i] = 0;
    printf("DFS Traversal: ");
    DFS(start);

    printf("\n");
    return 0;
}
