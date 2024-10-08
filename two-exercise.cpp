/*

Ejercicio Nro. 2: Elabore un programa que presente en pantalla los primeros veinte 20 números que:

a.- Que finalicen en uno (1).

b.- Que sean divisibles exactamente entre veintiuno (21).

c.- Que el resultado de su división entre veintiuno (21) al sacarle la raíz cuadrada de un numero entero que termine en uno (1).

El rango a revisar es desde 50000 hasta que consiga los veinte (20) números.

En la pantalla deberá presentarse el número, su división entre veintiuno (21) y la raíz cuadrada de ese resultado que termina en uno (1):

Numero terminado en uno – División entre 21 – Raíz Cuadrada que termina en uno

54621 – 2601 - 51
*/

#include <iostream>
#include <cmath>
using namespace std;

bool esDivisiblePor21(int number)
{
    return number % 21 == 0;
};

int main()
{
    int rangoARevisar = 50000;
    int numeros = 0;

    while (numeros < 20)
    {
        if (esDivisiblePor21(rangoARevisar))
        {
            double division = rangoARevisar / 21;
            if (division == int(division))
            {
                int divisionExactaPor21 = int(division);
                double raiz = sqrt(divisionExactaPor21);
                if (raiz == int(raiz) and int(raiz) % 10 == 1)
                {
                    int raizExacta = int(raiz);
                    cout << numeros << " - " << rangoARevisar << " - " << divisionExactaPor21 << " - " << raizExacta << endl;
                    numeros++;
                };
            };
        };
        rangoARevisar++;
    };
    return 0;
};