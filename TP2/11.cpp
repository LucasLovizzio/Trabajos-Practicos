/*
Escribir un programa que permita al usuario ingresar números enteros positivos (los números ingresados no
deben almacenarse). Al finalizar, informar la cantidad de veces que apareció cada dígito (del 0 al 9) en todos los
números.
Ejemplo: Si el usuario ingresa los números 1156, 23, 73364, 988, 1003, 5, se debe informar que el 0 apareció 2
veces, el 1 apareció 3 veces, el 2 apareció 1 vez, el 3 apareció 4 veces, etc.
*/

#include <iostream>

using namespace std;

void contar_digitos(int arreglo[],int num)
{
    int i;
    while (num!=0){
        i = num%10;
        arreglo[i]++;
        num/=10;
    }
}

int main() {
    const int MAX = 10; // Definimos la cantidad de dígitos
    int frecuencia_digitos[MAX]={0,0,0,0,0,0,0,0,0,0};

    int numero;
    
    do
    {
        cout << "Ingrese números enteros positivos (0 para finalizar): "; 
        contar_digitos(frecuencia_digitos, numero);
    } while (cin >> numero && numero != 0);
    // Solicitamos al usuario que ingrese los números enteros positivos, separados por comas.
    
    // Mostramos la frecuencia de cada dígito.
    for (int i = 0; i < MAX; i++) 
    {
        cout << "El dígito " << i << " apareció " << frecuencia_digitos[i] << " veces." << endl;
    }

    return 0;
}
