#include <stdio.h>
#include <math.h>

int main()
{
	int size=0,x[3]={0,0,0},y[3]={0,0,0},d=0,flag=0,n[3]={0,0,0},a=0,b=0,i=0,x_d=0,y_d=0;
	scanf("%d",&size);
	for(i=0;i<3;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
	}
	for(a=0;a<size+1;a++)
	{
		for(b=0;b<size+1;b++)
		{
			flag=0;
			d=(size*size)+(size*size)+1;
			for(i=0;i<3;i++)
			{
				if( pow( (x[i]-a) , 2 ) + pow( (y[i]-b) , 2 ) < d || ( ( pow( (x[i]-a) , 2 ) + pow( (y[i]-b) , 2 ) == d) && (x[i]<x_d) ) ||  ( ( pow( (x[i]-a) , 2 ) + pow( (y[i]-b) , 2 ) == d) && (x[i]==x_d) &&(y[i]<y_d) ) )
				{
					d=pow( (x[i]-a) , 2 ) + pow( (y[i]-b) , 2 );
					x_d=x[i];
					y_d=y[i];
					flag=i;
				}			
			}			
			n[flag]++;
		}
	}
	printf("%d\n%d\n%d\n",n[0],n[1],n[2]);
	return 0;
}
