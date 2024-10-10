/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Practica de Programacion
 * @brief Este es un ejemplo simple de factorial
 */

#include <iostream>

// Función que calcula el factorial de un número
int Factorial(int number) {
    int factorial = 1;
    for (int i = 1; i <= number; ++i) {
        factorial *= i;
    }
    return factorial;
}

int main() {
    std::cout << "Introduce un número: ";
    int number;
    std::cin >> number;
    
    // Calcular y mostrar el factorial
    std::cout << "El factorial de " << number << " es " << Factorial(number) << std::endl;
    
    return 0;
}
