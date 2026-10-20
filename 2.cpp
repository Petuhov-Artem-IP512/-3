#include <iostream>
#include <iomanip>
#include <cstdlib>

int main() {
    int N;
    std::cout << "N = ";
    std::cin >> N;
    if (N <= 0) return 0;

    // 1. Создание и заполнение матрицы A (N x N)
    int** A = new int*[N];
    for (int i = 0; i < N; ++i) {
        A[i] = new int[N];
        for (int j = 0; j < N; ++j) A[i][j] = rand() % 90 + 10;
    }

    std::cout << "\nМатрица A:\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) std::cout << std::setw(4) << A[i][j];
        std::cout << "\n";
    }

    int* D = new int[N * N];
    int k;

    // а) Правые диагонали (начиная с правого верхнего)
    k = 0;
    for (int c = N - 1; c >= 0; --c)
        for (int r = 0, j = c; r < N && j >= 0; ++r, --j) D[k++] = A[r][j];
    for (int r = 1; r < N; ++r)
        for (int i = r, j = N - 1; i < N && j >= 0; ++i, --j) D[k++] = A[i][j];

    std::cout << "\na) Правые диагонали: ";
    for (int i = 0; i < N * N; ++i) std::cout << D[i] << " ";

    // b) Левые диагонали (начиная с левого верхнего)
    k = 0;
    for (int c = 0; c < N; ++c)
        for (int r = 0, j = c; r < N && j < N; ++r, ++j) D[k++] = A[r][j];
    for (int r = 1; r < N; ++r)
        for (int i = r, j = 0; i < N && j < N; ++i, ++j) D[k++] = A[i][j];

    std::cout << "\nb) Левые диагонали: ";
    for (int i = 0; i < N * N; ++i) std::cout << D[i] << " ";

    // c) Спираль из центра (без segfault на чётных N)
    k = 0;
    int r = (N - 1) / 2, c = (N - 1) / 2;
    int dr[] = {0, 1, 0, -1}, dc[] = {1, 0, -1, 0};
    int dir = 0, len = 1, steps = 0, turns = 0;

    while (k < N * N) {
        if (r >= 0 && r < N && c >= 0 && c < N) D[k++] = A[r][c];
        r += dr[dir]; c += dc[dir];
        if (++steps == len) {
            steps = 0;
            dir = (dir + 1) % 4;
            if (++turns % 2 == 0) len++;
        }
    }

    std::cout << "\nc) Спираль из центра: ";
    for (int i = 0; i < N * N; ++i) std::cout << D[i] << " ";

    // d) Спираль с левого верхнего угла
    k = 0;
    int top = 0, bot = N - 1, left = 0, right = N - 1;
    while (top <= bot && left <= right) {
        for (int j = left; j <= right; ++j) D[k++] = A[top][j];
        top++;
        for (int i = top; i <= bot; ++i) D[k++] = A[i][right];
        right--;
        if (top <= bot) for (int j = right; j >= left; --j) D[k++] = A[bot][j];
        bot--;
        if (left <= right) for (int i = bot; i >= top; --i) D[k++] = A[left][i];
        left++;
    }

    std::cout << "\nd) Спираль с угла: ";
    for (int i = 0; i < N * N; ++i) std::cout << D[i] << " ";

    // Очистка памяти Задания 1
    for (int i = 0; i < N; ++i) delete[] A[i];
    delete[] A;
    delete[] D;

    // --- ЗАДАНИЕ 2 ---
    std::cout << "\n\n=== Задание 2 ===\nСтрок: ";
    int rows;
    std::cin >> rows;

    int** jag = new int*[rows];
    int* sizes = new int[rows];

    for (int i = 0; i < rows; ++i) {
        std::cout << "Длина строки " << i + 1 << ": ";
        std::cin >> sizes[i];
        jag[i] = new int[sizes[i]];
        for (int j = 0; j < sizes[i]; ++j) jag[i][j] = rand() % 90 + 10;
    }

    std::cout << "\nМассив:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < sizes[i]; ++j) std::cout << jag[i][j] << " ";
        std::cout << "\n";
        delete[] jag[i];
    }
    delete[] jag;
    delete[] sizes;

    return 0;
}