/*
Dadas dos matrices de 4 x 4 leídas por teclado, informar la matriz resultante de la operación A + B.
*/

#include <iostream>
using namespace std;

const int MAX = 4;

void ingresar_matriz(int matriz[MAX][MAX], int dimension)
{
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            cout << "Elemento (" << i << ", " << j << "): ";
            cin >> matriz[i][j];
        }
    }
}

void suma_Matricial(int arreglo1[MAX][MAX],int arreglo2[MAX][MAX], int arreglo_resultado[MAX][MAX], int dimension)
{
    cout << "La suma matricial entre el arreglo A y el B es: " << endl;
    for (int i = 0 ; i<dimension ; i++)
    {
        for (int j = 0 ; j < dimension ; j++)
        {
            arreglo_resultado[i][j] = arreglo1[i][j] + arreglo2[i][j];
            cout << arreglo_resultado[i][j] << "\t";
        }
        cout <<endl;
    }
}

int main()
{
    int A[MAX][MAX],B[MAX][MAX],C[MAX][MAX];

    // A+B = C

    cout << "Ingrese la matriz A: " << endl, ingresar_matriz(A,MAX);
    cout << "Ingrese la matriz A: " << endl, ingresar_matriz(B,MAX);
    suma_Matricial(A,B,C,MAX);
    return 0;
}