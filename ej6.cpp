/*Escribir un programa que calcule la suma de una determinada cantidad de elementos de la serie armónica:
1/1 + 1/2 + 1/3 + … + 1/n, donde n se especifica por el usuario.*/

#include <iostream>
using namespace std;

float n;
float suma = 0.0;
int main()
{    
    cout << "Ingrese un numero 'n' para calcular la suma de una cantidad 'n' de elementos de la serie armonica: ";
    cin >> n;

    
    for(int i=1; i<=n; i++)
    {
        suma+= 1.0/i;
    }

    cout << "La suma de la serie armonica de " << n << " elementos es: " << suma << endl;

    return 0;
}