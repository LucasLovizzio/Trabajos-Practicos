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

//Main
int main()
{
    Nodo * inicioSuc1 = nullptr;
    Nodo * inicioSuc2 = nullptr;
    Nodo * listaSucursales = nullptr;

    while()
}