#include "graph.h"

int has_triangle(Graph* g) {
    if (!g) return 0;

    // Check all triples of distinct nodes (i < j < k)
    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = i + 1; j < MAX_NODES; j++) {
            if (g->adj[i][j] == 0) continue; // edge i-j missing, skip this pair
            for (int k = j + 1; k < MAX_NODES; k++) {
                if (g->adj[i][k] == 1 && g->adj[j][k] == 1) {
                    return 1; // triangle found
                }
            }
        }
    }
    return 0; // no triangle found
}