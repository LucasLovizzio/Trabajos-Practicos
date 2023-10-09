/*
Escribir un programa que almacene en un arreglo los datos de los alumnos de una escuela luego de finalizado elaño académico. 
Como máximo, puede haber 500 alumnos. De cada alumno se debe guardar el nombre y la
calificación obtenida en el primer, segundo y tercer trimestre del año académico. Imprimir el listado de
nombres de alumnos mostrando un mensaje de "APTO" si el alumno supera o iguala la calificación de 5 para
todas las notas o "NO APTO" si no lo alcanza.
Utilizar un arreglo como campo del struct para almacenar las tres calificaciones.
*/

#include <iostream>
using namespace std;

// Dimensiones

const int MAX = 500;

// STRUCTS

struct Calificacion {
    int primerCuatri;
    int segundoCuatri;
    int tercerCuatri;
};

struct Alumno {
    string Nombre;
    Calificacion notas;
};

void agregarSocio(Alumno arreglo[], int &dim_Logica)
{
    string nombreYApellido;
    int nota;
    
    while(nombreYApellido!="X"){
        cout << "Ingrese su nombre y apellido: ";
        getline(cin>>ws, nombreYApellido);
        if (nombreYApellido == "X")
        {
            continue;
        }
        arreglo[dim_Logica].Nombre = nombreYApellido;

        cout << "Ingrese la nota del primer cuatrimestre: ";
        cin >> nota;
        arreglo[dim_Logica].notas.primerCuatri = nota;
        cout << "Ingrese la nota del segundo cuatrimestre: ";
        cin >> nota;
        arreglo[dim_Logica].notas.segundoCuatri = nota;
        cout << "Ingrese la nota del tercer cuatrimestre: ";
        cin >> nota;
        arreglo[dim_Logica].notas.tercerCuatri = nota;

        dim_Logica++;
    }

    cout << "Lista de alumnos: \n";
    
    for (int i = 0; i< dim_Logica ; i++)
    {
        cout << arreglo[i].Nombre << ": ";
        if (arreglo[i].notas.primerCuatri>=5 and arreglo[i].notas.segundoCuatri>=5 and arreglo[i].notas.tercerCuatri>=5){
            cout << "APTO" << endl;
        }
        else{
            cout << "NO APTO" << endl;
        }
    }
    
}

int main()
{
    Alumno alumnos[MAX];
    int dl = 0;

    cout << "Si ingresa como nombre 'X' se deja de ingresar nombres \n";
    agregarSocio(alumnos,dl);

}