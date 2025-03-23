#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5

int minDistance(int dist[], bool visited[]) {
  int min = INT_MAX, min_index;

  for (int v = 0; v < V; v++)
    if (!visited[v] && dist[v] <= min)
      min = dist[v], min_index = v;

  return min_index;
}

void dijkstra(int graph[V][V], int src) {
  int dist[V];
  bool visited[V];

  for (int i = 0; i < V; i++) {
    dist[i] = INT_MAX;
    visited[i] = false;
  }

  dist[src] = 0;

  for (int count = 0; count < V - 1; count++) {
    int u = minDistance(dist, visited);
    visited[u] = true;

    for (int v = 0; v < V; v++)
      if (!visited[v] && graph[u][v] && dist[u] != INT_MAX
          && dist[u] + graph[u][v] < dist[v])
        dist[v] = dist[u] + graph[u][v];
  }

  printf("Vertex  Distance from Source (%d)\n", src);
  for (int i = 0; i < V; i++)
    printf("%d \t %d\n", i, dist[i]);
}

int main() {
  int graph[V][V] = {
    {0, 2, 0, 6, 0},
    {2, 0, 3, 8, 5},
    {0, 3, 0, 0, 7},
    {6, 8, 0, 0, 9},
    {0, 5, 7, 9, 0}
  };

  dijkstra(graph, 0);

  printf("__________________________\n");
  printf("Programmed by: Pierce Neupane\n");
  return 0;
}
