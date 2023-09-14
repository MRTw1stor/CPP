/* Даны числа С,Р и D. Вычислить сумму корней квадратных этих чисел и произведение
этих чисел. */

#include <iostream>
#include <cmath>

int main(){
    
    setlocale(LC_ALL, "Rus");
    
    int C,P,D;
    std::cout<<"\nВведите число C=";
    std::cin>>C;
    std::cout<<"\nВведите число P=";
    std::cin>>P;
    std::cout<<"\nВведите число D=";
    std::cin>>D;
    
    const int result1 = sqrt(C) + sqrt(P) + sqrt(D);
    std::cout<<"\nСумма корней квадратов введеных чисел="<<result1;
    
    std::cout << std::endl;
    
    const int result2 = C*P*D;
    std::cout<<"\nПроизведение введеных чисел="<<result2;
}