/*Escribir un programa que determine si un año es bisiesto.
Nota: un año es bisiesto si es múltiplo de 4. Los años múltiplos de 100 no son bisiestos, excepto que también
sean múltiplos de 400.
Ejemplo: 2000 es bisiesto, 1800 no lo es.*/


#include <iostream>
using namespace std;


bool bisiesto(int año)
{
    if(año%400==0)
        return true;
    if(año%100==0)
        return false;
    if (año%4==0)
        return true;
    else return false;
}

int main()
{
    int año;
    
    cout << "Ingrese un año y se determinará si es bisiesto o no: " ; cin >> año; cout << endl;
    
    if (bisiesto(año)==true)
    {
        cout << "El año ingresado es bisiesto";
    }
    else
        cout << "El año ingresado no es bisiesto";
    return 0;
}