#include <iostream>
using namespace std;

struct Producto {
    string descripcion;
    float precio;
};

struct Venta {
    Producto producto;
    int cantidad;
};

int main(){

    Venta * p_Venta;
    p_Venta = new Venta;
    Venta productos;

    // Entrada de informacion
    cout << "Ingrese la cantidad vendida: ";
    cin >> productos.cantidad;
    
    cout << "Ingrese la descripcion del producto: ";
    getline(cin>>ws , productos.producto.descripcion);
    
    cout << "Ingrese el precio del producto: ";
    cin >> productos.producto.precio;

    p_Venta = &productos;

    // Descuento de un 15%
    p_Venta->producto.precio *=0.85;

    // Muestra de la compra
    cout << "\t\tVenta\n";
    cout << "Descripcion: " << p_Venta->producto.descripcion << endl;
    cout << "Precio total: " << (p_Venta->producto.precio) * (p_Venta->cantidad);
}