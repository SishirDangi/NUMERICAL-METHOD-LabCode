/*Write a program to calculate derivative from divided difference table */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
 float x[20], y[20][20], xp, h, sum=0.0, term, first_derivative;
 int i,j, n, index, flag = 0, sign=1;
 printf("Enter number of data: ");
 scanf("%d", &n);
 printf("Enter data:\n");
 for(i = 0; i < n ; i++)
 {
  printf("x[%d] = ", i);
  scanf("%f", &x[i]);
  printf("y[%d] = ", i);
  scanf("%f", &y[i][0]);
 }
 printf("Enter at what value of x you want to calculate derivative: ");
 scanf("%f", &xp);
 for(i=0;i< n;i++)
 {
     if (fabs(xp - x[i])< 0.0001)
     {
        index = i;
        flag = 1;
        break;
     }
 }
 if (flag==0)
 {
     printf("Invalid calculation point!!! /nProgram exiting...");
     exit(0);
 }
 for(i = 1; i < n; i++)
 {
  for(j = 0; j < n-i; j++)
  {
      y[j][i] = y[j+1][i-1] - y[j][i-1];
  }
 }
 h = x[1] - x[0];
 for(i=1; i< n-index; i++)
 {
     term = pow(y[index][i], i)/i;
     sum = sum + sign*term;
     sign = -sign;
 }

 first_derivative = sum/h;
 printf("First derivative at x = %0.2f is %0.2f", xp, first_derivative);

 return 0;
}
