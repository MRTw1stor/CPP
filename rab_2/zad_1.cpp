/* Составить программу для определения таблицы значений функции у в произвольном
диапазоне [a,b] изменения аргумента х с произвольным шагом h, вводимым с клавиатуры.
Таблица должна содержать следующие столбцы: порядковый номер, значение аргумента x,
значение функции, сообщение о возрастании или убывании функции, разность двух соседних
значений функции. Определить максимальное и минимальное значения функции. */

#include <iostream>
#include <cmath>
using namespace std;

// Функция, для которой строится таблица значений
double computeFunction(double x) {
    // Вычисление значения функции
    return exp(x+1)*cos(x);
}

int main() {
    // Ввод значений
    double a, b, h;
    cout << "Введите начало диапазона a: ";
    cin >> a;
    cout << "Введите конец диапазона b: ";
    cin >> b;
    cout << "Введите шаг h: ";
    cin >> h;

    // Объявление переменных
    int count = 1;
    double x = a;
    double prevFuncValue = computeFunction(x);
    double maxFuncValue = prevFuncValue;
    double minFuncValue = prevFuncValue;

    // Заголовок таблицы значений
    cout << "----------------------------------------------------------------------" << endl;
    cout << "| № | Значение x | Значение функции |       Сообщение       |   Разность   |" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    
    // Сравнение возрастает или убывает функция
    while (x <= b) {
        double funcValue = computeFunction(x);
        string message;
        if (funcValue > prevFuncValue) {
            message = "Функция возрастает";
        } else if (funcValue < prevFuncValue) {
            message = "Функция убывает";
        } else {
            message = "Функция не меняется";
        }
        double diff = funcValue - prevFuncValue;

        // Обновляем максимальное и минимальное значения функции
        if (funcValue > maxFuncValue) {
            maxFuncValue = funcValue;
        }
        if (funcValue < minFuncValue) {
            minFuncValue = funcValue;
        }

        // Вывод значений таблицы
        cout << "  " << count << "       " << x << "         " << funcValue << "         " << message << "       " << diff<< endl;

        // Обновление и увеличение значений
        x += h;
        prevFuncValue = funcValue;
        count++;
    }

    // Вывод максимального и минимального значения функции
    cout << "----------------------------------------------------------------------" << endl;
    cout << "Максимальное значение функции: " << maxFuncValue << endl;
    cout << "Минимальное значение функции: " << minFuncValue << endl;
}