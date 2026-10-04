#include "Matrix.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>

Matrix::Matrix() : data_(nullptr), rows_(0), cols_(0) {}

Matrix::Matrix(int size) : data_(nullptr), rows_(size), cols_(size) {
    if (size < 0) {
        throw std::invalid_argument("Размерность не может быть отрицательной");
    }
    if (size == 0) {
        rows_ = 0;
        cols_ = 0;
        return;
    }
    data_ = new int*[rows_];
    for (int i = 0; i < rows_; ++i) {
        data_[i] = new int[cols_]{};
        data_[i][i] = 1; // Единичная диагональ
    }
}

Matrix::Matrix(int rows, int cols) : data_(nullptr), rows_(rows), cols_(cols) {
    if (rows < 0 || cols < 0) {
        throw std::invalid_argument("Размерность не может быть отрицательной");
    }
    if (rows == 0 || cols == 0) {
        rows_ = 0;
        cols_ = 0;
        return;
    }
    data_ = new int*[rows_];
    for (int i = 0; i < rows_; ++i) {
        data_[i] = new int[cols_]{};
    }
}

Matrix::~Matrix() {
    if (data_ == nullptr) return;
    for (int i = 0; i < rows_; ++i) {
        delete[] data_[i];
    }
    delete[] data_;
    data_ = nullptr;
}

int Matrix::get(int i, int j) const {
    if (i < 0 || i >= rows_ || j < 0 || j >= cols_) {
        throw std::out_of_range("Индексы выходят за границы матрицы");
    }
    return data_[i][j];
}

void Matrix::set(int i, int j, int value) {
    if (i < 0 || i >= rows_ || j < 0 || j >= cols_) {
        throw std::out_of_range("Индексы выходят за границы матрицы");
    }
    data_[i][j] = value;
}

void Matrix::inputFromKeyboard() {
    std::cout << "Введите элементы матрицы (" << rows_ << "x" << cols_ << "):\n";
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            std::cin >> data_[i][j];
        }
    }
}

void Matrix::fillRandom() {
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            data_[i][j] = std::rand() % 100;
        }
    }
}

void Matrix::print() const {
    if (rows_ == 0 || cols_ == 0 || data_ == nullptr) {
        std::cout << "[Пустая матрица 0x0]\n";
        return;
    }
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            std::cout << std::setw(4) << data_[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int Matrix::sum() const {
    int total = 0;
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            total += data_[i][j];
        }
    }
    return total;
}

int Matrix::getRows() const {
    return rows_;
}

int Matrix::getCols() const {
    return cols_;
}