/* Составить программу вывода всех трехзначных десятичных чисел, сумма цифр которых
равна данному целому числу.*/

#include <iostream>
using namespace std;

// Получем сумму введенного числа
int getSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    // Ввод данных
    int targetSum;
    cout << "Введите целое число: ";
    cin >> targetSum;
    
    // Вывод заголовка
    cout << "Трехзначные числа, сумма цифр которых равна " << targetSum << ":\n";
    
    // Нахождение подходящих чесил и вывод их
    for (int num = 100; num <= 999; num++) {
        if (getSum(num) == targetSum) {
            cout << num << "; ";
        }
    }
}
