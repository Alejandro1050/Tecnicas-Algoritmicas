#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits> 

using namespace std;

// Definición de la estructura de un nodo
struct Node {
    int x, y; // Coordenadas del nodo
    int g, h; // Costos g y h
    Node* parent; // Puntero al nodo padre

    Node(int x, int y, int g, int h, Node* parent = nullptr)
        : x(x), y(y), g(g), h(h), parent(parent) {}

    // Función para calcular el costo total f = g + h
    int f() const {
        return g + h;
    }

    // Sobrecarga del operador < para la cola de prioridad
    bool operator<(const Node& other) const {
        return f() > other.f();
    }
};

// Función para calcular la distancia Manhattan entre dos puntos
int manhattanDistance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// Función para generar un grafo aleatorio
vector<vector<int>> generateRandomGrid(int width, int height, int obstacleProbability) {
    vector<vector<int>> grid(height, vector<int>(width, 0));
    srand(time(0));

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (rand() % 100 < obstacleProbability) {
                grid[y][x] = 1; // 1 representa un obstáculo
            }
        }
    }

    return grid;
}

// Función para imprimir el grafo
void printGrid(const vector<vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int cell : row) {
            cout << (cell == 1 ? "#" : ".") << " ";
        }
        cout << endl;
    }
}

// Función para reconstruir y mostrar la ruta
void reconstructPath(Node* node) {
    vector<Node*> path;
    while (node != nullptr) {
        path.push_back(node);
        node = node->parent;
    }

    for (auto it = path.rbegin(); it != path.rend(); ++it) {
        cout << "(" << (*it)->x << ", " << (*it)->y << ")";
        if (it + 1 != path.rend()) cout << " -> ";
    }
    cout << endl;
}

// Algoritmo A*
bool aStar(const vector<vector<int>>& grid, int startX, int startY, int goalX, int goalY) {
    int height = grid.size();
    int width = grid[0].size();

    // Definir los movimientos posibles (arriba, abajo, izquierda, derecha)
    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };

    // Cola de prioridad para los nodos abiertos
    priority_queue<Node> openSet;

    // Matriz para mantener el costo g de cada celda
    vector<vector<int>> gCost(height, vector<int>(width, INT_MAX));

    // Nodo inicial
    Node* startNode = new Node(startX, startY, 0, manhattanDistance(startX, startY, goalX, goalY));
    openSet.push(*startNode);
    gCost[startY][startX] = 0;

    while (!openSet.empty()) {
        Node current = openSet.top();
        openSet.pop();

        // Si llegamos al destino, reconstruir y mostrar la ruta
        if (current.x == goalX && current.y == goalY) {
            reconstructPath(&current);
            return true;
        }

        // Explorar los vecinos
        for (int i = 0; i < 4; ++i) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            // Verificar si el vecino está dentro del grafo y no es un obstáculo
            if (nx >= 0 && nx < width && ny >= 0 && ny < height && grid[ny][nx] == 0) {
                int tentativeGCost = current.g + 1;

                // Si encontramos un camino mejor
                if (tentativeGCost < gCost[ny][nx]) {
                    gCost[ny][nx] = tentativeGCost;
                    int hCost = manhattanDistance(nx, ny, goalX, goalY);
                    Node* neighbor = new Node(nx, ny, tentativeGCost, hCost, new Node(current));
                    openSet.push(*neighbor);
                }
            }
        }
    }

    // Si no se encuentra una ruta
    cout << "No se encontró una ruta válida." << endl;
    return false;
}

int main() {
    int width = 10;
    int height = 10;
    int obstacleProbability = 20; // Probabilidad de que una celda sea un obstáculo (20%)

    // Generar el grafo aleatorio
    vector<vector<int>> grid = generateRandomGrid(width, height, obstacleProbability);

    // Imprimir el grafo
    printGrid(grid);

    // Definir el punto de inicio y el destino
    int startX = 0, startY = 0;
    int goalX = 9, goalY = 9;

    // Ejecutar el algoritmo A*
    aStar(grid, startX, startY, goalX, goalY);

    return 0;
}