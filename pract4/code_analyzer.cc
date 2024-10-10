// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares en C++
// Autor: Daniel Palenzuela Álvarez
// Correo: alu0101140469@ull.edu.es
// Fecha: 08/10/2024
// Archivo: code_analyzer.cc
// Descripción: Implementación de la clase CodeAnalyzer que permite almacenar y
// procesar información sobre variables, bucles, comentarios y la función main
// de un archivo de código C++ analizado. Genera un reporte con los resultados.

#include "code_analyzer.h"

// Añadir información de variables a la lista
void CodeAnalyzer::addVariableInfo(const std::string& info) {
    variableInfo.push_back(info); // Agrega la información de la variable a la lista de variables
}

// Añadir información de bucles a la lista
void CodeAnalyzer::addLoopInfo(const std::string& info) {
    loopInfo.push_back(info); // Agrega la información del bucle a la lista de bucles
}

// Añadir información de comentarios a la lista
void CodeAnalyzer::addCommentInfo(const std::string& info) {
    commentInfo.push_back(info); // Agrega la información del comentario a la lista de comentarios
}

// Establecer si el programa tiene la función main
void CodeAnalyzer::setMainFunction(bool hasMain) {
    hasMainFunction = hasMain; // Almacena el estado de la existencia de la función main
}

// Verificar si la descripción ya ha sido encontrada
bool CodeAnalyzer::descriptionFound() const {
    return foundDescription; // Devuelve el estado de la variable foundDescription
}

// Generar el reporte en el archivo de salida
void CodeAnalyzer::generateReport(const std::string& outputFileName) {
    std::ofstream outFile(outputFileName); // Abre el archivo de salida para escribir
    if (!outFile) {
        std::cerr << "Error al abrir el archivo de salida.\n"; // Mensaje de error si no se puede abrir el archivo
        return; // Sale de la función si el archivo no se abre correctamente
    }

    // Escribe la sección de VARIABLES en el archivo de salida
    outFile << "VARIABLES:\n";
    for (const auto& var : variableInfo) {
        outFile << var << "\n"; // Escribe cada variable en una nueva línea
    }

    // Escribe la sección de LOOPS en el archivo de salida
    outFile << "\nLOOPS:\n";
    for (const auto& loop : loopInfo) {
        outFile << loop << "\n"; // Escribe cada bucle en una nueva línea
    }

    // Escribe la sección MAIN en el archivo de salida
    outFile << "\nMAIN:\n";
    outFile << (hasMainFunction ? "True" : "False") << "\n"; // Indica si existe o no la función main

    // Escribe la sección de COMMENTS en el archivo de salida
    outFile << "\nCOMMENTS:\n";
    for (const auto& comment : commentInfo) {
        outFile << comment << "\n"; // Escribe cada comentario en una nueva línea
    }

    outFile.close(); // Cierra el archivo de salida
}
