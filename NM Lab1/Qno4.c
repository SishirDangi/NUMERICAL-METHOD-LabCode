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
#define E 0.005
float f(float x)
{
    return (x*x*x-x-5);
}
float g(float x)
{
    return pow((x + 5), (2.0 / 5.0));
}
int main()
{
	int itr=0;
	float x0,x1,error;
	printf("Enter the initial guess: ");
	scanf("%f",&x0);
	begin:
	x1=g(x0);
	error=fabs(x1-x0)/x1;
	if(error<=E)
	{
		printf("Root= %.3f",x1);
		printf("\nFunctional value: %.4f",f(x1));
		printf("\nNumber of steps:  %d",itr);
	}
	else
	{
		x0=x1;
		itr++;
	goto begin;
	}
	return 0;
}

