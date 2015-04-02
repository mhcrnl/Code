#include <stdio.h>

int main()
{
	int i=0,j=0,a=0,b=0,output[1000]={1},flag=0;
	scanf("%d%d",&a,&b);
	for(i=1;i<=1000;i++)
	{
		output[i]=(output[i-1]*a)%1000;
		for(j=1;j<i;j++)
		{
			if (output[i]==output[j])
			{
				flag=1;
				break;
			}			
		}
		if (flag==1) break;
	}
	output[0]=output[i-1];
	printf("%d\n",output[b%(i-1)]);
	return 0;
}
