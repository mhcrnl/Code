#include <stdio.h>
#include <math.h>

int main()
{
	int time=0,i=0,j=0,k=0;
	scanf("%d",&time);
	int result[10]={0,0,0,0,0,0,0,0,0,0};
	for(i=0;i<time;i++)
	{
		float x[4]={0,0,0,0},y[4]={0,0,0,0},a=0,b=0,c=0,d=0,e=0,f=0;
		float m=0,n=0;
		for(j=0;j<4;j++) scanf("%f%f",&x[j],&y[j]);
		if(x[2]-x[0]!=0)
		{			
			m=(y[2]-y[0])/(x[2]-x[0]);
		    n=y[0]-m*x[0];			
			if( (m*x[1]+n-y[1])*(m*x[3]+n-y[3])>0 )
		    {				
				int tmp=0;
			    tmp=x[2];
			    x[2]=x[3];
			    x[3]=tmp;
			    tmp=y[2];
			    y[2]=y[3];
			    y[3]=tmp;
		    }			
		}
		else if( (x[1]<x[0]&&x[3]<x[0]) || (x[1]>x[0]&&x[3]>x[0]) )
		{
			    int tmp=0;
			    tmp=x[2];
			    x[2]=x[3];
			    x[3]=tmp;
			    tmp=y[2];
			    y[2]=y[3];
			    y[3]=tmp;
		}
		if(x[2]-x[0]!=0)
		{
			m=(y[2]-y[0])/(x[2]-x[0]);
		    n=y[0]-m*x[0];
			if( (m*x[1]+n-y[1])*(m*x[3]+n-y[3])>0 )
		    {			
				int tmp=0;
			    tmp=x[2];
			    x[2]=x[1];
			    x[1]=tmp;
			    tmp=y[2];
			    y[2]=y[1];
			    y[1]=tmp;
		    }
		}
		else if( (x[1]<x[0]&&x[3]<x[0]) || (x[1]>x[0]&&x[3]>x[0]) )
		{
			    int tmp=0;
			    tmp=x[2];
			    x[2]=x[1];
			    x[1]=tmp;
			    tmp=y[2];
			    y[2]=y[1];
			    y[1]=tmp;
		}
		a = (pow((x[1]-x[0]),2)+pow((y[1]-y[0]),2));
		b= (pow((x[2]-x[1]),2)+pow((y[2]-y[1]),2));
		c= (pow((x[3]-x[2]),2)+pow((y[3]-y[2]),2));
		d= (pow((x[0]-x[3]),2)+pow((y[0]-y[3]),2));
		e= (pow((x[2]-x[0]),2)+pow((y[2]-y[0]),2));
		f= (pow((x[3]-x[1]),2)+pow((y[3]-y[1]),2));
		if(a==b&&b==c&&c==d)
		{
			if(a*2==e) result[i]=1;
			else result[i]=3;
		}
		else if(a==c&&b==d&&e==f)
		{
			if(a+b==e) result[i]=2;
		}
	}
	for(i=0;i<time;i++)
	{
		switch(result[i])
		{
			case 0: printf("other\n"); break;
			case 1: printf("square\n"); break;
			case 2: printf("rectangle\n"); break;
			case 3: printf("diamond\n"); break;
		}
	}
	return 0;
}
