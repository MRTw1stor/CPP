/* Дано натуральное число N. Получить все такие натуральные K, что N делится на K**2 и не делится на
K**3.*/

#include <iostream>
using namespace std;

int main() {
    // Ввод данных
    int N;
    cout << "Введите натуральное число N: ";
    cin >> N;
    
    // Находим натуральное число
    cout << "Все натуральные K, такие что N делится на K**2 и не делится на K**3: ";
    for (int K = 1; K <= N; K++) {
        if (N % (K * K) == 0 && N % (K * K * K) != 0) {
            cout << K << "; ";
        }
    }
}

/* №1
Функция пользователя (или пользовательская функция) отличается от стандартной функции тем, 
что пользовательская функция создается программистом самостоятельно для выполнения 
определенной задачи или набора задач, а стандартные функции уже предопределены в языке 
программирования и обычно используются для выполнения стандартных 
операций (например, вывод на экран, сортировка и т. д.).
*/

/* №2
Способы передачи аргументов в функцию в C++ включают передачу по значению, 
передачу по ссылке и передачу указателя. При передаче по значению функция получает 
копию значения аргумента, при передаче по ссылке функция получает возможность 
изменять оригинальное значение аргумента, а при передаче указателя функция 
получает доступ к оригинальному значению аргумента через его адрес.
*/

/* №3
Локальные переменные - это переменные, объявленные внутри блока кода функции 
или другого компонента программы, и их область видимости ограничена этим блоком кода. 
Глобальные переменные - это переменные, объявленные вне всех функций и 
их область видимости распространяется на всю программу.
*/

/* №4
Оператор return используется в функции для возврата значения обратно
в вызывающую программу. Это позволяет функции выполнить вычисления, 
обработку данных и вернуть результат для дальнейшего использования в программе. 
Кроме того, оператор return также может использоваться для завершения 
выполнения функции в случае, если функция ничего не возвращает (например, функция типа void).
*/