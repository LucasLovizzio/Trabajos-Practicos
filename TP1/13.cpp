/*Leer una cadena de caracteres de teclado e, independientemente de cómo ha sido ingresada, convertir la
primera letra a mayúscula y el resto a minúsculas. Considerar que la cadena puede estar vacía.
Nota: la función toupper(carácter) convierte un carácter a mayúscula si éste es una letra de la A a la Z (si es
cualquier otro carácter, incluso letras acentuadas, no hace nada). De la misma forma, tolower(carácter) convierte
a minúscula.
Precondición: si la cadena no está vacía, el primer carácter es una letra.
Ejemplo: si se ingresa la cadena “EsTO ES UNa cadENA de Texto”, el resultado debería ser “Esto es una cadena
de texto” */

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string cadena;

    cout << "Ingrese una cadena de texto la cual sera reformada: \n";
    getline(cin>>ws, cadena);

    for (int i = 0; i < cadena.length(); i++)
    {
        if (i==0)
            cadena[i]=toupper(cadena[i]);
        else
            cadena[i]=tolower(cadena[i]);
    }

    cout << cadena;

    return 0;
}