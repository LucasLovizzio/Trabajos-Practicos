/*Escribir un bucle para validar lo ingresado por el usuario: se debe solicitar el ingreso de un carácter y sólo se debe
interrumpir el bucle cuando el usuario haya ingresado el carácter 's' o el carácter 'n'. La solicitud de ingreso del
dato debe hacerse al menos una vez antes de evaluar si el bucle debe interrumpirse o no. No utilizar "while true"
como condición. A continuación, si el usuario ingresó la letra 's', imprimir "usted eligió SÍ" y, si ingresó la 'n'
imprimir "usted eligió NO".

Nota: para evaluar la condición de corte del bucle considerando mayúsculas y minúsculas es posible utilizar las
funciones toupper(carácter) y tolower(carácter), que convierten el carácter pasado por parámetro a mayúscula
o a minúscula respectivamente (si el carácter no es una letra, no se modifica).*/


#include <iostream>
using namespace std;

float evaluarletra(char letra, float & corte)
{
    if (tolower(letra)=='s')
    {
        corte = true;
        return true;
    }
    if (tolower(letra)=='n')
    {
        corte = false;
        return true;
    }
    else return false;
}

int main()
{
    char letra;
    float corte;

    cout << "El siguiente bulce se interrumple al ingresar 's' o 'n'\n";
    
    do
    {
        cout << "Ingrese una letra: ", cin >> letra;

    } while (evaluarletra(letra, corte)!=true);

    if (corte == false)
        cout << "Usted eligió NO";
    else cout << "Usted eligió SI";
    
    return 0;
}