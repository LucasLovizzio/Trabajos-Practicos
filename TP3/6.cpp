#include <iostream>
#include <string>
#include <locale>
using namespace std;

struct Nodo{
    string nombre;
    Nodo * siguiente;
};

Nodo * insertarAlFinal(Nodo * inicio, string nombre)
{
    
    Nodo * nuevo = new Nodo;
    nuevo->nombre = nombre;
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
        cout << aux->nombre << " ";
    }
}

int main(){
    Nodo * inicio = new Nodo;
    inicio = nullptr;
    string nombre;
    cout << "Ingrese un nombre: ";

    getline(cin>>ws,nombre);
    while (nombre.length()!=1 && tolower(nombre[0])!='x')
    {
        inicio = insertarAlFinal(inicio,nombre);
        cout << "Ingrese otro nombre o x para finalizar: ";
        getline(cin>>ws,nombre);
    }
    mostrarLista(inicio);
    return 0;
}