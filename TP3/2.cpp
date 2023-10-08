/*¿Qué salidas produce el siguiente código?*/

#include <iostream>
using namespace std;
int main() {
    int *p1, *p2;
    p1 = new int;
    p2 = new int;

    *p1 = 10;
    *p2 = 20;

    cout << *p1 << " " << *p2 << endl; // 10 20

    *p1 = *p2;
    cout << *p1 << " " << *p2 << endl; // 20 20

    *p2 = 30;
    cout << *p1 << " " << *p2 << endl; // 20 30

}