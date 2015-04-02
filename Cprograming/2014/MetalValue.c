#include <stdio.h>

int value(int type,int width,int height,int	length)
{
	int min=0,output=0,i=0;
	if(type==79) type=30;
	else if(type==47) type=10;
	else if(type==29) type=4;
	else if(type==82) type=5;
	else if(type==26) type=3;
	else if(type==22) type=9;
	else return -1;
	min=width;
	if(height<min) min=height;
	if(length<min) min=length;
	if(min<=0) return -2;
	for(i=min;i>=2;i--)
	{
		if((height%i + length%i + width%i)==0) break;
	}
	output=type*i*i*i*width*height*length;
	return output;
}

int main()
{
	printf("%d\n",value(79,4,8,2));
	return 0;
}
