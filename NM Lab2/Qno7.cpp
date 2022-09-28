/*Write a program to implement least square approximation for linear data. 
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of data: ";
    cin >> n;

    float sum_x, sum_y, sum_sqx, sum_xy, a, b, x[n], y[n];

    cout << "Enter x and y coord (x, y): ";
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; i++)
    {
        sum_sqx = sum_sqx + pow((x[i]), 2);
        sum_xy = sum_xy + (x[i] * y[i]);
        sum_x = sum_x + x[i];
        sum_y = sum_y + y[i];
    }
    b = ((n * sum_xy) - (sum_x * sum_y)) / ((n * sum_sqx) - pow(sum_x, 2));
    a = (sum_y - b * sum_x) / n;
    cout << "Y = " << a << " + " << b << "x\n";
    return 0;
}

