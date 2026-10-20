#pragma once
#include <stdexcept>

class Matrix {
public:
    // Конструкторы
    Matrix();
    explicit Matrix(int size);
    Matrix(int rows, int cols);

    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);


    ~Matrix();

    // Доступ к элементам
    int get(int i, int j) const;
    void set(int i, int j, int value);


    void inputFromKeyboard();
    void fillRandom();
    void print() const;

    // Вычисление и геттеры
    int sum() const;
    int getRows() const;
    int getCols() const;

private:
    int** data_ = nullptr;
    int rows_ = 0;
    int cols_ = 0;
};