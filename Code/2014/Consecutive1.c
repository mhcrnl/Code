#include <stdio.h>

int main()
{
	int n=0,count=0,max=0,result[1000000]={0},i=0,input=0;
	while(scanf("%d",&input)!=EOF)
	{
		count=0;
		max=0;
		while(input!=0)
		{
			if(input%2==1)
			{
				count++;
				if(count>max) max=count;
			}
			else count=0;
			input=input/2;
		}
		result[n]=max;
		n=n+1;
	}
	for(i=0;i<n;i++) printf("%d\n",result[i]);
	return 0;
}
