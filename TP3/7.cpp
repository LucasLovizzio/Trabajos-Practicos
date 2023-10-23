/* 
Se lee de teclado una secuencia de números que finaliza con la primera ocurrencia de un número negativo, el
cual no debe ser procesado. Los números deben ser almacenados en una lista enlazada simple. Se solicita:
A. Leer de teclado un número e informar si existe en la lista.
B. Leer de teclado un número e informar la cantidad de ocurrencias del número en la lista.
C. Implementar una función que reciba la lista de números y genere dos nuevas listas, una con los
números pares y otra con los impares. Las nuevas listas deberán estar formadas con los nodos de la lista
original, la que quedará vacía después de invocar a la función. Imprimir las listas resultantes.
*/

#include <iostream>
using namespace std;



//STRUCT

struct Nodo
{
    int dato;
    Nodo * siguiente;
};

// FUNCIONES

Nodo * insertarAlFinal(Nodo * inicio, int numero)
{
    Nodo * nuevo = new Nodo;
    nuevo->dato = numero;
    nuevo->siguiente = nullptr;
    
    if (inicio == nullptr){
        inicio = nuevo;
    }
    else{
        Nodo * aux = inicio;
        while(aux->siguiente != nullptr){
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
    
    return inicio;
}

//A. Leer de teclado un número e informar si existe en la lista.

bool encontrarElemento(Nodo * inicio, int numero){
    for (Nodo * aux = inicio ; aux != nullptr ; aux = aux->siguiente){
        if (aux->dato == numero)
            return true;
    }
    return false;
}

//B. Leer de teclado un número e informar la cantidad de ocurrencias del número en la lista.

int contarElementos(Nodo * inicio, int numero){
    int contador = 0;
    for (Nodo * aux = inicio ; aux != nullptr ; aux = aux->siguiente){
        if (aux->dato == numero)
            contador++;
    }
    return contador;
}

//C. Implementar una función que reciba la lista de números y genere dos nuevas listas, una con los
//números pares y otra con los impares. Las nuevas listas deberán estar formadas con los nodos de la lista
//original, la que quedará vacía después de invocar a la función. Imprimir las listas resultantes.

Nodo * dividirLista(Nodo * inicio, Nodo *& par, Nodo *& impar){
    for (Nodo * aux = inicio ; aux != nullptr ; aux = aux->siguiente){
        if (aux->dato % 2 == 0){
            par = insertarAlFinal(par, aux->dato);
        }
        else{
            impar = insertarAlFinal(impar, aux->dato);
        }
    }
    cout << "Lista par: ";
    for (Nodo * aux = par ; aux != nullptr ; aux = aux->siguiente){
        cout << aux->dato << " ";
    }
    cout << "\nLista impar: ";
    for (Nodo * aux = impar ; aux != nullptr ; aux = aux->siguiente){
        cout << aux->dato << " ";
    };
    return inicio;
}

//Menu

void menu(Nodo * inicio, Nodo * par, Nodo * impar)
{
    int opcion, numero;
    cout << "\t\t MENU \n";
    cout << "1 - Informar si existe determinado numero en la lista.\n";
    cout << "2 - Informar la cantidad de ocurrencias del número en la lista.\n";
    cout << "3 - Dividir en lista par e impar.\n";
    cout << "0 - Salir\n";

    cin >> opcion;

    switch (opcion)
    {
        case 0:
        {
            break;
        }
        case 1:
        {
            cout << "Ingrese el numero que quiere saber si existe en la lista: ";
            cin >> numero;
            if (encontrarElemento(inicio , numero) == true)
                cout << "El numero " << numero << " pertenece a la lista";
            else
                cout << "El numero " << numero << " no pertenece a la lista";
            menu(inicio,par,impar);
            break;
        }
        case 2:
        {
            cout << "Ingrese el numero que quiere saber cuantas veces aparece en la lista: ";
            cin >> numero;
            int contador = contarElementos(inicio, numero);
            cout << "El numero " << numero << " aparece " << contador << " veces en la lista.";
            menu(inicio,par,impar);
            break;
        }
        case 3:
        {
            dividirLista(inicio, par, impar);
            menu(inicio,par,impar);
            break;
        }
        default:
        {
            cout << "Opcion incorrecta.";
            menu(inicio,par,impar);
            break;
        }
    }
}

int main(){
    
    Nodo * inicio = new Nodo;
    inicio = nullptr;
    Nodo * par = new Nodo;
    par = nullptr;
    Nodo * impar = new Nodo;
    impar = nullptr;

    int numero;
    cin >> numero;

    while (numero>=0){
        inicio = insertarAlFinal (inicio, numero);
        cin >> numero;
    }
    menu(inicio,par,impar);

}