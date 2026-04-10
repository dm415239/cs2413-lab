#include "graph.h"

int count_isolated(Graph* g) {
    if (!g) return 0;

    int isolated_count = 0;

    for (int i = 0; i < MAX_NODES; i++) {
        int has_edge = 0;
        for (int j = 0; j < MAX_NODES; j++) {
            // Skip self-loop check (usually diagonal is 0)
            if (i != j && g->adj[i][j] == 1) {
                has_edge = 1;
                break;
            }
        }
        if (!has_edge) {
            isolated_count++;
        }
    }

    return isolated_count;
}