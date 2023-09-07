/*Implementar un programa que solicite una palabra y verifique si es palíndromo. Una palabra es palíndromo si
puede leerse igual de izquierda a derecha que de derecha a izquierda.
Precondición: todos los caracteres son minúsculas y no se ingresarán vocales acentuadas ni diéresis.*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string invertirCadena(string text)
{
    reverse(text.rbegin(),text.rend());
    return text;
}

int main()
{
    string cadena;
    
    cout << "Ingrese una cadena de texto, se le informará si es un palíndromo: \n";
    getline(cin>>ws,cadena);

    if(invertirCadena(cadena) == cadena)
        cout << "La palabra ingresada es un palíndromo";
    else
        cout << "La palabra ingresada no es un palíndromo";

    return 0;
}