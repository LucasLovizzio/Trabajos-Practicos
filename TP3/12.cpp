/* 
Generar una lista enlazada simple con la nómina de artículos de un supermercado. De cada artículo se conoce:
código, descripción, precio y stock. La carga finaliza con el código -1. Se solicita:
A. Leer de teclado un porcentaje e incrementar el precio de todos los artículos en esa cantidad.
B. Incrementar el stock de un artículo. Se lee de teclado el código y la cantidad con la que se debe
incrementar el stock. Si no existe el artículo en la lista se debe informar.
C. Eliminar de la lista los artículos que no tienen stock.
*/

#include <iostream>
using namespace std;

// STRUCTS

struct Articulo{
    int codigo;
    string descripcion;
    float precio;
    int stock;
};

struct Nodo {
    Articulo articulo;
    Nodo * siguiente;
};

// FUNCIONES 

Nodo * insertarOrdenadoCodigo(Nodo * inicio, Articulo producto){
    Nodo * nuevo = new Nodo;
    nuevo->siguiente = nullptr;
    nuevo->articulo = producto;

    if(inicio == nullptr || nuevo->articulo.codigo < inicio->articulo.codigo)
    {
        nuevo->siguiente = inicio;
        inicio = nuevo;
    }
    else{
        Nodo * aux = inicio;
        while (aux->siguiente != nullptr && aux->siguiente->articulo.codigo < nuevo->articulo.codigo){
            aux = aux->siguiente;
        }
        if (aux->siguiente != nullptr){
            nuevo->siguiente = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
    return inicio;
}

Nodo * incrementarPrecio(Nodo * inicio, float porcentaje){
    Nodo * aux = inicio;
    while (aux != nullptr){
        aux->articulo.precio += aux->articulo.precio * porcentaje / 100;
        aux = aux->siguiente;
    }
    return inicio;
}

Nodo * incremenetarStock (Nodo * inicio, int codigo , int stock)
{
    Nodo * aux = inicio;
    while (aux != nullptr){
        if(aux->articulo.codigo == codigo)
        {
            aux->articulo.stock += stock;
            return inicio;
        }
        else
        {
            aux = aux->siguiente;
        }
    }
    cout << "El codigo ingresado no corresponde a ningun producto en stock.\n";
    return inicio;
}

Nodo * eliminarsinStock(Nodo * inicio){
    if (inicio != nullptr)
    {
        Nodo * aux = inicio;
        if (aux->articulo.stock == 0) {
            inicio = inicio->siguiente;
            delete aux;
        }
        else{
            while(aux->siguiente != nullptr && aux->siguiente->articulo.codigo != 0)
            {
                aux = aux->siguiente;
            }
            if(aux->siguiente->articulo.codigo == 0)
            {
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
    cout << "Lista de productos: \n\n";
    for (Nodo * aux = inicio ; aux != nullptr ; aux = aux->siguiente)
    {
        cout << "Codigo: "<< aux->articulo.codigo << "\n";
        cout << "Descripcion: "<< aux->articulo.descripcion << "\n";
        cout << "Precio: $"<< aux->articulo.precio << "\n";
        cout << "Stock: "<< aux->articulo.stock << "\n";
        cout << "\t::::::::::\n";
    }
    cout << endl;
    system("pause");
}

void menu(Nodo * inicio)
{
    int opcion = 0;
    while(opcion != 5)
    {
        cout << "\t\tMENU\n\n";
        cout << "1 - Aumentar precios\n";
        cout << "2 - Aumentar stock\n";
        cout << "3 - Mostrar lista\n";
        cout << "4 - Eliminar productos sin stock\n";
        cout << "5 - Salir\n";

        int stock, porcentaje, codigo;
        cin >> opcion;

        switch (opcion)
        {
            case 1:
                cout << "Ingresa el porcentaje a aumentar: ";
                cin >> porcentaje;
                inicio = incrementarPrecio(inicio, porcentaje);
                break;

            case 2:
                cout << "Ingresa el codigo del producto: ";
                cin >> codigo;
                cout << "Ingrese la cantidad de stock que desea aumentar: ";
                cin >> stock;
                inicio = incremenetarStock(inicio, codigo, stock);
                break;
            case 3: 
                mostrarLista(inicio);
                break;
            case 4:
                inicio = eliminarsinStock(inicio);
                break;
            case 5:
                break;
            default:
                cout << "Se ha ingresado una opcion incorrecta \n";
                system("pause");
                system("cls");
                break;
        }
    }

    
}

int main(){
    Nodo * inicio = nullptr;

    Articulo producto;

    cout << "Ingrese el codigo del producto: ";
    cin >> producto.codigo;

    while (producto.codigo != -1)
    {
        cout << "Ingrese la descripcion del producto: ";
        getline(cin>>ws,producto.descripcion);
        cout << "Ingrese el precio del producto: ";
        cin >> producto.precio;
        cout << "Ingrese el stock del producto: ";
        cin >> producto.stock;

        inicio = insertarOrdenadoCodigo(inicio, producto);

        cout << "Ingrese el codigo del producto: ";
        cin >> producto.codigo;
    }

    menu(inicio);

    return 0;
}