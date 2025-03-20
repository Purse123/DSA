#include <stdio.h>
#include <stdlib.h>

typedef struct EDGE {
  int src, dest, weight;
} EDGE;

typedef struct GRAPH {
  int num_vertices, num_edges;
  EDGE* edges;
} GRAPH;

GRAPH* createGraph(int vertices, int edges) {
  GRAPH* graph = (GRAPH*)malloc(sizeof(GRAPH));
  graph->num_vertices = vertices;
  graph->num_edges = edges;
  graph->edges = (EDGE*)malloc(edges * sizeof(EDGE));

  return graph;
}

int findParent(int parent[], int i) {
  if (parent[i] == i)
    return i;
  return parent[i] = findParent(parent, parent[i]);
}

void unionSets(int parent[], int rank[], int x, int y) {
  int rootX = findParent(parent, x);
  int rootY = findParent(parent, y);

  if (rank[rootX] < rank[rootY])
    parent[rootX] = rootY;
  else if (rank[rootX] > rank[rootY])
    parent[rootY] = rootX;
  else {
    parent[rootY] = rootX;
    rank[rootX]++;
  }
}

int compareEdges(const void* a, const void* b) {
  return ((EDGE*)a)->weight - ((EDGE*)b)->weight;
}

void kruskalMST(GRAPH* graph) {
  int v = graph->num_vertices;
  EDGE result[v - 1];
  int e = 0, i = 0;

  qsort(graph->edges, graph->num_edges, sizeof(EDGE), compareEdges);

  int* parent = (int*)malloc(v * sizeof(int));
  int* rank = (int*)calloc(v, sizeof(int));

  for (int j = 0; j < v; j++) parent[j] = j;

  while (e < v - 1 && i < graph->num_edges) {
    EDGE nextEdge = graph->edges[i++];

    int x = findParent(parent, nextEdge.src);
    int y = findParent(parent, nextEdge.dest);

    if (x != y) {
      result[e++] = nextEdge;
      unionSets(parent, rank, x, y);
    }
  }

  printf("Kruskal's MST:\n");
  for (i = 0; i < e; i++)
    printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);

  free(parent);
  free(rank);
}

int main() {
  int vertices = 5, edges = 7;
  GRAPH* graph = createGraph(vertices, edges);

  graph->edges[0] = (EDGE){0, 1, 2};
  graph->edges[1] = (EDGE){0, 3, 6};
  graph->edges[2] = (EDGE){1, 2, 3};
  graph->edges[3] = (EDGE){1, 3, 8};
  graph->edges[4] = (EDGE){1, 4, 5};
  graph->edges[5] = (EDGE){2, 4, 7};
  graph->edges[6] = (EDGE){3, 4, 9};

  kruskalMST(graph);

  free(graph->edges);
  free(graph);
  return 0;
}
