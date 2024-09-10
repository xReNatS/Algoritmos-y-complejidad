#include <bits/stdc++.h>
#include <vector>
#include <fstream>   
#include <algorithm>  
#include <random>     
#include <iterator>   
#include <cstdlib>
#include <ctime>      
#include "algoritmos.hpp"

using namespace std;

////////////////////// ALGORITMOS DE ORDENAMIENTO ////////////////////////

// Version optimizada de Bubble Sort.
void bubbleSort(vector<int>& v) {
 
    int n = v.size();

    for (int i = 0; i < n - 1; i++) {
        bool flag = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                flag = true;
            }
        }
        if (!flag)
            break;
    }
}
////////////////////////////////////////


// Algoritmo Merge Sort
void merge(vector<int>& arr, int left, 
                     int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
////////////////////////////////////////


//Algoritmo Quick Sort
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

// Función Quicksort con pivote aleatorio
void quicksort(vector<int>& arr, int inicio, int fin) {
    if (inicio < fin) {
        int pivoteIndex = particionar(arr, inicio, fin);
        quicksort(arr, inicio, pivoteIndex - 1);
        quicksort(arr, pivoteIndex + 1, fin);
    }
}
////////////////////////////////////////


// Funcion para imprimir un vector
void imprimirVector(vector<int>& vector)
{
    int tamaño = vector.size(); //cuidado
    for (int i = 0; i < tamaño; i++)
        cout << vector[i] << " ";
    cout << endl;
}
////////////////////////////////////////


////////////////////// MULTIPLICACION DE MATRICES ///////////////////////

// Función para trasponer una matriz
vector<vector<int>> trasponerMatriz(const vector<vector<int>>& matriz) {
    int filas = matriz.size();
    int columnas = matriz[0].size();
    vector<vector<int>> traspuesta(columnas, vector<int>(filas));

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            traspuesta[j][i] = matriz[i][j];
        }
    }

    return traspuesta;
}


// Función para multiplicar matrices
vector<vector<int>> multiplicarMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int filasA = A.size();               // Número de filas de A
    int columnasA = A[0].size();         // Número de columnas de A
    int columnasB = B[0].size();         // Número de columnas de B

    // Crear una matriz resultado con las dimensiones apropiadas y llenarla con ceros
    vector<vector<int>> resultado(filasA, vector<int>(columnasB, 0));

    // Multiplicación de matrices
    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasB; j++) {
            for (int k = 0; k < columnasA; k++) {
                resultado[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return resultado;
}


// Función para multiplicar matrices usando la traspuesta de B
vector<vector<int>> multiplicarMatricesTraspuesta(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int filasA = A.size();               // Número de filas de A
    int columnasA = A[0].size();         // Número de columnas de A
    int columnasB = B[0].size();         // Número de columnas de B

    // Trasponemos la matriz B para hacer accesos más eficientes a la memoria
    vector<vector<int>> B_traspuesta = trasponerMatriz(B);

    // Crear una matriz resultado con las dimensiones apropiadas y llenarla con ceros
    vector<vector<int>> resultado(filasA, vector<int>(columnasB, 0));

    // Multiplicación de matrices usando la traspuesta de B
    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasB; j++) {
            for (int k = 0; k < columnasA; k++) {
                resultado[i][j] += A[i][k] * B_traspuesta[j][k];
            }
        }
    }

    return resultado;
}
////////////////////////////////////////


// Función para sumar dos matrices
vector<vector<int>> sumarMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> resultado(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            resultado[i][j] = A[i][j] + B[i][j];
    return resultado;
}

// Función para restar dos matrices
vector<vector<int>> restarMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> resultado(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            resultado[i][j] = A[i][j] - B[i][j];
    return resultado;
}

// Función que implementa el algoritmo de Strassen
vector<vector<int>> multiplicarStrassen(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> resultado(n, vector<int>(n));

    // Caso base: si la matriz es 1x1, multiplicar directamente
    if (n == 1) {
        resultado[0][0] = A[0][0] * B[0][0];
        return resultado;
    }

    int mid = n / 2;

    // Dividir las matrices en submatrices
    vector<vector<int>> A11(mid, vector<int>(mid)), A12(mid, vector<int>(mid)),
                        A21(mid, vector<int>(mid)), A22(mid, vector<int>(mid)),
                        B11(mid, vector<int>(mid)), B12(mid, vector<int>(mid)),
                        B21(mid, vector<int>(mid)), B22(mid, vector<int>(mid));

    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];
            
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }

    // Calcular las siete multiplicaciones de Strassen
    vector<vector<int>> M1 = multiplicarStrassen(sumarMatrices(A11, A22), sumarMatrices(B11, B22)); // M1 = (A11 + A22) * (B11 + B22)
    vector<vector<int>> M2 = multiplicarStrassen(sumarMatrices(A21, A22), B11);                     // M2 = (A21 + A22) * B11
    vector<vector<int>> M3 = multiplicarStrassen(A11, restarMatrices(B12, B22));                    // M3 = A11 * (B12 - B22)
    vector<vector<int>> M4 = multiplicarStrassen(A22, restarMatrices(B21, B11));                    // M4 = A22 * (B21 - B11)
    vector<vector<int>> M5 = multiplicarStrassen(sumarMatrices(A11, A12), B22);                     // M5 = (A11 + A12) * B22
    vector<vector<int>> M6 = multiplicarStrassen(restarMatrices(A21, A11), sumarMatrices(B11, B12)); // M6 = (A21 - A11) * (B11 + B12)
    vector<vector<int>> M7 = multiplicarStrassen(restarMatrices(A12, A22), sumarMatrices(B21, B22)); // M7 = (A12 - A22) * (B21 + B22)

    // Combinar los resultados para formar la matriz C
    vector<vector<int>> C11 = sumarMatrices(restarMatrices(sumarMatrices(M1, M4), M5), M7); // C11 = M1 + M4 - M5 + M7
    vector<vector<int>> C12 = sumarMatrices(M3, M5);                                       // C12 = M3 + M5
    vector<vector<int>> C21 = sumarMatrices(M2, M4);                                       // C21 = M2 + M4
    vector<vector<int>> C22 = sumarMatrices(restarMatrices(sumarMatrices(M1, M3), M2), M6); // C22 = M1 + M3 - M2 + M6

    // Unir las submatrices en la matriz resultado
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            resultado[i][j] = C11[i][j];
            resultado[i][j + mid] = C12[i][j];
            resultado[i + mid][j] = C21[i][j];
            resultado[i + mid][j + mid] = C22[i][j];
        }
    }

    return resultado;
}


