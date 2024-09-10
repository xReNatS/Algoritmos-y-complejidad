#include <iostream>
#include <fstream>    // Para manejar archivos
#include <vector>     // Para manejar el vector de números
#include <iterator>   // Para usar ostream_iterator
#include <numeric>    // Para usar std::iota (rellenar el vector en orden)

using namespace std;

int main() {
    // Definir la cantidad de números a generar
    int cantidad = 1000000;  // Generar 1 millón de números, puedes cambiar este valor

    // Crear un vector con números del 1 a 'cantidad' en orden
    vector<int> numeros(cantidad);
    iota(numeros.begin(), numeros.end(), 1);  // Llena el vector con números de 1 a 'cantidad'

    // Abrir el archivo para escribir
    ofstream archivo("numeros_ordenados.txt");

    // Verificar si el archivo se pudo abrir correctamente
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo para escribir" << endl;
        return 1;
    }

    // Escribir los números en el archivo, separados por espacios
    for (size_t i = 0; i < numeros.size(); i++) {
        archivo << numeros[i];
        if (i != numeros.size() - 1) {
            archivo << " ";  // Asegurarse de no agregar un espacio al final
        }
    }

    // Cerrar el archivo
    archivo.close();

    cout << "Archivo generado con números ordenados y guardados en el vector." << endl;

    // Verificación: imprimir los primeros 10 números del vector para verificar el orden
    cout << "Primeros 10 números en el vector: ";
    for (int i = 0; i < 10; ++i) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    return 0;
}
