/*Escribir un programa que lea una fecha en el formato numérico AAAAMMDD y la informe con el formato
DD/MM/AAAA.*/

#include <iostream>
#include <string>
using namespace std;

string prefecha;
string dia,mes,año;

int main()
{    
    cout << "Ingrese una fecha con el formato AAAAMMDD, para pasar al formato DD/MM/AAAA: ";
    getline(cin>>ws,prefecha);

    año = prefecha.substr(0,4);
    mes = prefecha.substr(4,2);  // sustrae una parte de la cadena desde una x posicion, una n cantidad de caracteres.
    dia = prefecha.substr(6,2);


    cout << "Su fecha es: " << dia << "/" << mes << "/" << año;
    return 0;
}