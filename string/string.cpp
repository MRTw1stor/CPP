/* Ввести с клавиатуры строку символов. Признак окончания ввода строки – нажатие клавиши
"Ввод". Программа должна определить длину введенной строки L, и, если длина L кратна 5,
то подсчитывается количество скобок всех видов.*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    // Ввод данных
    cout << "Введите любое количество скобок: ";
    string input;
    getline(cin, input);
    int L = input.length();

    // Объявляем переменные для скобок по их названию
    if (L % 5 == 0) {
        int count_open = 0;
        int count_close = 0;
        int count_curly_open = 0;
        int count_curly_close = 0;
        int count_square_open = 0;
        int count_square_close = 0;

        // Находим количество видов всех скобок
        for (char c : input) {
            if (c == '(' ) {
                count_open++;
            } else if (c == ')') {
                count_close++;
            } else if (c == '{') {
                count_curly_open++;
            } else if (c == '}') {
                count_curly_close++;
            } else if (c == '[') {
                count_square_open++;
            } else if (c == ']') {
                count_square_close++;
            }
        }

        // Выводим количество скобок всех видов
        cout << "Количество круглых скобок: " << count_open + count_close << endl;
        cout << "Количество фигурных скобок: " << count_curly_open + count_curly_close << endl;
        cout << "Количество квадратных скобок: " << count_square_open + count_square_close << endl;
    }
    else{
        cout << "Введенное количество символов не кратно 5";
    }
}