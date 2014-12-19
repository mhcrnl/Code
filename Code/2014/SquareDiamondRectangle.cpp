#include <stdio.h>

int main()
{
	int time=0,i=0,j=0,k=0,result[10000]={0},n=0,x[4]={0,0,0,0},y[4]={0,0,0,0},d[6]={0,0,0,0,0,0},tmp=0;
	scanf("%d",&time);
	for(i=0;i<time;i++)
	{		
		for(j=0;j<4;j++) scanf("%d%d",&x[j],&y[j]);
		n=0;
		for(j=0;j<3;j++)
		{			
			for(k=j+1;k<4;k++)
			{
				d[n]=(x[k]-x[j])*(x[k]-x[j])+(y[k]-y[j])*(y[k]-y[j]);
				n=n+1;
			}				
		}
		for(j=0;j<5;j++)
		{
			for(k=j+1;k<6;k++)
			{
				if(d[k]<d[j])
				{					
					tmp=d[k];
					d[k]=d[j];
					d[j]=tmp;
				}
			}
		}
		if(d[0]==d[1] && d[1]==d[2] && d[2]==d[3] && d[4]==2*d[3] && d[4]==d[5]) result[i]=1;
		else if(d[0]==d[1] && d[2]==d[3] && (d[4]==d[0]+d[2]) && d[4]==d[5]) result[i]=2;
		else if(d[0]==d[1] && d[1]==d[2] && d[2]==d[3] && (d[0]==d[4]/4+d[5]/4)) result[i]=3;		
		else if(d[4]==d[1] && d[1]==d[2] && d[2]==d[3] && (d[1]==d[0]/4+d[5]/4)) result[i]=3;		
	}
	for(i=0;i<time;i++)
	{
		switch(result[i])
		{
			case 0: printf("other\n"); break;
			case 1: printf("square\n"); break;
			case 2: printf("rectangle\n"); break;
			case 3: printf("diamond\n"); break;
			default:printf("other\n"); break;
		}
	}
	return 0;
}