/*
Escribir un programa que permita al usuario gestionar los pagos de la cuota de un club.
a) Para ello, almacenar en un arreglo los números de DNI de los socios que pagaron. El club no tiene más
de 200 socios.
b) Permitir al usuario buscar un DNI en el arreglo y, si el DNI está en el arreglo, imprimir "Cuota al día". Si
no está, imprimir "Socio con deuda".
c) También se debe permitir al usuario eliminar un DNI del arreglo, en caso de haberlo ingresado
erróneamente.
d) Finalmente, imprimir todo el arreglo.
*/
#include <iostream>
using namespace std;

const int MAX = 200;
int dimlogica = 3;
void agregarSocio(int DNI, int arreglo[], int &dim_Logica)
{
    arreglo[dim_Logica]=DNI; 
    dim_Logica++;
}

void eliminarSocio(int DNI, int arreglo[], int &dim_Logica)
{
    int i = 0;
    while (i<dim_Logica && arreglo[i] != DNI)
    {
        i++;
    }
    if (arreglo[i]==DNI)
    {
        for (int j = i; j<dim_Logica-1 ; i++)
        {
            arreglo[j]=arreglo[j+1];
        }
        dim_Logica--;
    }
}

void buscarSocio(int DNI, int arreglo[], int dim_Logica)
{
    bool encontrado=false;
    for (int i = 0 ; i<dim_Logica ; i++)
    {
        if (arreglo[i]==DNI)
            encontrado = true;
    }
    if (encontrado==true){
        cout << "Cuota al dia\n";}
    else{
        cout << "Socio con deuda\n";}
}

void menu()
{
    int socios[MAX]={44444444,45444444,46444444};
    int opcion;
    int DNI;
    do
    {
        cout << "1 - Agregar socio \n";
        cout << "2 - Eliminar socio \n";
        cout << "3 - Buscar socio \n";
        cout << "0 - Salir\n\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "Ingrese el DNI del nuevo socio: ";
            cin >> DNI; cout << endl;
            agregarSocio(DNI, socios, dimlogica);
            break;
        case 2:
            cout << "Ingrese el DNI del socio a eliminar: ";
            cin >> DNI; cout << endl;
            eliminarSocio(DNI, socios, dimlogica);
            break;
        case 3:
            cout << "Ingrese el DNI del socio: ";
            cin >> DNI; cout << endl;
            buscarSocio(DNI, socios, dimlogica);
            break;
        case 0:
            break;
        default:
            cout << "ERROR (opcion incorrecta)...";
            break;
        }

    } while (opcion!=0);
    
}


int main()
{
    menu();
    return 0;
}