/*Escribir un programa que visualice el más grande, el más pequeño y el promedio de N números enteros. El valor
de N se solicita al usuario al comienzo del programa y luego se le permite introducir los números.*/

#include <iostream>
using namespace std;

int mayor,menor,n,num,cont;
bool flag=true;
float promedio;

int main()
{    
    cout << "Ingrese la cantidad de numeros a ingresar: ";
    cin >> n;

    for (int i = 1; i<=n ; i++)
    {
        
        cout << "Ingrese un numero: ";
        cin >> num;
        
        if(flag==true)
        {
            mayor = num;
            menor = num;
            flag  = false;
        }

        if (num < menor)
            menor = num;
        if (num > mayor)
            mayor = num;
        
        cont+=num;
    }

    promedio = float(cont)/float(n);   

    cout << "Mayor: " << mayor << endl;
    cout << "Menor: " << menor << endl;
    cout << "Promedio: " << promedio << endl;

    return 0;
}