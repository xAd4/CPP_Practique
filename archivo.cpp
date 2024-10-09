#include <iostream>
#include <string>

using namespace std;

// Función para calcular el día de la semana utilizando la fórmula de Zeller
int calcularDiaSemana(int dia, int mes, int year) {
    if (mes == 1 || mes == 2) {
        mes += 12;
        year -= 1;
    }
    int k = year % 100;
    int j = year / 100;
    int diaSemana = (dia + 13 * (mes + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
    return diaSemana;
}

// Función para convertir el día de la semana a su nombre correspondiente
string nombreDiaSemana(int diaSemana) {
    string dias[] = {"Sábado", "Domingo", "Lunes", "Martes", "Miércoles", "Jueves", "Viernes"};
    return dias[diaSemana];
}

// Función que muestra los días feriados en Venezuela y calcula su día de la semana
void mostrarDiasFeriados(int year) {
    // Definir los días y meses de los feriados
    int diasFeriados[] = {1, 19, 1, 24, 5, 24, 12, 24, 25, 31};
    int mesesFeriados[] = {1, 4, 5, 6, 7, 7, 10, 12, 12, 12};
    string nombresFeriados[] = {
        "Año Nuevo", 
        "Día de la Declaración de la Independencia", 
        "Día del Trabajador", 
        "Batalla de Carabobo", 
        "Firma del Acta de la Independencia", 
        "Natalicio de Simón Bolívar", 
        "Día de la Resistencia Indígena", 
        "Víspera de Navidad", 
        "Navidad", 
        "Fin de Año"
    };

    cout << "Los días feriados para " << year << " corresponden a:\n";
    for (int i = 0; i < 10; i++) {
        int diaSemana = calcularDiaSemana(diasFeriados[i], mesesFeriados[i], year);
        cout << diasFeriados[i] << " de " << (mesesFeriados[i] == 1 ? "Enero" : mesesFeriados[i] == 4 ? "Abril" : mesesFeriados[i] == 5 ? "Mayo" : 
                mesesFeriados[i] == 6 ? "Junio" : mesesFeriados[i] == 7 ? "Julio" : mesesFeriados[i] == 10 ? "Octubre" : "Diciembre")
             << " = " << nombreDiaSemana(diaSemana) << " (" << nombresFeriados[i] << ")" << endl;
    }
}

int main() {
    int year;
    cout << "Ingrese el año a buscar (2024 - 2099): ";
    cin >> year;

    // Validar el año ingresado
    if (year < 2024 || year > 2099) {
        cout << "Año inválido. Ingrese un año entre 2024 y 2099." << endl;
    } else {
        // Mostrar los días feriados para el año ingresado
        mostrarDiasFeriados(year);
    }

    return 0;
}
