/*Cargar un arreglo con 20 números enteros ingresados por teclado de manera que el arreglo siempre se
encuentre ordenado en forma ascendente. El arreglo se cargará por completo.
Hacer tres variantes, suponiendo que el usuario carga los datos de las siguientes formas:
a) El usuario ingresa los números en orden ascendente.
b) El usuario ingresa los números en orden descendente.
c) El usuario ingresa los números sin un orden en particular*/

#include <iostream>
using namespace std;

const int dimensionFisica = 20;
int dimensionLogica = 0;

void imprimirArreglo(int arreglo[], int dim_Logica)
{
    for(int k = 0 ; k<dim_Logica ; k++)
        cout << arreglo[k] << " ";
}

void cargarOrdenado(int arreglo[], int & dim_Logica, int numero)
{
    int i = 0;
    while (i < dim_Logica && arreglo[i] < numero )
    {
        i++;
    }
    for(int j=dim_Logica ; j>i ; j--)
    {
        arreglo[j] = arreglo[j-1];
    }
    arreglo[i] = numero;
    dim_Logica++;
}


int main()
{
    int arregloNumeros[dimensionFisica];
    int numero;
    
    for(int w = 0; w<dimensionFisica-1; w++)
    {
        cout << "Ingrese un numero: " , cin >> numero , cout << endl;
        cargarOrdenado(arregloNumeros, dimensionLogica, numero);
    }
    
    imprimirArreglo(arregloNumeros,dimensionLogica);
    return 0;
}