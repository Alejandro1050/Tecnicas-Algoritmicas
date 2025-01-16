#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

/* Function to sort array using insertion sort */
void insertionSort(vector<int>& arr, int n)
{
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/* A utility function to print array of size n */
void printArray(const vector<int>& arr, int n)
{
    cout << endl << "Ordenado:" << endl;
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver method
int main()
{
    vector<int> arr;

    // Loop para llenar el vector con 10 elementos
    cout << "Original:" << endl;
    for (int i = 0; i < 10; i++) {
        // Generamos un número al azar del 1 al 100
        int valor = 1 + rand() % 100;
        cout << valor << " ";
        arr.push_back(valor);
    }
    cout << endl;

    int n = arr.size();

    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}
