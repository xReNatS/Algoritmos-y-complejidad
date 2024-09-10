#include <iostream>
#include <vector>
#include <chrono> 
#include <algorithm> 
#include "algoritmos.hpp"

using namespace std;

vector<int> creacionVector(int tamaño, int orden){
    vector<int> vector;

    //PEQUEÑO
    if(tamaño == 1){
        tamaño = 1000;
    }

    //MEDIANO
    else if(tamaño == 2){
        tamaño = 10000;
    }

    //GRANDE
    else{
        tamaño = 100000;
    }

    //DATASET ORDENADO
    if(orden == 1){
        vector = dataset_ordenado(tamaño);
    }

    //DATASET DESORDENADO
    else if(orden == 2){
        vector = dataset_desordenado(tamaño);
    }

    //DATASET PARCIALMENTE ORDENADO
    else{
        vector = dataset_parcial_ordenado(tamaño);
    }
    return vector;
}

vector<vector<int>> creacionMatriz(int tamaño, int tipo, char nombre[], int numMatriz){
    vector<vector<int>> matriz;
    int filas, columnas;

    //CREACION MATRIZ CUADRADA
    if (tipo != 2){

        //PEQUEÑA
        if(tamaño == 1){
            filas = 64;
        }

        //MEDIANA
        else if(tamaño == 2){
            filas = 128;
        }

        //GRANDE
        else{
            filas = 256;
        }

        matriz = generarMatriz(filas, 0, true);
    }

    //CREACION MATRIZ RECTANGULAR
    else {

        //PEQUEÑA
        if(tamaño == 1){
            filas = 64;
            columnas = 128;
        }

        //MEDIANA
        else if(tamaño == 2){
            filas = 128;
            columnas = 256;
        }

        //GRANDE
        else{
            filas = 256;
            columnas = 512;
        }

        //PARA SABER SI ES LA PRIMERA O LA SEGUNDA MATRIZ
        if (numMatriz == 1)
        {
            matriz = generarMatriz(filas, columnas, false);
        }
        else{

            matriz = generarMatriz(columnas, filas, false);
        }
    }
    guardarMatrizEnArchivo(matriz, nombre);
    return matriz;
    
}

///////////// MENU DE OPCIONES POR CONSOLA ////////////////////////

