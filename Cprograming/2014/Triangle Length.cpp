#include <stdio.h>

int main ()
{
	int a,b,c;
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	
	printf("%d",(a+b>c)&&(c+b>a)&&(a+c>b));	
	return 0;
}
