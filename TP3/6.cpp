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

bool encontrarElemento(Nodo * inicio, string nombreBuscado){
    for (Nodo * aux = inicio ; aux != nullptr ; aux = aux->siguiente){
        if (aux->nombre == nombreBuscado)
            return true;
    }
    return false;
}

Nodo * eliminarElemento(Nodo * inicio, string nombreABorrar){
    if (inicio != nullptr){
        Nodo * aux = inicio;
        if (inicio->nombre == nombreABorrar){
            inicio = inicio->siguiente;
            delete aux;
        }
        else{
            while(aux->siguiente != nullptr && aux->siguiente->nombre != nombreABorrar){
                aux = aux->siguiente;
            }
            if (aux->siguiente->nombre == nombreABorrar){
                Nodo * aEliminar = aux->siguiente;
                aux->siguiente = aEliminar->siguiente;
                delete aEliminar;
            }
        }
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
    cout << endl;
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

    cout << "Ingrese el nombre de un alumno para verificar si esta en la lista o no: ";
    getline(cin>>ws,nombre);
    if (encontrarElemento(inicio,nombre) == true)
        cout << "El alumno pertenece a la lista\n";
    else
        cout << "El alumno no pertenece a la lista\n";

    cout << "Ingrese un nombre de usuario a eliminar ('Josefina Ortega'): ";
    getline(cin>>ws,nombre);
    inicio = eliminarElemento(inicio, nombre);
    mostrarLista(inicio);
    return 0;
}