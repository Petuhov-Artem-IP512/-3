#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Matrix.h"

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // 1. Создать матрицу a (3, 4), заполнить, вывести
    Matrix a(3, 4);
    a.fillRandom();
    std::cout << "Matrix a:\n";
    a.print();

    // 2. Копирование через конструктор копирования
    Matrix b = a;

    // 3. Изменить b и убедиться, что a не изменилась
    b.set(0, 0, 999);
    std::cout << "\nAfter b.set(0, 0, 999):\n";
    std::cout << "Matrix a:\n";
    a.print();
    std::cout << "Matrix b:\n";
    b.print();

    // 4. Создать c (2, 2), заполнить, присвоить a
    Matrix c(2, 2);
    c.fillRandom();
    c = a;

    // 5. Вывести c (должна быть копия a)
    std::cout << "\nMatrix c after c = a:\n";
    c.print();

    // 6. Цепочка присваиваний
    Matrix d, e;
    d = e = a;
    std::cout << "\nMatrix d:\n";
    d.print();
    std::cout << "Matrix e:\n";
    e.print();

    // 7. Самоприсваивание
    a = a;
    std::cout << "\nMatrix a after a = a:\n";
    a.print();
    std::cout << "(should be unchanged)\n";

    return 0;
}