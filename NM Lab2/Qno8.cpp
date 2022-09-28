/* Write a program to implement least square approximation for non- linear data. 
 eqn is y = ax^b
 lny = ln(ax^b)
 lny = lna + ln x^b
 ln y = lna  + bln x
 Y = A + bX
 a = ln a
 X = lnx
 Y = ln y
 */
 
#include <iostream>
#include <cmath>
#define e 2.718
using namespace std;
int main()
{
    int n;
    cout << "Enter a number of cases: ";
    cin >> n;

    float x[n], y[n];

    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    float a, b, sum_x, sum_y, sum_xy, sum_sqx;
    sum_x = sum_y = sum_xy = sum_sqx = 0;
    for (int i = 0; i < n; i++)
    {
        sum_sqx = sum_sqx + pow(log(x[i]), 2);
        sum_xy = sum_xy + (log(x[i]) * log(y[i]));
        sum_x = sum_x + log(x[i]);
        sum_y = sum_y + log(y[i]);
    }
    b = ((n * sum_xy) - (sum_x * sum_y)) / ((n * sum_sqx) - pow(sum_x, 2));
    a = (sum_y - b * sum_x) / n;
    cout << "Y = " << pow(e, a) << "*" << b << "^x";
    return 0;
}

