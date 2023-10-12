/* Написать программу, которая по заданному номеру месяца n определяет количество дней в
этом месяце k.*/

#include <iostream>
using namespace std;

int main() {
    // Ввод данных
    int n;
    cout << "Введите номер месяца: ";
    cin >> n;

    int k;

    // Выбираем номер какого месяца ввел пользователь
    switch (n) {

        case 1: // Январь
        case 3: // Март
        case 5: // Май
        case 7: // Июль
        case 8: // Август
        case 10: // Октябрь
        case 12: // Декабрь
            k = 31;
            break;

        case 4: // Апрель
        case 6: // Июнь
        case 9: // Сентябрь
        case 11: // Ноябрь
            k = 30;
            break;

        case 2: // Февраль
            k = 28;
            break;

        // Если такого месяца нет то выводи ошибку
        default:
            cout << "Неверный номер месяца!" << endl;
    }
    // Выводим количество дней в выбранном месяце
    cout << "Количество дней в месяце: " << k << endl;
}
