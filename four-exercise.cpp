/*

Ejercicio Nro. 4: Elabore un programa que presente en pantalla los primeros diez (10) números que:

a.- Que sean divisibles exactamente entre catorce (14).

b.- Que el resultado de su división entre catorce (14) al sacarle la raíz cuadrada de un numero entero (sin parte decimal).

c.- Que el resultado de la raíz sea un numero primo (Divisible de forma exacta solamente entre el mismo y entre 1) que termine en tres (3).

El rango a revisar es desde 500000 hasta que consiga los diez (10) números.

En la pantalla deberá presentarse el número, su división entre catorce (14) y la raíz cuadrada de ese resultado:

Numero – División entre 14 – Raíz Cuadrada y numero Primo

521486 – 37249 - 193

*/

#include <iostream>
#include <cmath>
using namespace std;

bool divisiblePor14(int number)
{
    return number % 14 == 0;
}

bool esPrimo(int number)
{
    if (number <= 1)
        return false;
    for (int i = 2; i <= sqrt(number); i++)
    {
        if (number % i == 0)
            return false;
    };
    return true;
}

int main()
{

    int rangoARevisar = 500000;
    int numeros = 0;

    while (numeros < 10)
    {

        if (divisiblePor14(rangoARevisar))
        {
            double division14 = rangoARevisar / 14.0;
            double raiz = sqrt(division14);
            if (raiz == int(raiz))
            {
                int raizExacta = int(raiz);
                if (esPrimo(raizExacta) && raizExacta % 10 == 3)
                {
                    cout << numeros << " - " << rangoARevisar << " – " << division14 << " - " << raizExacta << endl;
                    numeros++;
                }
            }
        }
        rangoARevisar++;
    }
}