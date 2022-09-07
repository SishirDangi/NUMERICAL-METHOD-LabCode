/* Write a program to solve non-linear equation using Secant method. Your program should read
an initial guess from keyboard and display the followings if the solution is obtained:
a. Estimated root of the equation
b. Functional value at calculated root
c. Required number of iterations
*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#define    f(x)    x*x*x - 2*x - 5
void main()
{
	 float x0, x1, x2, f0, f1, f2, e;
	 int step = 1, N;
	 printf("\nEnter initial guesses:\n");
	 scanf("%f%f", &x0, &x1);
	 printf("Enter tolerable error:\n");
	 scanf("%f", &e);
	 printf("Enter maximum iteration:\n");
	 scanf("%d", &N);
	 printf("\nStep\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
	 do
	 {
		  f0 = f(x0);
		  f1 = f(x1);
		  if(f0 == f1)
		  {
			   printf("Mathematical Error.");
			   exit(1);
		  }

		  x2 = x1 - (x1 - x0) * f1/(f1-f0);
		  f2 = f(x2);

		  printf("%d\t\t%f\t%f\t%f\t%f\n",step,x0,x1,x2, f2);

		  x0 = x1;
		  f0 = f1;
		  x1 = x2;
		  f1 = f2;

		  step = step + 1;

		  if(step > N)
		  {
			   printf("Not Convergent.");
			   exit(0);
		  }
	 }
     while(fabs(f2)>e);
	 printf("\nRoot is: %f", x2);
	 getch();
}
