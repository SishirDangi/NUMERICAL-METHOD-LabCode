/* Write a program to to calculate an approximate value of y when x = 0.4 given that
dy/dx = x + y and y(0) = 1
With h=0.1 and h=0.2
Using RK 4th order method
 */
#include <stdio.h>
// Function to calculate the derivative of y with respect to x
float dy_dx(float x, float y) {
    return x + y;
}

// Fourth-order Runge-Kutta method
float rk4(float (*dy_dx)(float, float), int x0, int y0, float h, float x_target) {
    float xn = x0;
    float yn = y0;
    while (xn < x_target) {
        float m1 = dy_dx(xn, yn);
        float m2 = dy_dx(xn + h/2, yn + h*m1/2);
        float m3 = dy_dx(xn + h/2, yn + h*m2/2);
        float m4 = dy_dx(xn + h, yn + h*m3);
        yn += (m1 + 2*m2 + 2*m3 + m4)*h/ 6;
        xn += h;
    }
    return yn;
}

int main() {
    int x0 = 0;
    int y0 = 1;
    float h = 0.1;
    float x_target = 0.4;
    float y_approx1 = rk4(dy_dx, x0, y0, h, x_target);
    printf("Approximate value of y when x = 0.4 and h = 0.1 is: %f\n", y_approx1);

    h = 0.2;
    float y_approx2 = rk4(dy_dx, x0, y0, h, x_target);
    printf("Approximate value of y when x = 0.4 and h = 0.2 is: %f\n", y_approx2);
    return 0;
}
