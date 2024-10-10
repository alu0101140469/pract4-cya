// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares en C++
// Autor: Daniel Palenzuela Álvarez
// Correo: alu0101140469@ull.edu.es
// Fecha: 08/10/2024
// Archivo: main.cc
// Descripción: Programa principal que analiza un archivo de código C++
// utilizando expresiones regulares para extraer información sobre
// variables, bucles, comentarios y la función main.

#include "code_analyzer.h" // Incluir la definición de la clase CodeAnalyzer

// Función que analiza el archivo de entrada y extrae información relevante
void analyzeFile(const std::string& inputFileName, const std::string& outputFileName) {
    std::ifstream inFile(inputFileName); // Abre el archivo de entrada
    if (!inFile) {
        std::cerr << "Error al abrir el archivo de entrada.\n"; // Mensaje de error si no se puede abrir el archivo
        return; // Sale de la función si el archivo no se abre correctamente
    }

    CodeAnalyzer analyzer; // Crea una instancia de CodeAnalyzer para almacenar la información
    std::string line; // Variable para almacenar cada línea leída del archivo
    int lineNumber = 0; // Contador de líneas

    // Expresiones regulares para detectar elementos clave en el código
    std::regex intVarRegex(R"(^\s*int\s+(\w+)(\s*=\s*\w+)?;)"); // Regex para variables de tipo int
    std::regex doubleVarRegex(R"(^\s*double\s+(\w+)(\s*=\s*\w+)?;)"); // Regex para variables de tipo double
    std::regex forLoopRegex(R"(^\s*for\s*\(.*\)\s*\{?)"); // Regex para bucles for
    std::regex whileLoopRegex(R"(^\s*while\s*\(.*\)\s*\{?)"); // Regex para bucles while
    std::regex mainFuncRegex(R"(^\s*int\s+main\s*\()"); // Regex para la función main
    std::regex singleLineCommentRegex(R"(//.*$)"); // Regex para comentarios de una línea
    std::regex multiLineCommentStartRegex(R"(/\*.*)"); // Regex para el inicio de comentarios multilínea
    std::regex multiLineCommentEndRegex(R"(.*\*/)"); // Regex para el final de comentarios multilínea

    bool inMultiLineComment = false; // Bandera para controlar si estamos dentro de un comentario multilínea

    // Leer el archivo línea por línea
    while (std::getline(inFile, line)) {
        lineNumber++; // Incrementa el contador de líneas

        std::smatch match; // Almacena los resultados de la búsqueda de regex

        // Detectar declaración de variables int
        if (std::regex_search(line, match, intVarRegex)) {
            std::string varName = match[1]; // Nombre de la variable
            std::string init = match[2].matched ? " (initialized)" : " (uninitialized)"; // Verifica si está inicializada
            analyzer.addVariableInfo("[Line " + std::to_string(lineNumber) + "] INT: " + varName + init); // Añade información de la variable
        }

        // Detectar declaración de variables double
        if (std::regex_search(line, match, doubleVarRegex)) {
            std::string varName = match[1]; // Nombre de la variable
            std::string init = match[2].matched ? " (initialized)" : " (uninitialized)"; // Verifica si está inicializada
            analyzer.addVariableInfo("[Line " + std::to_string(lineNumber) + "] DOUBLE: " + varName + init); // Añade información de la variable
        }

        // Detectar bucles for
        if (std::regex_search(line, match, forLoopRegex)) {
            analyzer.addLoopInfo("[Line " + std::to_string(lineNumber) + "] LOOP: for"); // Añade información sobre el bucle for
        }

        // Detectar bucles while
        if (std::regex_search(line, match, whileLoopRegex)) {
            analyzer.addLoopInfo("[Line " + std::to_string(lineNumber) + "] LOOP: while"); // Añade información sobre el bucle while
        }

        // Detectar función main
        if (std::regex_search(line, match, mainFuncRegex)) {
            analyzer.setMainFunction(true); // Marca que la función main está presente
        }

        // Detectar comentarios de una línea
        if (std::regex_search(line, match, singleLineCommentRegex)) {
            analyzer.addCommentInfo("[Line " + std::to_string(lineNumber) + "] " + match[0].str()); // Añade el comentario de una línea
        }

        // Detectar comentarios multilínea
        if (std::regex_search(line, match, multiLineCommentStartRegex)) {
            inMultiLineComment = true; // Indica que se ha encontrado el inicio de un comentario multilínea
            // Verifica si es el primer comentario para considerarlo como descripción
            if (!analyzer.descriptionFound()) {
                analyzer.addCommentInfo("[Line " + std::to_string(lineNumber) + "] DESCRIPTION: Start of multi-line comment");
            } else {
                analyzer.addCommentInfo("[Line " + std::to_string(lineNumber) + "] Start of multi-line comment");
            }
        }

        // Si estamos dentro de un comentario multilínea
        if (inMultiLineComment) {
            if (std::regex_search(line, match, multiLineCommentEndRegex)) {
                analyzer.addCommentInfo("[Line " + std::to_string(lineNumber) + "] End of multi-line comment"); // Añade el final del comentario
                inMultiLineComment = false; // Sale del estado de comentario multilínea
            }
        }
    }

    inFile.close(); // Cierra el archivo de entrada

    // Generar el reporte de análisis
    analyzer.generateReport(outputFileName); // Crea el archivo de reporte
}

// Función principal del programa
int main(int argc, char* argv[]) {
    // Verifica que se han pasado exactamente 2 argumentos
    if (argc != 3) {
        std::cerr << "Uso incorrecto. Debe ejecutarse como:\n";
        std::cerr << "./p04_code_analyzer <archivo de entrada> <archivo de salida>\n"; // Mensaje de uso
        return 1; // Salir con código de error
    }

    std::string inputFileName = argv[1]; // Nombre del archivo de entrada
    std::string outputFileName = argv[2]; // Nombre del archivo de salida

    analyzeFile(inputFileName, outputFileName); // Llama a la función de análisis

    return 0; // Salir con éxito
}
