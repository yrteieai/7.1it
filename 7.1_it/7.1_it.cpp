#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** Z, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** Z, const int rowCount, const int colCount);
void Sort(int** Z, const int rowCount, const int colCount);
void Change(int** Z, const int col1, const int col2, const int rowCount);
void Calc(int** Z, const int rowCount, const int colCount, int& S, int& k);

int main() {
    srand((unsigned)time(NULL));
    const int Low = 18;
    const int High = 74;
    const int rowCount = 9;
    const int colCount = 6;

    // Створення динамічної матриці
    int** Z = new int* [rowCount];
    for (int i = 0; i < rowCount; i++) {
        Z[i] = new int[colCount];
    }

    // Генерація матриці
    Create(Z, rowCount, colCount, Low, High);

    // Виведення початкової матриці
    cout << "Initial matrix:" << endl;
    Print(Z, rowCount, colCount);

    // Сортування матриці
    Sort(Z, rowCount, colCount);

    // Виведення відсортованої матриці
    cout << "Sorted matrix:" << endl;
    Print(Z, rowCount, colCount);

    // Підрахунок суми і кількості елементів, що відповідають критеріям
    int S = 0;
    int k = 0;
    Calc(Z, rowCount, colCount, S, k);

    // Виведення результатів після обчислень та заміни
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    cout << "Modified matrix after Calc:" << endl;
    Print(Z, rowCount, colCount);

    // Очищення пам'яті
    for (int i = 0; i < rowCount; i++) {
        delete[] Z[i];
    }
    delete[] Z;

    return 0;
}

// Функція створення матриці
void Create(int** Z, const int rowCount, const int colCount, const int Low, const int High) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            Z[i][j] = Low + rand() % (High - Low + 1);
        }
    }
}

// Функція для виведення матриці
void Print(int** Z, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << setw(4) << Z[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

// Функція для сортування матриці за стовпчиками відповідно до ключів
void Sort(int** Z, const int rowCount, const int colCount) {
    for (int i0 = 0; i0 < colCount - 1; i0++) {
        for (int i1 = 0; i1 < colCount - i0 - 1; i1++) {
            // Перевірка умови впорядкування першого рядка (за зростанням зліва направо)
            if (Z[0][i1] > Z[0][i1 + 1]) {
                Change(Z, i1, i1 + 1, rowCount);
            }
            // Якщо перші елементи рівні, сортуємо другий рядок за спаданням справа наліво
            else if (Z[0][i1] == Z[0][i1 + 1] && Z[1][i1] < Z[1][i1 + 1]) {
                Change(Z, i1, i1 + 1, rowCount);
            }
            // Якщо перший і другий рядки рівні, сортуємо третій рядок за спаданням справа наліво
            else if (Z[0][i1] == Z[0][i1 + 1] && Z[1][i1] == Z[1][i1 + 1] && Z[2][i1] < Z[2][i1 + 1]) {
                Change(Z, i1, i1 + 1, rowCount);
            }
        }
    }
}

// Функція для обміну двох стовпчиків місцями
void Change(int** Z, const int col1, const int col2, const int rowCount) {
    for (int i = 0; i < rowCount; i++) {
        int tmp = Z[i][col1];
        Z[i][col1] = Z[i][col2];
        Z[i][col2] = tmp;
    }
}

// Функція для обчислення суми та кількості елементів, що відповідають критерію
void Calc(int** Z, const int rowCount, const int colCount, int& S, int& k) {
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            // Елемент підходить, якщо він не непарний та не кратний 7
            if (Z[i][j] % 2 == 0 && Z[i][j] % 7 != 0) {
                S += Z[i][j];
                k++;
                Z[i][j] = 0;  // Заміна на 0
            }
        }
    }
}
