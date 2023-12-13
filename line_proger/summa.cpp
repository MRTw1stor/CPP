/* Даны числа С,Р и D. Вычислить сумму корней квадратных этих чисел и произведение
этих чисел. */

#include <iostream>
#include <cmath>
using namespace std;

int main(){

    // Ввод данных
    int C,P,D;
    cout<<"\n Введите число C = ";
    cin>>C;
    cout<<"\n Введите число P = ";
    cin>>P;
    cout<<"\n Введите число D = ";
    cin>>D;
    
    int result1 = sqrt(C) + sqrt(P) + sqrt(D);
    int result2 = C*P*D;
    // Вывод суммы корней
    cout<<"Сумма корней квадратов введеных чисел: "<<C<<" + "<<P<<" + "<<D<<" = "<<result1<<endl;
    // Вывод произведения чисел
    cout<<"Произведение введеных чисел: "<<C<<" * "<<P<<" * "<<D<<" = "<<result2;
}