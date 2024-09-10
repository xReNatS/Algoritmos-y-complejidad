#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matriz;

// Función para sumar dos matrices
Matriz sumarMatrices(const Matriz& A, const Matriz& B) {
    int n = A.size();
    Matriz resultado(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            resultado[i][j] = A[i][j] + B[i][j];
    return resultado;
}

// Función para restar dos matrices
Matriz restarMatrices(const Matriz& A, const Matriz& B) {
    int n = A.size();
    Matriz resultado(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            resultado[i][j] = A[i][j] - B[i][j];
    return resultado;
}

// Función que implementa el algoritmo de Strassen
Matriz multiplicarStrassen(const Matriz& A, const Matriz& B) {
    int n = A.size();
    Matriz resultado(n, vector<int>(n));

    // Caso base: si la matriz es 1x1, multiplicar directamente
    if (n == 1) {
        resultado[0][0] = A[0][0] * B[0][0];
        return resultado;
    }

    int mid = n / 2;

    // Dividir las matrices en submatrices
    Matriz A11(mid, vector<int>(mid)), A12(mid, vector<int>(mid)),
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
    Matriz M1 = multiplicarStrassen(sumarMatrices(A11, A22), sumarMatrices(B11, B22)); // M1 = (A11 + A22) * (B11 + B22)
    Matriz M2 = multiplicarStrassen(sumarMatrices(A21, A22), B11);                     // M2 = (A21 + A22) * B11
    Matriz M3 = multiplicarStrassen(A11, restarMatrices(B12, B22));                    // M3 = A11 * (B12 - B22)
    Matriz M4 = multiplicarStrassen(A22, restarMatrices(B21, B11));                    // M4 = A22 * (B21 - B11)
    Matriz M5 = multiplicarStrassen(sumarMatrices(A11, A12), B22);                     // M5 = (A11 + A12) * B22
    Matriz M6 = multiplicarStrassen(restarMatrices(A21, A11), sumarMatrices(B11, B12)); // M6 = (A21 - A11) * (B11 + B12)
    Matriz M7 = multiplicarStrassen(restarMatrices(A12, A22), sumarMatrices(B21, B22)); // M7 = (A12 - A22) * (B21 + B22)

    // Combinar los resultados para formar la matriz C
    Matriz C11 = sumarMatrices(restarMatrices(sumarMatrices(M1, M4), M5), M7); // C11 = M1 + M4 - M5 + M7
    Matriz C12 = sumarMatrices(M3, M5);                                       // C12 = M3 + M5
    Matriz C21 = sumarMatrices(M2, M4);                                       // C21 = M2 + M4
    Matriz C22 = sumarMatrices(restarMatrices(sumarMatrices(M1, M3), M2), M6); // C22 = M1 + M3 - M2 + M6

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

// Función para imprimir matrices
void imprimirMatriz(const Matriz& matriz) {
    for (const auto& fila : matriz) {
        for (int elemento : fila) {
            cout << elemento << " ";
        }
        cout << endl;
    }
}

int main() {
    // Definir dos matrices cuadradas de tamaño 2^k (4x4 en este caso)
    Matriz A = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    Matriz B = {
        {17, 18, 19, 20},
        {21, 22, 23, 24},
        {25, 26, 27, 28},
        {29, 30, 31, 32}
    };

    // Multiplicar usando el algoritmo de Strassen
    Matriz C = multiplicarStrassen(A, B);

    // Imprimir la matriz resultado
    cout << "Matriz resultado:" << endl;
    imprimirMatriz(C);

    return 0;
}
