#include <stdio.h>

int main ()
{
	int a;
	scanf("%d",&a);
	
	printf("%d",(a%3)||(a%5)||(!(a%7)));	
	return 0;
}
