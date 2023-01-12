/* Write a program to to calculate an approximate value of y when x = 0.4 given that
dy/dx = x + y and y(0) = 1
With h=0.1 and h=0.2
Using Euler’s algorithm
 */
#include <stdio.h>
#include<math.h>
#include<conio.h>
float f(float x, float y) {
    return x + y;
}

float euler(float x0, float y0, float h, float (*f)(float, float)) {
    float x = x0;
    float y = y0;
    while (x < 0.4) {
        y += h * f(x, y);
        x += h;
    }
    return y;
}

int main() {
    // using h = 0.1
    float x0 = 0;
    float y0 = 1;
    float h = 0.1;
    float y_approx_h1 = euler(x0, y0, h, f);
    printf("The approximate value of y when X=0.4 with h=0.1 is: %f\n", y_approx_h1);

    // using h = 0.2
    h = 0.2;
    float y_approx_h2 = euler(x0, y0, h, f);
    printf("The approximate value of y when X=0.4 with h=0.2 is: %f\n", y_approx_h2);
    return 0; 
}      
