/*Leer una secuencia de caracteres que finaliza con la letra minúscula 'n', la cual debe ser procesada. Contabilizar
la cantidad de cada una de las letras vocales minúsculas. También informar la cantidad de caracteres leídos en
total y el porcentaje de letras vocales minúsculas encontradas en la secuencia.*/

#include <iostream>
using namespace std;

int main()
{    
    char letra;
    int cantMinus=0,cantLeidos=0;
    float porcLetrasVocMin;

    do
    {
        cout << "Ingrese una letra: ";
        cin >> letra;

        switch (letra)
        {
        case 'a':
            cantMinus++;
            break;
        case 'e':
            cantMinus++;
            break;
        case 'i':
            cantMinus++;
            break;
        case 'o':
            cantMinus++;
            break;
        case 'u':
            cantMinus++;
            break;
        default:
            break;
        }

        cantLeidos++;


    } while (letra!='n');
    
    porcLetrasVocMin = float(cantMinus)/float(cantLeidos)*100;

    cout << "Cantidad de letras vocales minusculas leidas: " << cantMinus << endl;
    cout << "Cantidad de letras leidas: " << cantLeidos << endl;
    cout << "Porcentaje de letras vocales minusculas: %" << porcLetrasVocMin << endl;


    return 0;
}