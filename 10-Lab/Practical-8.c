#include <stdio.h>
#include <stdlib.h>

#define MAX 30

struct Edge {
    int u, v, w;
};

struct Subset {
    int parent;
    int rank;
};

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int compare(const void *a, const void *b) {
    return ((struct Edge*)a)->w - ((struct Edge*)b)->w;
}

void KruskalMST(struct Edge edges[], int V, int E) {
    struct Edge result[MAX];
    int e = 0, i = 0, total_weight = 0;

    qsort(edges, E, sizeof(edges[0]), compare);

    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < E) {
        struct Edge next = edges[i++];
        int x = find(subsets, next.u);
        int y = find(subsets, next.v);

        if (x != y) {
            result[e++] = next;
            Union(subsets, x, y);
            total_weight += next.w;
        }
    }

    printf("\nEdges in the Minimum Spanning Tree:\n");
    for (i = 0; i < e; i++)
        printf("%d -- %d  Weight: %d\n", result[i].u, result[i].v, result[i].w);

    printf("\nTotal weight of MST = %d\n", total_weight);

    free(subsets);
}

int main() {
    int V, adj[MAX][MAX];
    struct Edge edges[MAX];
    int E = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Convert matrix to edge list
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (adj[i][j] != 0) {
                edges[E].u = i;
                edges[E].v = j;
                edges[E].w = adj[i][j];
                E++;
            }
        }
    }

    KruskalMST(edges, V, E);
    return 0;
}


