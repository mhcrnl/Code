#include <stdio.h>

int main()
{
	int i=0,j=0,month[12]={31,30,31,30,31,30,31,31,30,31,30,31},year=0,time=0,result[10000]={0},input_m=0,input_d=0,start=0;
	scanf("%d%d",&year,&start);
	scanf("%d",&time);
	if (year%4!=0 || (year%100==0&&year%400!=0)) month[1]=28;
	else month[1]=29;

	for(i=0;i<time;i++)
	{
		scanf("%d%d",&input_m,&input_d);
		if(input_m<1||input_m>12) result[i]=-1;
	    else if(input_d<1||input_d>month[input_m-1]) result[i]=-2;
    	else
	    {		  
		  result[i]=start;
		  for(j=0;j<input_m-1;j++)
		  {
			result[i]=(result[i]+month[j])%7;
		  }
		result[i]=(result[i]+input_d-1)%7;
	    }
	}

	for(i=0;i<time;i++) printf("%d\n",result[i]);
	return 0;
}
