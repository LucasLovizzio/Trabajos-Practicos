/*

Se lee de teclado una secuencia de números enteros, finalizando cuando el usuario ingresa un cero (que no
debe insertarse). Los números leídos deberán ser almacenados en una lista circular. Hacer dos versiones,
insertando en cada una con diferente criterio, a saber:
a) Al inicio de la lista.
b) Al final de la lista.
Finalmente, imprimir la lista.

*/

// Struct Nodo

struct Nodo
{
    int dato;
    Nodo * siguiente;
};


#include <iostream>
using namespace std;

Nodo * insertarAlPrincipioCircular(Nodo *fin, int numero)
{
    Nodo * nuevo = new Nodo;
    nuevo->dato = numero;
    nuevo->siguiente = nullptr;

    if (fin == nullptr)
    {
        nuevo->siguiente = nuevo;
        fin = nuevo;
    }
    else
    {
        nuevo->siguiente = fin->siguiente;
        fin->siguiente = nuevo;
    }
    return fin;
}

Nodo * insertarAlFinalCircular (Nodo * fin, int numero)
{
    Nodo * nuevo = new Nodo;
    nuevo->dato = numero;
    nuevo->siguiente = nullptr;

    if (fin == nullptr)
        nuevo->siguiente = nuevo;
    else{
        nuevo->siguiente = fin->siguiente;
        fin->siguiente = nuevo;
    }
    return nuevo;
}

void imprimir(Nodo * fin)
{
    
    if (fin != nullptr)
    {
        Nodo * aux = fin->siguiente;
        do
        {
            cout << aux->dato << " ";
            aux = aux->siguiente;
        } while (aux != fin->siguiente);
        cout << endl;
    }
}

int main()
{
    Nodo * final = nullptr;
    Nodo * principio = nullptr;
    int numero;

    cout << "Ingrese un numero: ";
    cin >> numero;
    
    while (numero != 0)
    {
        final = insertarAlFinalCircular(final, numero);
        principio = insertarAlPrincipioCircular(principio, numero);

        cout << "Ingrese un numero: ";
        cin >> numero;   
    }
    cout << "Lista final: ";
    imprimir(final);
    cout << "Lista principio: ";
    imprimir(principio);

    return 0;
}