#include<stdio.h>
int main()
{
	int a[5][5],b[5][5];
	int i,j,r,c;
	printf("enter the number of row");
	scanf("%d",&r);
	printf("enter the number of column");
	scanf("%d",&c);
	printf("enter the first matrix element\n");
	
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&a[i][j]);
		}
		printf("enter the second matrix element\n");
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				scanf("%d",&b[i][j]);
			}
		printf("%d%d",a[i][j],b[i][j]);
		}
	}
}
		
