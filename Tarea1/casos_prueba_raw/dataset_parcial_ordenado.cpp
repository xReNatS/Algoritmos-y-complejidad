#include <iostream>
#include <fstream>    // Para manejar archivos
#include <vector>     // Para manejar el vector de números
#include <algorithm>  // Para desordenar los números (std::shuffle)
#include <random>     // Para el generador de números aleatorios
#include <numeric>    // Para usar std::iota (rellenar el vector en orden)
#include <iterator>   // Para usar ostream_iterator

using namespace std;

int main() {
    // Definir la cantidad de números a generar
    int cantidad = 1000001;  // Puedes cambiar este valor para generar más o menos números

    // Crear un vector con números del 1 a 'cantidad'
    vector<int> numeros(cantidad);
    iota(numeros.begin(), numeros.end(), 1);  // Llena el vector con números de 1 a 'cantidad'

    // Calcular la mitad del tamaño
    int mitad = cantidad / 2;

    // Si la cantidad es impar, la primera mitad tiene un elemento más
    if (cantidad % 2 != 0) {
        mitad++;
    }

    // Desordenar la segunda mitad del vector
    random_device rd;
    mt19937 generador(rd());
    shuffle(numeros.begin() + mitad, numeros.end(), generador);

    // Abrir el archivo para escribir
    ofstream archivo("numeros_mitad_ordenados_mitad_desordenados.txt");

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

    cout << "Archivo generado con la primera mitad de números ordenados y la segunda mitad desordenada." << endl;

    // Verificación: imprimir los primeros 10 números del vector y los últimos 10 para comprobar el orden y desorden
    cout << "Primeros 10 números en el vector (ordenados): ";
    for (int i = 0; i < 10; ++i) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    cout << "Últimos 10 números en el vector (desordenados): ";
    for (int i = cantidad - 10; i < cantidad; ++i) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    return 0;
}
