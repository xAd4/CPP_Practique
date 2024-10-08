#include <iostream>
using namespace std;

// Funcion para verificar si el año es bisiesto
bool esBisiesto(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Funcion para obtener el número maximo de días en un mes dado un año específico
int diasEnMes(int mes, int year)
{
    if (mes == 2)
    {
        return esBisiesto(year) ? 29 : 28; // Febrero tiene 29 días si es bisiesto, sino 28
    }
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        return 30; // Abril, Junio, Septiembre y Noviembre tienen 30 días
    }
    return 31; // Todos los demas meses tienen 31 días
}

// Funcion para calcular los días acumulados hasta el comienzo del mes
int diasAcumuladosHastaMes(int mes, int year)
{
    int diasAcumuladosPorMes[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334}; // Días acumulados hasta el primer día de cada mes sin bisiestos
    int diasAcumulados = diasAcumuladosPorMes[mes - 1];

    // Si es año bisiesto y ya paso febrero, agregar un día adicional
    if (esBisiesto(year) && mes > 2)
    {
        diasAcumulados++;
    }

    return diasAcumulados;
}

// Funcion para determinar qué placas pueden surtir combustible en la fecha dada
void buscarPlaca(int dia, int mes, int year)
{
    // Validacion de la fecha ingresada
    if (year < 2024 || year > 2070)
    {
        cout << "Año invalido. Intente con un año entre 2024 y 2050." << endl;
        return;
    }
    if (mes < 1 || mes > 12)
    {
        cout << "Mes invalido. Intente con un mes entre 1 y 12." << endl;
        return;
    }
    if (dia < 1 || dia > diasEnMes(mes, year))
    {
        cout << "Día invalido. Intente con un día valido para el mes ingresado." << endl;
        return;
    }

    // Calcular días acumulados desde el 1 de octubre de 2024 hasta la fecha ingresada
    int diasDesdeInicio = (year - 2024) * 365 + diasAcumuladosHastaMes(mes, year) + (dia - 1) - 273;

    // Contar años bisiestos entre 2024 y el año actual
    for (int i = 2024; i < year; i++)
    {
        if (esBisiesto(i))
        {
            diasDesdeInicio++;
        }
    }

    // Ciclo de 5 días para determinar las placas que pueden surtir
    const string placas[5] = {"1-2", "3-4", "5-6", "7-8", "9-0"};
    int diaCiclo = diasDesdeInicio % 5;

    // Mostrar las placas que pueden surtir ese día
    cout << "Para la fecha ingresada (" << dia << "/" << mes << "/" << year << "), las placas que pueden surtir son: " << placas[diaCiclo] << endl;
}

// Funcion principal para el menú interactivo
int main()
{
    while (true)
    {
        int opcion;
        cout << "\n--- Menu ---\n";
        cout << "1. Ingresar fecha\n";
        cout << "2. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1)
        {
            int dia, mes, year;
            cout << "Ingrese dia: ";
            cin >> dia;
            cout << "Ingrese mes: ";
            cin >> mes;
            cout << "Ingrese año: ";
            cin >> year;
            buscarPlaca(dia, mes, year);
        }
        else if (opcion == 2)
        {
            cout << "Saliendo del programa..." << endl;
            break;
        }
        else
        {
            cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    }

    cout << "Presiona ENTER para salir...";
    cin.get();
    cin.ignore();

    return 0;
}
