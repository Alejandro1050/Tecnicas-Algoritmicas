#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
using namespace std;

/* Bubble Sort */
void bubbleSort(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
        }
    }
}

/* Insertion Sort */
void insertionSort(vector<int>& v, int n)
{
    for (int i = 1; i < n; ++i) {
        int key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
}

/* Imprimir el array */
void printArray(const vector<int>& v, const string& title)
{
    cout << endl << title << endl;
    for (int i : v)
        cout << i << " ";
    cout << endl;
}

int main()
{
    vector<int> original;

    // Llenar el vector original con 10 elementos aleatorios
    cout << "Original:" << endl;
    for (int i = 0; i < 10; i++) {
        int valor = 1 + rand() % 100;
        cout << valor << " ";
        original.push_back(valor);
    }
    cout << endl;

    // Crear copias del vector para cada algoritmo
    vector<int> v_insertion = original;
    vector<int> v_bubble = original;

    // Medir el tiempo de ejecución de Insertion Sort
    auto start_insert = chrono::high_resolution_clock::now();
    insertionSort(v_insertion, v_insertion.size());
    auto end_insert = chrono::high_resolution_clock::now();

    auto duration_insert = chrono::duration_cast<chrono::microseconds>(end_insert - start_insert);
    printArray(v_insertion, "Insertion Sort:");
    cout << "Tiempo de ejecución: " << duration_insert.count() << " µs" << endl;

    // Medir el tiempo de ejecución de Bubble Sort
    auto start_bubble = chrono::high_resolution_clock::now();
    bubbleSort(v_bubble);
    auto end_bubble = chrono::high_resolution_clock::now();

    auto duration_bubble = chrono::duration_cast<chrono::microseconds>(end_bubble - start_bubble);
    printArray(v_bubble, "Bubble Sort:");
    cout << "Tiempo de ejecución: " << duration_bubble.count() << " µs" << endl;

    return 0;
}
