/*
Escribir una función que, dado un arreglo de int y su dimensión lógica, invierta los elementos del arreglo.
Ejemplos: Si el arreglo contiene los elementos [1,2,3,4,5] deberá quedar [5,4,3,2,1].
Si el arreglo contiene [10,20] deberá quedar [20,10].
Si el arreglo contiene [5] deberá quedar [5].
*/

#include <iostream>
using namespace std;

const int MAX=10;
int dimensionLogica=0;

void invertir_arreglo(int a[], int dl)
{
    int arreglo_invertido[MAX];
    int j = dl-1;
    for (int i = 0 ; i<dl ; i++, j--)
    {
        arreglo_invertido[i]=a[j];
        cout << arreglo_invertido [i] << " ";
    }
}

int main()
{
    int A[MAX] = {2,8,5,2,2,7,2,7,4,2};
    int B[MAX];
    int C[MAX] = {2};
    int D[MAX] = {2,2,2};
    int E[MAX] = {1,3,5,7,9};
    int dlA=10, dlB=0, dlC=1, dlD=3, dlE=5;
    invertir_arreglo(A, dlA); cout << endl;
    invertir_arreglo(B, dlB); cout << endl;
    invertir_arreglo(C, dlC); cout << endl;
    invertir_arreglo(D, dlD); cout << endl;
    invertir_arreglo(E, dlE); cout << endl;
    return 0;
}