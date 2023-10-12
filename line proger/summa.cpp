/* Даны числа С,Р и D. Вычислить сумму корней квадратных этих чисел и произведение
этих чисел. */

#include <iostream>
#include <cmath>
using namespace std;

int main(){

    // Ввод данных
    int C,P,D;
    cout<<"\nВведите число C= ";
    cin>>C;
    cout<<"\nВведите число P= ";
    cin>>P;
    cout<<"\nВведите число D= ";
    cin>>D;
    
    // Вывод суммы корней
    const int result1 = sqrt(C) + sqrt(P) + sqrt(D);
    cout<<"\nСумма корней квадратов введеных чисел="<<result1;
    
    cout << endl;
    
    // Вывод произведения чисел
    const int result2 = C*P*D;
    cout<<"\nПроизведение введеных чисел="<<result2;
}