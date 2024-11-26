#ifndef SCRIPT_LOADER_H
#define SCRIPT_LOADER_H

#include <string>

// Estructura para simular una consola
struct ConsoleBox {
    void new_text();
    void set_text(const std::string& text);
};

// Consola global para el programa
extern ConsoleBox consoleBox;

// Prototipos de funciones
void load_script(const char* filename, bool show_script = false);
void load_script();
void ejecutar_opcion(int opcion);

#endif // SCRIPT_LOADER_H
