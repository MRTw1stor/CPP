/* Составить программу для вычисления */

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    
    setlocale(LC_ALL, "Rus");
    
    float a,b,y;
    cout<<"\nВведите число a=";
    cin>>a;
    cout<<"\nВведите число b=";
    cin>>b;
    cout<<"\nВведите число y=";
    cin>>y;
    
    const int result = 7*y + 3+(sin(a)) + sqrt(pow(b, 2) + 19) / 7 * y + sqrt(pow(b, 2) + 19) + 2;
    cout<<"Резутьтат="<<result;
}
