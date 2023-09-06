/*Leer una frase de teclado e informar la longitud de la última palabra. Se considera al espacio como separador
de palabras.

Precondición: el string no finaliza con espacios*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string cadena;
    int longUltimaPalabra = 0;
    cout << "Ingrese una cadena de texto que finalice sin espacios: \n";
    getline(cin>>ws,cadena);
    int tamañoCadena = cadena.length();

    for (int i=0 ; i<tamañoCadena; i++)
    {
        if(cadena[i] == ' ')
            longUltimaPalabra = 0;
        else longUltimaPalabra++;
    }

    cout << "La longitud de la ultima palabra de la cadena es: " << longUltimaPalabra;

    return 0;
}