/*GRUPO 4
Alumnos: Maxi Javier Palma, Milenka Artero Figginni, Gonzalo Suazo, Maria Eugenia Pinteño y Lucas Ezequiel Lovizzio.
*/

#include <iostream>
#include <string>
using namespace std;

string oracion(string frase)
{
    for (int i = 0; i < frase.length(); i++)            /*Funcion Notacion oracion extraida del ejercicio 13 del TP1, adaptado a la consigna*/
    {
        if (i==0)
            frase[i]=toupper(frase[i]);                 /*El for recorre la frase, el primer caracacter frase[0] se convierte en mayuscula*/
        else                                            /*el resto de las letras se colocan en minuscula.*/
            frase[i]=tolower(frase[i]);
    }
    return frase;
}

string camelCase(string frase)                          /*Sacamos solamente el espacio, ya que en la consigna indicaba solamente la eliminacion del espacio*/
{                                                       /*y en el ejemplo saca espacio y comas.*/


    string resultado;                                   /*string en donde se ingresan las letras*/
    bool siguientemayus = false;    
    for(int i=0 ; i < frase.length(); i++)
    {
        
        if (siguientemayus == true)                     /*flag que usamos para detectar espacios y saber cuando la siguiente letra se pasa a mayusculas*/
        {
            resultado += toupper(frase[i]);
            siguientemayus = false;                     /*se desactiva el flag*/
        }
        else if (frase[i]!=' ')
            resultado += tolower(frase[i]);             /*si no se detecta un espacio la letra es minuscula*/
        else
            siguientemayus=true;                        /*si no entra en el else if es debido a que es un espacio, por lo tanto la siguiente letra es mayuscula*/
    }
    return resultado;
}
void menu()
{
    int opcion;
    string texto;

    do
    {
        cout << "Elija una opcion: "<<endl;
        cout << endl;
        cout << "*** Tipos de Notación***" << endl;             /*Menu de opciones*/
        cout << "[0] - Salir" << endl;
        cout << "[1] - Notación Oración."<< endl;
        cout << "[2] - Notación Camel Case." << endl;

        cin >> opcion;                                          /*Se pide la elección de una opción del menu*/

        switch (opcion)
        {
        case 0:
            break;
        
        case 1:
            cout << "*** Notación Oración***" << endl;
            cout << "Ingrese una frase: ";                      /*Menú notación oración*/
            getline(cin>>ws, texto);
            cout << "Notación Oración: " << oracion(texto) << endl;
            break;
        case 2:
            cout << "*** Notación Camel Case ***" << endl;
            cout << "Ingrese una frase: ";                      /*Menú notación Camel Case*/
            getline(cin>>ws, texto);
            cout <<"Notacion Camel Case: " << camelCase(texto) << endl;
            break;
        default:
            cout << "Ingreso una opción incorrecta" << endl;
        }

    }while(opcion!=0);                                          /*hasta que no se ingrese un cero no termina el programa*/
}

int main()
{
    menu();
    return 0;
}