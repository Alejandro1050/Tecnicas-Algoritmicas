#include <iostream>
#include <list>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Grafo {
  int numVertices;
  list<int>* listasAdyacencia;
  bool* visitado;

public:
  Grafo(int vertices);
  void agregarArista(int origen, int destino);
  void DFS(int vertice);
  void generarGrafoAleatorio(int numAristas);
};

// Inicializar el grafo
Grafo::Grafo(int vertices) {
  numVertices = vertices;
  listasAdyacencia = new list<int>[vertices];
  visitado = new bool[vertices];
  for (int i = 0; i < vertices; i++)
    visitado[i] = false;
}

// Agregar aristas
void Grafo::agregarArista(int origen, int destino) {
  listasAdyacencia[origen].push_front(destino);
}

// Generar un grafo aleatorio con un número dado de aristas
void Grafo::generarGrafoAleatorio(int numAristas) {
  srand(time(0));
  for (int i = 0; i < numAristas; i++) {
    int origen = rand() % numVertices;
    int destino = rand() % numVertices;
    if (origen != destino) {
      agregarArista(origen, destino);
    }
  }
}

// Algoritmo DFS
void Grafo::DFS(int vertice) {
  visitado[vertice] = true;
  cout << vertice << " ";

  list<int>::iterator i;
  for (i = listasAdyacencia[vertice].begin(); i != listasAdyacencia[vertice].end(); ++i)
    if (!visitado[*i])
      DFS(*i);
}

int main() {
  int numVertices = 6;
  int numAristas = 8;
  Grafo g(numVertices);
  g.generarGrafoAleatorio(numAristas);

  cout << "Recorrido DFS desde el vértice 0:" << endl;
  g.DFS(0);

  return 0;
}
