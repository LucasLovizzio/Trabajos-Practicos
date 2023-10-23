/* 
Implementar una función que reciba dos parámetros: una lista enlazada simple de números enteros y un
número entero. La función debe eliminar todas las ocurrencias del número indicado en el segundo parámetro.
Retornar la cantidad de ocurrencias eliminadas. Nota: se debe pasar una sola vez por cada uno de los
elementos de la lista.
*/

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

int eliminarElementos(Nodo * inicio, int numero){
    int contador = 0;
    Nodo * aux = inicio;
    Nodo * anterior = nullptr;
    while (aux != nullptr){
        if (aux->dato == numero){
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
    return contador;
}
int main(){
    
    Nodo * inicio  = new Nodo;
    inicio  = nullptr;
    int numero;
    cout << "Ingrese un numero: ";
    cin >> numero;

    while(numero != 0){
        inicio = insertarAlFinal(inicio , numero);
        cout << "Ingrese otro numero: ";
        cin >> numero;
    }
    cout << "Ingrese el numero que quiere eliminar: ";
    cin >> numero;
    int contador = eliminarElementos(inicio, numero);
    cout << "Se eliminaron " << contador << " ocurrencias del numero " << numero << endl;

    return 0;
}