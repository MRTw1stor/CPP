/* Составить программу для определения таблицы значений функции у в произвольном
диапазоне [a,b] изменения аргумента х с произвольным шагом h, вводимым с клавиатуры.
Таблица должна содержать следующие столбцы: порядковый номер, значение аргумента x,
значение функции, сообщение о возрастании или убывании функции, разность двух соседних
значений функции. Определить максимальное и минимальное значения функции. */

#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

int main(){
    
    setlocale(LC_ALL, "Rus");
    
    double a,b,h;
    cout<<"\nВведите число a=";
    cin>>a;
    cout<<"\nВведите число b=";
    cin>>b;
    cout<<"\nВведите шаг h=";
    cin>>h;
    
    while(a <= b)
    {
        float y = exp(a+1)*cos(a);
        printf("Y = %.4f ",y);
        printf("X = %.4f \n",a);
        a+=h;
        
    };
}