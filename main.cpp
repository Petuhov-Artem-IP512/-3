#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Matrix.h"

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::cout << "=== 1. Создание матриц разными конструкторами ===\n";
    Matrix m1;        
    Matrix m2(3);    
    Matrix m3(3, 4);  
    Matrix m4(2, 3);  

    std::cout << "\n=== 2. Вывод M2, M3, M4 ===\n";
    std::cout << "M2 (единичная 3x3):\n";
    m2.print();
    std::cout << "M3 (3x4 нули):\n";
    m3.print();
    std::cout << "M4 (2x3 нули):\n";
    m4.print();

    std::cout << "\n=== 3. Заполнение M2 по формуле i * j ===\n";
    for (int i = 0; i < m2.getRows(); ++i) {
        for (int j = 0; j < m2.getCols(); ++j) {
            m2.set(i, j, i * j);
        }
    }
    m2.print();

    std::cout << "\n=== 4. Заполнение M3 случайными числами ===\n";
    m3.fillRandom();
    m3.print();

    std::cout << "\n=== 5. Заполнение M4 с клавиатуры ===\n";
    m4.inputFromKeyboard();
    m4.print();

    std::cout << "\n=== 6. Подсчет суммы элементов M3 ===\n";
    std::cout << "Сумма элементов M3: " << m3.sum() << "\n";

    std::cout << "\n=== 7. Демонстрация работы исключений ===\n";
    try {
        Matrix bad(-1, 5);
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught: " << e.what() << '\n';
    }

    try {
        m3.get(100, 100);
    } catch (const std::out_of_range& e) {
        std::cout << "Caught: " << e.what() << '\n';
    }

    return 0;
}

