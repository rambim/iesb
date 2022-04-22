#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
//======================LIST
typedef struct {
  void**  values;
  size_t  len, capacity;
  void*   minimum;
  int     (*compare)(const void*, const void*);
} ArrList;
 
ArrList* init_list(size_t capacity, int (*compare)(const void*, const void*)) {
  ArrList *l = (ArrList*) calloc(1, sizeof(ArrList));
  l->capacity = capacity;
  l->len = 0;
  l->values = (void**) calloc(capacity + 1, sizeof(void*));
  l->values[capacity] = NULL;
  l->compare = compare;
  return l;
}
 
void add_value(ArrList *l, void *value) {
  if(l->len == l->capacity) {
    l->capacity += 100;
    l->values = realloc(l->values, 2*l->capacity);
  }
  if(l->minimum == NULL || l->compare(l->minimum, value) > 0)
    l->minimum = value;
  l->values[l->len++] = value;
}
 
bool is_empty(ArrList *list) { return list->len == 0;}
//======================END LIST
 
//======================GRAPH
typedef enum { WHITE = 1, GREY = 2, BLACK = 3 } COLOR;
typedef struct {
  int   value;
  bool  enabled;
  ArrList *adj_list;
  COLOR color;
} Vertex;
 
int compare_vertices(const void* v, const void* u) {
  Vertex *a = (Vertex*) v;
  Vertex *b = (Vertex*) u;
  return (a->value - b->value);
}
 
Vertex* init_vertex(int value) {
  Vertex *v = (Vertex*) calloc(1, sizeof(Vertex));
  v->value = value;
  v->enabled = false;
  v->adj_list = init_list(100, compare_vertices);
  v->color = WHITE;
  return v;
}
 
typedef struct {
  ArrList *vertices;
} Graph;
 
Graph* init_graph(size_t size) {
  Graph *g = (Graph*) calloc(1, sizeof(Graph));
  g->vertices = init_list(size, compare_vertices);
  return g;
}
 
void add_vertex(Graph* g, int value) {
  g->vertices->values[value] = init_vertex(value);
}
 
void add_edge(Graph* g, int u, int v) {
  Vertex* a = (Vertex*) g->vertices->values[u];
  add_value(a->adj_list, g->vertices->values[v]);
}
 
void custom_bfs(Vertex* root) {
  ArrList *enabled = init_list(100, compare_vertices);
  ArrList *disabled = init_list(100, compare_vertices);
 
  root->color = GREY;
  
  for(int i = 0; i < root->adj_list->len; i++) {
    Vertex *tmp = root->adj_list->values[i];
    if(tmp->color != WHITE) continue;
 
    if(tmp->enabled)
      add_value(enabled, tmp);
    else
     add_value(disabled, tmp);
  }
 
  if(!is_empty(enabled)) {
    printf("%d\n", ((Vertex*) enabled->minimum)->value);
    return;
  } else 
    for(int i = 0; i < disabled->len; i++)
      custom_bfs(disabled->values[i]);
 
  root->color = BLACK;
  return;
}
 
int main(void){
  int n;
  scanf("%d", &n);
 
  Graph *g = init_graph(n + 1);
  for(int i = 1; i <=n; i++)
    add_vertex(g, i);
  
  for(int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    add_edge(g, a, b);
  }
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    ((Vertex *) g->vertices->values[v])->enabled = true;
  }
  custom_bfs(g->vertices->values[1]);
}