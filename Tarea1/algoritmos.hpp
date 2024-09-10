// matrices.h
#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <vector>

// Prototipos de las funciones
////////////////////// ALGORITMOS DE ORDENAMIENTO ////////////////////////
//BubbleSort
void bubbleSort(std::vector<int>& v);
//MergeSort
void merge(std::vector<int>& arr, int left, int mid, int right);
void mergeSort(std::vector<int>& arr, int left, int right);
//QuickSort
void intercambiar(std::vector<int>& arr, int i, int j);
int seleccionarPivoteAleatorio(int inicio, int fin);
int particionar(std::vector<int>& arr, int inicio, int fin);
void quicksort(std::vector<int>& arr, int inicio, int fin);
void imprimirVector(std::vector<int>& vector);
////////////////////// MULTIPLICACION DE MATRICES ///////////////////////
std::vector<std::vector<int>> trasponerMatriz(const std::vector<std::vector<int>>& matriz);
std::vector<std::vector<int>> multiplicarMatrices(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B);
std::vector<std::vector<int>> multiplicarMatricesTraspuesta(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B);
void imprimirMatriz(const std::vector<std::vector<int>>& matriz);
//Strassen
std::vector<std::vector<int>> sumarMatrices(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B);
std::vector<std::vector<int>> restarMatrices(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B);
std::vector<std::vector<int>> multiplicarStrassen(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B);
////////////////////// CASOS DE PRUEBA //////////////////////////////////
//Ordenamiento
std::vector<int> dataset_desordenado(int tamaño);
std::vector<int> dataset_ordenado(int tamaño);
std::vector<int> dataset_parcial_ordenado(int tamaño);
void dataset_resultado(std::vector<int>& vector, char nombre[]);
//Matrices
std::vector<std::vector<int>> generarMatriz(int filas, int columnas, bool cuadrada);
void guardarMatrizEnArchivo(const std::vector<std::vector<int>>& matriz, char nombreArchivo[]);


#endif // MATRICES_H
