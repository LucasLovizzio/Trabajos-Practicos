#include <iostream>
using namespace std;

const int MAX=100;
int dimensionLogica;

void cargar(float arreglo[], int cantidad , int &dl)
{
    float num;
    for (int i=0; i<cantidad; i++)
    {
        cout << "Número para almacenar: ";
        cin >> num;
        arreglo[i]=num; 
        dl++;
    }
}

void imprimirArreglo(float arreglo[], int dl)
{
    for(int j=0 ; j<dl ; j++)
    {
        cout << arreglo[j] << " ";
    }
}

int main()
{
    float numeros[MAX];
    int cantidad;
    do{
        cout << "Ingrese la cantidad de numeros a almacenar: ";
        cin >> cantidad;
    } while (cantidad > MAX);
    cargar(numeros, cantidad , dimensionLogica);
    imprimirArreglo(numeros, dimensionLogica);
}