// Si se desea se puede imprimir el vector antes de ser ordenado y despues de ser ordenado por cada algoritmo solo debe borrar los cout comentados
// lo mismo con las matrices
void seleccionOpciones(int input){

    int input2, input3 = -1;

    //ORDENAMIENTO DE VECTOR
    if(input == 1){

        cout << "\n\nElegir algoritmo de ordenamiento:\n\n\t(1) Bubble Sort.\n\t(2) Merge Sort.\n\t(3) Quick Sort.\n\t(4) Ordenamiento por defecto.\n\t(5) Todos.\n\nEntrada: ";
        cin >> input;

        while(input != 1 && input != 2 && input != 3 && input != 4 && input != 5){
            cout << "\n\nENTRADA INVÁLIDA, ELIJA UNA OPCIÓN VÁLIDA:\n\n\t(1) Bubble Sort.\n\t(2) Merge Sort.\n\t(3) Quick Sort.\n\t(4) Ordenamiento por defecto.\n\nEntrada: ";
            cin >> input;
        }

        cout << "\n\nElegir tamaño del vector:\n\n\t(1) Pequeño (1000).\n\t(2) Mediano (10000).\n\t(3) Grande (100000).\n\nEntrada: ";
        cin >> input2;

        while(input2 != 1 && input2 != 2 && input2 != 3){
            cout << "\n\nENTRADA INVÁLIDA, ELIJA UNA OPCIÓN VÁLIDA:\n\n\t(1) Pequeño.\n\t(2) Mediano.\n\t(3) Grande.\n\nEntrada: ";
            cin >> input2;
        }

        cout << "\n\nElegir tipo de caso de prueba:\n\n\t(1) Ordenado.\n\t(2) Desordenado.\n\t(3) Parcialmente ordenado (primera mitad).\n\nEntrada: ";
        cin >> input3;

        while(input3 != 1 && input3 != 2 && input3 != 3){
            cout << "\n\nENTRADA INVÁLIDA, ELIJA UNA OPCIÓN VÁLIDA:\n\n\t(1) Ordenado.\n\t(2) Desordenado.\n\t(3) Parcialmente ordenado (primera mitad).\n\nEntrada: ";
            cin >> input3;
        }
        bool flag = false;
        if(input == 5){flag = true;};
        vector<int> vector1 = creacionVector(input2, input3);
        //imprimirVector(vector1);
        vector<int> vector2 = vector1;
        vector<int> vector3 = vector1;
        vector<int> vector4 = vector1;

        if(input == 1 || flag){
            auto inicio = chrono::high_resolution_clock::now();
            bubbleSort(vector2);
            auto fin = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> duracion = fin - inicio;
            cout << "Tiempo de ejecución de BubbleSort: " << duracion.count() << " ms" << endl;
            //imprimirVector(vector2);
            dataset_resultado(vector2, (char*)"dataset_resuelto_por_bubblesort.txt");

        }
        if (input == 2 || flag){
            int size = vector3.size();
            auto inicio = chrono::high_resolution_clock::now();
            mergeSort(vector3, 0, size-1);
            auto fin = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> duracion = fin - inicio;
            cout << "Tiempo de ejecución de MergeSort: " << duracion.count() << " ms" << endl;
            //imprimirVector(vector3);
            dataset_resultado(vector3, (char*)"dataset_resuelto_por_mergesort.txt");
        }
        if (input == 3 || flag){
            int size = vector4.size();
            auto inicio = chrono::high_resolution_clock::now();
            quicksort(vector4, 0, size-1);
            auto fin = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> duracion = fin - inicio;
            cout << "Tiempo de ejecución de QuickSort: " << duracion.count() << " ms" << endl;
            //imprimirVector(vector4);
            dataset_resultado(vector4, (char*)"dataset_resuelto_por_quicksort.txt");
        }
        if (input == 4 || flag){
            auto inicio = chrono::high_resolution_clock::now();
            sort(vector1.begin(), vector1.end());
            auto fin = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> duracion = fin - inicio;
            cout << "Tiempo de ejecución de ordenamiento por defecto: " << duracion.count() << " ms" << endl;
            //imprimirVector(vector1);
            dataset_resultado(vector1, (char*)"dataset_resuelto_por_predeterminado.txt");
        }

    }

    //MULTIPLICACION DE MATRICES
    else if(input == 2){
        vector<vector<int>> matrizResultado;

        cout << "\n\nElegir algoritmo de multiplicación de matríces:\n\n\t(1) Multiplicación iterativa cúbica.\n\t(2) Multiplicación iterativa cúbica traspuesta.\n\t(3) Algoritmo Strassen.\n\t(4) Todos.\n\nEntrada: ";
        cin >> input;

        while(input != 1 && input != 2 && input != 3 && input != 4){
            cout << "\n\nENTRADA INVÁLIDA, ELIJA UNA OPCIÓN VÁLIDA:\n\n\t(1) Multiplicación iterativa cúbica.\n\t(2) Multiplicación iterativa cúbica traspuesta.\n\t(3) Algoritmo Strassen.\n\t(4) Todos.\n\nEntrada: ";
            cin >> input;
        }

        bool flag = false;
        if(input == 4){flag = true;};

        cout << input << endl;
        if(input != 3 && !flag){

            cout << "\n\nElegir tipo de matriz:\n\n\t(1) Cuadrada.\n\t(2) Rectangular.\n\nEntrada: ";
            cin >> input3;

            while(input3 != 1 && input3 != 2){
                cout << "\n\nENTRADA INVÁLIDA, ELIJA UNA OPCIÓN VÁLIDA:\n\n\t(1) Cuadrada.\n\t(2) Rectangular.\n\nEntrada: ";
                cin >> input3;
            }
            if(input3 == 1){

                cout << "\n\nElegir tamaño de la matriz:\n\n\t(1) Pequeña. (64x64)\n\t(2) Mediana. (128x128)\n\t(3) Grande. (256x256)\n\nEntrada: ";
                cin >> input2;

                while(input2 != 1 && input2 != 2 && input2 != 3){
                    cout << "\n\nENTRADA INVÁLIDA, ELIJA UNA OPCIÓN VÁLIDA:\n\n\t(1) Pequeña. (64x64)\n\t(2) Mediana. (128x128)\n\t(3) Grande. (256x256)\n\nEntrada: ";
                    cin >> input2;
                }
            }
            else{

                cout << "\n\nElegir tamaño de la matriz:\n\n\t(1) Pequeña. (64x128)\n\t(2) Mediana. (128x256)\n\t(3) Grande. (256x512)\n\nEntrada: ";
                cin >> input2;

                while(input2 != 1 && input2 != 2 && input2 != 3){
                    cout << "\n\nENTRADA INVÁLIDA, ELIJA UNA OPCIÓN VÁLIDA:\n\n\t(1) Pequeña. (64x128)\n\t(2) Mediana. (128x256)\n\t(3) Grande. (256x512)\n\nEntrada: ";
                    cin >> input2;
                }
            }
        }
        else{

            cout << "\n\nElegir tamaño de la matriz:\n\n\t(1) Pequeña (64x64).\n\t(2) Mediana. (128x128)\n\t(3) Grande. (256x256)\n\nEntrada: ";
            cin >> input2;

            while(input2 != 1 && input2 != 2 && input2 != 3){
                cout << "\n\nENTRADA INVÁLIDA, ELIJA UNA OPCIÓN VÁLIDA:\n\n\t(1) Pequeña. (64x64)\n\t(2) Mediana. (128x128)\n\t(3) Grande. (256x256)\n\nEntrada: ";
                cin >> input2;
            }
        }

        vector<vector<int>> matriz1 = creacionMatriz(input2, input3, (char*)"matriz_1" , 1);
        vector<vector<int>> matriz2 = creacionMatriz(input2, input3, (char*)"matriz_2" , 2);
        
        //imprimirMatriz(matriz2);
        //imprimirMatriz(matriz2);

        //MULTIPLICACION DE MATRICES ITERATIVA
        if(input == 1 || flag){
            auto inicio = chrono::high_resolution_clock::now();
            matrizResultado = multiplicarMatrices(matriz1, matriz2);
            auto fin = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> duracion = fin - inicio;
            cout << "Tiempo de ejecución de multiplicacion iterativa: " << duracion.count() << " ms" << endl;
            //imprimirMatriz(matrizResultado);
            guardarMatrizEnArchivo(matrizResultado, (char*)"matriz_resultado_iterativa");
        }

        //MULTIPLICACION DE MATRICES ITERATIVA TRASPUESTA
        if(input == 2 || flag){
            auto inicio = chrono::high_resolution_clock::now();
            matrizResultado = multiplicarMatricesTraspuesta(matriz1, matriz2);
            auto fin = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> duracion = fin - inicio;
            cout << "Tiempo de ejecución de multiplicacion iterativa traspuesta: " << duracion.count() << " ms" << endl;
            //imprimirMatriz(matrizResultado);
            guardarMatrizEnArchivo(matrizResultado, (char*)"matriz_resultado_iterativa_traspuesta");
        }

        //MULTIPLICACION DE MATRICES CON STRASSEN
        if(input == 3 || flag){
            auto inicio = chrono::high_resolution_clock::now();
            matrizResultado = multiplicarStrassen(matriz1, matriz2);
            auto fin = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> duracion = fin - inicio;
            cout << "Tiempo de ejecución de multiplicacion por Strassen: " << duracion.count() << " ms" << endl;
            //imprimirMatriz(matrizResultado);
            guardarMatrizEnArchivo(matrizResultado, (char*)"matriz_resultado_strassen");
        }

    }
}


int main(){

    int input;
    cout << "Elegir una opción:\n\n\t(1) Ordenar un vector.\n\t(2) Multiplicar matrices.\n\nEntrada: ";
    cin >> input;

    while(input != 1 && input != 2){
        cout << "\n\nENTRADA INVÁLIDA, ELIJA UNA OPCIÓN VÁLIDA:\n\n\t(1) Ordenar un vector.\n\t(2) Multiplicar matrices.\n\nEntrada: ";
        cin >> input;
    }
    seleccionOpciones(input);

    return 0;
}