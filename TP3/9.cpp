/* 
Desarrollar un programa que realice las siguientes operaciones en listas enlazadas simples de números enteros.
A. Cargar una lista insertando los elementos ordenados en forma descendente. Finaliza luego de ingresar
el cero, que también se debe agregar a la lista.
B. Eliminar las ocurrencias de los números que son múltiplos de 3.
C. Imprimir la lista antes y después de la eliminación.
 */

#include <iostream>
using namespace std;

//Struct Nodo

struct Nodo
{
    int dato;
    Nodo * siguiente;
};

// Funciones

Nodo * insertarOrdenado(Nodo * inicio, int numero)
{
    Nodo * nuevo = new Nodo;
    nuevo->dato = numero;
    
    if (inicio == nullptr || nuevo->dato > inicio->dato){
        nuevo->siguiente = inicio;
        inicio = nuevo;
    }
    else{
        Nodo * aux = inicio;
        while(aux->siguiente != nullptr && aux->siguiente->dato > nuevo->dato){
            aux = aux->siguiente;
        }
        nuevo->siguiente = aux->siguiente;
        aux->siguiente = nuevo;
    }
    return inicio;
}

Nodo * eliminarMultiplosDe3(Nodo * inicio){
    int contador = 0;
    Nodo * aux = inicio;
    Nodo * anterior = nullptr;
    while (aux != nullptr){
        if (aux->dato % 3 == 0){
            contador++;
            if (anterior == nullptr){
                inicio = aux->siguiente;
                delete aux;
                aux = inicio;
            }
            else{
                anterior->siguiente = aux->siguiente;
                delete aux;
                aux = anterior->siguiente;
            }
        }
        else{
            anterior = aux;
            aux = aux->siguiente;
        }
    }
    return inicio;
}

void mostrarLista(Nodo * inicio)
{
    cout << "Lista: ";
    for (Nodo * aux = inicio ; aux != nullptr ; aux = aux->siguiente)
    {
        cout << aux->dato << " ";
    }
    cout << endl;
}

// Main

int main()
{
    Nodo * inicio  = new Nodo;
    inicio = nullptr;
    
    int numero=0;
    
    do{
        cout << "Ingrese un numero: ";
        cin >> numero;
        inicio = insertarOrdenado(inicio , numero);
    }while(numero != 0);

    cout << "Lista antes de eliminar los multiplos de 3: ";
    mostrarLista(inicio);
    inicio = eliminarMultiplosDe3(inicio);
    cout << "Lista despues de eliminar los multiplos de 3: ";
    mostrarLista(inicio);

    return 0;
}