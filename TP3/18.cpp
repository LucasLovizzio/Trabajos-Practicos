/* 

Cargar en una lista circular, insertando al final, los títulos de las charlas que se darán en una conferencia de
tecnología. Independientemente de cómo las ingrese el usuario, se deben almacenar con la primera letra en
mayúscula y el resto en minúsculas.
a) Imprimir la lista resultante.
b) Solicitar al usuario el ingreso de un título e informar si existe en la lista. La búsqueda debe ser "case
insensitive" (es decir, sin importar que se ingrese con diferentes mayúsculas y minúsculas, si el título
coincide debe informarse que existe).

*/

#include <iostream>
using namespace std;

//Struct

struct Nodo
{
    string dato;
    Nodo * siguiente;
};

//Funciones

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

Nodo * insertarAlFinalCircular (Nodo * fin, string titulo)          /*Funcion insertarAlFinalCircular extraida del ejercicio 16 del TP3*/
{                                                                   /*Se adapto para que funcione con strings*/
    Nodo * nuevo = new Nodo;                    /*Se crea un puntero a un nuevo nodo*/
    nuevo->dato = titulo;                       /*Se le asigna el dato a ese nodo*/
    nuevo->siguiente = nullptr;                 /*Se le asigna el puntero siguiente a nullptr*/

    if (fin == nullptr)                         /*Si el puntero fin es nullptr*/
        nuevo->siguiente = nuevo;               /*El nuevo puntero siguiente apunta a si mismo*/                                    
    else{                                       /*Si no es nullptr*/
        nuevo->siguiente = fin->siguiente;      /*El nuevo puntero siguiente apunta a fin->siguiente*/                          
        fin->siguiente = nuevo;                 /*Fin->siguiente apunta al nuevo nodo*/
    }
    return nuevo;                               /*Se retorna el puntero a nuevo*/
}

void encontrar(Nodo * fin, string titulo)
{
    Nodo * aux = fin->siguiente;
    bool encontrado = false;
    if (fin->siguiente != nullptr)
    {
        do
        {
            if (aux->dato == titulo)                                                /*Si el dato del nodo es igual al titulo ingresado*/
                encontrado = true;                                                  /*Se cambia el valor de encontrado a true*/
            aux = aux->siguiente;
        } while (aux != fin->siguiente && encontrado == false);                     /*Se recorre la lista hasta que se encuentre el titulo o se llegue al final*/
        if (encontrado == true)                                                     /*Si se encontro el titulo*/
            cout << "El titulo ingresado se encuentra en la lista" << endl;         /*Se imprime que se encontro*/
        else                                                                        /*Si no se encontro*/
            cout << "El titulo ingresado no se encuentra en la lista" << endl;      /*Se imprime que no se encontro*/
    }
    else                                                                            /*Si el puntero fin->siguiente es nullptr*/
    {           
        cout << "La lista esta vacia" << endl;                                      /*Se imprime que la lista esta vacia*/
    }
}

void imprimir(Nodo * fin)
{
    
    if (fin != nullptr)
    {
        Nodo * aux = fin->siguiente;
        do
        {
            cout << aux->dato << " ";
            aux = aux->siguiente;
        } while (aux != fin->siguiente);
        cout << endl;
    }
}

int main()
{
    Nodo * fin = nullptr;
    string titulo;

    cout << "Ingrese el titulo de la charla ('x' para cortar): ";
    cin >> titulo;

    while (titulo != "x" && titulo != "X")              //Se ingresa el titulo de la charla, si es distinto de x o X se convierte en oracion (primera letra mayuscula)
    {
        titulo = oracion(titulo);
        fin = insertarAlFinalCircular(fin, titulo);
        cout << "Ingrese el titulo de la charla: ";
        cin >> titulo;
    }
    
    imprimir(fin);

    cout << "Ingrese un titulo para confirmar si esta o no esta en la lista ('x' para cortar): ";
    cin >> titulo;

    while (titulo != "x" && titulo != "X")
    {
        titulo = oracion(titulo);
        encontrar(fin, titulo);
        cout << "Ingrese un titulo para confirmar si esta o no esta en la lista ('x' para cortar): ";
        cin >> titulo;
    }
    return 0;
}