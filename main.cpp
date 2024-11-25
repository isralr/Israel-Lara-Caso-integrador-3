#include <iostream>
#include "script_loader.h"

// Prototipo
void ejecutar_opcion(int opcion);

int main() {
    int opcion;
    std::cout << "Opciones:\n";
    std::cout << "1. Proporcionar un archivo y mostrar su contenido.\n";
    std::cout << "2. Solicitar un archivo al usuario.\n";
    std::cout << "Elige una opción (1 o 2): ";
    std::cin >> opcion;
    std::cin.ignore(); // Limpia el buffer de entrada
    ejecutar_opcion(opcion);
    return 0;
}
