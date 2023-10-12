/* Написать программу, которая по заданному номеру месяца n определяет количество дней в
этом месяце k.*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Введите номер месяца: ";
    cin >> n;

    int k;

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

        default:
            cout << "Неверный номер месяца!" << endl;
    }
    cout << "Количество дней в месяце: " << k << endl;
}