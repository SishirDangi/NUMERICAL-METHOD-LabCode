/* Write a program to to calculate an approximate value of y when x = 0.4 given that
dy/dx = x + y and y(0) = 1
With h=0.1 and h=0.2
Using Heun’s algorithm
 */
#include <stdio.h>
#include<math.h>
#include<conio.h>
// Function to calculate the derivative of y with respect to x
float dy_dx(float x, float y) {
    return x + y;
}

// Heun's Method
float heuns(float (*dy_dx)(float, float), int x0, int y0, float h, float x_target) {
    float xn = x0;
    float yn = y0;
    while (xn < x_target) {
        float m1 = dy_dx(xn, yn);
        float m2 = dy_dx(xn + h, yn + h*m1);
        yn += h*(m1 + m2) / 2;
        xn += h;
    }
    return yn;
}

int main() {
	//Using h=0.1
    int x0 = 0;
    int y0 = 1;
    float h = 0.1;
    float x_target = 0.4;
    float y_approx1 = heuns(dy_dx, x0, y0, h, x_target);
    printf("Approximate value of y when x = 0.4 and h = 0.1 is: %f\n", y_approx1);
	//Using h=0.2
    h = 0.2;
    float y_approx2 = heuns(dy_dx, x0, y0, h, x_target);
    printf("Approximate value of y when x = 0.4 and h = 0.2 is : %f\n", y_approx2);
    return 0;
}
