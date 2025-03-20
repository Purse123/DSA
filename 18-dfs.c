#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
  int vertex;
  struct NODE* next;
} NODE;

typedef struct GRAPH {
  int num_vertices;
  NODE** adj_lists;
} GRAPH;

GRAPH* createGraph(int vertices) {
  GRAPH* graph = (GRAPH*)malloc(sizeof(GRAPH));
  graph->num_vertices = vertices;
  graph->adj_lists = (NODE**)malloc(vertices * sizeof(NODE*));

  for (int i = 0; i < vertices; i++)
    graph->adj_lists[i] = NULL;

  return graph;
}

NODE* createNode(int vertex) {
  NODE* newNode = (NODE*)malloc(sizeof(NODE));
  newNode->vertex = vertex;
  newNode->next = NULL;
  return newNode;
}

void addEdge(GRAPH* graph, int src, int dest) {
  NODE* newNode = createNode(dest);
  newNode->next = graph->adj_lists[src];
  graph->adj_lists[src] = newNode;

  newNode = createNode(src);
  newNode->next = graph->adj_lists[dest];
  graph->adj_lists[dest] = newNode;
}

void dfsUtil(GRAPH* graph, int vertex, int* visited) {
  printf("%d ", vertex);
  visited[vertex] = 1;

  NODE* temp = graph->adj_lists[vertex];
  while (temp) {
    if (!visited[temp->vertex])
      dfsUtil(graph, temp->vertex, visited);
    temp = temp->next;
  }
}

void dfs(GRAPH* graph, int start_vertex) {
  int* visited = (int*)calloc(graph->num_vertices, sizeof(int));
  printf("DFS Traversal: ");
  dfsUtil(graph, start_vertex, visited);
  printf("\n");
  free(visited);
}

int main() {
  GRAPH* g = createGraph(4);

  addEdge(g, 0, 1);
  addEdge(g, 0, 2);
  addEdge(g, 1, 2);
  addEdge(g, 2, 3);

  dfs(g, 0);
  return 0;
}
