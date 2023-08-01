#include <stdio.h>
double recHorner(double coef[],int n ,double x)
{
	if(n==0)
	{
		return coef[0];
	}
	return coef[n]+ x*recHorner(coef,n-1,x);
}
void main()
{
	double value,x;
	int i,n;
	printf("Enter number of coefficients:");
	scanf("%d",&n);
	double coef[n];
	printf("Enter the coefficients:\n");
	for(i=0;i<n;i++)
	{
		scanf("%lf",&coef[i]);
	}
	printf("Enter the X: \n");
	scanf("%lf",&x);
	value=recHorner(coef,n,x);
	printf("P(%lf) = %lf \n",x,value);
	
}

		
