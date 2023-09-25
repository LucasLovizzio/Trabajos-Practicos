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