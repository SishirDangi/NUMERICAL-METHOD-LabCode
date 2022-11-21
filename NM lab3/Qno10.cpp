/* Write a program to evaluate double integration of a function using Trapezoidal rule. */
#include <iostream>
#include <cmath>
using namespace std;
float f(int x, int y)
{
    return pow(x, y);
}

float doubleIntegration(int xl, int xu, int yl, int yu)
{
    return (yu - yl) * (xu - xl) * (f(xl, yl) + f(xl, yu) + f(xu, yu) + f(xu, yl))/4.0;
}
int main()
{
    int xl, xu, yl, yu;
    cout << "Enter x limits (xl, xu)= ";
    cin >> xl>> xu;
    cout << "Enter y limits (yl, yu)= ";
    cin >> yl >> yu;
    cout << "I= "<< doubleIntegration(xl, xu, yl, yu);
    return 0;
}
