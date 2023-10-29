/* 
Implementar una función que reciba dos listas enlazadas simples con datos de tipo string ordenadas según el
alfabeto y retorne una tercera lista ordenada por el mismo criterio, conformada por todos los elementos de las
listas originales (merge). Agregar las funciones auxiliares que sean necesarias para cumplir con este propósito.
*/

#include <iostream>
using namespace std;

struct  Nodo {
    string dato;
    Nodo * siguiente;
};

void mostrarLista(Nodo * inicio)
{
    cout << "Lista: ";
    for (Nodo * aux = inicio ; aux != nullptr ; aux = aux->siguiente)
    {
        cout << aux->dato << " ";
    }
    cout << endl;
}

Nodo * insertarOrdenado(Nodo * inicio, string dato){
    Nodo * nuevo = new Nodo;
    nuevo->dato = dato;
    nuevo->siguiente = nullptr;

    if (inicio == nullptr){
        inicio = nuevo;
    }
    else{
        Nodo * aux = inicio;
        Nodo * ant = nullptr;
        while(aux != nullptr && aux->dato < dato){
            ant = aux;
            aux = aux->siguiente;
        }
        if (ant == nullptr){
            nuevo->siguiente = inicio;
            inicio = nuevo;
        }
        else{
            ant->siguiente = nuevo;
            nuevo->siguiente = aux;
        }
    }
    return inicio;
}

Nodo * combinarListas(Nodo * lista1 , Nodo * lista2, Nodo * lista3){
    Nodo * aux1 = lista1;
    Nodo * aux2 = lista2;
    Nodo * aux3 = lista3;

    while (aux1 != nullptr){
        aux3 = insertarOrdenado(aux3, aux1->dato);
        aux1 = aux1->siguiente;
    }
    while (aux2 != nullptr)
    {
        aux3 = insertarOrdenado(aux3, aux2->dato);
        aux2 = aux2->siguiente;
    }
    
    return aux3;
}

int main(){
    Nodo * lista1 = new Nodo, *lista2 = new Nodo, *lista3 = new Nodo; 
    lista1->siguiente = nullptr, lista2->siguiente = nullptr, lista3->siguiente = nullptr;
    string dato;
    Nodo * listas[3] = {lista1, lista2, lista3};
    
    for(int i = 0 ; i < 2 ; i++)
    {
        cout << "Ingrese los datos a agregar en la lista "<< i+1 <<" (0 para cortar): ";
        getline(cin>>ws,dato);
        while(dato != "0")
        {
            listas[i] = insertarOrdenado(listas[i], dato);
            cout << "Ingrese otro dato o 0 para cortar: ";
            getline(cin>>ws,dato);
        }
    }

    // Mostrar las dos listas

    mostrarLista(lista1);
    mostrarLista(lista2);

    // Combinar las dos listas

    lista3 = combinarListas(lista1, lista2, lista3);
    cout << "Listas combinadas \n";
    mostrarLista(lista3);
}