#include <iostream>
#include <fstream>    // Para manejar archivos
#include <vector>     // Para manejar el vector de números
#include <algorithm>  // Para desordenar los números (std::shuffle)
#include <random>     // Para el generador de números aleatorios
#include <iterator>   // Para usar ostream_iterator
#include <ctime>      // Para la semilla de rand

using namespace std;

int main() {
    // Definir la cantidad de números a generar
    int cantidad = 1000000;  // Generar 1 millón de números, puedes cambiar este valor

    // Crear un vector con números del 1 a 'cantidad' en una sola línea
    vector<int> numeros(cantidad);
    iota(numeros.begin(), numeros.end(), 1);  // Llena el vector con números de 1 a 'cantidad'

    // Inicializar el generador de números aleatorios
    random_device rd;
    mt19937 generador(rd());

    shuffle(numeros.begin(), numeros.end(), generador);

    ofstream archivo("dataset_numeros_desordenados.txt");
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo para escribir" << endl;
        return 1;
    }

    for (size_t i = 0; i < numeros.size(); i++) {
        archivo << numeros[i];
        if (i != numeros.size() - 1) {
            archivo << " ";
        }
    }
    archivo.close();
    
    return 0;
}
