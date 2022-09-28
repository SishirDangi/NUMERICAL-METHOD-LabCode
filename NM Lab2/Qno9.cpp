/* Write a program to implement least square approximation polynomial data.
*/

#include <iostream>
#include <math.h>
using namespace std;
float sum(float *var, int size)
{
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += var[i];
    }
    return sum;
}
float mulsum(float *ind, float *dep, int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (dep[i] * ind[i]);
    }
    return sum;
}
float sqsum(float *var, int n)
{

    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (var[i] * var[i]);
    }
    return sum;
}
void regression(float *a, float *b, int n, float *d, float *ind)
{

    *b = (n * mulsum(d, ind, n) - sum(d, n) * sum(ind, n)) / (n * sqsum(ind, n) - pow(sum(ind, n), 2));

    *a = (sum(d, n) / n - *(b) * (sum(ind, n) / n));
}

int main()
{
    int size;
    cout << "Enter the size of data: ";
    cin >> size;
    float dpen[size], indepen[size], a, b;
    cout << "Enter dependen and independent value: \n";
    for (int i = 0; i < size; i++)
    {
        cin >> indepen[i] >> dpen[i];
    }
    regression(&a, &b, size, dpen, indepen);
    cout << "A: " << a << "\tb: " << b;
    return 0;
}

