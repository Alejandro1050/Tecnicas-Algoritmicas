#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// Función para generar un vector aleatorio de 10 elementos
vector<int> generarVectorAleatorio() {
    vector<int> vec(10);
    srand(time(0)); // Semilla para números aleatorios
    for (int i = 0; i < 10; ++i) {
        vec[i] = rand() % 100; // Números aleatorios entre 0 y 99
    }
    return vec;
}

// Función para imprimir un vector
void imprimirVector(const vector<int>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

// Función para representar el grafo como una lista de adyacencia
void representarGrafo(const vector<int>& vec) {
    cout << "Grafo (Lista de adyacencia):" << endl;
    for (int i = 0; i < vec.size() - 1; ++i) {
        cout << vec[i] << " -> " << vec[i + 1] << endl;
    }
}

int main() {
    // Generar un vector aleatorio
    vector<int> vec = generarVectorAleatorio();

    // Imprimir el vector original
    cout << "Vector original: ";
    imprimirVector(vec);

    // Ordenar el vector
    sort(vec.begin(), vec.end());

    // Imprimir el vector ordenado
    cout << "Vector ordenado: ";
    imprimirVector(vec);

    // Representar el grafo
    representarGrafo(vec);

    return 0;
}