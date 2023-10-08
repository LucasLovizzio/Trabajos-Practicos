/*Dado el siguiente programa, indicar la salida en cada punto señalado*/

#include <iostream>
using namespace std;
int main() {
    int *p1, *p2;

    p1 = new int;
    *p1 = 42;
    p2 = p1;
    cout << *p1 << endl; // 42
    cout << *p2 << endl; // 42

    *p2 = 53;
    cout << *p1 << endl; // 53
    cout << *p2 << endl; // 53

    p1 = new int; 
    *p1 = 88;
    cout << *p1 << endl; // 88
    cout << *p2 << endl; // 53
    cout << "FIN"; //C. Luego de ejecutar esta línea
    return 0;
}