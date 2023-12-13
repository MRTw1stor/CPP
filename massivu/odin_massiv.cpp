/* Найти среднее арифметическое элементов массива х(n), исключив из них максимальное и
минимальное значение.*/

#include <iostream>
#include <random>
#include <limits>
using namespace std;

int main() {
    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    // Инициализация генератора случайных чисел
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distrib(1, 10);

    int* x = new int[n];

    cout << "Элементы массива: ";
    for (int i = 0; i < n; i++) {
        x[i] = distrib(gen);
        cout << x[i] << " ";
    }
    cout << endl;

    // Находим минимальное и максимальное значение в массиве
    int minVal = numeric_limits<int>::max();
    int maxVal = numeric_limits<int>::min();
    for (int i = 0; i < n; i++) {
        if (x[i] < minVal) {
            minVal = x[i];
        }
        if (x[i] > maxVal) {
            maxVal = x[i];
        }
    }

    int sum = 0;
    int count = 0;

    // Находим сумму всех элементов, исключая минимальное и максимальное значение
    for (int i = 0; i < n; i++) {
        if (x[i] != minVal && x[i] != maxVal) {
            sum += x[i];
            count++;
        }
    }

    if (count > 0) {
        double average = static_cast<double>(sum) / count;
        cout << "Минимальное значение массива: " << minVal << endl;
        cout << "Максимальное значение массива: " << maxVal << endl;
        cout << "Элементы массива без минимальных и максимальных значений: ";
            for (int i = 0; i < n; i++) {
                if(x[i] != minVal && x[i] != maxVal){
                    cout << x[i] << " ";
                }
            }
        cout << endl;
        cout << "Среднее арифметическое элементов массива (исключив минимальное и максимальное значение): " <<sum<<" / "<<count<<" = "<< average << endl;
    } else {
        cout << "В массиве нет уникальных элементов для вычисления среднего значения." << endl;
    }
}