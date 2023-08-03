#include<stdio.h>
int main()
{
	int i,n,a=0,b=1,c;
	printf("enter the value");
	scanf("%d",&n);
	for(i=2;i<=n;i++)
	printf("%d%d",a,b);
	c=a+b;
	a=b;
	b=c;
	
}
