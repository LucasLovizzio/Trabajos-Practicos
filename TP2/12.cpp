/*
Escribir una variante del programa anterior en la que, en lugar de informar la cantidad de veces que apareció
cada dígito, se informe si apareció o no cada dígito en todos los números ingresados. Analizar cómo puede
resolverse este ejercicio evitando contabilizar la cantidad de dígitos.
Ejemplo: Si el usuario ingresa los números 44, 1, 710, 15, se debe informar que el 0 apareció, el 1 apareció, el 2
no apareció, el 3 no apareció, el 4 apareció, el 5 apareció, etc.
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
        if (frecuencia_digitos[i]==0)
            cout << "El " << i << " NO apareció " << endl;
        else
            cout << "El " << i << " aparecio" << endl;
    }

    return 0;
}
