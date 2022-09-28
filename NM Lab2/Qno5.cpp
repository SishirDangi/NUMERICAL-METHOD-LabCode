/*Write a program to approximate the functional value at any given 
x from given n no. of  data using Cubic Spline interpolation. 
*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, i;
    cout << "Enter the number of testcases: ";
    cin >> n;
    float x[n], f[n], h[n - 1], u[n - 1], a[n - 1], s, x1;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> f[i];
    }

    cout << "Enter a value to be interpolated: ";
    cin >> x1;
    for (int i = 0; i < n - 1; i++)
    {
        h[i + 1] = x[i + 1] - x[i];
        u[i] = x1 - x[i + 1];
    }

    i = 1;
    a[0] = 0;
    a[n - 1] = 0;
    a[1] = ((6 * ((f[2] - f[1]) / h[2]) - ((f[1] - f[0]) / h[1])) - h[1] * a[0] - h[2] * a[2]) / (2 * (h[1] + h[2]));
    for (i = 0; i < n; i++)
    {

        if (x1 <= x[i])
        {
            u[0] = u[i - 1];
            u[1] = u[i];
            break;
        }
    }
    s = (a[i - 1] * (pow(h[i - 1], 2) * u[i] - pow(u[i], 3)) + a[i] * (pow(u[i - 1], 3) - h[i] * u[i - 1])) / (6 * h[i]) + (f[i] * u[i - 1] - f[i - 1] * u[i]) / h[i];
    cout << s;
    return 0;
}

