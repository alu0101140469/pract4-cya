// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares en C++
// Autor: Daniel Palenzuela Álvarez
// Correo: alu0101140469@ull.edu.es
// Fecha: 08/10/2024
// Archivo: code_analyzer.h
// Descripción: Declaración de la clase CodeAnalyzer que almacena y gestiona
// la información sobre variables, bucles, comentarios y la existencia
// de la función main en un archivo de código C++.

#ifndef CODE_ANALYZER_H
#define CODE_ANALYZER_H

#include <iostream>   // Para la entrada y salida estándar
#include <fstream>    // Para la manipulación de archivos
#include <regex>      // Para el uso de expresiones regulares
#include <string>     // Para la clase std::string
#include <vector>     // Para la clase std::vector

// Clase que representa el analizador de código C++
class CodeAnalyzer {
private:
    // Almacena la información de las variables detectadas
    std::vector<std::string> variableInfo;

    // Almacena la información de los bucles detectados
    std::vector<std::string> loopInfo;

    // Almacena la información de los comentarios detectados
    std::vector<std::string> commentInfo;

    // Indica si existe una función main en el código
    bool hasMainFunction = false;

    // Indica si se ha encontrado una descripción en los comentarios
    bool foundDescription = false;

public:
    // Métodos para añadir información sobre variables, bucles y comentarios
    void addVariableInfo(const std::string& info); // Añade información sobre una variable
    void addLoopInfo(const std::string& info);      // Añade información sobre un bucle
    void addCommentInfo(const std::string& info);   // Añade información sobre un comentario
    void setMainFunction(bool hasMain);              // Establece si existe una función main

    // Verifica si la descripción ya ha sido encontrada
    bool descriptionFound() const; // Devuelve el estado de foundDescription

    // Genera el reporte en el archivo de salida
    void generateReport(const std::string& outputFileName); // Crea el archivo de reporte
};

#endif // CODE_ANALYZER_H
