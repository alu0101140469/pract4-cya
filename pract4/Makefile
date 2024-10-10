# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Asignatura: Computabilidad y Algoritmia
# Curso: 2º
# Práctica 4: Expresiones regulares en C++
# Autor: Daniel Palenzuela Álvarez
# Archivo: Makefile
# Compilar: make
# Ejecutar: ./p04_code_analyzer code.cc output.txt
# Limpiar archivos generados: make clean

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

TARGET = p04_code_analyzer
SRCS = main.cc code_analyzer.cc
HEADERS = code_analyzer.h

all: $(TARGET)

$(TARGET): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)
