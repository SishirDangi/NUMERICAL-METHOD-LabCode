/* Write a program to solve non-linear equation using Half Interval method. Your program should
read an initial guess from keyboard and display the followings if the solution is obtained:
a. Estimated root of the equation
b. Functional value at calculated root
c. Required number of iterations
*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f(x) cos(x) - x * exp(x)

void main()
{
	 float x0, x1, x2, f0, f1, f2, e;
	 int step = 1;
	 up:
	 printf("\nEnter two initial guesses:\n");
	 scanf("%f%f", &x0, &x1);
	 printf("Enter tolerable error:\n");
	 scanf("%f", &e);

	 f0 = f(x0);
	 f1 = f(x1);

	 if( f0 * f1 > 0.0)
	 {
		  printf("Incorrect Initial Guesses.\n");
		  goto up;
	 }

	 printf("\nStep\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
	 do
	 {
		  x2 = (x0 + x1)/2;
		  f2 = f(x2);

		  printf("%d\t\t%f\t%f\t%f\t%f\n",step, x0, x1, x2, f2);

		  if( f0 * f2 < 0)
		  {
			   x1 = x2;
			   f1 = f2;
		  }
		  else
		  {
			   x0 = x2;
			   f0 = f2;
		  }
		  step = step + 1;
	 }while(fabs(f2)>e);
	 printf("\nRoot is: %f", x2);
	 getch();
}
