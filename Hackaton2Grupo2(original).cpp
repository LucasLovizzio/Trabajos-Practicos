/*Aliumnos : */
#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

// Structs 
struct FechaDeNacimiento
{
    int dia;
    int mes;
    int año;
};

struct Persona
{
    int DNI;
    string NombreApellido;
    char Sexo;
    FechaDeNacimiento Cumpleaños;
};

//Funciones
bool ValidarDNI(int DNI) // Funcion que sirve para saber si el DNI tiene 8 digitos
{
    int contador;
    while (DNI != 0)
    {
        DNI = DNI/10;
        contador++;
    }
    if (contador == 7)
        return true;
    else
        return false;
}

bool ValidarSexo(char sexo) // Funcion para saber si el sexo ingresado es el correcto
{
 if (tolower(sexo) =='f'||tolower(sexo) == 'm')
    return true;
else 
    return false;
}

bool validarDia (int dia){  // Funcion para saber si el dia es correcto
    if (dia <= 31 && dia >= 1)
        return true;
    else
        return false;
}

bool validarMes(int mes){    // Funcion para saber si el mes es correcto
    if (mes <=12 && mes >= 1)
        return true;
    else
        return false;
}

bool validarAño(int año){  // Funcion para saber si el año es correcto.
    if (año<=2023 && año >=1900)
        return true;
    else
        return false;  
}


void cargar (Persona arreglo[], int & dl){  // Funcion para inscribir personas
    Persona nuevaPersona;
    int dni;
    int dia, mes, año;
    string NombreApellido;
   
    char sexo;
    cout << "Ingrese el nombre de la persona: ";
    getline (cin>>ws,nuevaPersona.NombreApellido);
   
    cout << "Ingrese el DNI: ";
    cin >> dni;
  
    while (ValidarDNI (dni)!= true)
    {
        cout << "Ingrese un DNI correcto";
        cin >> dni;
    }
    nuevaPersona.DNI=dni;
   
    cout << "Ingrese el sexo de la persona: ";
    cin >> sexo;
   
    while (ValidarSexo(sexo)!= true)
    {
        cout << "Ingrese F para femenino o M para masculino";
        cin >> dni;
    }
    nuevaPersona.Sexo=sexo;

    cout << "Ingrese el dia de nacimiento: ";
    cin >> dia; 
    nuevaPersona.Cumpleaños.dia=dia;
    

    cout << "Ingrese el mes de nacimiento: ";
    cin >> mes; 
    nuevaPersona.Cumpleaños.mes=mes;

    cout << "Ingrese el año de nacimiento: ";
    cin >> año; 
    nuevaPersona.Cumpleaños.año=año;

    arreglo[dl]=nuevaPersona;
    dl++;
}

void personasPorAño(Persona arreglo[], int dl){ // Funcion para contar personas inscriptas por año
    int contador=0 , año ;
    cout << "Ingrese un año para ver cuantas personas hay inscriptas: ";
    cin >> año;
    
    for (int i = 0; i < dl; i++)
    {
       if (arreglo[dl].Cumpleaños.año==año);
    
    }

    cout << "Cantidad de personas inscriptas nacidas en el año " << año << "son: "<< contador;

}

void imprimirInscriptos(Persona arreglo[], int dl) // FUncion para imprimir arreglo de personas
{
    for (int i = 0; i < dl; i++)
    {
        cout << "Nombre Apellido: " << arreglo[dl].NombreApellido << endl;
        cout << "DNI: " << arreglo[dl].DNI << endl;
        cout << "Sexo: " << arreglo[dl].Sexo << endl;
        cout << "Fecha de nacimiento: " << arreglo[dl].Cumpleaños.dia << "/" << arreglo[dl].Cumpleaños.mes << "/" << arreglo[dl].Cumpleaños.año << endl;
    }
}

void dividirGenero (Persona arreglo[], Persona arregloFemenino[], Persona arregloMasculino[],int dl,int dlFem,int dlMasc){ // Funcion que divide el arreglo de inscriptos en 2 nuevos dependiendo de su genero

    for (int i = 0; i < dl; i++)
    {
       if (tolower(arreglo[dl].Sexo)=='f'){
            arregloFemenino[dlFem]=arreglo[dl];
            dlFem++;
       }
        else 
        {
            arregloMasculino[dlMasc]=arreglo[dl]; 
            dlMasc++;
        }     
    }
    cout << "Femeninas inscriptas: "<< endl;
    imprimirInscriptos(arregloFemenino, dlFem);
    cout << "Masculinos inscriptos: "<<endl;
    imprimirInscriptos(arregloMasculino , dlMasc);
    
}

void menu (){     // Funcion que muestra el menu interactivo.
    Persona inscriptos[MAX];   
    Persona inscriptosFemeninos[MAX];
    Persona inscriptosMasculinos[MAX];
    int dimensionLogica=0, dlFemenino=0, dlMasculino=0;
    int opcion; 

    do
    {
        cout << "Menu invitados\n";
        cout << "1 - Cargar invitados\n";
        cout << "2 - Informar personas inscriptas por año de nacimiento\n";
        cout << "3 - Mostrar listado ordenado por genero\n";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cargar(inscriptos, dimensionLogica);
            break;
        case 2:
            personasPorAño(inscriptos, dimensionLogica);
            break;
        case 3:
            dividirGenero(inscriptos, inscriptosFemeninos, inscriptosMasculinos, dimensionLogica, dlFemenino, dlMasculino);
            break;
        default:
            cout << "ERROR - Ingrese una opcion correcta.";
            break;
        }

    } while (opcion !=0);
}

int main()
{   
    menu();
    return 0;
}