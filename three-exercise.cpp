/*

Ejercicio Nro. 3: Elabore un programa que presente en pantalla los primeros veinte (20) números que:

a.- Que sean divisibles exactamente entre cuatro (4). (Sin parte decimal)

b.- Que sean divisibles exactamente entre seis (6). (Sin parte decimal)

c.- Que su raíz cuadrada de un numero entero (Sin parte decimal) y que ese número termine es cuatro (4).

El rango a revisar es desde 50000 hasta que consiga los veinte (20) números.

En la pantalla deberá presentarse el número, su división entre cuatro (4), su división entre seis (6) y la raíz cuadrada de ese resultado que termina en 4:

Numero – División entre 4 – División entre 6 - Raíz Cuadrada terminada en 4

54756 – 13689 – 9126 - 234

*/

#include <iostream>
#include <cmath>
using namespace std;

bool divisibleEntre4(int number)
{
    return number % 4 == 0;
};

bool divisibleEntre6(int number)
{
    return number % 6 == 0;
};

int main()
{
    int rangoARevisar = 50000;
    int numeros = 0;

    while (numeros < 20)
    {
        if (divisibleEntre4(rangoARevisar))
        {
            double division4 = rangoARevisar / 4.0;
            if (division4 == int(division4))
            {
                int division4Exacta = int(division4);
                if (divisibleEntre6(division4Exacta))
                {
                    double division6 = division4Exacta / 6.0;
                    if (division6 == int(division6))
                    {
                        int division6Exacta = int(division6);
                        double raizCuadrada = sqrt(division6Exacta);
                        if (raizCuadrada == int(raizCuadrada) && int(raizCuadrada) % 10 == 4)
                        {
                            int raizExacta = int(raizCuadrada);
                            cout << numeros << " - " << rangoARevisar << " - " << division4Exacta << " - " << division6Exacta << " - " << raizExacta << endl;
                            numeros++;
                        };
                    };
                };
            };
        };
        rangoARevisar++;
    };
    return 0;
}