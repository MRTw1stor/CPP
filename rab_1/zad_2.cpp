/* Составить программу для вычисления */

#include <iostream>
#include <cmath>

int main(){
    
    setlocale(LC_ALL, "Rus");
    
    double a,b,y;
    std::cout<<"\nВведите число a=";
    std::cin>>a;
    std::cout<<"\nВведите число b=";
    std::cin>>b;
    std::cout<<"\nВведите число y=";
    std::cin>>y;
    
    const int result = 7*y + 3+(sin(a)) + sqrt(pow(b, 2) + 19) / 7 * y + sqrt(pow(b, 2) + 19) + 2;
    std::cout<<"\nРезутьтат="<<result;
}