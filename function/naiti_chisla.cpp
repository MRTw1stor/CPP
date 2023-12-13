/* Дано натуральное число N. Получить все такие натуральные K, что N делится на K**2 и не делится на
K**3.*/

#include <iostream>
using namespace std;

// Функция для проверки, делится ли число N на K^2
bool isDivisibleByKSquare(int N, int K) {
    return N % (K * K) == 0;
}

// Функция для проверки, не делится ли число N на K^3
bool isNotDivisibleByKCubed(int N, int K) {
    return N % (K * K * K) != 0;
}

int main() {
    int N;
    cout << "Введите натуральное число N: ";
    cin >> N;

    cout << "Все натуральные K, такие что N делится на K**2 и не делится на K**3: ";
    for (int K = 1; K <= N; K++) {
        if (isDivisibleByKSquare(N, K) && isNotDivisibleByKCubed(N, K)) {
            cout << K << "; ";
        }
    }
}