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

NODE* createNode(int vertex) {
  NODE* newNode = (NODE*)malloc(sizeof(NODE));
  newNode->vertex = vertex;
  newNode->next = NULL;

  return newNode;
}

GRAPH* createGraph(int no_of_v) {
  GRAPH* graph = (GRAPH *)malloc(sizeof(GRAPH));
  graph->num_vertices = no_of_v;

  // linked list of each vertex
  graph->adj_lists = (NODE **)malloc(no_of_v * sizeof(NODE *));
  
  for (int i = 0; i < no_of_v; ++i) {
    graph->adj_lists[i] = NULL;
  }

  return graph;
}

void addEdge(GRAPH* graph, int src, int dest) {
  NODE* newNode = createNode(dest);
  newNode->next = graph->adj_lists[src];
  graph->adj_lists[src] = newNode;

  newNode = createNode(src);
  newNode->next = graph->adj_lists[dest];
  graph->adj_lists[dest] = newNode;
}

void bfs(GRAPH* graph, int start_vertex) {
  int* visited = (int*)calloc(graph->num_vertices, sizeof(int));
  int queue[graph->num_vertices], front = 0, rear = 0;

  queue[rear++] = start_vertex;
  visited[start_vertex] = 1;

  printf("BFS Traversal: ");
  while (front < rear) {
    int current = queue[front++];
    printf("%d ", current);

    NODE* temp = graph->adj_lists[current];
    while (temp) {
      if (!visited[temp->vertex]) {
	queue[rear++] = temp->vertex;
	visited[temp->vertex] = 1;
      }
      temp = temp->next;
    }
  }
  printf("\n");
  free(visited);
}

int main() {
  int v = 4;
  GRAPH* g = createGraph(v);

  addEdge(g, 0, 1);
  addEdge(g, 0, 2);
  addEdge(g, 1, 2);
  addEdge(g, 2, 3);

  bfs(g, 0);
  return 0;
}
