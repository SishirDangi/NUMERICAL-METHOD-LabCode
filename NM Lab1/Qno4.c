/* Write a program to solve non-linear equation using Fixed Point Iteration method. Your
program should read an initial guess from keyboard and display the followings if the solution is
obtained:
a. Estimated root of the equation
b. Functional value at calculated root
c. Required number of iterations
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#define G(x) (a3*x*x*x+a2*x*x+a0)/(-a1)
float a0,a1,a2,a3;
int main()
{
float x0,x1,E,Er;
printf("Enter cofficients a3 ,a2,a1 and a0\n"); 
scanf("%f%f%f%f",&a3,&a2,&a1,&a0); 
printf("Enter 2 initial guess and E\n"); 
scanf("%f%f",&x0,&E);
while(1)
{
x1 =G(x0);
Er=(x1-x0)/x1;
if(fabs(Er) < E)
{
	printf("Root=%f\n",x1);
	break;
}
x0 =x1;
}
getch();
}

