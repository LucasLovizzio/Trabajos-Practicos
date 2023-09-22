#include <iostream>
#include <string>
using namespace std;

int cantidadVocales(string cadena)
{
    int cantVoc=0;

    for(int i=0 ; i<cadena.length() ; i++ )
    {
        switch(tolower(cadena[i]))
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            cantVoc++;
            break;
        default:
            break;
        }
    }
    return cantVoc;
}

int contar(string cadena, char caracter)
{
    int cantCaracter=0;
    for (int i=0 ; i<cadena.length(); i++)
    {
        if (cadena[i]==caracter)
            cantCaracter++;
    }
    return cantCaracter;    
}

void caracteresPares(string cadena)
{
    for(int i=0; i<cadena.length(); i=i+2)
    {
        cout << cadena[i] << " ";
    }
}

int main() 
{
    int opcion;
    do 
    {
        string cadena;
        cout << "Ingresar frase: ";
        getline(cin>>ws, cadena);
        cout << "MENÚ: " << endl;
        cout << "1. Cantidad total de vocales (mayúsculas y minúsculas)." << endl;
        cout << "2: Contar cuántas veces aparece un carácter." << endl;
        cout << "3: Mostrar caracteres en posiciones (índice) pares." << endl;
        cout << "0: Salir." << endl;
        cout << "Opción elegida: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Cantidad de vocales: " << cantidadVocales(cadena) << endl;
            break;
        case 2:
            cout << "Ingresar carácter a contar: ";
            char caracter;
            cin >> caracter;
            cout << "Cantidad encontrada: " << contar(cadena, caracter) << endl;
            break;
        case 3:
            caracteresPares(cadena);
            cout << endl;
            break;
        case 0:
            break;
        default:
            cout << "Opción no válida" << endl;
            break;
        }
    } while (opcion != 0);
}
