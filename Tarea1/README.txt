DATOS:
    NOMBRE: Renato Ramírez | ROL: 202173639

ESPECIFICACIONES:
    Version C++: 11.2.0
    Consola utilizada: WSL GNU bash, version 5.1.16(1)-release (x86_64-pc-linux-gnu)

CONSIDERACIONES:
    Primero que todo, recalcar que los algoritmos utilizados y codigos para crear los casos de prueba, no fueron hechos por mi
    (revisar carpetas raw), encontrara dos carpetas raw, estas contienen los algoritmos originales, provistos por diversas fuentes
    (se especifica en el PDF). Sin embargo, los algoritmos fueron adaptados por mi para que funcionaran bien con mi codigo main,
    los detalles los podra encontrar en "algoritmos.cpp" y en "algoritmos.hpp" encontrara las funciones de forma mas resumida,
    algunas funciones no tienen muchos comentarios, estos se encuentran en los archivos raw.

    La ejecucion del programa lo llevara a un menu simplificado para ejecutar los algoritmos, considerando tamaños pequeño, mediano
    y grande para todos los algoritmos (los tamaños especificos se pueden encontrar utilizando el menu o en el codigo, especificamente
    en las funciones "crearVector" y "crearMatriz"), se guardaran los datos de entrada en un archivo .txt y los resultados de salida
    de cada algoritmo tambien en un archivo .txt, mostrando por pantalla el tiempo de ejecucion de cada algoritmo (si se desea, es
    posible printear por pantalla el resultado de los vectores o de las matrices, las funciones se encuentran comentadas, descomentelas
    y podra imprimir lo que necesite), finalmente el comando para compilar el archivo main es el siguiente:

        1.- g++ main.cpp algoritmos.cpp -o main -Wall
        2.- ./main
