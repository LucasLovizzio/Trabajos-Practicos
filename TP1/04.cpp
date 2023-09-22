
/*Escribir un programa que, dado un número (entero largo) expresado en segundos, informe el equivalente en
horas, minutos y segundos.*/

#include <iostream>
using namespace std;

int horas=0,minutos=0,segundos;

int main()
{    
    cout << "Escriba un numero expresado en segundos, y se informara un equivalente en horas, minutos y segundos: ";
    cin >> segundos;

    while (segundos>=60)
    {
        minutos = segundos/60;
        segundos= segundos%60;
    }
    while (minutos>=60)
    {
        horas = minutos/60;
        minutos = minutos%60;
    }
    
    cout << "Horas: " << horas <<endl;
    cout << "Minutos: " << minutos<<endl;
    cout << "Segundos: "<< segundos<<endl;
    return 0;
}