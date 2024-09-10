#include <iostream>
#include <fstream>    // Para manejar archivos
#include <vector>     // Para manejar la matriz como un vector de vectores
#include <random>     // Para generar números aleatorios
#include <ctime>      // Para usar time como semilla de rand

using namespace std;

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

// Función para guardar la matriz en un archivo
void guardarMatrizEnArchivo(const vector<vector<int>>& matriz, const string& nombreArchivo) {
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
    cout << "Matriz guardada en el archivo: " << nombreArchivo << endl;
}

int main() {
    int filas, columnas;
    bool cuadrada;

    // Pedir al usuario los parámetros de la matriz
    cout << "Ingresa el número de filas: ";
    cin >> filas;
    cout << "Ingresa el número de columnas (se ignorará si la matriz es cuadrada): ";
    cin >> columnas;
    cout << "¿La matriz debe ser cuadrada? (1 para sí, 0 para no): ";
    cin >> cuadrada;

    // Generar la matriz
    vector<vector<int>> matriz = generarMatriz(filas, columnas, cuadrada);

    // Guardar la matriz en un archivo
    string nombreArchivo = "matriz_aleatoria.txt";
    guardarMatrizEnArchivo(matriz, nombreArchivo);

    // Verificación: mostrar los primeros valores de la matriz en consola (opcional)
    cout << "Primeros valores de la matriz generada: " << endl;
    for (int i = 0; i < min(5, filas); ++i) {
        for (int j = 0; j < min(5, columnas); ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
