#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

struct hora {
    int horas;
    int minutos;
    int segundos;
};

struct linea {
    std::string mes;
    int dia;
    hora hora;
    std::string direccionIP;
    std::string razon;
};

bool mayor(linea a1, linea a2) {
    // Comparar el mes
    if (a1.mes != a2.mes) {
        return a1.mes < a2.mes;
    }

    // Comparar el día
    if (a1.dia != a2.dia) {
        return a1.dia < a2.dia;
    }

    // Comparar la hora usando la estructura hora
    if (a1.hora.horas != a2.hora.horas) {
        return a1.hora.horas < a2.hora.horas;
    }

    if (a1.hora.minutos != a2.hora.minutos) {
        return a1.hora.minutos < a2.hora.minutos;
    }

    return a1.hora.segundos < a2.hora.segundos;
}

void bubbleSort(std::vector<linea>& lineas) {
    int n = lineas.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (mayor(lineas[j], lineas[j + 1])) {
                std::swap(lineas[j], lineas[j + 1]);
            }
        }
    }
}

int main() {
    std::vector<linea> lineas;
    std::ifstream archivoEntrada("bitacora.txt");
    std::ofstream archivoSalida("bitacora_ordenada.txt");

    if (!archivoEntrada) {
        std::cerr << "No se pudo abrir el archivo 'bitacora.txt'" << std::endl;
        return 1;
    }

    linea temp;
    std::string horaTexto;

    while (archivoEntrada >> temp.mes >> temp.dia >> horaTexto >> temp.direccionIP) {
        // Parsear la hora desde el texto en el formato "hh:mm:ss"
        std::istringstream ss(horaTexto);
        char delimiter;

        ss >> temp.hora.horas >> delimiter >> temp.hora.minutos >> delimiter >> temp.hora.segundos;

        getline(archivoEntrada, temp.razon);
        lineas.push_back(temp);
    }

    // Ordenar las líneas
    bubbleSort(lineas);

    // Solicitar al usuario las fechas de inicio y fin de búsqueda
    std::string fechaInicio, fechaFin;
    std::cout << "Ingrese la fecha de inicio (Mes Dia hh:mm:ss): ";
    std::cin.ignore();
    getline(std::cin, fechaInicio);

    std::cout << "Ingrese la fecha de fin (Mes Dia hh:mm:ss): ";
    getline(std::cin, fechaFin);

    archivoSalida << "Registros entre " << fechaInicio << " y " << fechaFin << ":\n";

    for (linea registro : lineas) {
        std::string fechaRegistro = registro.mes + " " + std::to_string(registro.dia) + " " +
                                    std::to_string(registro.hora.horas) + ":" +
                                    std::to_string(registro.hora.minutos) + ":" +
                                    std::to_string(registro.hora.segundos);

        if (fechaRegistro >= fechaInicio && fechaRegistro <= fechaFin) {
            archivoSalida << registro.mes << " " << registro.dia << " " <<
                             registro.hora.horas << ":" << registro.hora.minutos << ":" << registro.hora.segundos << " " <<
                             registro.direccionIP << registro.razon << "\n";
        }
    }

    archivoEntrada.close();
    archivoSalida.close();

    std::cout << "Los registros han sido ordenados y almacenados en 'bitacora_ordenada.txt'" << std::endl;

    return 0;
}
