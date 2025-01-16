// implementación de Bubble sort en C++

#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& v) {
    int n = v.size();

    // loop for() con la cantidad de elementos (n) a ordenar
   
    for (int i = 0; i < n - 1; i++) {

        // ültimos elementos i ya ordenados
       
        for (int j = 0; j < n - i - 1; j++) {
          
              // Compariamos elementos adyacentes
            if (v[j] > v[j + 1])
              
                  // Intercambiamos si estan en orden erroneo

                swap(v[j], v[j + 1]);
        }
    }
}

int main() {

    // Creamos el vector v
    vector<int> v;

    // Loop for para llenar el vector con 10 elementos
    for (int i = 0; i < 10; i++){
        // tomamos un número al azar del 1 al 100 para insertarlo 
        // en el vector
        
        int valor = 1 + rand() % 100;
        cout << valor << " ";
        v.push_back(valor);
    }

    cout << endl;

    // Ordenamos el vector
    bubbleSort(v);
    for (auto i : v)
        cout << i << " ";
    return 0;
}