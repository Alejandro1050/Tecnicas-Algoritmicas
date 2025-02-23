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
  void BFS(int verticeInicio);
  void generarGrafoAleatorio(int numAristas);
};

// Crear un grafo con los vértices dados y mantener una lista de adyacencia
Grafo::Grafo(int vertices) {
  numVertices = vertices;
  listasAdyacencia = new list<int>[vertices];
}

// Agregar aristas al grafo
void Grafo::agregarArista(int origen, int destino) {
  listasAdyacencia[origen].push_back(destino);
  listasAdyacencia[destino].push_back(origen);
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

// Algoritmo BFS
void Grafo::BFS(int verticeInicio) {
  visitado = new bool[numVertices];
  for (int i = 0; i < numVertices; i++)
    visitado[i] = false;

  list<int> cola;

  visitado[verticeInicio] = true;
  cola.push_back(verticeInicio);

  list<int>::iterator i;

  while (!cola.empty()) {
    int verticeActual = cola.front();
    cout << "Visitado " << verticeActual << " ";
    cola.pop_front();

    for (i = listasAdyacencia[verticeActual].begin(); i != listasAdyacencia[verticeActual].end(); ++i) {
      int verticeAdyacente = *i;
      if (!visitado[verticeAdyacente]) {
        visitado[verticeAdyacente] = true;
        cola.push_back(verticeAdyacente);
      }
    }
  }
}

int main() {
  int numVertices = 6;
  int numAristas = 8;
  Grafo g(numVertices);
  g.generarGrafoAleatorio(numAristas);

  cout << "Recorrido BFS desde el vértice 0:" << endl;
  g.BFS(0);

  return 0;
}
