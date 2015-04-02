#include <stdio.h>

int main()
{
	int a[100]={0},i=0,n=0,j=0,k=0;
	scanf("%d%d",&i,&n);
	for(j=0;j<n;j++) scanf("%d",&a[j]);
	for(j=0;j<n-1;j++)
	{
		for(k=j+1;k<n;k++) 
		{
			if(a[j]<a[k])
			{
				int tmp=0;
				tmp=a[j];
				a[j]=a[k];
				a[k]=tmp;
			}
		}
	}
	printf("%d\n",a[i-1]);
	return 0;
}
