/*
Escribir un programa para ser utilizado en una ventanilla de venta de entradas de un pequeño teatro con
capacidad para 50 personas. Las filas están identificadas de la 0 a la 4 y cada fila tiene asientos numerados de 1
a 10. Se debe registrar, por cada asiento, si está libre o no. Al iniciar el programa, todos los asientos están libres.
Cuando alguien desea comprar una entrada, se deben informar qué localidades están libres. Entonces el cliente
deberá elegir su asiento (indicando fila y número de asiento) y éste se marcará como vendido. Si ya se
vendieron todas las entradas, no se debe permitir elegir asiento.
*/

#include <iostream>
using namespace std;

const int MAX_filas = 5;
const int MAX_asiento = 9;
bool permitir_venta = true;
bool asientos[MAX_filas][MAX_asiento];

void liberarAsientos(bool arreglo[MAX_filas][MAX_asiento],int dimfila,int dimasiento,int &asientosDisponibles)
{
    for (int i = 0 ; i<dimfila ; i++)
    {
        for (int j = 0 ; j < dimasiento ; j++ )
        {
            arreglo[i][j] = false;
            asientosDisponibles++;
        }
    }
}

void mostrarAsientos(bool arreglo[MAX_filas][MAX_asiento],int dimfila,int dimasiento)
{
    cout << "\t1\t2\t3\t4\t5\t6\t8\t9\t10"<<endl;
    for (int i = 0 ; i<dimfila ; i++)
    {
        cout << i;
        for (int j = 0 ; j < dimasiento ; j++ )
        {
            if (arreglo[i][j]==false)
                cout << "\tL ";
            else
                cout << "\tO";
        }
        cout << endl;
    }
}

void comprarAsiento(bool arreglo[MAX_filas][MAX_asiento], int dimfila , int dimasiento, int &asientosDisponibles)
{
    int fila,asiento;
    bool compraAsiento = false;

    if(asientosDisponibles==0)
    {
        cout << "No hay mas asientos disponibles para comprar";
        compraAsiento = true;
    }
    while(compraAsiento!=true)
    {
        mostrarAsientos(asientos,dimfila,dimasiento);
        cout << "Seleccione la fila: ", cin >> fila , cout << endl;
        cout << "Seleccione el asiento: ", cin >> asiento , cout << endl;
        if (asientos[fila][asiento-1]==false)
        {
            asientos[fila][asiento-1]=true;
            asientosDisponibles--;
            compraAsiento = true;
        }
    }
}

void menu()
{
    int opcion;
    int asientosDisponibles=0;
    liberarAsientos(asientos, MAX_filas, MAX_asiento,asientosDisponibles); // Setea todos los asientos a Libres
    system("cls");
    cout << "\t\t\t BIENVENIDO\n";
    cout << endl;

    do
    {
        cout << "1 - Comprar Ticket\n";
        cout << "2 - Mostrar asientos\n";
        cout << "3 - Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            comprarAsiento(asientos , MAX_filas, MAX_asiento, asientosDisponibles);
            //system("pause");
            //system("cls");
            break;
        case 2:
            mostrarAsientos(asientos , MAX_filas, MAX_asiento);
            //system("pause");
            //system("cls");
        case 3:
            break;
        default:
            cout << "OPCION INCORRECTA";
            break;
        }

    } while (opcion!=3);

}

int main()
{
    menu();
    return 0;
}