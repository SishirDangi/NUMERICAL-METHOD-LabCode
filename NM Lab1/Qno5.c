//Write program to implement Horner’s method.
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#define P(x) (a[4]*x*x*x*x+a[3]*x*x*x+a[2]*x*x+a[1]*x+a[0])
float a[100], b[100];
int main()
{
	
	float x;
	int n,i;
	printf("Enter degree of polynomial: \n"); 
	scanf("%d",&n);
	printf("Enter the coefficients from lower order to higher order:\n");
	for (i=n; i>=0;i--)
	{
		scanf("%f",&a[i]);
	}
	printf("Enter the value at which polynomial to be evaluated:\n");
	scanf("%f",&x);
	b[n]=a[n];
	while(n>0)
	{
		b[n-1]=a[n-1]+b[n]*x;
		n--;
	}
	printf("Value of polynomial p(%f)= %f",x,b[0]);
	getch();
	return 0;
}

