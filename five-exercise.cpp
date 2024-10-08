/*

Ejercicio Nro. 5: Elabore un programa que presente en pantalla los primeros veinte (20) números que:

a.- Que finalicen en ocho (8).

b.- Que sean divisibles exactamente entre siete (7). (sin parte decimal)

c.- Que el resultado de su división entre siete (7) al sacarle la raíz cuadrada de un numero entero que termine en dos (2).

El rango a revisar es desde 500000 hasta que consiga los veinte números.

En la pantalla deberá presentarse el número, su división entre siete (7) y la raíz cuadrada de ese resultado que termina en (2) dos:

Numero – División entre 7 – Raíz Cuadrada terminada en dos

681408 – 97344 - 312

*/

#include <iostream>
#include <cmath>
using namespace std;

bool divisiblePor7(int number)
{
    if (number <= 1)
        return false;
    return (number % 7 == 0);
}

int main()
{
    int rangoARevisar = 500000;
    int numeros = 0;

    while (numeros <= 20)
    {
        if (rangoARevisar % 10 == 8)
        {
            if (divisiblePor7(rangoARevisar))
            {
                double division = rangoARevisar / 7.0;
                double raiz = sqrt(division);
                if (raiz == int(raiz))
                {
                    int raizExacta = int(raiz);
                    if (raizExacta % 10 == 2)
                    {
                        cout << numeros << " - " << rangoARevisar << " - " << division << " - " << raizExacta << endl;
                        numeros++;
                    }
                }
            }
        }
        rangoARevisar++;
    }
    return 0;
}