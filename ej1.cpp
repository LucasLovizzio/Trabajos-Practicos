/*Escribir un programa que imprima los números del 1 al 100, mostrando de a cinco por renglón.*/

#include <iostream>
using namespace std;

int main()
{    
    for(int num = 1; num<=100; num++)
    {
        cout << num << " ";
        if(num%5==0)
            cout << endl;
    }
    return 0;
}