#include <stdio.h>

int main ()
{
	float x1,x2,x3,x4,y1,y2,y3,y4,n1,n2,n3,n4;
	
	scanf("%f%f%f%f%f%f%f%f",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
	
	n1=y1-(y2-y1)/(x2-x1)*x1;
	
	n2=y2-(y3-y2)/(x3-x2)*x2;
	
	n3=y3-(y4-y3)/(x4-x3)*x3;
	
	n4=y4-(y1-y4)/(x1-x4)*x4;
	
	if(((n1*n3)<=0)&&((n2*n4)<=0)) printf("1");
	else printf("0");

	return 0;
} 