/*Escribir una función que reciba un punto de coordenadas (X,Y) desde el teclado y devuelva TRUE si el punto
pertenece a la recta de ecuación Y = 3X + 2 ó FALSE en caso contrario.
Nota: sólo se debe hacer la función, aunque puede ser útil realizar la invocación y utilizar el valor de retorno para
imprimir algo en pantalla, a fines de probar el algoritmo.*/

bool cordenadas(int x, int y)
{
    if(y == 3*x+2)
        return true;
    else return false;
}