#include <iostream>
#include <vector>
using namespace std;

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

// Función para imprimir una matriz
void imprimirMatriz(const vector<vector<int>>& matriz) {
    for (const auto& fila : matriz) {
        for (int elemento : fila) {
            cout << elemento << " ";
        }
        cout << endl;
    }
}

int main() {
    // Matriz A (ejemplo)
    vector<vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}
    };

    // Matriz B (ejemplo)
    vector<vector<int>> B = {
        {7, 8},
        {9, 10},
        {11, 12}
    };

    // Validar si la multiplicación es posible
    if (A[0].size() != B.size()) {
        cout << "Error: No se pueden multiplicar estas matrices." << endl;
        return -1;
    }

    // Multiplicar las matrices
    vector<vector<int>> resultado = multiplicarMatrices(A, B);

    // Imprimir el resultado
    cout << "La matriz resultado es:" << endl;
    imprimirMatriz(resultado);

    return 0;
}
