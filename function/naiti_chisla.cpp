/* Дано натуральное число N. Получить все такие натуральные K, что N делится на K**2 и не делится на
K**3.*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Ввод данных
    int N;
    cout << "Введите натуральное число N: ";
    cin >> N;
    
    vector<int> result;

    // Находим натуральное число
    for (int K = 1; K <= N; K++) {
        if (N % (K * K) == 0 && N % (K * K * K) != 0) {
            result.push_back(K);
        }
    }

    // Выводим все натуральные числа, которые мы нашли
    cout << "Все натуральные K, такие что N делится на K**2 и не делится на K**3: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ";";
    }
}