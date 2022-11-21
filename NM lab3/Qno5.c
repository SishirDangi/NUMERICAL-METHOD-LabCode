/* Write a program to calculate integration using composite Simpson’s 1/3 rule. */
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f(x) 1/(1+x)
int main()
{
	float a,h,x0,xn,fx0,fxn,term,v;
	int i,k;
	printf("Enter Lower & Upper Limit: \n");
	scanf("%f %f",&x0,&xn);
	printf("Enter number of segments: \n");
	scanf("%d",&k);
	h=(xn-x0)/k;
	fx0=f(x0);
	fxn=f(xn);
	term=f(x0)+f(xn);
	for(i=1; i<=k-1; i=i+2)
	{
	a=x0+i*h;
	term=term+4*(f(a));
	}
	for(i=2;i<=k-2;i=i+2)
	{
		a=x0+i*h;
		term=term+2*(f(a));
	}
	v=h/3*term;
	printf("\nValue of Integration=%f\n",v);
	getch();
	return 0;
	}
