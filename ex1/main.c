#include <stdio.h>

#define MAX_EDGES 100

typedef struct {
    int a, b;
} Edge;

typedef struct {
    int n, m;
    Edge edges[MAX_EDGES];
} Graph;

void readFile(Graph *graph){
    FILE *f = fopen("graf.in", "r");
    fscanf(f, "%d %d", &graph->n, &graph->m);
    int i;
    for (i = 0; i < graph->m; i++)
        fscanf(f, "%d-%d", &graph->edges[i].a, &graph->edges[i].b);
    fclose(f);
}

void dfs(Graph *graph, int node, int visited[100], int step) {
    if (visited[node]) return;
    //printf("Step %d: %d\n", step, node);
    visited[node] = step;
    //printf("%d ", node);
    int i;
    for (i = 0; i < graph->m; i++) {
        if (graph->edges[i].a == node) {
            dfs(graph, graph->edges[i].b, visited, step+1);
        }
    }
}



int main() {
    Graph graph;
    readFile(&graph);
//    for(int i = 0; i < graph.m; i++)
//        printf("%d-%d\n", graph.edges[i].a, graph.edges[i].b);
    int visited[100] = {};
    dfs(&graph, 1, visited, 0);
    for(int i = 1; i <= graph.n; i++)
        printf("%d ", visited[i]);
    return 0;
}
