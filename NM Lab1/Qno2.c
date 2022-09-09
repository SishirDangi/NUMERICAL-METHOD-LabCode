/*. Write a program to solve non-linear equation using Newton’s method. Your program should
read an initial guess from keyboard and display the followings if the solution is obtained:
a. Estimated root of the equation
b. Functional value at calculated root
c. Required number of iterations
*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
float f(float x){
	return 3*x - cos(x) -1;
}
float fd(float x){
	return 3 + sin(x);
}
int main()
{
   int itr=1;
   float xi, x1, fxi, fdxi, root, e;
   printf("\nEnter the initial value:");
   scanf("%f",&xi);
   printf("Enter tolerable error:");
   scanf("%f",&e);
   begin:
   fxi=f(xi);
   fdxi=fd(xi);
   x1=xi-(fxi/fdxi);  
   if((fabs(x1-xi)/x1)<e)
   {
   	
   	printf("\nRoot=%f",x1);
      printf("\nFuction value= %f",f(x1));
      printf("\nIteration steps= %d",itr);
   }
   else
   {
   	xi=x1;
   	fxi=f(x1);
      itr ++;
      goto begin;
      }
   getch();
 }
