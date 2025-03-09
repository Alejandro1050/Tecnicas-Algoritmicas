/*
Algoritmos voraces 
Los Algoritmos voraces son algorítmos que intentan 
resolver el problema dado eligiendo la opción 
aparentemente más óptima a cada paso. 

Los algoritmos voraces estan diseñados para tomar 
decisiones rápidas y sencillas con la esperanza de 
llegar a la mejor solución posible.
*/
#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>

using namespace std;

// Función para encontrar el número mínimo de monedas necesarias
void minMonedas(vector<int> &monedas, int cantidad) {
    vector<int> resultado;
    int n = monedas.size();

    for (int i = 0; i < n; i++) {
        while (cantidad >= monedas[i]) {
            cantidad -= monedas[i];
            resultado.push_back(monedas[i]);
        }
    }

    // Mostrar resultado
    cout << "Monedas usadas: ";
    for (int moneda : resultado) {
        cout << moneda << " ";
    }
    cout << endl;
}

int main() {
    vector<int> monedas = {100, 50, 20, 10, 5, 2, 1}; // Denominaciones (ejemplo en pesos mexicanos)
    srand(time(0));
    // Generar una cantidad aleatoria entre 1 y 100
    int cantidad = rand() % 1000 + 1; 

    cout << "Cantidad a cambiar: " << cantidad << " MXN" << endl;
    minMonedas(monedas, cantidad);

    return 0;
}
