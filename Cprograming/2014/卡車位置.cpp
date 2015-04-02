#include <stdio.h>

int main ()
{
    int x=0,y=0,time_1=0,time_2=0,cmd=0,way=0;
 	while(cmd!=3)
	{
		scanf("%d%d",&time_2,&cmd);
        
	    if(way==0) y=y+10*(time_2-time_1);
	    if(way==1) x=x-10*(time_2-time_1);
	    if(way==2) y=y-10*(time_2-time_1);
	    if(way==3) x=x+10*(time_2-time_1);
	
	    if(cmd==1) way=(way+1)%4;
	    if(cmd==2) way=(way+3)%4;
		
		time_1=time_2;		
	}
	
	printf("%d %d\n",x,y);
	return 0;
}
