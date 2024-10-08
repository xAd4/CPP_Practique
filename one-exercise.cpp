/*
01.- Programación I - Ejercicios Propuestos
Ejercicio Nro. 1: Elabore un programa que presente en pantalla los primeros veinte (20) números que al sacarle la raíz cuadrada el resultado sea un numero:

a.- Entero (sin parte decimal)

b.- Primo

c.- Que termine siete (7).

El rango a revisar es desde 100000 hasta que ubique los veinte (20) números

En la pantalla deberá presentarse el número y su raíz:

Numero – Raíz cuadrada (Primo que termina en siete)

54621 - 337

120409 – 347
*/

#include <iostream>
#include <cmath>
using namespace std;

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
    int rangoARevisar = 100000;
    int numeros = 0;

    while (numeros < 20)
    {
        double raizCuadrada = sqrt(rangoARevisar);
        if (raizCuadrada == int(raizCuadrada))
        {
            int raizCuadradaExacta = int(raizCuadrada);
            if (raizCuadradaExacta % 10 == 7 && esPrimo(raizCuadradaExacta))
            {
                cout << rangoARevisar << " - " << raizCuadradaExacta << endl;
                numeros++;
            };
        };
        rangoARevisar++;
    }

    cout << "Presiona Enter para salir...";
    cin.ignore();
    cin.get();
    return 0;
}