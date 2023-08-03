#include<stdio.h>
int main()
{
	int i,n,fact=1;
	printf("enter the value");
	scanf("%d",&n);
	if(n<0)
	printf("error");
	else
	{
		for(i=1;i<=n;i++)
		{
		 fact=fact*i;	
		}
		printf("factorial of %d:%d",n,fact);
	}
	
}