// Función para imprimir una matriz
void imprimirMatriz(const vector<vector<int>>& matriz) {
    for (const auto& fila : matriz) {
        for (int elemento : fila) {
            cout << elemento << " ";
        }
        cout << endl;
    }
}


//Funcion para crear dataset y vector con numeros aleatorios
vector<int> dataset_desordenado(int tamaño){

    int cantidad = tamaño;  // Genera la cantidad de numeros que sea tamaño

    vector<int> vector(cantidad);
    iota(vector.begin(), vector.end(), 1);  // Llena el vector con números de 1 a 'cantidad'

    // Inicializar el generador de números aleatorios
    random_device rd;
    mt19937 generador(rd());

    shuffle(vector.begin(), vector.end(), generador);

    ofstream archivo("dataset_numeros_desordenados.txt");
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo para escribir" << endl;
        exit(1);
    }

    for (size_t i = 0; i < vector.size(); i++) {
        archivo << vector[i];
        if (i != vector.size() - 1) {
            archivo << " ";
        }
    }
    archivo.close();
    return vector;
}
//////////////////////////////////////////////


//Funcion para crear dataset y vector con numeros ordenados
vector<int> dataset_ordenado(int tamaño){
    int cantidad = tamaño; 

    // Crear un vector con números del 1 a 'cantidad' en orden
    vector<int> vector(cantidad);
    iota(vector.begin(), vector.end(), 1);  // Llena el vector con números de 1 a 'cantidad'

    ofstream archivo("dataset_numeros_ordenados.txt");

    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo para escribir" << endl;
        exit(1);
    }

    for (size_t i = 0; i < vector.size(); i++) {
        archivo << vector[i];
        if (i != vector.size() - 1) {
            archivo << " "; 
        }
    }

    archivo.close();
    return vector;
}
//////////////////////////////////////////////


//Funcion para crear dataset y vector con numeros parcialmente ordenados (primera mitad)
vector<int> dataset_parcial_ordenado(int tamaño){
    int cantidad = tamaño; 

    vector<int> vector(cantidad);
    iota(vector.begin(), vector.end(), 1); 

    // Calcular la mitad del tamaño
    int mitad = cantidad / 2;

    // Si la cantidad es impar, la primera mitad tiene un elemento más
    if (cantidad % 2 != 0) {
        mitad++;
    }

    // Desordenar la segunda mitad del vector
    random_device rd;
    mt19937 generador(rd());
    shuffle(vector.begin() + mitad, vector.end(), generador);

    ofstream archivo("dataset_numeros_parcial_ordenados.txt");

    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo para escribir" << endl;
        exit(1);
    }

    for (size_t i = 0; i < vector.size(); i++) {
        archivo << vector[i];
        if (i != vector.size() - 1) {
            archivo << " ";
        }
    }

    // Cerrar el archivo
    archivo.close();
    return vector;
}
////////////////////////////////////////////


//Funcion para crear archivo con los datos ordenados por los diferentes algoritmos
void dataset_resultado(vector<int>& vector, char nombre[]){

    ofstream archivo(nombre);
        if (!archivo.is_open()) {
            cerr << "No se pudo abrir el archivo para escribir" << endl;
            exit(1);
        }

        for (size_t i = 0; i < vector.size(); i++) {
            archivo << vector[i];
            if (i != vector.size() - 1) {
                archivo << " ";
            }
        }
        archivo.close();
}
////////////////////////////////////////////


// Función para generar una matriz de forma aleatoria
vector<vector<int>> generarMatriz(int filas, int columnas, bool cuadrada) {
    // Si la matriz debe ser cuadrada, ajustamos las columnas para que coincidan con las filas
    if (cuadrada) {
        columnas = filas;
    }

    // Crear una matriz (vector de vectores) de tamaño filas x columnas
    vector<vector<int>> matriz(filas, vector<int>(columnas));

    // Generador de números aleatorios
    random_device rd;
    mt19937 generador(rd());
    uniform_int_distribution<int> distribucion(1, 1000);  // Números aleatorios entre 1 y 1000

    // Llenar la matriz con números aleatorios
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = distribucion(generador);
        }
    }

    return matriz;  // Devolver la matriz generada
}
////////////////////////////////////////////


// Función para guardar la matriz en un archivo
void guardarMatrizEnArchivo(const vector<vector<int>>& matriz, char nombreArchivo[]) {
    ofstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo para escribir" << endl;
        return;
    }

    int filas = matriz.size();
    int columnas = matriz[0].size();

    // Escribir la matriz en el archivo, fila por fila
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            archivo << matriz[i][j];
            if (j != columnas - 1) {
                archivo << " ";  // Espacio entre números, pero no al final de la fila
            }
        }
        archivo << "\n";  // Salto de línea al final de cada fila
    }

    archivo.close();
}
////////////////////////////////////////////