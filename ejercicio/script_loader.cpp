#include "script_loader.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <stdexcept>
#include <limits>

// Definición de la consola simulada
ConsoleBox consoleBox;

void ConsoleBox::new_text() {
    std::cout << "Consola: Nuevo texto cargado.\n";
}

void ConsoleBox::set_text(const std::string& text) {
    std::cout << text << std::endl;
}

void load_script(const char* filename, bool show_script) {
    std::string script;
    FILE* file = nullptr;

    try {
        // Abre el archivo en modo binario para lectura
        file = fopen(filename, "rb");
        if (!file) {
            std::perror("Error al abrir el archivo");
            throw std::runtime_error("No se pudo abrir el archivo. Verifica el nombre o permisos.");
        }

        char buffer[4001];
        size_t bytesRead;
        while ((bytesRead = fread(buffer, 1, 4000, file)) > 0) {
            buffer[bytesRead] = '\0';
            script.append(buffer);
        }

        if (ferror(file)) {
            throw std::runtime_error("Error durante la lectura del archivo.");
        }

        fclose(file);
        file = nullptr;

        if (show_script) {
            std::cout << "\033[34m\033[47m"; // Color de texto
            std::cout << script << "\033[0m" << std::endl;
        }

        consoleBox.new_text();
        consoleBox.set_text(script);
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        if (file) fclose(file);
    } catch (...) {
        std::cerr << "Error desconocido durante la operación." << std::endl;
        if (file) fclose(file);
    }
}

void load_script() {
    char filename[500];
    std::cout << "Introduce el nombre del archivo: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpia el buffer
    std::cin.getline(filename, sizeof(filename));
    load_script(filename, true);
}

void ejecutar_opcion(int opcion) {
    if (opcion == 1) {
        const char* filename = "script.txt";
        std::cout << "Intentando cargar el archivo: " << filename << std::endl;
        load_script(filename, true);
    } else if (opcion == 2) {
        load_script();
    } else {
        std::cout << "Opción no válida." << std::endl;
    }
}
