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

// BFS Customizado
void custom_bfs(Vertex* root) {
  // Lista de todas dos vertices onde estao as garotas
  ArrList *enabled = init_list(100, compare_vertices);

  // Lista de onde as garotas nao estao
  ArrList *disabled = init_list(100, compare_vertices);

  // Colore o vertice com CINZA (seus vertices estao sendo visitados)
  root->color = GREY;
  
  // Visita todos os vertices adjacentes à root
  for(int i = 0; i < root->adj_list->len; i++) {
    Vertex *tmp = root->adj_list->values[i];
    // se o vertice ja foi visita, pula
    if(tmp->color != WHITE) continue;
    
    // se tiver uma garota nesse vertice 
    // entao ele é adicionado à lista enabled 
    if(tmp->enabled)
      add_value(enabled, tmp);
    // vai pra outra lista caso contrario
    else
     add_value(disabled, tmp);
  }

  if(!is_empty(enabled)) {
    printf("%d", ((Vertex*) enabled->minimum)->value);
    return;
  } else 
    for(int i = 0; i < disabled->len; i++)
      custom_bfs(disabled->values[i]);

  root->color = BLACK;
  return;
}

int main(void){
  int k; scanf("%d", &k);
 
  for (size_t i = 0; i < k; i++) {
    int n, m; scanf("%d %d", &n, &m);

    Graph *g = init_graph(n);
    for(int j = 0; j < n; j++)
      add_vertex(g, j + 1);
    
    for(int j = 0; j < m; j++) {
      int v, w, p; scanf("%d %d %d", &v, &w, &p);
      if(p == 1)
        add_edge(g, v, w);
      if(p == 2)
        add_edge(g, w, v), add_edge(g, v, w);;
    }
    
    custom_bfs(g->vertices->values[0]);

    int ret = 1;
    for (size_t j = 0; j < g->vertices->len; j++) {
      if(((Vertex*) g->vertices->values[i])->color != BLACK) {
        ret = 0; break;
      }
    }
    printf("%d", ret);
  }
  return 0;
}