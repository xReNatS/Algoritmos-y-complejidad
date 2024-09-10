#include <iostream>
#include <vector>
#include <cstdlib>  // Para std::rand() y std::srand()
#include <ctime>    // Para std::time()

using namespace std;

// Función para intercambiar dos elementos
void intercambiar(vector<int>& arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Función para elegir un pivote aleatorio
int seleccionarPivoteAleatorio(int inicio, int fin) {
    return inicio + std::rand() % (fin - inicio + 1);
}

// Función de partición con pivote aleatorio
int particionar(vector<int>& arr, int inicio, int fin) {
    // Selecciona un pivote aleatorio y lo coloca al final del subarray
    int pivoteIndex = seleccionarPivoteAleatorio(inicio, fin);
    intercambiar(arr, pivoteIndex, fin);
    
    int pivote = arr[fin];
    int i = inicio - 1;

    for (int j = inicio; j < fin; ++j) {
        if (arr[j] <= pivote) {
            ++i;
            intercambiar(arr, i, j);
        }
    }
    intercambiar(arr, i + 1, fin);
    return i + 1;
}

// Función Quicksort recursiva
void quicksort(vector<int>& arr, int inicio, int fin) {
    if (inicio < fin) {
        int pivoteIndex = particionar(arr, inicio, fin);
        quicksort(arr, inicio, pivoteIndex - 1);
        quicksort(arr, pivoteIndex + 1, fin);
    }
}

int main() {
    // Inicializar el generador de números aleatorios
    std::srand(std::time(0));

    // Crear un vector con números desordenados
    vector<int> arr = {34, 7, 23, 32, 5, 62, 32, 12, 3, 8};

    // Mostrar el vector original
    cout << "Vector original: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Ordenar el vector usando Quicksort
    quicksort(arr, 0, arr.size() - 1);

    // Mostrar el vector ordenado
    cout << "Vector ordenado: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
