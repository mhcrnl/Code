#include <stdio.h>

int main()
{
	long long int num[10000][2]={0},tmp=0;
	int n=0,count=0,i=0,j=0;
	while(scanf("%lld",&num[n][0])!=EOF)
	{
		tmp=num[n][0];
		while(tmp>=1)
		{
			if(tmp%2==1) num[n][1]++;
			tmp=tmp/2;
		}
		n=n+1;
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if( (num[i][1]>num[j][1]) || (num[i][1]==num[j][1] && num[i][0]>num[j][0]))
			{
				long long int t;
				t=num[i][0];
				num[i][0]=num[j][0];
				num[j][0]=t;
				t=num[i][1];
				num[i][1]=num[j][1];
				num[j][1]=t;
			}
		}
	}
	for(i=0;i<n;i++) printf("%lld\n",num[i][0]);
	return 0;
}
