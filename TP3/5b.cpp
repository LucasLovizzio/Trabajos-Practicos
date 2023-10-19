#include <iostream>
using namespace std;

struct Nodo
{
    int dato;
    Nodo * siguiente;
};

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
        while(aux->siguiente!=nullptr){
            aux = aux->siguiente;
        }
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
    Nodo * inicio  = nullptr;
    int numero;
    cout << "Ingrese un numero: ";
    cin >> numero;

    while (numero != 0){
        inicio = insertarAlFinal(inicio , numero);
        cout << "Ingrese otro numero: ";
        cin >> numero;
    }

    mostrarLista(inicio);
    
    return 0;
}