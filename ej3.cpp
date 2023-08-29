/*Leer tres letras desde teclado e indicar cuál de ellas viene primero en el alfabeto.*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string letra;
string letras="";

int main()
{    
    cout << "Ingrese tres letras distintas" << endl;

    for (size_t i = 1; i <= 3; i++)
    {
        cout << "Ingrese una letra: ";
        cin >> letra;

        letras+=letra;                          
    }
    
    sort(letras.begin(),letras.end()); // Ordena las letras de menor a mayor con respecto al alfabeto.
    cout << "La letra '" << letras[0] << "' es la que viene primera en el alfabeto de las tres ingresadas.";
    
    return 0;
}