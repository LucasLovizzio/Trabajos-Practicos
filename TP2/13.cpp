/*

Dado un arreglo bidimensional de tipo float de 7 filas y 10 columnas, describir las sentencias para:

a) Asignar el valor 105 a la posición que se encuentra en la segunda fila, quinta columna.
b) Asignar en todas las posiciones de la cuarta fila el valor 1.5.
c) Imprimir todos los valores de la matriz, colocando cada fila en una nueva línea.
d) Permutar las columnas 3 y 5.
e) Sumar todos los elementos de las filas 2 y 6.
f) Imprimir todos los valores de la tercera columna.
g) Hallar en qué fila y columna se encuentra almacenado el mayor elemento

*/

#include <iostream>

using namespace std;

int main() {
    const int filas = 7;
    const int columnas = 10;
    float matriz[filas][columnas];

    // a) Asignar el valor 105 a la posición que se encuentra en la segunda fila, quinta columna.
    matriz[1][4] = 105.0;

    // b) Asignar en todas las posiciones de la cuarta fila el valor 1.5.
    for (int i = 0; i < columnas; i++) {
        matriz[3][i] = 1.5;
    }

    // c) Imprimir todos los valores de la matriz, colocando cada fila en una nueva línea.
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    // d) Permutar las columnas 3 y 5.
    for (int i = 0; i < filas; i++) {
        float temp = matriz[i][2];
        matriz[i][2] = matriz[i][4];
        matriz[i][4] = temp;
    }

    // e) Sumar todos los elementos de las filas 2 y 6.
    float suma_filas_2_y_6 = 0.0;
    for (int i = 1; i <= 6; i += 4) {
        for (int j = 0; j < columnas; j++) {
            suma_filas_2_y_6 += matriz[i][j];
        }
    }

    // f) Imprimir todos los valores de la tercera columna.
    for (int i = 0; i < filas; i++) {
        cout << matriz[i][2] << endl;
    }

    // g) Hallar en qué fila y columna se encuentra almacenado el mayor elemento.
    int fila_max = 0;
    int columna_max = 0;
    float max_valor = matriz[0][0];

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (matriz[i][j] > max_valor) {
                max_valor = matriz[i][j];
                fila_max = i;
                columna_max = j;
            }
        }
    }

    cout << "El mayor elemento se encuentra en la fila " << fila_max << " y la columna " << columna_max << endl;

    return 0;
}
