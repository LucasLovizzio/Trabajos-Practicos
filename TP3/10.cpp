/* 
Cargar una lista enlazada simple con palabras ingresadas por el usuario, las cuales deben almacenarse en
minúsculas independientemente de cómo las ingrese. Luego, a partir de esa lista, generar una nueva lista con
las palabras que se encuentran repetidas. Finalmente, imprimir ambas listas.
*/

#include <iostream>
using namespace std;

//Struct Nodo

struct Nodo
{
    string palabra;
    Nodo * siguiente;
};

//Funciones

Nodo * insertarAlFinal(Nodo * inicio, string palabra)
{
    
    Nodo * nuevo = new Nodo;
    nuevo->palabra = palabra;
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

bool encontrarElemento(Nodo * inicio, string palabra){
    for (Nodo * aux = inicio ; aux != nullptr ; aux = aux->siguiente){
        if (aux->palabra == palabra)
            return true;
    }
    return false;
}

Nodo * ListRepetidas(Nodo * inicio, Nodo * repetidas){
    Nodo * aux = inicio;
    Nodo * aux2 = inicio;
    Nodo * aux3 = repetidas;

    while(aux != nullptr){
        while(aux2 != nullptr){
            if (aux->palabra == aux2->palabra && aux != aux2){
                if (encontrarElemento(repetidas, aux->palabra) == false){
                    repetidas = insertarAlFinal(repetidas, aux->palabra);
                }
            }
            aux2 = aux2->siguiente;
        }
        aux = aux->siguiente;
        aux2 = inicio;
    }
    return repetidas;    
}

int main(){
    Nodo * inicio = new Nodo;
    inicio = nullptr;

    Nodo * repetidas = new Nodo;
    repetidas = nullptr;

    string palabra;

    cout << "Para cortar el bluce ingrese '0'\n Ingrese una palabra: ";
    cin >> palabra;
    while(palabra != "0"){
        for (int i = 0 ; i < palabra.length() ; i++){
            palabra[i] = tolower(palabra[i]);               //Paso la palabra a minuscula
        }
        inicio = insertarAlFinal(inicio, palabra);
        cout << "Ingrese otra palabra: ";
        cin >> palabra;
    }

    repetidas = ListRepetidas(inicio, repetidas);
    cout << "Lista repetidas: ";

    while(repetidas != nullptr){
        cout << repetidas->palabra << " ";
        repetidas = repetidas->siguiente;
    }
    return 0;
}