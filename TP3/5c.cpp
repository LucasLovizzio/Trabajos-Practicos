#include <iostream>
using namespace std;

struct Nodo
{
    int dato;
    Nodo * siguiente;
};

Nodo * insertarOrdenado(Nodo * inicio, int numero)
{
    
    Nodo * nuevo = new Nodo;
    nuevo->dato = numero;
    
    if (inicio == nullptr || nuevo->dato < inicio->dato){
        nuevo->siguiente = inicio;
        inicio = nuevo;
    }
    else{
        Nodo * aux = inicio;
        while(aux->siguiente != nullptr && aux->siguiente->dato < nuevo->dato){
            aux = aux->siguiente;
        }
        nuevo->siguiente = aux->siguiente;
        aux->siguiente = nuevo;
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
}

int main()
{
    Nodo * inicio  = new Nodo;
    inicio  = nullptr;
    int numero;
    cout << "Ingrese un numero: ";
    cin >> numero;

    while (numero != 0){
        inicio = insertarOrdenado(inicio , numero);
        cout << "Ingrese otro numero: ";
        cin >> numero;
    }

    mostrarLista(inicio);
    
    return 0;
}