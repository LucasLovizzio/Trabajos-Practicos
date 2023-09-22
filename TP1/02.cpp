/*Contar la cantidad de números negativos leídos desde teclado. La serie termina con el valor cero (0), el cual no
debe procesarse. ¿Qué cambiaría si debiera procesarse también el último número ingresado (0)?*/



#include <iostream>
using namespace std;

int main()
{    
    int num, cont_negativos = 0;

    cout << "Se contabilizaran solamente los negativos y termina el codigo al ingresarse un 0" << endl;
    
    do
    {
        cout << "Ingrese un numero: ";
        cin >> num;

        if(num<0)
            cont_negativos++;    

    } while (num!=0);

    cout << "Usted ha ingresado " << cont_negativos << " numeros negativos.";
    

    return 0;
}