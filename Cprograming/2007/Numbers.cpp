#include<stdio.h>

int main()
{
	int	N,m;
	scanf("%d%d",&N,&m);
	
	int data[N],sum[m],max[m],min[m];
	
	for(int i=0;i<m;i++) sum[i]=0;
	
	for(int i=0;i<N;i++) scanf("%d",&data[i]);
	
	for(int i=0;i<N;i++)
	{		
		if( sum[ data[i]%m ]==0 ) max[ data[i]%m ]=min[ data[i]%m ]=data[i];
		else if( data[i] <= min[ data[i]%m ] ) min[ data[i]%m ]=data[i];
		else if( data[i] >= max[ data[i]%m ] ) max[ data[i]%m ]=data[i];
		sum[ data[i]%m ]=sum[ data[i]%m ] + data[i];
	}
	
	for(int i=0;i<m;i++) printf("%d %d %d\n",sum[i],max[i],min[i]);
	return 0;
}
