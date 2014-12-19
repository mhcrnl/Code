#include <stdio.h>

int calc(int m,int n,int table[100],int tmp[100],int now)
{
	int i=0,j=0,flag=0,next=0;
	for(i=0;i<n*n;i++)
	{
		table[now]=tmp[i];
		next=0;
		for(j=now-1;j>=0;j--)
		{
			if(table[now]==table[j])
			{
				next=1;
				break;
			}
		}
		if(next==0)
		{
			if(now==n*n-1)
			{
				int sum=0,sum2=0,a=0,b=0;
				for(a=0;a<n;a++)
				{
					sum=0;
					sum2=0;
					for(b=0;b<n;b++)
					{
						sum=sum+table[a*n+b];
						sum2=sum2+table[a+b*n];
					}
					if(sum>m) return 0;
					if(sum2>m) return 0;
				}
				return 1;
			}
			flag=calc(m,n,table,tmp,now+1);
			if(flag==1) return 1;
		}
	}
	return 0;
}

int main()
{
	int i=0,j=0,table[100]={0},tmp[100]={0},m=0,n=0;
	scanf("%d",&n);
	for(i=0;i<n*n;i++) scanf("%d",&tmp[i]);
	scanf("%d",&m);
	for(i=0;i<n*n-1;i++)
	{
		for(j=i+1;j<n*n;j++)
		{
			if(tmp[i]>tmp[j])
			{
				int t=0;
				t=tmp[i];
				tmp[i]=tmp[j];
				tmp[j]=t;
			}
		}
	}
	calc(m,n,table,tmp,0);
	for(i=0;i<n*n;i++)
	{
		printf("%d",table[i]);
		if(i%n==n-1) printf("\n");
		else printf(" ");
	}
	return 0;
}
