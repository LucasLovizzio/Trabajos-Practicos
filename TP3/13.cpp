/* 

Dos sucursales de Fiestísima disponen cada una de una lista enlazada simple con el detalle de las ventas
realizadas. De cada venta se conoce: código de producto y cantidad vendida (un producto pudo haber sido
vendido 0, 1 o más veces en la misma sucursal). Las listas de ventas están ordenadas de menor a mayor por
código de producto. Realizar una función que reciba las dos listas y retorne una nueva lista unificando todas las
ventas, ordenada por el mismo criterio. Utilizar un algoritmo destructivo (que reutilice los nodos de las listas
originales). Agregar las funciones auxiliares que sean necesarias.

*/

#include <iostream>
using namespace std;

//Structs

struct Venta
{
    int codigoProducto;
    int cantidadVendida;
};

struct Nodo
{
    Venta dato;
    Nodo * siguiente;
};

//Funciones

Nodo * insertarOrdenado (Nodo * inicio , Nodo * nuevo)
{
    if (inicio == nullptr || nuevo->dato.codigoProducto < inicio->dato.codigoProducto)  
    {
        nuevo->siguiente = inicio;
        inicio = nuevo;
    }
    else
    {
        Nodo * aux = inicio;
        while (aux->siguiente != nullptr && aux->siguiente->dato.codigoProducto < nuevo->dato.codigoProducto)
        {
            aux = aux->siguiente;
        }
        if (aux->siguiente != nullptr)
        {
            nuevo->siguiente = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
    return inicio;
}

Nodo * combinarListas(Nodo * lista1 , Nodo * lista2, Nodo * lista3)
{
    Nodo * anterior;

    while (lista1 != nullptr)
    {
        anterior = lista1;
        lista1 = lista1->siguiente;
        anterior->siguiente == nullptr;
        lista3 = insertarOrdenado(lista3, anterior);
    }
    while (lista2 != nullptr)
    {
        anterior = lista2;
        lista2 = lista2->siguiente;
        anterior->siguiente == nullptr;
        lista3 = insertarOrdenado(lista3, anterior);
    }
    return lista3;
}

void mostrarLista(Nodo * inicio)
{
    cout << "Lista de productos: \n\n";
    for (Nodo * aux = inicio ; aux != nullptr ; aux = aux->siguiente)
    {
        cout << "\t::::::::::\n";
        cout << "\tCodigo de producto: " << aux->dato.codigoProducto << endl;
        cout << "\tCantidad vendida: " << aux->dato.cantidadVendida << endl;
        cout << "\t::::::::::\n";
    }
    cout << endl;
    system("pause");
}

//Main
int main()
{
    Nodo * inicioSuc1 = nullptr;
    Nodo * inicioSuc2 = nullptr;
    
    Nodo * Sucursales[2] = {inicioSuc1, inicioSuc2};
    Nodo * listaSucursales = nullptr;

    for (int i = 0 ; i < 2 ; i++)
    {
        cout << "Usted estara ingresando datos en la lista " << i+1 << endl;

        int codigoProducto, cantidadVendida;
        cout << "Ingrese el codigo del producto (-1 para cortar): ";
        cin >> codigoProducto;

        while (codigoProducto != -1)
        {
            cout << "Ingrese la cantidad vendida: ";
            cin >> cantidadVendida;

            Nodo * nuevo = new Nodo;
            nuevo->dato.codigoProducto = codigoProducto;
            nuevo->dato.cantidadVendida = cantidadVendida;
            nuevo->siguiente = nullptr;

            Sucursales[i] = insertarOrdenado(Sucursales[i], nuevo);

            cout << "Ingrese el codigo del producto (-1 para cortar): ";
            cin >> codigoProducto;
        }
    }

    mostrarLista(Sucursales[0]);
    mostrarLista(Sucursales[1]);

    listaSucursales = combinarListas(inicioSuc1, inicioSuc2, listaSucursales);

    mostrarLista(listaSucursales);

    return 0;
}