/*
Una matriz cuadrada A se dice que es simétrica si A(i,j) = A(j,i) para todo i, j. Escribir un programa que decida si
una matriz de 3 x 3 dada es o no simétrica.
*/

#include <iostream>

using namespace std;

void ingresar_matriz(int matriz[][3], int dimension)
{
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            cout << "Elemento (" << i << ", " << j << "): ";
            cin >> matriz[i][j];
        }
    }
}

bool matriz_simetrica(int matriz[][3], int dimension)
{
    bool simetrica = true;
    for (int i = 0; i < dimension; i++) 
    {
        for (int j = 0; j < dimension; j++) 
        {
            if (matriz[i][j] != matriz[j][i]) 
            {
                simetrica = false;
                break;
            }
        }
        if (!simetrica)
            break;
    }
    return simetrica;
}

int main() {
    const int dimension = 3;
    int matriz[dimension][dimension];

    // Solicitar al usuario que ingrese los elementos de la matriz.
    cout << "Ingrese los elementos de la matriz de 3x3:" << endl;

    ingresar_matriz(matriz, dimension);

    // Verificar si la matriz es simétrica.
    bool simetrica = matriz_simetrica(matriz, dimension);

    // Mostrar el resultado.
    if (simetrica == true) {
        cout << "La matriz es simétrica." << endl;
    } else {
        cout << "La matriz no es simétrica." << endl;
    }

    return 0;
}
