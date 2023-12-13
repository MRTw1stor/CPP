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

    cout << "Введите номер столбца (от 0 до " << colon - 1 << "): ";
    cin >> colIndex;

    if (colIndex < 0 || colIndex >= colon) {
        cout << "Ошибка: Некорректный номер столбца."; // В случае некорректного ввода номера столбца
    } else {
        if (isThreeDigitProduct(arr, colIndex, product)) { // Проверка произведения элементов столбца
            cout << "Произведение элементов " << colIndex << "-го столбца является трехзначным числом: " << product<< endl; // Вывод результата (и произведения)
                cout << "Массив:" << endl;
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < colon; j++) {
                        cout << arr[i][j] << " ";
                    }
                    cout << endl;
                }
        } else {
            cout << "Произведение элементов " << colIndex << "-го столбца НЕ является трехзначным числом: " << product<< endl; // Вывод результата (и произведения)
            cout << "Массив:" << endl;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < colon; j++) {
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
}

/* №1
Способы декларирования двумерных массивов:

Статическое декларирование:
int arr[3][3]; // Двумерный массив 3x3

Динамическое декларирование:
int **arr;
arr = new int*[3];
for(int i = 0; i < 3; ++i) {
    arr[i] = new int[3];
}

Декларирование с помощью векторов:
vector<vector<int>> arr(3, vector<int>(3));
*/

/* №2
Способы заполнения двумерных массивов:

Ввод значений с клавиатуры:
for(int i=0; i<3; i++) {
    for(int j=0; j<3; j++) {
        cin >> arr[i][j];
    }
}

Инициализация значений при декларировании:
int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

Заполнение случайными числами:
for(int i=0; i<3; i++) {
    for(int j=0; j<3; j++) {
        arr[i][j] = rand() % 100;
    }
}
*/

/* №3
Формы (способы) работы с элементами двумерного массива:

Обращение к конкретному элементу:
int element = arr[1][2]; // Получение значения третьего элемента второй строки

Использование вложенных циклов для перебора всех элементов:
for(int i=0; i<3; i++) {
    for(int j=0; j<3; j++) {
        cout << arr[i][j] << " "; // Вывод элемента на экран
    }
    cout << endl;
}

Преобразование двумерного массива в одномерный:
int onedim[9];
int k = 0;
for(int i=0; i<3; i++) {
    for(int j=0; j<3; j++) {
        onedim[k] = arr[i][j];
        k++;
    }
}
*/