#include<stdio.h>
int main()
{
	int n,fact=1,i;
	printf("enter the value\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	    fact=fact*i;
	printf("factorialof%d:%d",n,fact);
	return 1;
}
