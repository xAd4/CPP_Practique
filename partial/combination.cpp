/*

Enunciado detallado y explicativo:
Título: Programa para calcular la fecha exacta de la combinación específica de un día y día de la semana a partir de una fecha dada.

Descripción: Dado un día de inicio (miércoles 3 de abril de 2024), el usuario debe especificar tres parámetros:

Día a buscar: El día del mes deseado (un número entre 1 y 31).
Día de la semana a buscar: El día de la semana deseado (Lunes=1, Martes=2, ..., Domingo=7).

Número de combinaciones a buscar: La cantidad de veces que desea que se repita la combinación anterior (día del mes y día de la semana) en el calendario.
El programa calculará la fecha exacta (día, mes y año) en la que ocurre esa combinación específica de día del mes y día de la semana, tantas veces como se especificó, a partir del miércoles 3 de abril de 2024.

Reglas del programa:
-El programa comenzará a contar desde el miércoles 3 de abril de 2024 (Día=3 y Día de la semana=3).
-El programa recorrerá el calendario día a día, verificando si se cumple la combinación deseada de día del mes y día de la semana.
-El programa considerará los años bisiestos al calcular los días de febrero.
-Cada vez que se encuentre la combinación especificada, el contador de combinaciones se incrementará.
-El programa finalizará cuando haya encontrado el número de combinaciones especificado por el usuario.
-El programa imprimirá la fecha exacta (día, mes, año) de la última combinación encontrada.

Requisitos del usuario:
-Ingresar un día del mes entre 1 y 31.
-Ingresar un día de la semana entre 1 (Lunes) y 7 (Domingo).

-Ingresar un número de combinaciones mayor a 0.
Detalles adicionales:
-La fecha de inicio es el miércoles 3 de abril de 2024.
-El programa debe gestionar correctamente los cambios de mes y año.
-Si el año es bisiesto, febrero tendrá 29 días; en caso contrario, tendrá 28 días.

-El día de la semana se manejará con ciclos de 7 días.
Ejemplo de funcionamiento:
Supongamos que el usuario desea encontrar la 5ta combinación en la que el día del mes sea 15 y el día de la semana sea lunes. El programa mostrará en pantalla la fecha exacta en la que ocurre esa quinta combinación.

*/

#include <iostream>
#include <string>

using namespace std;

// Enumeración para representar los días de la semana
enum DiaSemana
{
    LUNES = 1,
    MARTES,
    MIERCOLES,
    JUEVES,
    VIERNES,
    SABADO,
    DOMINGO
};

// Arreglos constantes para los días de la semana y los meses del año
const string NOMBRES_DIAS_SEMANA[] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};
const string NOMBRES_MESES[] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};

// Función que verifica si un año es bisiesto
bool esAñoBisiesto(int año)
{
    return (año % 4 == 0 && año % 100 != 0) || (año % 400 == 0);
}

// Función que obtiene un número entero dentro de un rango específico
int obtenerNumeroEnRango(const string &mensaje, int minimo, int maximo)
{
    int numero;
    do
    {
        cout << mensaje;
        cin >> numero;
        if (numero < minimo || numero > maximo)
        {
            cout << "Error: Ingrese un número dentro del rango (" << minimo << " a " << maximo << ").\n";
        }
    } while (numero < minimo || numero > maximo);
    return numero;
}

// Función que avanza al siguiente día, considerando cambios de mes y año
void avanzarUnDia(int &dia, int &mes, int &año, int &diaSemana)
{
    dia++;       // Avanzar el día del mes
    diaSemana++; // Avanzar el día de la semana

    // Comprobamos si el día sobrepasa el número de días permitidos en el mes actual
    if ((dia == 31 && (mes == 4 || mes == 6 || mes == 9 || mes == 11)) || // Meses con 30 días
        (dia == 29 && mes == 2 && !esAñoBisiesto(año)) ||                 // Febrero en un año no bisiesto
        (dia == 30 && mes == 2 && esAñoBisiesto(año)) ||                  // Febrero en un año bisiesto
        (dia == 32))
    { // Meses con 31 días
        dia = 1;
        mes++;
    }

    // Verificar el cambio de año
    if (mes == 13)
    {
        mes = 1;
        año++;
    }

    // Reseteamos el ciclo semanal: 1 = Lunes, ..., 7 = Domingo
    if (diaSemana == 8)
    {
        diaSemana = LUNES;
    }
}

// Función que calcula la combinación deseada
void calcularCombinacion(int diaABuscar, int diaSemanaABuscar, int combinacionesObjetivo)
{
    // Fecha inicial: Miércoles 3 de abril de 2024
    int dia = 3;
    int mes = 4;
    int año = 2024;
    int diaSemana = MIERCOLES;

    int combinacionesEncontradas = 0;

    // Recorremos el calendario hasta encontrar la cantidad de combinaciones deseadas
    while (combinacionesEncontradas < combinacionesObjetivo)
    {
        // Verificar si la fecha actual coincide con la combinación buscada
        if (dia == diaABuscar && diaSemana == diaSemanaABuscar)
        {
            combinacionesEncontradas++;
        }
        avanzarUnDia(dia, mes, año, diaSemana);
    }

    // Retrocedemos un día ya que el bucle avanza un día adicional
    dia--;

    // Imprimir el resultado
    cout << "\nLa combinación nro. " << combinacionesEncontradas
         << " del día " << NOMBRES_DIAS_SEMANA[diaSemana - 1] << " " << dia
         << " ocurrirá el " << dia << " de " << NOMBRES_MESES[mes - 1]
         << " del año " << año << ".\n";
}

// Función principal del programa
int main()
{
    // Obtener datos de entrada del usuario
    int diaABuscar = obtenerNumeroEnRango("Ingrese el día a buscar (1 a 31): ", 1, 31);
    int diaSemanaABuscar = obtenerNumeroEnRango("Ingrese el día de la semana a buscar (1=Lunes, 7=Domingo): ", 1, 7);
    int combinacionesObjetivo = obtenerNumeroEnRango("Ingrese la cantidad de combinaciones a buscar: ", 1, INT_MAX);

    // Calcular y mostrar el resultado de la combinación deseada
    calcularCombinacion(diaABuscar, diaSemanaABuscar, combinacionesObjetivo);

    cout << "Enter para salir...";
    cin.get();
    cin.ignore();
    return 0;
}
