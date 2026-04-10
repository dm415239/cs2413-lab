#include "graph.h"

int count_edges(Graph* g) {
    if (!g) return 0;   // handle null pointer without needing <stddef.h>

    int count = 0;
    // Since the graph is undirected, only count upper triangular part (i < j)
    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = i + 1; j < MAX_NODES; j++) {
            if (g->adj[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}