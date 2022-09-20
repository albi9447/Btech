#include<stdio.h>	
void main()
{
	int n,i,j,k,x=0;
	printf("Enter the number of nodes: ");
	scanf("%d",&n);
	int a[n][n],b[n][n];
	printf("Enter the routing table: \n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			b[i][j]=a[i][j];
		}
	while(x<=n)
	{	
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				for(k=0;k<n;k++)
					if(a[i][j]>a[i][k]+a[k][j])
						a[i][j]=a[i][k]+a[k][j];
		x++;
	}					
	printf("Distance Vector table:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
}