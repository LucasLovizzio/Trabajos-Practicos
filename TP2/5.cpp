/*
Implementar una función llamada mas_uno que tiene como parámetro un arreglo estático de enteros y que
incrementa en uno el valor de cada elemento de dicho arreglo. Añadir otros parámetros que se necesiten.
*/

#include <iostream>
using namespace std;

int dimensionLogica=7;

void mas_uno(int arreglo[], int dim_logica)
{
    for(int i = 0; i<dim_logica;i++)
    {
        arreglo[i]+=1;
    }
}

void imprimirArreglo(int arreglo[], int dim_Logica)
{
    for(int k = 0 ; k<dim_Logica ; k++)
        cout << arreglo[k] << " ";
}

int main()
{
    int numeros[] = {1,5,20,13,8,9,1};
    mas_uno(numeros,dimensionLogica);
    imprimirArreglo(numeros,dimensionLogica);
    return 0;
}