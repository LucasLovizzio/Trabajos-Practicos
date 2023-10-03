/*

Realizar un algoritmo que almacene información de, como máximo, 500 libros en un arreglo estático. Un libro
se define como un struct con los siguientes campos: titulo, autor, ISBN, editorial, cantidadHojas. El algoritmo
finaliza luego de cargar el libro "El hobbit", el cual debe procesarse o cuando ya no quede espacio en el arreglo
(lo que suceda primero). Finalmente, imprimir el arreglo resultante mostrando todos los datos de cada libro.

*/

#include <iostream>
#include <string>
using namespace std;

const int MAX_Libros = 500;

struct libro
{
    string titulo;
    string autor;
    string ISBN;
    string editorial;
    int cantHojas;
};

void cargarLibros(libro arregloLibros[MAX_Libros], int &cantLibros)
{
    libro nuevoLibro;
    do
    {
        cout << "Ingrese el titulo del libro: ";
        getline(cin>>ws, nuevoLibro.titulo);
        if (nuevoLibro.titulo == "El hobbit") {
            break;
        }
        cout << "Ingrese el autor del libro: ";
        getline(cin>>ws, nuevoLibro.autor);

        cout << "Ingrese el ISBN del libro: ";
        getline(cin>>ws, nuevoLibro.ISBN);

        cout << "Ingrese la editorial del libro: ";
        getline(cin>>ws, nuevoLibro.editorial);

        cout << "Ingrese la cantidad de hojas del libro: ";
        cin >> nuevoLibro.cantHojas;
        cin.ignore(); // Limpiar el buffer del salto de línea

        // Almacenar el libro en el arreglo
        arregloLibros[cantLibros] = nuevoLibro;
        cantLibros++;
    }while (cantLibros < MAX_Libros);
}

void imprimirLibros(libro arregloLibros[MAX_Libros], int cantLibros)
{
    cout << "Lista de libros:" << endl;
    for (int i = 0; i < cantLibros; i++) {
        cout << "Libro " << i + 1 << ":" << endl;
        cout << "Título: " << arregloLibros[i].titulo << endl;
        cout << "Autor: " << arregloLibros[i].autor << endl;
        cout << "ISBN: " << arregloLibros[i].ISBN << endl;
        cout << "Editorial: " << arregloLibros[i].editorial << endl;
        cout << "Cantidad de Hojas: " << arregloLibros[i].cantHojas << endl;
        cout << endl;
    }
}

int main()
{
    libro Libros[MAX_Libros];
    int numlibros = 0;
    cargarLibros(Libros, numlibros);
    imprimirLibros(Libros, numlibros);

}
