/* Дан двумерный массив. Выяснить, является ли произведение элементов n-го столбца
массива трехзначным числом.*/

#include <iostream>
#include <random>
using namespace std;

const int rows = 3;
const int colon = 3;

// Функция для проверки, является ли произведение элементов столбца трехзначным числом
bool isThreeDigitProduct(int arr[][colon], int colIndex, int& product) {
    product = 1;
    for (int i = 0; i < rows; ++i) {
        product *= arr[i][colIndex]; // Вычисление произведения элементов столбца
    }

    return (product >= 100 && product <= 999); // Проверка, является ли произведение трехзначным числом
}

int main() {
    int arr[rows][colon];

    // Инициализация генератора случайных чисел
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distrib(1, 10);

    // Заполнение двумерного массива случайными числами
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colon; j++) {
            arr[i][j] = distrib(gen);
        }
    }

    int colIndex;
    int product;

    cout << "Массив:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colon; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Введите номер столбца (от 0 до " << colon - 1 << "): ";
    cin >> colIndex;

    if (colIndex < 0 || colIndex >= colon) {
        cout << "Ошибка: Некорректный номер столбца."; // В случае некорректного ввода номера столбца
    } else {
        if (isThreeDigitProduct(arr, colIndex, product)) { // Проверка произведения элементов столбца
            cout << "Произведение элементов " << colIndex << "-го столбца является трехзначным числом: " << product<< endl; // Вывод результата (и произведения)
        } else {
            cout << "Произведение элементов " << colIndex << "-го столбца НЕ является трехзначным числом: " << product<< endl; // Вывод результата (и произведения)
        }
    }
}