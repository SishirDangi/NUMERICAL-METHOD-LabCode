/*Write a program to approximate the functional value at any given 
x from given n no. of  data using Newton’s forward difference interpolation.
*/
#include <iostream>
using namespace std;
float nb(float x[], float y[], float x1, float y1, int n)
{

    static float s = (x1 - x[0]) / (x[1] - x[0]);
    static int step = 1;

    if (step < n)
    {

        for (int i = 1; i <= n - step; i++)
        {
            y[i - 1] = y[i] - y[i - 1];
        }

        y1 += s * y[0];
        step++;
        s *= (s - 1) / float(step);

        return nb(x, y, x1, y1, n);
    }
    return y1;
}
int main()
	{
    int n;
    cout << "Enter the number of test cases: ";
    cin >> n;

    float x[n], y[n], x1, y1;

    cout << "Enter x and y Coordinates: ";
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    cout << "Enter the value : ";
    cin >> x1;

    y1 = y[0];
    cout << "X: " << x1 << " Y: " << nb(x, y, x1, y1, n);

    return 0;
} 

