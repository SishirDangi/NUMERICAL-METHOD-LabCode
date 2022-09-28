/*
Write a program to approximate the functional value at any given x from given n 
no. of  data using Newton’s central divided difference interpolation. 
*/
#include <iostream>
void newton(float x[], float y[], int n, float y_coord, float x_coord)
{

    float arr[n - 1];
    static int step = 1;
    std::cout << step << "\n";
    for (int i = 1, j = i + step - 1; i < n; i++, j++)
    {
        std::cout << y[i] << " " << y[i - 1] << "\t" << x[j] << " " << x[j - step] << "\t";
        arr[i - 1] = (y[i] - y[i - 1]) / (x[j] - x[j - step]);
        std::cout << arr[i - 1] << "\n";
    }
    float value = 1;

    for (int i = 0; i < step; i++)
    {
        value *= (x_coord - x[i]);
    }
    y_coord += arr[0] * value;

    if (step <= n)
    {
        step++;
        return newton(x, arr, n - 1, y_coord, x_coord);
    }
    else
    {
        std::cout << y_coord;
        return;
    }
}
int main()
{
    int n;
    std::cout << "Enter the number of test cases: ";
    std::cin >> n;
    float x[n], y[n], x_coord, y_coord;
    std::cout << "Enter the coordinates: ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> x[i] >> y[i];
    }
    std::cout << "Enter the x coordinate: ";
    std::cin >> x_coord;
    y_coord = y[0];
    newton(x, y, n, y_coord, x_coord);
}

