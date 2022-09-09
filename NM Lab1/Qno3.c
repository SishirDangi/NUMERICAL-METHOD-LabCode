/* Write a program to solve non-linear equation using Secant method. Your program should read
an initial guess from keyboard and display the followings if the solution is obtained:
a. Estimated root of the equation
b. Functional value at calculated root
c. Required number of iterations
*/
#include<stdio.h>
#include<math.h>
#include<conio.h>
#define E 0.01
float F(float x){
	return cos(x)+2*sin(x)+x*x;
}

int main()
{
	int itr=1;
	float x1,x2,x3,f1,f2,f3;
	printf("Enter first initial guess: ");
	scanf("%f",&x1);
	printf("Enter second initial guess: ");
	scanf("%f",&x2);
	f1=F(x1);
	f2=F(x2);
	begin:
	x3=(f2*x1-f1*x2)/(f2-f1);
	f3=F(x3);
		if(fabs((x3-x2)/x3)<E)
      {
			printf("\nRoot= %.2f",x3);
			printf("\nFuction value= %.4f",F(x3));
			printf("\nIteration steps= %d",itr);
   }
   else{
         itr++;
         	x1=x2;
            f1=f2;
            x2=x3;
            f2=f3;
            goto begin;
         }
      return 0;
}

