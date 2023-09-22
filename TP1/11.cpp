/*Leer una cadena de caracteres (string) de teclado e imprimirla en orden inverso.*/

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

void invertirCadena(string text)
{
    reverse(text.rbegin(),text.rend());
    cout << text;
}

int main()
{
    string texto;
    cout << "Ingrese una cadena de texto para imprimir en orden inverso: ", getline(cin>>ws,texto);
    invertirCadena(texto);
    return 0;
}

