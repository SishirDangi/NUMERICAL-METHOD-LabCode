/* Solve the equation 
d^2f = 3x^2y
over the square domain 0 <= x <= 1.5 and 0 <= y <= 1.5 with f=0 on the boundary. Take (h=0.5)
*/
#include <stdio.h>
#include <conio.h>
#include<math.h>
float f(float x, float y)
	{
    return (3.0 * x* x * y);
	}
void poisson(float x0, float xn, float y0, float yn, float h, float k){
    float f1, f2, f3, f4;
    f1 = f2 = f3 = f4 = 0;
    float error = 1, f1_old;
    while(error > 0.005f){
        f1_old = f1;
        f1 = (f4 + f2 - f(x0 + h, y0 + k))/4.0;
        f2 = (f1 + f3 - f(xn - h, y0 + k))/4.0;
        f3 = (f2 + f4 - f(xn - h, yn - k))/4.0;
        f4 = (f3 + f1 - f(x0 + h, yn - k))/4.0;
        error = (f1 - f1_old)/f1;
        if(error < 0){error *= -1;
		}
    }
    printf("F1: %f\n", f1);
    printf("F2: %f\n", f2);
    printf("F3: %f\n", f3);
    printf("F4: %f\n", f4);
}
int main(){
    float x0, y0,xn, yn, h, k;
    x0 = y0 = 0;
    xn = yn = 1.5;
    h = k = 0.5;
    poisson(x0, xn, y0, yn, h, k);
    return 0;
	}

