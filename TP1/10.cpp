/*Escribir un programa que imprima el menú mostrado a continuación y solicite al usuario elegir una opción, la
cual se debe ejecutar para luego volver a mostrar el menú repetidas veces, hasta que el usuario decida salir:
‘A’: Invertir número.
‘B’: Sumatoria de dígitos.
‘C’: Decir si son múltiplos.
‘D’: Salir.
Dependiendo del carácter ingresado por el usuario, realizar la acción indicada en el menú: A: leer un número e
invertir sus dígitos para luego imprimirlo en orden inverso; B: solicitar un número e imprimir la suma de sus 
dígitos; C: solicitar el ingreso de dos números y decir si el primero es múltiplo del segundo; D: terminar el
programa.
Si el usuario ingresa un carácter que no es la opción D, se debe ejecutar lo que corresponda y volver a mostrar
el menú para permitirle elegir otra opción. Si el carácter ingresado por el usuario no es A, B, C ni D, mostrarle un
mensaje de error y continuar mostrándole el menú y solicitando una opción hasta que ingrese una que sea válida.*/

#include <iostream>
#include <algorithm>
using namespace std;

void invertirNum()
{
    int num,resto,numInv=0;
    
    cout << "Ingrese un numero para invertir: ";
    cin >> num;

    while(num>0)
    {
        resto=num%10;
        num=num/10;
        numInv=numInv*10+resto;
    }
    cout << "El numero invertido es: " <<numInv << endl;
    system("pause");
    system("cls");
}

void sumarDigitos()
{
    int num,resto,sumDigit=0;
    
    cout << "Ingrese un numero para sumar sus digitos: ";
    cin >> num;

    while(num>0)
    {
        resto=num%10;
        num=num/10;
        sumDigit+=resto;
    }   
    cout << "La suma de los digitos de el numero ingresado es: " << sumDigit << endl;
    system("pause");
    system("cls");
}

void sonMultiplos()
{
    int num1,num2;

    cout << "Ingrese un numero: ", cin >> num1, cout << endl;
    cout << "Ingrese otro numero: ", cin >> num2, cout << endl;

    if (num1%num2==0)
        cout << num1 <<" es multiplo de " << num2 << endl;
    else
        cout << num1 <<" no es multiplo de " << num2 << endl;
    system("pause");
    system("cls");
}

int menu()
{
    char opcion;
    cout << endl;
    cout << "------MENU------\n";
    cout << "A- Invertir número.\n";
    cout << "B- Sumatoria de digitos\n";
    cout << "C- Decir si son multiplos.\n";
    cout << "D- Salir\n";

    cin >> opcion;
    
    switch (toupper(opcion))
    {
    case 'A':
        invertirNum();
        menu(); 
        break;
    case 'B':
        sumarDigitos();
        menu();
        break;

    case 'C':
        sonMultiplos();
        menu();
        break;

    case 'D':
        break;

    default:
        cout << "Ha ingresado una opcion incorrecta, porfavor ingrese nuevamente una opcion."<< endl;
        menu();
        break;
    }
    return 0;
}

int main()
{
    menu();
    return 0;
}